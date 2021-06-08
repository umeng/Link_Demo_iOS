//
//  UMImprintObserverManager.h
//  UMMobClick
//
//  Created by 张军华 on 2018/2/11.
//  Copyright © 2018年 UMeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol UMImprintObserverProtocol <NSObject>

@optional
-(void)imprintObserveValueForImprintKey:(NSString*)imprintKey newImprintValue:(id)newImprintValue oldImprintValue:(id)oldImprintValue;

@end


@interface UMImprintObserverManager : NSObject

+ (instancetype)sharedInstance;

-(BOOL)registerImprintKey:(NSString*)imprintKey withDelegate:(id<UMImprintObserverProtocol>)delegate;

-(BOOL)unregisterImprintKey:(NSString*)imprintKey withDelegate:(id<UMImprintObserverProtocol>)delegate;


-(BOOL)existImprintObserver;
-(void)processImprintKey:(NSString*)imprintKey newImprintValue:(id)newImprintValue oldImprintValue:(id)oldImprintValue;

@end
