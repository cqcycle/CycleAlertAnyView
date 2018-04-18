//
//  CycleAlertManager.h
//  CycleAlertViewExample
//
//  Created by zl on 2017/11/10.
//  Copyright © 2017年 zl. All rights reserved.
//  管理视图的弹出

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class CyclePresentController;
typedef NS_ENUM(NSInteger,alertViewDirectionType){
    alertViewDirectionTypeBottom = 1,
    alertViewDirectionTypeCenter = 2
};

@interface CycleAlertManager : NSObject<UIViewControllerAnimatedTransitioning,UIViewControllerTransitioningDelegate>
///初始化管理者
+(instancetype)sharedCycleAlertManager;
/** 是否隐藏背景 */
@property (nonatomic , assign) BOOL hideCoverView;
/** 背景View透明度 */
@property (nonatomic , assign) CGFloat coverViewAlpha;
/** 背景View背景色 */
@property (nonatomic) UIColor *coverViewBgColor;
/**  设置尺寸 */
@property (nonatomic) CGRect presentedFrame;
/** 方向 */
@property (nonatomic,assign) alertViewDirectionType AlertDirection;

/** coverView背景视图 */
@property (nonatomic , strong) UIView   *coverView;
/** 弹出的控制器Controller */
@property (nonatomic, strong) CyclePresentController*  presentationViewController;
/** 背景灰色是否可以点击 */
@property (nonatomic, assign) BOOL canClickBgView;
/** 设置消失时间 */
@property (nonatomic, assign) CGFloat dismissTime;


@end
