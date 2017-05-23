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
 *  验证类型
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

+ (void)verifyForType:(GyVerifyType)type withPnMD5:(NSString *)pnMD5 withSmsTemplateId:(NSString *)smsTemplateId withCallback:(GyVerifyCallback)callback;

+ (void)smsVerifyCode:(NSString *)code withPnMD5:(NSString *)pnMD5 withCallback:(GyCallback)callback;

+ (void)destory;

@end
