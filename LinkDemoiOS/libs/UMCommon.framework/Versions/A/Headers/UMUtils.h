//
//  UMUtils.h
//  UMCommon
//
//  Created by San Zhang on 9/29/16.
//  Copyright © 2016 UMeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UMUtils : NSObject

+ (NSString *)appkey;

#pragma mark enviroument
+ (BOOL)isDebugging;

+ (uint64_t)UTCIntervalMS; //Millisecond Unit
+ (NSTimeInterval)durationNowWith1970TimeInterval:(NSTimeInterval)timeIntervalSince1970;

#pragma mark identify info
+ (NSString *)idfa;
+ (NSString *)umfa;

+ (NSString *)idfv;
+ (NSString *)openUDIDString;
+ (NSString *)utdid;
+ (NSString *)deviceToken;
+ (NSString *)deviceMacAddressString;  //hardcode @"02:00:00:00:00:00"

#pragma mark device info
+ (NSString *)osString;
+ (NSString *)osVersionString;
+ (NSString *)countryString;
+ (NSString *)languageString;
+ (NSString *)timezoneString;
+ (int)timezone;
+ (NSString *)dateString;  //yyyy-MM-dd

+ (BOOL)isPad;
+ (NSString *)deviceModelString;
+ (NSString *)deviceJailBreakString;
+ (BOOL)isDeviceJailBreak;
+ (NSDictionary *)batteryInfo;

// height*width
+ (NSString *)resolutionString;

#pragma mark app info
+ (NSString *)appPackageNameString;
+ (NSString *)appDisplayNameString;
+ (NSString *)realAppDisplayNameString;
+ (NSString*)processName;
+ (NSString *)appBundleVersionString;
+ (NSString *)appShortVersionString;
+ (NSString *)appPirateString;
+ (BOOL)isAppPirate;

#pragma mark network info
+ (int)accessStatus;
+ (NSString *)accessString;
+ (NSString *)accessSubType;
+ (NSString *)carrierString;
+ (NSString *)mncString;
+ (NSString *)mccString;
+ (NSString *)localIPString;
#pragma mark - string tools
+ (BOOL)notEmptyString:(NSString *)string;
+ (BOOL)isEmptyString:(NSString *)string;

+ (NSString *)bytesToHexString:(Byte *)bytes length:(int)length;
+ (NSString *)getString:(NSString *)source bytesLength:(int)length;
#ifdef WITH_PRIV

+ (NSString *)getValidUrlString:(NSString *)string;
#endif

+ (NSString *)md5:(NSString *)string;
+ (NSData *)md5DataWithData:(NSData *)data;
+ (Byte *)md5BytesWithString:(NSString *)string;

+ (id)JSONValue:(NSString *)string;
+ (NSString *)JSONFragment:(id)object;

+ (NSString *)urlEncode:(NSString *)string;
+ (NSString *)urlDecode:(NSString *)string;

+ (NSString *)encodeBase64:(NSData *)data;
+ (NSData *)decodeBase64:(NSString *)encodedStr;

+ (NSData *)deflatedData:(NSData *)sourceData;

// AES128 cipher
+ (NSData *)AES128EncryptData:(NSData *)content withKey:(const void *)key;
+ (NSData *)AES128DecryptData:(NSData *)cipherData withKey:(const void *)key;

// reflect method
+ (void)performClass:(NSString *)className method:(NSString *)methodName object:(id)object;
+ (void)reflectClass:(NSString *)className selector:(NSString *)method params:(void *[])pointers paramsCount:(int)count;
+(BOOL)loadSysFramework:(NSString *)frameworkname;
+ (id)reflectObject:(id)obj selector:(NSString *)method;
+ (id)reflectObject:(id)obj selector:(NSString *)method object:(id)object;
+ (id)reflectObject:(id)obj selector:(NSString *)method object:(id)object1 object:(id)object2;

//NSInvocation method调用
+ (void)invoke:(id)target selString:(NSString *)selString argument:(id)obj returnValue:(void *)retValue;

#pragma mark - 集成common组件业务类型Flag,用于判断用户集成了那些业务
+(void)appendComponentFlag:(NSString*)componentFlag;
+(NSString*)componentFlags;

#pragma mark - UI无埋点的反射函数参数原型
+ (void)invoke:(id)target selString:(NSString *)selString object1:(id)object1 object2:(id)object2 returnValue:(void *)retValue;
+ (void)invoke:(id)target selString:(NSString *)selString object1:(id)object1 selector:(SEL)selector returnValue:(void *)retValue;
+ (void)invoke:(id)target selString:(NSString *)selString enabled:(BOOL)enabled returnValue:(void *)retValue;
+ (void)invoke:(id)target selString:(NSString *)selString enabled:(BOOL)enabled md5:(id)md5 returnValue:(void *)retValue;
@end
