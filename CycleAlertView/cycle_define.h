//
//  cycle_define.h
//  MyCycleTool
//
//  Created by dihuijun on 17/8/15.
//  Copyright © 2017年 Cycle. All rights reserved.
//

#ifndef cycle_define_h
#define cycle_define_h






/*************     宏     ********************/
//代码块self的弱应用
#define WS(weakSelf) __weak __typeof(&*self)weakSelf = self
///判断字符串是否为空
#define kisNilString(__String) (__String==nil || __String == (id)[NSNull null] || ![__String isKindOfClass:[NSString class]] || [__String isEqualToString:@""] || [[__String stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] isEqualToString:@""])
///打印
#if DEBUG
#define NSLog(FORMAT,...)   NSLog(@"%@文件%d行输出打印:%@",[[[NSString stringWithFormat:@"%s",__FILE__] componentsSeparatedByString:@"/"] lastObject], __LINE__,[NSString stringWithFormat:FORMAT, ##__VA_ARGS__])
#else
#define NSLog(FORMAT, ...) nil
#endif



/** 随机颜色  */
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue: (255)/255.0 alpha:1.0]
/** 设置图片  */
#define kImageNamed(s)  [UIImage imageNamed:s]
/** 传入字符串的颜色 */
#define kColorWithHexString(s)   [UIColor colorWithHexString:s]
/** 设置加粗的字体 */
#define kBoldFont(f)  [UIFont boldSystemFontOfSize:f]
/** 屏幕宽度和高度 */
#define kSCREENWIDTH [UIScreen mainScreen].bounds.size.width
#define kSCREENHEIGHT [UIScreen mainScreen].bounds.size.height
/** 字体 */
#define kFont(selfFont) [UIFont systemFontOfSize:selfFont]
/** 颜色 **/
#define kColor(color)  [UIColor color]
/** 三原色 */
#define KRGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:(a)]
/** 主窗口 */
#define KeyWindow [UIApplication sharedApplication].keyWindow
/**  iOS版本 */
#define iOS(version) ([UIDevice currentDevice].systemVersion.doubleValue >=(version))

/*
 国际化
 创建一个Localizable.strings
 English:"home"="home";
 Chinese:"home"="首页";
 
 value:注释，对key注释
 table:nil表示如果为nil他会去找整个的Localizable.strings,如果table:abc,他会找abc.strings
 */
#undef L
#define L(key) \
[[NSBundle mainBundle]localizedStringForKey:(key) value:@"" table:nil]

//释放定时器
#define IT_INVALIDATE_TIMER(__TIMER)\
{\
[__TIMER invalidate];\
__TIMER = nil;\
}



#import "CyclePresentController.h"
#import "CycleAlertManager.h"


#endif /* cycle_define_h */
