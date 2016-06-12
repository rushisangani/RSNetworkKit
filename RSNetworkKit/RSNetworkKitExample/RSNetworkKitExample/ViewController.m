//
//  ViewController.m
//  RSNetworkKitExample
//
//  Created by Rushi Sangani on 12/06/16.
//  Copyright © 2016 Rushi Sangani. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    [self getDataFromServer];
}

-(void)getDataFromServer {
    
    NSString *urlString;
    NSDictionary *headers;
    NSDictionary *params;
    
    [[NetworkClient sharedClient] requestWithURL:urlString requestType:POST withHeader:headers andParams:params successBlock:^(id response) {
       
        NSLog(@"response %@",response);
        
    } andFailure:^(NSString *error) {
        NSLog(@"Error %@", error.description);
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
