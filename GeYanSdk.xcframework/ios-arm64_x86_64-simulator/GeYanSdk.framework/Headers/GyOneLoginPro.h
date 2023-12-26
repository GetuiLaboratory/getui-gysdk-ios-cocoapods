//
//  GyOneLoginPro.h
//  GySdkLib
//
//  Created by lzy on 2020/2/25.
//  Copyright © 2020 getui. All rights reserved.
//  

#import <Foundation/Foundation.h>

@class UIViewController;
@class GyAuthViewModel;

NS_ASSUME_NONNULL_BEGIN

@interface GyOneLoginPro : NSObject

/**
 进行用户认证授权, 获取网关 token 。

 @discussion 调用限制说明

 为避免授权页面多次弹出, 在调用该方法后, 授权页面弹出, 再次调用该方法时,
 该方法会直接跳出, 不执行授权逻辑。

 @discussion 需要用户在弹出的页面上同意服务意条款后, 才会进行免密认证。

 @param viewController  present认证页面控制器的vc
 @param viewModel       自定义授权页面的视图模型
 @param completion      结果处理回调

 @seealso GyAuthViewModel

 */
+ (void)requestTokenWithViewController:(UIViewController *)viewController
                             viewModel:(GyAuthViewModel *)viewModel
                            completion:(void (^)(NSDictionary *_Nullable result))completion;

+ (void)requestTokenWithCompletion:(void (^)(NSDictionary *_Nullable result))completion;

/**
 * @abstract 重新预取号
 *
 * @discussion 在通过requestTokenWithCompletion方法成功登录之后，为保证用户在退出登录之后，能快速拉起授权页面，请在用户退出登录时，调用此方法
 */
+ (void)renewPreGetToken;

/**
* @abstract 获取预取号结果
*
* @param completion 预取号结果
*/
+ (void)getPreGetTokenResult:(void (^)(NSDictionary *_Nullable result))completion;

/**
 * @abstract 判断预取号结果是否有效
 *
 * @return YES: 预取号结果有效，可直接拉起授权页面
 *          NO: 预取号结果无效，需手动加载进度条，等待预取号完成之后拉起授权页面
 */
+ (BOOL)isPreGetTokenResultValidate;

/**
 @abstract 关闭当前的授权页面

 @param animated 是否需要动画
 @param completion 关闭页面后的回调

 @discussion
 请不要使用其他方式关闭授权页面, 否则可能导致 OneLogin 无法再次调起
 */
+ (void)dismissAuthViewController:(BOOL)animated completion:(void (^ __nullable)(void))completion;

+ (void)dismissAuthViewController:(void (^ __nullable)(void))completion;

/**
 停止点击授权页面登录按钮之后的加载进度条
 */
+ (void)stopLoading;

/**
 enable授权页面登录按钮
 */
+ (void)enableAuthButton;

/**
 disable授权页面登录按钮
 */
+ (void)disableAuthButton;

/**
 * @abstract 服务条款左边复选框是否勾选
 */
+ (BOOL)isProtocolCheckboxChecked;

/**
 * @abstract 获取当前授权页面对应的配置
 *
 * @return 当前授权页面对应的配置
 */
+ (GyAuthViewModel *_Nullable)currentAuthViewModel;

/**
 * @abstract 获取当前授权页面对应的ViewController
 *
 * @return 当前授权页面对应的ViewController
 */
+ (UIViewController *_Nullable)currentAuthViewController;

/**
 * @abstract 更新授权页面一键登录按钮的文案
 *
 * @param authButtonTitle 一键登录按钮的文案
 */
+ (void)updateAuthButtonTitle:(NSAttributedString *)authButtonTitle;

/**
* @abstract 删除预取号的缓存
*/
+ (void)deletePreResultCache;

@end

NS_ASSUME_NONNULL_END
