//
//  UMConfigureCache.h
//  UMMobClick
//
//  important: no public, Only used internal umeng component
//
//  Created by San Zhang on 10/14/16.
//  Copyright © 2016 UMeng. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSString *kUMReachabilityChangedNotificationFromUMCommon;
void umengLog(NSString *format, ...);

@interface UMConfigureCache : NSObject

@property(copy) NSString *appkey;

#ifdef WITH_PRIV
@property(copy) NSString *primaryDomain;
@property(copy) NSString *standbyDomain;
#endif

@property(copy) NSString *channel;
@property(atomic,readwrite,copy)NSString *wraperType;
@property(atomic,readwrite,copy)NSString *wraperVersion;

@property(assign) BOOL  encryptEnabled;
@property(assign) BOOL  logEnabled;

@property(assign) int  eNetStatus;

@property(retain) NSMutableDictionary *moduleVer;

//@property(assign) BOOL  isIgnore;
//@property(assign) int  isIgnoreCount;


@property(strong) NSOperationQueue *slnetworkerQueue;

@property(assign) BOOL  aEnabled;

+ (UMConfigureCache *)sharedInstance;


- (void)beginBackgroundTask;
- (void)endBackgroundTask;


// disk cache  // use NSUserDefault
+ (id)objectWithKey:(NSString *)key;
+ (void)setObject:(id)value forKey:(NSString *)key;
+ (void)removeObjectForKey:(NSString *)key;

// memory cache TBD
+ (id)memoryCacheObjectWithKey:(NSString *)key;
+ (void)memoryCacheObject:(id)value forKey:(NSString *)key;

+ (void)accumulateCount:(int)count withKey:(NSString *)key;
+ (void)incCounterForKey:(NSString *)key;
+ (int)counterThenIncWithKey:(NSString *)key;

//keyChain
+ (void)keyChainSave:(NSString *)value key:(NSString*)key forKey:(NSString *)forKey;
+ (NSString *)keyChainLoad:(NSString*)key forKey:(NSString *)forKey;

- (void)flushStatelessFile;
@end
