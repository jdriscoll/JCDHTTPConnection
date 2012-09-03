//
//  JCDHTTPConnection.h
//  Created by Justin Driscoll on 11/26/11.
//

#import <Foundation/Foundation.h>


typedef void (^OnSuccess) (NSHTTPURLResponse *response, NSString *bodyString);
typedef void (^OnFailure) (NSHTTPURLResponse *response, NSString *bodyString, NSError *error);
typedef void (^OnDidSendData) (NSInteger bytesWritten, NSInteger totalBytesWritten, NSInteger totalBytesExpectedToWrite);


@interface JCDHTTPConnection : NSObject

@property (strong, nonatomic) NSURLRequest *request;
@property (strong, nonatomic) NSHTTPURLResponse *response;
@property (strong, nonatomic) NSMutableData *data;
@property (readonly) NSString *body;

@property (copy, nonatomic) OnSuccess onSuccess;
@property (copy, nonatomic) OnFailure onFailure;
@property (copy, nonatomic) OnDidSendData onDidSendData;

- (id)initWithRequest:(NSURLRequest *)urlRequest;
- (BOOL)executeRequestOnSuccess:(OnSuccess)onSuccessBlock
                        failure:(OnFailure)onFailureBlock
                    didSendData:(OnDidSendData)onDidSendDataBlock;

@end
