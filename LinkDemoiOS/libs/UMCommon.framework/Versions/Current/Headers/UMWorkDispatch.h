//
//  UMWorkDispatch.h
//  MobClick
//
//  Created by San Zhang on 6/23/14.
//
//

#import <Foundation/Foundation.h>

#define UMDispatchCenter [UMWorkerDispatch sharedInstance]

typedef enum eUMEventTypes
{
    // UM-Common-System ->
    E_UM_C_DATA_FLUSH = 0x01, // notify work-thread to check and send report log.
    E_UM_C_NET_IDLE,
    E_UM_C_INIT,
    E_UM_C_ZERO,
    E_UM_C_LOAD_TABLE,
    E_UM_C_LOAD_ANALYTICS_TABLE,
    E_UM_C_ZID,

 //   E_UM_C_DATA_LBS

    // UM-Common-System <-
    
    // Analytics ->  define_types_ad.h
    /*    E_UM_EVT_ACTIVATE = 0x100,
     E_UM_EVT_INACTIVATE,
     E_UM_EVT_EVENT,
     E_UM_EVT_ERROR,
     E_UM_EVT_EKV,
     E_UM_CC_AG_EVT,
     
     // stack cache
     E_UM_EVT_EVENT_BEGIN,
     E_UM_EVT_EVENT_END,
     E_UM_EVT_EKV_BEGIN,
     E_UM_EVT_EKV_END,
     
     E_UM_PAGE_DURATION,
     E_UM_PAGE_BEGIN,
     E_UM_PAGE_END,
     
     E_UM_PROFILE_SIGNIN,
     E_UM_PROFILE_SIGNOFF,
     // Analytics <-
     
     // Dplus ->
     E_UM_D_TRACK_EVENT = 0x200,
     E_UM_AUTO_PAGEVIEW,
     //  E_UM_D_SESSION,
     // Dplus <-
     
     // Share -> define_types_s.h
     E_UM_S_AUTH = 0x300,
     E_UM_S_EVENT,
     E_UM_S_USER_INFO,
     // Share <-
     
     // Push -> define_types_p.h
     E_UM_P_LOG = 0x400,
     // Push <-
     */
}eUMEventTypes;

//typedef void (^UMCompletionBlock)(id object);
//@property(nonatomic, strong) UMCompletionBlock  cbBlock;

@interface UMDispatchEvent : NSObject
@property(nonatomic, assign) int32_t      eEventType;
@property(nonatomic, strong) id           object;
@end

@protocol UMLogDataProtocol <NSObject>

- (void)workEvent:(UMDispatchEvent *)dispatchEvent;
- (NSDictionary *)setupReportData:(int64_t)maxSize;
- (void)removeCacheData:(NSDictionary *)json;
@optional
- (BOOL)shoudleSetupReportDataWithContext:(id)context;

//- (BOOL)cachedDataReady;
@end


@interface UMWorkDispatch : NSObject

+ (id)sharedInstance;

/* make package and save to local file.
 @param component: implement UMLogDataProtocol class
 @param event: wrapper object for component's event
 @param eType: pre-define event's type
 @return void
 */
+ (void)sendEvent:(id)event withType:(int)eType component:(id<UMLogDataProtocol>)component;

/**
 get WorkQueue
 */
+(dispatch_queue_t)getWorkQueue;

+(BOOL)isInWorkQueue;

@end
