# RSNetworkKit

A delightful Library to handle all network calls for ios application. No need to use NSURLSession or NSURLConnection.
RSNetworkKit is build upon [AFNetworking 3.0](https://github.com/AFNetworking/AFNetworking). You can also use all APIs from AFNetworking as well.

## Features

It supports following features:

- Make all network request using GET, POST, PUT, DELETE etc with ease.
- Download request with progress using singleton method.
- Upload request OR Multipart form upload request with progress using singleton method.
- Background support for upload and download for larger files.
- Show progress when you set image to an UIImageView like Instagram. This is enhanced featured in **UIImageView+AFNetworking** category.

## How To Use

### NetworkClient

```objective-c
[[NetworkClient sharedClient] requestWithURL:urlString requestType:POST withHeader:headers andParams:params successBlock:^(id response) {

    NSLog(@"response %@",response);

} andFailure:^(NSString *error) {
    NSLog(@"Error %@", error.description);
}];
```

### RSNetworkManager

```objective-c
[[RSNetworkManager sharedManager] initWithBaseURL:@"BaseURLString"];  // This should be only once.

NSDictionary *headers = @{}; //prepare request headers if any.
NSDictionary *params = @{}; //prepare request parameters if any.

[[RSNetworkManager sharedManager] requestWithURL:@"urlString" requestType:GET withHeaders:headers andParams:params successBlock:^(NSURLResponse *response, id responseObject) {

} andFailure:^(NSError *error) {

}];
```

### RSDownloadManager

```objective-c
NSString *downloadImageURL = @"http://p1.pichost.me/i/19/1424006.jpg";

[[RSDownloadManager sharedManager] downloadWithURL:downloadImageURL downloadProgress:^(NSNumber *progress) {
 
    dispatch_async(dispatch_get_main_queue(), ^{
        // show progress here using [progress floatValue]
    });

} success:^(NSURLResponse *response, NSURL *filePath) {

} andFailure:^(NSError *error) {

}];
```

#### Background Download
```objective-c
[[RSDownloadManager sharedManager] downloadInBackgroundWithURL:@"DownloadURL" downloadProgress:^(NSNumber *progress) {

    // Show download progress on main thread if application is in foreground.

} success:^(NSURLResponse *response, NSURL *filePath) {

    // get downloaded file path

} andFailure:^(NSError *error) {

}];

[RSDownloadManager sharedManager].backgroundDownloadCompletionHandler = ^{
    // Show local notification here
};
```
In AppDelegate
```objective-c
-(void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)())completionHandler {

    if([identifier isEqualToString:bgDownloadSessionIdentifier]){
        [RSDownloadManager sharedManager].backgroundSessionCompletionHandler = completionHandler;
    }
}
```

### RSUploadManager

```objective-c
[[RSUploadManager sharedManager] uploadWithURL:@"URLString" filePath:@"Upload file path" uploadProgress:^(NSNumber *progress) {

    dispatch_async(dispatch_get_main_queue(), ^{
        // show progress here using [progress floatValue]
    });

} success:^(NSURLResponse *response, id responseObject) {

} andFailure:^(NSError *error) {

}];
```

#### Background Upload

```objective-c
[[RSUploadManager sharedManager] startUploadInBackgroundWithURL:@"URLString" filePath:@"Upload file path" uploadProgress:^(NSNumber *progress) {

    // Show upload progress on main thread if application is in foreground.

} success:^(NSURLResponse *response, id responseObject) {

} andFailure:^(NSError *error) {

}];

[RSUploadManager sharedManager].backgroundUploadCompletionHandler = ^{
    // Show local notification here
};
```
In AppDelegate
```objective-c
-(void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)())completionHandler {

    if([identifier isEqualToString:bgUploadSessionIdentifier]){
        [RSUploadManager sharedManager].backgroundSessionCompletionHandler = completionHandler;
    }
}
```

### ImageView With Progress

```objective-c
NSString *imageDownloadURL = @"http://www.planwallpaper.com/static/images/acede69a00dd92ffd13e1322d0e15d4b_large-hdwallpapers2016com.jpeg";
NSURL *imageURL = [NSURL URLWithString:imageDownloadURL];
NSURLRequest *imageRequest = [NSURLRequest requestWithURL:imageURL];

[self.imageView setImageWithURLRequest:imageRequest placeholderImage:placeHolderImage progress:^(NSProgress * _Nonnull downloadProgress) {

    // show progress here using downloadProgress.fractionCompleted

} success:^(NSURLRequest * _Nonnull request, NSHTTPURLResponse * _Nullable response, UIImage * _Nonnull image) {

} failure:^(NSURLRequest * _Nonnull request, NSHTTPURLResponse * _Nullable response, NSError * _Nonnull error) {

}];
```

## License

RSNetworkKit is released under the MIT license. See LICENSE for details.
