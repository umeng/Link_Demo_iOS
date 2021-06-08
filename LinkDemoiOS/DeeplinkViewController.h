//
//  ViewController.h
//  UMMobClick
//
//  Created by San Zhang on 9/6/16.
//  Copyright © 2016 UMeng. All rights reserved.
//

#import <UIKit/UIKit.h>

/*
 可在手机浏览器中打开测试页面进行测试
 https://admin.lotuspondapp.com/h5.html
*/
@interface DeeplinkViewController : UIViewController

@property (nonatomic, strong) NSString *path;

@property (nonatomic, strong) NSDictionary *params;

@property (nonatomic, strong) NSDictionary *install_params;

@end

