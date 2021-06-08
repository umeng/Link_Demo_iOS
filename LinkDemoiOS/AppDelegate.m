//
//  AppDelegate.m
//  LinkDemoiOS
//
//  Created by yk on 2021/6/7.
//

#import "AppDelegate.h"
#import <UMCommon/UMConfigure.h>
#import <UMLink/UMLink.h>
#import "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [UMConfigure initWithAppkey:@"5f3a217f1217863a799ae4d6" channel:@"App Store"];
    
    BOOL hasGetInstallParams = [[NSUserDefaults standardUserDefaults] boolForKey:@"key_Has_Get_InstallParams"];
    if (!hasGetInstallParams) {
        [MobClickLink getInstallParams:^(NSDictionary *params, NSURL *URL, NSError *error) {
            if (error) {
                return;
            }
            UINavigationController *platformVc = (UINavigationController *)self.window.rootViewController;
            ViewController *vc = platformVc.viewControllers[0];
            if (URL.absoluteString.length > 0||params.count > 0) {
                vc.install_params = params;
                [MobClickLink handleLinkURL:URL delegate:(id<MobClickLinkDelegate>)vc];
            }else{
                UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"提示"
                                                                                   message:@"没有匹配到安装参数"
                                                                            preferredStyle:UIAlertControllerStyleAlert];
                    
                    UIAlertAction* defaultAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault
                                                                          handler:nil];
                 
                    [alert addAction:defaultAction];
                [vc presentViewController:alert animated:YES completion:nil];
            }
            [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"key_Has_Get_InstallParams"];
        }];
    }else{
        //已经调用过getInstallParam方法，没必要在下次启动时再调用
        //但后续仍可在需要时调用，比如demo中的按钮点击
    }
    return YES;
}


- (BOOL)application:(UIApplication *)application continueUserActivity:(nonnull NSUserActivity *)userActivity restorationHandler:(nonnull void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler
{
    UINavigationController *platformVc = (UINavigationController *)self.window.rootViewController;
    UIViewController *vc = platformVc.viewControllers[0];
    if([MobClickLink handleUniversalLink:userActivity delegate:(id<MobClickLinkDelegate>)vc])
    {
        return YES;
    }
    //其它第三方处理
    return YES;
}

//iOS9以上，走这个方法
- (BOOL)application:(UIApplication *)application openURL:(nonnull NSURL *)url options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    NSLog(@"url:%@", url);
    UINavigationController *platformVc = (UINavigationController *)self.window.rootViewController;
    UIViewController *vc = platformVc.viewControllers[0];
    if([MobClickLink handleLinkURL:url delegate:(id<MobClickLinkDelegate>)vc])
    {
        return YES;
    }
    //其它第三方处理
    return YES;
}

- (BOOL)application:(UIApplication *)application openURL:(nonnull NSURL *)url sourceApplication:(nullable NSString *)sourceApplication annotation:(nonnull id)annotation
{
    NSLog(@"url:%@", url);
    UINavigationController *platformVc = (UINavigationController *)self.window.rootViewController;
    UIViewController *vc = platformVc.viewControllers[0];
    if([MobClickLink handleLinkURL:url delegate:(id<MobClickLinkDelegate>)vc])
    {
        return YES;
    }
    //其它第三方处理
    return YES;
}

@end
