//
//  GyCheckModel.h
//  GySdkLib
//
//  Created by admin on 2018/3/16.
//  Copyright © 2018年 getui. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GyContentModel : NSObject
@property (nonatomic, copy) NSString *pn;
@property (nonatomic, copy) NSString *slogan;
@property (nonatomic, copy) NSString *term;
@property (nonatomic, copy) NSString *link;

+ (GyContentModel*)currentModel;
@end

@interface GyCheckModel : NSObject
@property (nonatomic, copy) NSString *account;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *pn;
@property (nonatomic, copy) NSString *pwd;
@property (nonatomic, copy) NSString *nickName;
@property (nonatomic, copy) NSString *registerTime;
@property (nonatomic, copy) NSString *loginTime; // 登录保护专有
@property (nonatomic, copy) NSString *runEnv;
@property (nonatomic, copy) NSString *moveCount;
@property (nonatomic, copy) NSString *clickCount;
@property (nonatomic, copy) NSString *keyCount;
@property (nonatomic, copy) NSString *operatingTime;
@property (nonatomic, copy) NSString *ip;
@property (nonatomic, copy) NSString *appVer;
@property (nonatomic, copy) NSString *mac;
@property (nonatomic, copy) NSString *idfa;
@property (nonatomic, copy) NSString *referrer;
@property (nonatomic, copy) NSString *userAgent;
@property (nonatomic, copy) NSString *xForwardFor;
@property (nonatomic, copy) NSString *result;
@property (nonatomic, copy) NSString *reason;
@property (nonatomic, copy) NSString *loginType;
@end
