//
//  CyclePresentController.m
//  CycleAlertViewExample
//
//  Created by zl on 2017/11/9.
//  Copyright © 2017年 zl. All rights reserved.
//

#import "CyclePresentController.h"
#import "cycle_define.h"


@interface CyclePresentController()
/** coverView背景视图 */
//@property (nonatomic , strong) UIView   *coverView;
@end

@implementation CyclePresentController


/**  懒加载“背景视图”  */
- (UIView *)coverView {
    
    if (!_coverView) {

        _coverView = [UIView new];
        _coverView.backgroundColor = [UIColor blackColor];
        _coverView.alpha = 0.4;
        _coverView.userInteractionEnabled = YES;
        _coverView.frame = self.containerView.bounds;
        //添加手势
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(cycle_dismisViewController)];
        [_coverView addGestureRecognizer:tap];

    }
    ///是否隐藏背景
    _coverView.hidden = self.hideCoverView;
    ///背景色，透明度
    _coverView.backgroundColor = self.coverViewBgColor;
    _coverView.alpha = self.coverViewAlpha;
    
    return _coverView;
}
///控制背景视图的显示和隐藏
//-(void)setCoverView:(UIView *)coverView{
//    coverView.hidden = self.hideCoverView;
//}
//-(void)setHideCoverView:(BOOL)hideCoverView{
//    _hideCoverView = hideCoverView;
//    self.coverView.hidden = hideCoverView;
////    NSLog(@"%zd",hideCoverView);
//}

-(void)containerViewWillLayoutSubviews{
    [super containerViewWillLayoutSubviews];

//    NSLog(@"%f  %f  %f  %f",X,Y,presented_W,presented_H);
    ///设置弹出视图的尺寸
    self.presentedView.frame = self.presentedFrame;
    
//    self.presentedView.frame = CGRectMake(100   , 100, 200, 200);
    ///背景视图
    [self.containerView addSubview:self.coverView];
    [self.containerView insertSubview:self.coverView atIndex:0];
    ///10.5 是否可以点击背景View
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(noteClick:) name:@"kCanClickBgViewNotification" object:nil];

}
///10.6 点击背景View
- (void)noteClick:(NSNotification *)note{
    BOOL flg = note.object;
    self.canClickBgView = flg;
    [self cycle_dismisViewController];
}
-(void)dealloc{
    [[NSNotificationCenter defaultCenter]removeObserver:self];
}
- (void)cycle_dismisViewController{
//    NSLog(@"tap...");
    //[self presentview];
    if (self.canClickBgView) {
        [self.coverView removeFromSuperview];
        [self.presentedViewController dismissViewControllerAnimated:YES completion:^{
            NSLog(@"you tap me,and i have successed hide the coverView");
        }];
    }
    
    
}














@end
