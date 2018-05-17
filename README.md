# CycleAlertAnyView
（ios8.0,转场动画原理，根据自己需求看是否适合使用此转场ios动画）适用于任何内容弹出，内容面板，样式等全可自定义

1.创建一个继承自UIViewController,如AlertViewController

如AlertViewController.h

+(instancetype)sharedAlertViewController;

///弹出,如果需要传值过来，可以定义对应的属性，模型等接收并赋值，跟其他地方一样，小弟就少废话了
-(void)showAlertViewController;


如AlertViewController.m

#import "AlertViewController.h"

@interface AlertViewController ()

/** 管理者CycleAlertManager */
@property (nonatomic, strong) CycleAlertManager  *alertManager;

@end

@implementation AlertViewController

/** 管理者CycleAlertManager */

-(CycleAlertManager *)alertManager{

    if(!_alertManager){
    
        _alertManager = [CycleAlertManager sharedCycleAlertManager];
        
    }
    
    return  _alertManager;

}

  +(instancetype)sharedAlertViewController{

    return [[self alloc]init];
    
}

-(instancetype)init
{
    self = [super init];
    
    if (self) {
 
    }

    return self;

}

-(void)showAlertViewController{
    // WS(weakSelf);
    
    self.transitioningDelegate = self.alertManager;
    
    self.modalPresentationStyle = UIModalPresentationCustom;
    
    ///视图大小
    
    CGFloat alert_w = 200;
    
    CGFloat alert_h = 200;
    
    CGFloat alert_x = ([UIScreen mainScreen].bounds.size.width-alert_w)*0.5;
    
    CGFloat alert_y = ([UIScreen mainScreen].bounds.size.height-alert_h)*0.5;

    ///设置相关属性

    self.alertManager.presentedFrame = CGRectMake(alert_x, alert_y, alert_w, alert_h);
    
    ///设置背景View颜色

    self.alertManager.coverViewBgColor = [UIColor blackColor];
    
    ///设置背景View透明度

    self.alertManager.coverViewAlpha = 0.3;
    
    ///设置弹出方向，不设置，默认弹出方向为“中心弹出”
    
    self.alertManager.AlertDirection = alertViewDirectionTypeCenter;
    
    ///是否可以点击背景，不设置默认可以点击
    
    self.alertManager.canClickBgView = NO;///设置为NO不可以点击
    
    ///弹出
    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:self animated:YES completion:nil];
    
}

-(void)dealloc{

    self.alertManager = nil;
    
}

多多指点！谢谢
