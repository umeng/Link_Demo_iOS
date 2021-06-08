//
//  define_um_internal.h
//  UMMobClick
//
//  Created by San Zhang on 3/28/17.
//  Copyright © 2017 UMeng. All rights reserved.
//

#ifndef define_um_internal_h
#define define_um_internal_h

typedef enum eUMEnvelopeException
{
    E_UM_BE_OK = 0,
    E_UM_BE_SAVE_FAILED = 101,  // save file failed
    E_UM_BE_JSON_FAILED = 110,  // json failed
    E_UM_BE_CREATE_FAILED,      // create envelope failed
    E_UM_BE_DEFLATE_FAILED,     // deflate failed
    E_UM_BE_RAW_OVERSIZE,       // raw payload oversize
    E_UM_BE_FILE_OVERSIZE,     // envelope sizeover
}eUMEnvelopeException;

#define MIN_FEED_SIZE           2048

// macro define
#define TIME_ZOOM_NUMBER        1000

#define DEFCON_DEF_VALUE             (0)


#define ENVELOPE_ENTITY_RAW_LENGTH_MAX      (2048*1024)
#define ENVELOPE_LENGTH_MAX                 (200*1024)
//零号协议header预估大小
#define ENVELOPE_HEADER_LENGTH      3500

#define ENVELOPE_OUTED_DATE_INTERVAL        (14*24*60*60)

#define ENVELOPE_STRUCT_LENGTH      (512) // 259

#define kUMDefcon                   @"umDefcon"
#define kUMIDString                 @"umid"
#define kUMOID                      @"umOidStr"
//#define kUMTTString                 @"umtt"
#define kUMBackString                 @"backstate"

#define kUMConfigString                 @"cfgfield"
//零号协议字段
#define kUMConfigStr              @"cfgfd"
#define kUMIsConfig              @"iscfg"


#define kKeyChainUMID                 @"kUMId"
#define kKeyChainUMIDKey                @"kUMIdKey"

#define kUMPushDeviceToken          @"kUMessageUserDefaultKeyForDeviceToken"


#define UM_SUCCESSFUL_REQUESTS      @"umSuccessfulRequests"
#define UM_FAILED_REQUESTS          @"umFailedRequests"
#define UM_LAST_REQUEST_SPENT_MS    @"umLastRequestSpentMS"


#define kExperimentGroupInfo    @"umExperimentGroupInfo"
#define kExperimentRPT          @"umExperimentRPT"
#define kExperimentDOM          @"umExperimentDOM"

#define kUMReportIntervalChange      @"report_interval_change"
#define kUMLatestPostTS              @"lastPostInterval"
#define kUMSessionBeginLatestPostTS  @"umSBLastPostInterval"


// json key (header)
#define kUMAppVersionStandard        @"app_version"
#define kUMAppBuildVersion           @"app_b_v"

#define kUMPushSDKVersion            @"p_sdk_v"
#define kUMShareSDKVersion           @"s_sdk_v"
#define kUMAnalyticsSDKVersion       @"sdk_version"
#define kUMErrorsSDKVersion          @"e_sdk_v"
#define kUMInnerVersion              @"i_sdk_v"


#define kBUILD_ENVELOPE_EXCEPTION   @"exception"

// json key (components)
#define kUMAnalytics            @"analytics"
#define kUMDplus                @"dplus"
#define kUMPush                 @"push"
#define kUMShare                @"share"
#define kUMInner                @"inner"
#define kUMErrors               @"errors"

#define kUMJSONHeader           @"header"
#define kUMJSONContent          @"content"

#define kUMGValue           @"UMGValue"
#define kUMWValue         @"UMWValue"

#pragma mark - 集成common组件业务类型Flag,用于判断用户集成了那些业务
#define KUMkUMAnalyticsFlag                     @"a"
#define kUMPushFlag                             @"p"
#define kUMShareFlag                            @"s"
#define kUMErrorsFlag                           @"e"
#define kUMInnerFlag                            @"i"
#define kUMOplusFlag                            @"o"
#define kUMAutoBindingAnalyticsFlag             @"v"
#define kUMABTestFlag                           @"x"
#define kUMUAIRecFlag                           @"u"
#define kUMVerifyFlag                           @"n"
#define kUMDeviceFlag                           @"z"
#define kUMCrashFlag                            @"c"
#define kUMSMSFlag                              @"m"
#define kUMGameFlag                             @"g"






#define kUMModuleKey                            @"module"
#define kUMModuleVerKey                         @"module_ver"

#pragma mark - 判断UI无埋点的imprint的字段
#define KUMAutoEventBindingEnable               @"use_autotrack"
#define KUMAutoEventBindingMD5                  @"autotrack_md5"

//可视化埋点 UMVisual
#define KUMVisualEnable               @"utm-visual"

//判断EventBinding开关的枚举值
#define KUMAutoEventBindingEnableYES            @"1"
#define KUMAutoEventBindingEnableNO             @"0"

//通知
#define kUMAutoEventBindingEnableNotification  @"kUMAutoEventBindingEnableNotification"

//UMVisual通知
#define kUMVisualEnableNotification  @"kUMVisualEnableNotification"


//发送 E_UM_C_NET_IDLE消息的附带的信息，用于区别E_UM_C_NET_IDLE来自哪里
#define kUMIdleFromKey                         @"umIdleFrom"
#define kUMIdleFromValueForReachability        @"umReachability"
#define kUMIdleFromValueForAppActivate         @"umAppActivate"
#define kUMIdleFromValueForNetwork             @"umNetwork"
#define kUMIdleFromValueForUApp                @"umUApp"

//零号协议返回
#define kUMZeroFromKey @"umZeroKey"

#define kUMZidData @"umZidData"
#endif /* define_um_internal_h */
