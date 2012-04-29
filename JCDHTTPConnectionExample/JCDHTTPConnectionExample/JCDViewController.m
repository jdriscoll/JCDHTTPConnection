//
//  JCDViewController.m
//  JCDHTTPConnectionExample
//
//  Created by Justin Driscoll on 4/29/12.
//  Copyright (c) 2012 Retrobit, LLC. All rights reserved.
//

#import "JCDViewController.h"
#import "JCDHTTPConnection.h"

@interface JCDViewController ()
@end

@implementation JCDViewController

@synthesize URLTextField;
@synthesize statusLabel;
@synthesize responseTextView;

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

- (IBAction)go:(id)sender {
    [self.URLTextField resignFirstResponder];
    
    NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:self.URLTextField.text]];
    JCDHTTPConnection *connection = [[JCDHTTPConnection alloc] initWithRequest:request];
    
    self.statusLabel.text = @"Requesting URL...";
    
    [connection executeRequestOnSuccess:
     ^(NSHTTPURLResponse *response, NSString *bodyString) {
         self.statusLabel.text = [NSString stringWithFormat:@"Success: %d", response.statusCode];
         self.responseTextView.text = bodyString;
     } failure:^(NSHTTPURLResponse *response, NSString *bodyString, NSError *error) {
         self.statusLabel.text = [NSString stringWithFormat:@"Error: %d", response.statusCode];
         self.responseTextView.text = error.localizedDescription;
     } didSendData:^(NSInteger bytesWritten, NSInteger totalBytesWritten, NSInteger totalBytesExpectedToWrite) {
         self.statusLabel.text = @"Sending data...";        
     }];    
}

- (IBAction)openProjectPage:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"http://github.com/jdriscoll/JCDHTTPConnection"]];
}

@end
