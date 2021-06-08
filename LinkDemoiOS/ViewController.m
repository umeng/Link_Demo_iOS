//
//  ViewController.m
//  LinkDemoiOS
//
//  Created by yk on 2021/6/7.
//

#import "ViewController.h"
#import <UMLink/UMLink.h>
#import "DeeplinkViewController.h"

@interface ViewController ()<MobClickLinkDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
}

- (IBAction)onGetInstall:(id)sender {
    [MobClickLink getInstallParams:^(NSDictionary *params, NSURL *URL, NSError *error) {
        if (error) {
            return;
        }
        if (URL.absoluteString.length > 0||params.count > 0) {
            self.install_params = params;
            [MobClickLink handleLinkURL:URL delegate:self];
        }else{
            UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"提示"
                                                                               message:@"没有匹配到安装参数"
                                                                        preferredStyle:UIAlertControllerStyleAlert];
                
                UIAlertAction* defaultAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault
                                                                      handler:nil];
             
                [alert addAction:defaultAction];
            [self presentViewController:alert animated:YES completion:nil];
        }
        [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"key_Has_Get_InstallParams"];
    }];
}

#pragma mark - MobClickLinkDelegate

- (void)getLinkPath:(NSString *)path params:(NSDictionary *)params
{
    DeeplinkViewController *dlvc = [[DeeplinkViewController alloc] initWithNibName:nil bundle:nil];
    dlvc.path = path;
    dlvc.params = params;
    if (self.install_params) {
        dlvc.install_params = self.install_params;
    }
    [self.navigationController pushViewController:dlvc animated:YES];
}



@end
