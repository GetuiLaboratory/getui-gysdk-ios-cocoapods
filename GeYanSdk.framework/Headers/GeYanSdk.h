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
typedef void (^GyCallback)(BOOL isSuccess, NSError *error);
/**
 *  验证接口回调
 *
 *  @param verifyDictionary 返回调用结果信息
 */
typedef void (^GyVerifyCallback)(NSDictionary *verifyDictionary);


/**
 *  验证码验证接口回调
 *
 *  @param smsVerifyDictionary 短信验证结果信息
 */
typedef void (^GySmsVerifyCallback)(NSDictionary *smsVerifyDictionary);


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
 智能无感验证接口

 @param pnMD5 MD5后的手机号码
 @param accountId accountId
 @param businessId 业务Id
 @param callback 通用接口回调
 */
+ (void)nonSenseCaptchaWithPnMD5:(NSString *)pnMD5 accountId:(NSString *)accountId businessId:(NSString *)businessId withCallback:(GyVerifyCallback)callback;

/**
 动画验证接口

 @param businessId 业务Id
 @param callback 通用接口回调
 */

+ (void)startAnimationCaptchaWithBusinessId:(NSString *)businessId withCallback:(GyVerifyCallback)callback;
/**
 *  销毁 SDK
 */
+ (void)destroy;

@end
