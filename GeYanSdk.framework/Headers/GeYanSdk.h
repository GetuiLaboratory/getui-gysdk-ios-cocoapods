//
//  GySdk.h
//  GySdkLib
//
//  Created by admin on 2017/4/21.
//  Copyright © 2017年 getui. All rights reserved.
//

#import "GyCheckModel.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 *  注册接口回调
 *
 *  @param isSuccess 成功标志位
 *  @param error     错误信息
 */
typedef void (^GyCallback)(BOOL isSuccess, NSError *error, NSString *gyUid);

/**
 *  验证接口回调
 *
 *  @param verifyDictionary 返回调用结果信息
 */
typedef void (^GyVerifyCallback)(NSDictionary *verifyDictionary);

/**
 *  验证界面点击回调
 *
 *  @param senderTag 点击回调
 */
typedef void (^GyClickHandler)(NSInteger senderTag);


/**
 *  验证码验证接口回调
 *
 *  @param smsVerifyDictionary 短信验证结果信息
 */
typedef void (^GySmsVerifyCallback)(NSDictionary *smsVerifyDictionary);

/**
 *  准备弹出动画窗口回调，用于智能无感验证失败后，准备弹出动画窗口前的回调处理。
 *
 */
typedef void (^GyReadyAnimationCallback)(void);


/**
 *  验证方式
 */

typedef NS_ENUM(NSUInteger, GyVerifyType) {
    /**
     *  Cloud + Sms 验证
     */
            GyVerifyTypeCloudSms,
    /**
     *  Cloud 验证
     */
            GyVerifyTypeCloud,
    /**
     *  Sms 验证
     */
            GyVerifyTypeSms,
};


@interface GeYanSdk : NSObject


/**
 设置debug模式，发布时不要设置，默认关闭

 @param debug 是否打开调试
 */
+ (void)setDebug:(BOOL)debug;

/**
 获取SDK版本号

 @return SDK版本号
 */
+ (NSString *)getVersion;

/**
 *  初始化个验 SDK
 *
 *  @param aAppId appid
 */
+ (void)startWithAppId:(NSString *)aAppId withCallback:(GyCallback)callback;

/**
 *  云验证接口
 *
 *  @param type          验证方式
 *  @param pnMD5         手机号md5值,32位小写
 *  @param smsTemplateId 自定义短信模板 id，申请 AppId 时配置
 *  @param callback      验证接口回调
 */
+ (void)verifyForType:(GyVerifyType)type withPnMD5:(NSString *)pnMD5 withSmsTemplateId:(NSString *)smsTemplateId withCallback:(GyVerifyCallback)callback;

/**
 *  短信校验接口
 *
 *  @param code     短信验证码
 *  @param pnMD5    手机号md5值,32位小写
 *  @param callback 通用接口回调
 */
+ (void)smsVerifyCode:(NSString *)code withPnMD5:(NSString *)pnMD5 withCallback:(GySmsVerifyCallback)callback;

/**
 注册保护接口

 @param checkModel 校验模型
 @param callback 通用接口回调
 */
+ (void)checkRegister:(GyCheckModel *)checkModel withCallback:(GyVerifyCallback)callback;

/**
 登录保护接口
 
 @param checkModel 校验模型
 @param callback 通用接口回调
 */
+ (void)checkLogin:(GyCheckModel *)checkModel withCallback:(GyVerifyCallback)callback;


/**
 * 智能无感验证接口
 * @param pnMD5 MD5后的手机号码
 * @param accountId accountId
 * @param businessId 业务businessId
 * @param showLoadingView 是否显示动画
 * @param readyAnimationCallback 动画回调
 * @param callback 通用接口回调
 */
+ (void)nonSenseCaptcha:(NSString *)pnMD5 accountId:(NSString *)accountId businessId:(NSString *)businessId isShowLoadingView:(BOOL)showLoadingView readyAnimation:(GyReadyAnimationCallback)readyAnimationCallback completeCallback:(GyVerifyCallback)callback;

/**
 * 动画验证接口
 * @param businessId 业务ID
 * @param showLoadingView 是否显示动画
 * @param readyAnimationCallback 动画回调
 * @param callback 通用接口回调
 */
+ (void)startAnimationCaptcha:(NSString *)businessId isShowLoadingView:(BOOL)showLoadingView isReadyAnimation:(GyReadyAnimationCallback)readyAnimationCallback completeCallback:(GyVerifyCallback)callback;


/**
 一键登录接口

 @param clickHandler 点击事件回调
 @param callback 通用接口回调
 */
+ (void)oneTapLogin:(GyClickHandler)clickHandler andCallback:(GyVerifyCallback)callback;

/**
 * 本机号码校验
 * @param pn 手机号码
 * @param token token
 * @param callback 回调
 */
+ (void)checkPhoneNumber:(NSString *)pn withToken:(NSString *)token useCloudVerify:(BOOL)useCloudVerify andCallback:(GyVerifyCallback)callback;

/**
 * 检查当前环境是否可以使用一键登录方法
 * @param callback 结果回调
 */
+ (void)checkELoginEnable:(GyVerifyCallback)callback;

/**
 * 获取token
 * @param callback 结果回调
 */
+ (void)getVerifyTokenWithCallback:(GyVerifyCallback)callback;

/**
 * 关闭登录界面
 */
+ (void)closeAuthVC;

/**
 *  销毁 SDK
 */
+ (void)destroy;

@end
