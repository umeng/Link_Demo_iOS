//
//  UMModuleManager.h
//  UMMobClick
//
//  Created by San Zhang on 11/10/16.
//  Copyright © 2016 UMeng. All rights reserved.
//

#ifndef WITH_INTERNATIONAL

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, eStatusCode)
{
    E_STATUS_OK = 0,
    E_STATUS_FAILED = 1,
};

@interface UMDispatchObject : NSObject
@property(nonatomic, assign) int16_t    eStatus;
@property(nonatomic, strong, nullable) id         object;
@end

typedef void (^UMCompletionBlock)(UMDispatchObject* _Nullable object);

typedef void (^UMStringIntBlock)(NSString* _Nullable string, int code);

@protocol UMModuleProtocal <NSObject>
+ (nonnull NSNumber *)loadModule;
@end


@interface UMModuleManager : NSObject

+ (BOOL)loadModuleClass:(nonnull NSString *)aClassName;

//+ (BOOL)registerAntDFPWithToken:(nonnull NSString *)appName appKeyClient:(nonnull NSString *)appKeyClient callback:(nullable  UMStringIntBlock)cbBlock;

@end

#endif
