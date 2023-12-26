//
//  GyAuthPrivacyItem.h
//  GySdkLib
//
//  Created by lzy on 2019/7/19.
//  Copyright © 2019 getui. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class GyAuthPrivacyItem;

typedef void(^OLPrivacyTermItemBlock)(GyAuthPrivacyItem *termItem, UIViewController *controller);

@interface GyAuthPrivacyItem : NSObject

/**
 * 条款标题，条款标题, 若设置此属性且未设置"GyAuthViewModel#webNaviTitle",则作为隐私页面导航栏标题默认标题
 */
@property(nonatomic, strong) NSString *termTitle;

/**
 * 条款标题, 若设置此属性且未设置"GyAuthViewModel#webNaviTitle",则作为隐私页面导航栏默认标题
 */
@property(nonatomic, strong) NSAttributedString *termAttributeTitle;

/**
 条款链接
 */
@property(nonatomic, strong) NSURL *termLink;

/**
 条款链接
 */
@property (nonatomic, strong) NSURLRequest *urlRequest;

/**
 查看条款链接回调，当设置该回调时，查看服务条款时不进入SDK内部服务条款页面，由客户自定义处理
 */
@property(nonatomic, copy, nullable) OLPrivacyTermItemBlock block;

/**
 条款索引，默认为0，当有多条条款时，会根据此属性升序排列条款
 */
@property(nonatomic, assign) NSInteger index;
/**
 * init
 * @param title 标题。可以设置为NSString或者NSAttributedString
 * @param url 条款链接
 */
- (instancetype)initWithTitle:(id)title linkURL:(NSURL *)url;

/**
 *
 * @param title 标题。可以设置为NSString或者NSAttributedString
 * @param url 条款链接
 * @param index 排序索引，默认从小到大
 */
- (instancetype)initWithTitle:(id)title linkURL:(NSURL *)url index:(NSInteger)index;

/**
 *
 * @param title 标题。可以设置为NSString或者NSAttributedString
 * @param url 条款链接
 * @param index 排序索引，默认从小到大
 * @param block 点击回调
 */
- (instancetype)initWithTitle:(id)title linkURL:(NSURL *)url index:(NSInteger)index block:(OLPrivacyTermItemBlock _Nullable)block;

/**
 *
 * @param title 标题。可以设置为NSString或者NSAttributedString
 * @param urlRequest 条款链接NSURLRequest，可加载本地html
 * @param index 排序索引，默认从小到大
 * @param block 点击回调
 */
- (instancetype)initWithTitle:(id)title urlRequest:(NSURLRequest *)urlRequest index:(NSInteger)index block:(OLPrivacyTermItemBlock _Nullable)block;

- (NSString *)text;
- (nullable NSURL *)url;
@end

NS_ASSUME_NONNULL_END
