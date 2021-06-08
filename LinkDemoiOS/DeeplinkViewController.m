//
//  ViewController.m
//  UMMobClick
//
//  Created by San Zhang on 9/6/16.
//  Copyright © 2016 UMeng. All rights reserved.
//

#import "DeeplinkViewController.h"
#include <objc/runtime.h>

@interface DeeplinkViewController () 


@end

@implementation DeeplinkViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 100, self.view.frame.size.width, 400)];
    label.numberOfLines = 0;
    label.textColor = [UIColor blackColor];
    [self.view addSubview:label];
    
    NSMutableString *str = [NSMutableString string];
    [str appendFormat:@"path: \n%@", self.path];
    
    [str appendString:@"\n\n"];
    [str appendString:@"param: \n"];
    for (NSString *key in self.params) {
        [str appendFormat:@"%@=%@\n", key, self.params[key]];
    }
    
    [str appendString:@"\n\n"];
    [str appendString:@"install param: \n"];
    for (NSString *key in self.install_params) {
        [str appendFormat:@"%@=%@\n", key, self.install_params[key]];
    }
    
    label.text = str;
    
}

@end
