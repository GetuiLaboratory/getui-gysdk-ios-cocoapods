//
//  GySdk.h
//  GySdkLib
//
//  Created by admin on 2017/4/21.
//  Copyright © 2017年 getui. All rights reserved.
//

#import "GyCheckModel.h"
#import "GyAuthViewModel.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 *  注册接口回调
 *
 *  @param isSuccess 成功标志位
 *  @param error     错误信息
 */
typedef void (^GyCallback)(BOOL isSuccess, NSError *_Nullable error, NSString *_Nullable gyUid);

/**
 *  验证接口回调
 *
 *  @param verifyDictionary 返回调用结果信息
 */
typedef void (^GyVerifyCallback)(NSDictionary *_Nullable verifyDictionary);


/**
 *  验证码验证接口回调
 *
 *  @param smsVerifyDictionary 短信验证结果信息
 */
typedef void (^GySmsVerifyCallback)(NSDictionary *_Nullable smsVerifyDictionary);

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
+ (NSString *_Nonnull )getVersion;

/**
 *  初始化个验 SDK
 *
 *  @param aAppId appid
 */
+ (void)startWithAppId:(NSString *_Nonnull)aAppId withCallback:(GyCallback _Nonnull)callback;

/**
 *  云验证接口
 *
 *  @param type          验证方式
 *  @param pnMD5         手机号md5值,32位小写
 *  @param smsTemplateId 自定义短信模板 id，申请 AppId 时配置
 *  @param callback      验证接口回调
 */
+ (void)verifyForType:(GyVerifyType)type withPnMD5:(NSString *_Nonnull)pnMD5 withSmsTemplateId:(NSString *_Nonnull)smsTemplateId withCallback:(GyVerifyCallback _Nonnull)callback;

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

#pragma mark 一键登录功能, 包括设置预取号超时时间/预取号/登陆/关闭登陆页面等功能

/**
 * 设置一键登录预取号阶段的超时时间
 * @param timeout 单位秒
 */
+ (void)setEloginTimeout:(NSTimeInterval)timeout;

/**
 * 预登陆,若成功,则可以调用一键登录接口,打开登录页面
 * @param callback 通用接口回调
 * {
 *  code = 30000; // NSNumber, 非30000为失败的状态码
 *  processID = 47dab9b7c26629cd9bc117f88e2f9233; // NSString, 流水号
 *  operatorType = 4; // NSString, 操作类型
 *  errorCode = "-30003", // NSString, 运营商返回的错误码
 *  msg = "\U83b7\U53d6accessCode\U6210\U529f"; // NSString, 运营商返回的描述消息
 *  metadata = {}; // NSDictionary, 失败时, 运营商的响应内容。
 * }
 *  其中中国移动有效期为 1 小时,中国联通和中国电信为 10 分钟。
 */
+ (void)preGetToken:(GyVerifyCallback)callback;

/**
 * 一键登录
 * @param controller 当前viewController
 * @param model GYAuthViewModel
 * @param callback 通用接口回调
 * @discussion
 * {
 *  code = 30000; // NSNumber, 非30000为失败的状态码
 *  processID = 47dab9b7c26629cd9bc117f88e2f9233; // NSString, 流水号
 *  operatorType = 4; // NSString, 操作类型
 *  errorCode = "-30003", // NSString, 失败时,运营商返回的错误码
 *  msg = "\U83b7\U53d6accessCode\U6210\U529f"; // NSString, 描述消息
 *  metadata = {}; // NSDictionary, 失败时, 运营商的响应内容。
 *  token = "xxx",  //NSString, 登陆成功返回的用户授权凭证信息,可以用于在服务端获取完整手机号码
 *  expiredTime: 155555555555, //NSInteger,成功时, token有效期
 *  pn: "133****3333", //NSString,成功时, 脱敏7位手机号码
 * }
 * @discussion
 *  token 有效期:中国移动的有效期为 2 分钟，中国联通的为 30 分钟，中国电信的为 30 天。
 */
+ (void)oneTapLogin:(UIViewController *)controller withViewModel:(GyAuthViewModel *)model andCallback:(GyVerifyCallback)callback;

/**
 * 关闭登录界面
 * 请不要使用其他方式关闭授权页面, 否则可能导致 OneLogin 无法再次调起
 */
+ (void)closeAuthVC:(BOOL)animated completion:(void (^ __nullable)(void))completion;

+ (void)closeAuthVC:(void (^ __nullable)(void))completion;

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
 * @abstract 一键登录预取号拿到的token是否还在有效期
 *
 * @return YES - 还在有效期，可直接调用oneTapLogin 方法进行登陆
 *         NO  - 已失效，需重新调用preGetToken进行预取号之后再调用oneTapLogin方法进行取号
 */
+ (BOOL)isPreGettedTokenValidate;

/**
 * 当前网络环境
 * 根据返回结果判断是否适合使用一键登录方法(数据网络必须打开,如下所示,需要满足network==1 || network==3)
 * carrier: 运营商： 0.未知 / 1.中国移动 / 2.中国联通 / 3.中国电信
 * network: 网络类型： 0.无网络/ 1.数据流量 / 2.wifi / 3.数据+wifi
 * network即使返回非0, 也可能因为终端用户未授权,数据网络网络权限而无法访问设备的移动蜂窝数据网络
 * {
 *  carrier: 0/1/2/3
 *  network: 0/1/2/3
 * }
 */
+ (NSMutableDictionary *)currentNetworkInfo;

#pragma mark 本机号码校验功能, 与一键登录功能无关联

/**
 * 获取本机号码校验所需要的 processID 和 token
 * @param pn 待校验手机号码
 * @param callback 回调
 * {
 *  code: 30000, //NSNumber, 非30000为失败
 *  msg: "success" // NSString, 返回信息
 *  phone: "1333333333" // NSString, 输入的手机号
 *  token: "xxx" // NSString, 授权凭证
 *  processID: "xxx" // NSString, 流水号
 *  operatorType = 4; // NSString, 操作类型
 * }
 */
+ (void)getPhoneVerifyToken:(NSString *)pn andCallback:(GyVerifyCallback)callback;

/**
 * 本机号码校验,本接口为客户端校验手机号使用
 * 若需要服务端校验手机号码,请使用 getPhoneVerifyToken:andCallback 获取 相关参数
 * @param pn 待校验手机号码
 * @param token getPhoneVerifyToken 返回的 token
 * @param processId getPhoneVerifyToken 返回的processId
 * @param callback 回调
 * {
 *  code: 30000, //NSNumber, 非30000为失败
 *  msg: "success" // NSString, 返回信息
 * }
 */
+ (void)checkPhoneNumber:(NSString *_Nonnull)pn andCallback:(GyVerifyCallback _Nonnull)callback __deprecated_msg("请使用 checkPhoneNumber:withToken:withProcessId:andCallback");

+ (void)checkPhoneNumber:(NSString *_Nonnull)pn withToken:(NSString *_Nonnull)token withProcessId:(NSString *_Nonnull)processId andCallback:(GyVerifyCallback _Nonnull)callback;

#pragma mark 销毁 SDK

/**
 *  销毁 SDK
 */
+ (void)destroy;

@end
