//
//  GyAuthViewModel.h
//  GySdkLib
//
//  Created by lzy on 2019/7/19.
//  Copyright © 2019 getui. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GyAuthPrivacyItem.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^GYCustomUIHandler)(UIView *customAreaView);

@interface GyAuthViewModel : NSObject

#pragma mark - Status Bar/状态栏

/**
 状态栏样式。 默认 `UIStatusBarStyleDefault`。
 */
@property(nonatomic, assign) UIStatusBarStyle statusBarStyle;

#pragma mark - Navigation/导航

/**
 授权页导航的标题。默认为空字符串。
 */
@property(nullable, nonatomic, strong) NSAttributedString *naviTitle;

/**
 授权页导航的背景颜色。默认白色。
 */
@property(nullable, nonatomic, strong) UIColor *naviBgColor;

/**
 授权页导航左边的返回按钮的图片。默认黑色系统样式返回图片。尺寸会被约束为22x22。
 */
@property(nullable, nonatomic, strong) UIImage *naviBackImage;

/**
 授权页导航右边的自定义控件。
 */
@property(nullable, nonatomic, strong) UIView *naviRightControl;

/**
 导航栏隐藏。默认不隐藏。
 */
@property(nonatomic, assign) BOOL naviHidden;

#pragma mark - Logo/图标

/**
 授权页面上展示的图标。默认为 "OneLogin" 图标。
 */
@property(nullable, nonatomic, strong) UIImage *appLogo;

/**
 Logo 视图竖直方向偏移。

 @discussion
 如果导航栏没有隐藏, 偏移距离等于该视图顶部到导航底部的距离。
 如果导航栏隐藏, 偏移距离等于该视图顶部到状态栏之间的距离。
 */
@property(nonatomic, assign) CGFloat logoOffsetY;

/**
 Logo 图片隐藏。默认不隐藏。
 */
@property(nonatomic, assign) BOOL logoHidden;

#pragma mark - Phone Number Preview/手机号预览

/**
 号码预览文字的颜色。默认黑色。
 */
@property(nullable, nonatomic, strong) UIColor *phoneNumColor;

/**
 号码预览文字的大小。默认24pt。
 */
@property(nonatomic, assign) CGFloat phoneNumSize;

/**
 号码预览竖直方向偏移。

 @discussion
 如果导航栏没有隐藏, 偏移距离等于该视图顶部到导航底部的距离。
 如果导航栏隐藏, 偏移距离等于该视图顶部到状态栏之间的距离。
 */
@property(nonatomic, assign) CGFloat phoneNumLabelOffsetY;

#pragma mark - Switch Button/切换按钮

/**
 授权页切换账号按钮的颜色。默认蓝色。
 */
@property(nullable, nonatomic, strong) UIColor *switchButtonColor;

/**
 授权页切换账号按钮竖直方向偏移。

 @discussion
 如果导航栏没有隐藏, 偏移距离等于该视图顶部到导航底部的距离。
 如果导航栏隐藏, 偏移距离等于该视图顶部到状态栏之间的距离。
 */
@property(nonatomic, assign) CGFloat switchButtonOffsetY;

/**
 隐藏切换账号按钮。默认不隐藏。
 */
@property(nonatomic, assign) BOOL switchButtonHidden;

#pragma mark - Authorization Button/认证按钮

/**
 授权页认证按钮的背景图片, @[正常状态的背景图片, 不可用状态的背景图片, 高亮状态的背景图片]。默认正常状态为蓝色纯色, 不可用状态的背景图片时为灰色, 高亮状态为灰蓝色。
 */
@property(nullable, nonatomic, strong) NSArray<UIImage *> *authButtonImages;

/**
 授权按钮文案。默认白色的"一键登录"。
 */
@property(nullable, nonatomic, strong) NSAttributedString *authButtonTitle;

/**
 授权按钮竖直方向偏移。

 @discussion
 偏移距离等于该视图顶部到导航底部的距离。
 */
@property(nonatomic, assign) CGFloat authButtonOffsetY;

#pragma mark - Slogan/口号标语

/**
 Slogan竖直方向偏移。

 @discussion
 如果导航栏没有隐藏, 偏移距离等于该视图顶部到导航底部的距离。
 如果导航栏隐藏, 偏移距离等于该视图顶部到状态栏之间的距离。
 */
@property(nonatomic, assign) CGFloat sloganOffsetY;

/**
 Slogan 文字颜色。默认灰色, 12pt。
 */
@property(nonatomic, strong) UIColor *sloganTextColor;

#pragma mark - CheckBox & Privacy Terms/隐私条款勾选框及隐私条款

/**
 授权页面上条款勾选框初始状态。默认 YES。
 */
@property(nonatomic, assign) BOOL defaultCheckBoxState;

/**
 授权页面上勾选框勾选的图标。默认为蓝色图标。最大尺寸32x32, 推荐18x18。
 */
@property(nullable, nonatomic, strong) UIImage *checkedImage;

/**
 授权页面上勾选框未勾选的图标。默认为白色图标。最大尺寸32x32, 推荐18x18。
 */
@property(nullable, nonatomic, strong) UIImage *uncheckedImage;

/**
 隐私条款文字属性。默认基础文字灰色, 条款蓝色高亮, 12pt。
 */
@property(nullable, nonatomic, strong) NSDictionary<NSAttributedStringKey, id> *privacyTermsAttributes;

/**
 额外的条款。默认为空。
 */
@property(nullable, nonatomic, strong) NSArray<GyAuthPrivacyItem *> *additionalPrivacyTerms;

/**
 服务条款普通文字的颜色。默认灰色。
 */
@property(nullable, nonatomic, strong) UIColor *termTextColor;

/**
 隐私条款竖直方向偏移。

 @discussion
 偏移距离等于该视图底部到屏幕底部(视图控制器)底部的距离。
 */
@property(nonatomic, assign) CGFloat termsOffsetY;

#pragma mark - Custom Area/自定义区域

/**
 自定义区域视图的处理block

 @discussion
 提供的视图容器使用NSLayoutConstraint与相关的视图进行布局约束。
 如果导航栏没有隐藏, 顶部与导航栏底部对齐, 左边与屏幕对齐, 右边与屏幕对齐, 底部与屏幕对齐。
 如果导航栏隐藏, 顶部与状态栏底部对齐, 左边与屏幕对齐, 右边与屏幕对齐, 底部与屏幕对齐。
 */
@property(nullable, nonatomic, copy) GYCustomUIHandler customUIHandler;

#pragma mark - Background Image/授权页面背景图片

/**
 授权页面背景图片
 */
@property(nullable, nonatomic, strong) UIImage *backgroundImage;

@end

NS_ASSUME_NONNULL_END
