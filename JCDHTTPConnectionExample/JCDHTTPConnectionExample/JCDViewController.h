//
//  JCDViewController.h
//  JCDHTTPConnectionExample
//
//  Created by Justin Driscoll on 4/29/12.
//  Copyright (c) 2012 Retrobit, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JCDViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *URLTextField;
@property (weak, nonatomic) IBOutlet UILabel *statusLabel;
@property (weak, nonatomic) IBOutlet UITextView *responseTextView;

- (IBAction)go:(id)sender;
- (IBAction)openProjectPage:(id)sender;

@end
