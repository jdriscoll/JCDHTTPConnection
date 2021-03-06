# Block-Based NSURLConnection Wrapper (For ARC Projects)

JCDHTTPConnection is a lightweight wrapper for NSURLConnection that provides a simple block callback API.

### Usage

A JCDHTTPConnection object is initialized with a NSURLRequest object and then executeRequestOnSuccess:failure:didSendData is called on the connection to initiate the asynchronous request. The three callback blocks: onSuccess, onFailure and onDidSendData are all optional.

### Example

```objc    
NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:@"http://apple.com"]];

JCDHTTPConnection *connection = [[JCDHTTPConnection alloc] initWithRequest:request];

[connection executeRequestOnSuccess:
 ^(NSHTTPURLResponse *response, NSString *bodyString) {
     NSLog(@"SUCCESS: %d: %@", response.statusCode, bodyString);
 } failure:^(NSHTTPURLResponse *response, NSString *bodyString, NSError *error) {
     NSLog(@"FAILURE: %@", error);
 } didSendData:^(NSInteger bytesWritten, NSInteger totalBytesWritten, NSInteger totalBytesExpectedToWrite) {
     // This is not going to be called in this example but it's included for completeness.
     NSLog(@"DID SEND DATA: %d", bytesWritten);
 }];
```

### Example Project

The repository includes an example Xcode project that fetches URLs and displays the response.
 
