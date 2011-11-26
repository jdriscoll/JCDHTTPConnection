//
//  JCDHTTPConnection.h
//  Created by Justin Driscoll on 11/26/11.
//

#import <Foundation/Foundation.h>

@interface JCDHTTPConnection : NSObject

@property (strong, nonatomic) NSURLRequest *request;
@property (strong, nonatomic) NSHTTPURLResponse *response;
@property (strong, nonatomic) NSMutableData *data;
@property (readonly) NSString *body;

@property (copy) id (^onSuccess)(NSHTTPURLResponse *, NSString *);
@property (copy) id (^onFailure)(NSHTTPURLResponse *, NSString *, NSError *);
@property (copy) id (^onDidSendData)(NSInteger, NSInteger, NSInteger);

- (id)initWithRequest:(NSURLRequest *)urlRequest;
- (BOOL)executeRequestOnSuccess:(void (^)(NSHTTPURLResponse *, NSString *))onSuccessBlock
                        failure:(void (^)(NSHTTPURLResponse *, NSString *, NSError *))onFailureBlock
                    didSendData:(void (^)(NSInteger, NSInteger, NSInteger))onDidSendDataBlock;

@end
