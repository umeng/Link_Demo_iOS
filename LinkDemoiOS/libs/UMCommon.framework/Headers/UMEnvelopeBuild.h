//
//  UMEnvelopeBuild.h
//  UMCommon
//
//  Created by San Zhang on 3/26/17.
//  Copyright © 2017 UMeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UMEnvelopeBuild : NSObject

@property(nonatomic, retain) NSData *signature;
@property(nonatomic, retain) NSData *guid;
@property(assign) BOOL jobRunning;
@property(assign) int defcon;

+ (UMEnvelopeBuild *)sharedInstance;


- (int64_t)maxDataSpace;

/* check condition for build envelope file
 NOTE: all of event must to check, except 'session change' msg
 @return
 */
- (BOOL)isReadyBuild;


/* build envelope binary format and save to local file, and then call Component’s removeCacheData() method to clear input data which be store in DB/memory.
 @param extendheader: special header for component, e.g: { "d_app_v":"x.xx.x"}
 @param content: component's data, e.g: {"analytics":{..},"dplus"::{..}}
 @return made json data for envelope’s payload.
 1.	Succeed: entity payload data.
 2.	Failed: exception statue: {"exception":int_code, ...}.
	Code: 101: I/O Error,  102:no enough free space to save
 */
- (NSDictionary *)buildEnvelopeWithExtHeader:(NSDictionary *)extHeader content:(NSDictionary *)content;

//其他业务build接口
- (NSDictionary *)buildEnvelopeWithExtHeader:(NSDictionary *)header content:(NSDictionary *)content pathURL:(NSString *)aPath type:(NSString *)type version:(NSString *)version;


- (NSDictionary *)buildEnvelopeWithHeader:(NSDictionary *)extHeader content:(NSDictionary *)content path:(NSString *)path type:(NSString *)type version:(NSString *)version;

- (void)buildZeroEnvelopeWithExtHeader:(NSDictionary *)extHeader content:(NSDictionary *)content;

//以下三个函数是为了分类有状态的信封的子文件夹做的
+ (void)setEnvelopeSubFolder:(NSString*)subFolder maxCount:(NSUInteger)maxCount;
- (NSDictionary *)buildEnvelopeWithExtHeader:(NSDictionary *)extHeader content:(NSDictionary *)content subFolder:(NSString*)subFolder;
-(NSMutableArray*)envelopeFilesForSubFolders;

/*
 return key’s value storage imprint, nil: no exist.
 */
+ (NSString *)imprintProperty:(NSString *)key;

+ (BOOL)isIntegratedTestModel;

#ifndef WITH_INTERNATIONAL
- (NSDictionary *)buildInternalData;
#endif

#ifdef WITH_FILTERIMPRINTKEY
typedef void (^UMFilterImprintHandler)(NSString* imprintKey,NSString* imprintValue,NSError * __nullable error);
//注意此函数不是线程安全的，需要在workQueue里面保证其安全
+(void)setFilterImprintKey:(NSString*_Nonnull)imprintKey withHandler:(UMFilterImprintHandler _Nullable )handle;
#endif

-(void)loadCacheData;

-(NSMutableDictionary *_Nullable)insertToCacheTable:(NSDictionary *_Nullable)header content:(NSDictionary *_Nonnull)content type:(NSString *_Nullable)type path:(NSString * _Nullable)path version:(NSString *_Nullable)version;
@end
