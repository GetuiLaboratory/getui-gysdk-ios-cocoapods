//
//  GyAuthPrivacyItem.h
//  GySdkLib
//
//  Created by lzy on 2019/7/19.
//  Copyright © 2019 getui. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GyAuthPrivacyItem : NSObject
/**
 条款标题
 */
@property(nonatomic, strong) NSString *termTitle;

/**
 条款链接
 */
@property(nonatomic, strong) NSURL *termLink;

- (instancetype)initWithTitle:(NSString *)title linkURL:(NSURL *)url;
@end

NS_ASSUME_NONNULL_END
