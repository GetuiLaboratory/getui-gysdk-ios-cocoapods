//
//  GySdk.h
//  GySdkLib
//
//  Created by admin on 2017/4/21.
//  Copyright © 2017年 getui. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  通用接口回调
 *
 *  @param isSuccess 成功标志位
 *  @param error     错误信息
 */
typedef void (^GyCallback)(BOOL isSuccess, NSError *error);
/**
 *  验证接口回调
 *
 *  @param isCloudVerifySuccess 云验证成功标志位
 *  @param isSmsSendSuccess     短信发送成功标志位
 *  @param error                错误信息
 */
typedef void (^GyVerifyCallback)(BOOL isCloudVerifySuccess, BOOL isSmsSendSuccess, NSError *error);

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
+ (void)smsVerifyCode:(NSString *)code withPnMD5:(NSString *)pnMD5 withCallback:(GyCallback)callback;
/**
 *  销毁 SDK
 */
+ (void)destroy;

@end
