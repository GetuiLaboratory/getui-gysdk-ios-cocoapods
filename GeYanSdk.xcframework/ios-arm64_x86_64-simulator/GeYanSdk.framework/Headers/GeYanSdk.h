//
//  GySdk.h
//  GySdkLib
//
//  Created by ak on 2017/4/21.
//  Copyright © 2017年 getui. All rights reserved.
//
// GySdk-Version: 3.0.7.0

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// 运营商
typedef NS_ENUM(NSInteger, GyOperatorType) {
    GyOperatorTypeUNKNOW = 0,
    GyOperatorTypeCM = 1, //移动
    GyOperatorTypeCU = 2, //联通
    GyOperatorTypeCT = 3, //电信
};

#if __has_include(<GeYanSdk/GeYanSdk.h>)
#import <GeYanSdk/GyCheckModel.h>
#import <GeYanSdk/GyAuthViewModel.h>
#import <GeYanSdk/GyAuthPrivacyItem.h>
#import <GeYanSdk/GyOneLoginPro.h>
#else
#import "GyCheckModel.h"
#import "GyAuthViewModel.h"
#import "GyAuthPrivacyItem.h"
#import "GyOneLoginPro.h"
#endif

/// 注册接口回调
/// @param isSuccess 成功标志位
/// @param error     错误信息
typedef void (^GyCallback)(BOOL isSuccess, NSError *_Nullable error, NSString *_Nullable gyUid);


/// 验证接口回调
/// @param verifyDictionary 返回调用结果信息
typedef void (^GyVerifyCallback)(NSDictionary *_Nullable verifyDictionary);


@interface GeYanSdk : NSObject

//MARK: -

/// 初始化个验SDK
/// @param appId 您申请的APPID
/// @param callback 初始化结果回调
+ (void)startWithAppId:(NSString *_Nonnull)appId withCallback:(GyCallback _Nonnull)callback;

/// 预登录超时时间, 对[GeYanSdk preGetToken:]方法的超时设置
/// @param timeout 默认10s
/// SDK-3.0.0.0+
+ (void)setPreLoginTimeout:(NSTimeInterval)timeout;

/// 一键登录超时时间, 对[GeYanSdk oneTapLogin:...]方法的超时设置
/// @param timeout 默认10s
/// SDK-3.0.0.0+
+ (void)setEloginTimeout:(NSTimeInterval)timeout;

/// 设置联通参数， 优化首次取号速度
/// - Parameters:
///   - appId: appId
///   - appKey: appKey
+ (void)setUnicomWithAppId:(NSString* _Nonnull)appId appKey:(NSString* _Nonnull)appKey;

/// 设置移动参数， 优化首次取号速度
/// - Parameters:
///   - appId: appId
///   - appKey: appKey
+ (void)setMobileWithAppId:(NSString* _Nonnull)appId appKey:(NSString* _Nonnull)appKey;

/// 设置电信参数， 优化首次取号速度
/// - Parameters:
///   - appId: appId
///   - appKey: appKey
+ (void)setTelecomWithAppId:(NSString* _Nonnull)appId appKey:(NSString* _Nonnull)appKey;

//MARK: - 预取号

/// 手动预登录
/// 向运营商发起预登录请求
/// @param callback 预登录结果回调
+ (void)preGetToken:(GyVerifyCallback _Nonnull)callback;

/// 预取号缓存是否有效
/// YES - 还在有效期，可直接调用一键登录
/// NO  - 已失效，需重新预取号
/// 预取号有效期：电信1小时 、联通30分钟、移动2分钟
+ (BOOL)isPreGettedTokenValidate;

/// 删除预取号缓存
+ (void)deletePreResultCache;


//MARK: - 一键登录3.0

/// 一键登录
/// @param controller 当前viewController
/// @param model GYAuthViewModel
/// @param contentView 内容视图
/// @param subViewList contentView的子视图列表  @[pnLabel, sloganLabel, loginBtn, checkboxBtn, termLabel];
/// @param loginBlock 登录结果回调
/// SDK-3.0.0.0+
+ (void)oneTapLogin:(UIViewController *_Nonnull)controller
          viewModel:(GyAuthViewModel *_Nonnull)model
        contentView:(UIView *_Nonnull)contentView
        subViewList:(NSArray *_Nonnull)subViewList
         loginBlock:(GyVerifyCallback __nullable)loginBlock;


//MARK: - 一键登录2.0

/// 一键登录 (已废弃)
/// @param controller 当前viewController
/// @param model GYAuthViewModel
/// @param callback 通用接口回调
/// {
///   code = 30000;
///   expiredTime = 600;
///   msg = "操作成功";
///   number = "180****7372";
///   operatorType = 3;
///   processID = ff1ec6ed0e9378ee6944e0ad8f5c5cc7;
///   token = "bm01M2EyZDUyMmUzNjI0OWMyYTM1OGI3MDc1Y2NhMTI5OHw1NzIxfDN8djJ8M1==";
///  }
//+ (void)oneTapLogin:(UIViewController *_Nonnull)controller withViewModel:(GyAuthViewModel *_Nonnull)model andCallback:(GyVerifyCallback _Nonnull)callback;

/// 关闭登录界面
/// @param animated 是否动画
/// @param completion 完成回调
+ (void)closeAuthVC:(BOOL)animated completion:(void (^ __nullable)(void))completion;

/// 关闭 登录界面， animated=YES
/// @param completion 完成回调
+ (void)closeAuthVC:(void (^ __nullable)(void))completion;

/// 停止点击授权页面登录按钮之后的加载进度条
+ (void)stopLoading;

/// enable授权页面登录按钮
+ (void)enableAuthButton;

/// disable授权页面登录按钮
+ (void)disableAuthButton;

/// 更新授权页面一键登录按钮的标题文案
/// @param authButtonTitle 登录按钮的标题文案
+ (void)updateAuthButtonTitle:(NSAttributedString *_Nonnull)authButtonTitle;

/// 服务条款左边复选框是否勾选
+ (BOOL)isProtocolCheckboxChecked;


//MARK: - 本机号码校验

/// 获取本机号码校验所需要的 processID 和 token
/// @param callback 回调
/// {
///  code = 30000;
///  msg = "操作成功";
///  operatorType = 3;
///  processID = 0af5e43c1b06d1ca97f932725ae364ef;
///  token = nm62ee17653a214872904a42671bf25ac3;
/// }
+ (void)getPhoneVerifyTokenCallback:(GyVerifyCallback _Nonnull)callback;

/// 本机号码校验,本接口为客户端校验手机号使用
/// 若需要服务端校验手机号码,请使用 getPhoneVerifyToken:andCallback 获取 相关参数
/// @param pn 待校验手机号码
/// @param token getPhoneVerifyToken 返回的 token
/// @param processId getPhoneVerifyToken 返回的processId
/// @param opType getPhoneVerifyToken 返回的operatorType
/// @param callback 回调
/// {
///   code: 30000, //NSNumber, 非30000为失败
///   msg: "success" // NSString, 返回信息
/// }
+ (void)checkPhoneNumber:(NSString *_Nonnull)pn withToken:(NSString *_Nonnull)token withProcessId:(NSString *_Nonnull)processId withOperatorType:(NSString *_Nonnull)opType andCallback:(GyVerifyCallback _Nonnull)callback;

+ (void)checkPhoneNumber:(NSString *_Nonnull)pn andCallback:(GyVerifyCallback _Nonnull)callback __deprecated_msg("请使用 checkPhoneNumber:withToken:withProcessId:andCallback");


//MARK: -

/// 设置debug模式，发布时不要设置，默认关闭
/// @param debug 是否打开调试
+ (void)setDebug:(BOOL)debug;

/// 设置IDFA
/// SDK-2.0.6.0+
/// @param idfa idfa
+ (void)setIDFA:(NSString *_Nonnull)idfa;

/// 当前网络环境
/// 根据返回结果判断是否适合使用一键登录方法(数据网络必须打开,如下所示,需要满足network==1 || network==3)
/// carrier: 运营商： 0.未知 / 1.中国移动 / 2.中国联通 / 3.中国电信
/// network: 网络类型： 0.无网络/ 1.数据流量 / 2.wifi / 3.数据+wifi
/// network即使返回非0, 也可能因为终端用户未授权,数据网络网络权限而无法访问设备的移动蜂窝数据网络
/// {
///  carrier: 0/1/2/3
///  network: 0/1/2/3
/// }
+ (NSMutableDictionary *_Nonnull)currentNetworkInfo;


/// 获取当前授权页面对应的ViewController
+ (UIViewController *_Nullable)currentAuthViewController;

/// 获取当前手机卡数量
/// @return 0,1,2
+ (NSInteger)getCurrentCarrierCount;

/// 获取SDK版本号
+ (NSString *_Nonnull)getVersion;

/// 获取 gyuid
+ (NSString *_Nullable)gyuid;

/// 销毁 SDK
+ (void)destroy;


//MARK: - 废弃

/// 初始化SDK
/// 适用于首次安装初始化，需要等待网络授权后再进行注册的情况
/// @param appId 您申请的APPID
/// @param timeout 等待授权超时时间,单位秒
/// @param callback 初始化结果回调
+ (void)startWithAppId:(NSString *_Nonnull)appId withTimeout:(NSTimeInterval)timeout withCallback:(GyCallback _Nonnull)callback __deprecated_msg("已废弃");

/// 注册保护接口
/// @param checkModel 校验模型
/// @param callback 通用接口回调
+ (void)checkRegister:(GyCheckModel *_Nonnull)checkModel withCallback:(GyVerifyCallback _Nonnull)callback __deprecated_msg("已废弃");;
    
/// 登录保护接口
/// @param checkModel 校验模型
/// @param callback 通用接口回调
+ (void)checkLogin:(GyCheckModel *_Nonnull)checkModel withCallback:(GyVerifyCallback _Nonnull)callback __deprecated_msg("已废弃");


+ (void)setOnlyUseOneLogin:(BOOL)onlyUseOL __deprecated_msg("已废弃");

+ (void)setUseStrictMode:(BOOL)strictMode __deprecated_msg("已废弃");

@end
