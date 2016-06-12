//
//  RSNetworkKitConstants.h
//  RSNetworkKitExample
//
//  Created by Rushi Sangani on 12/06/16.
//  Copyright © 2016 Rushi Sangani. All rights reserved.
//

#import <Foundation/Foundation.h>


/********************** ENUMS ************************/

// RequestType enum

typedef NS_ENUM(NSInteger, RequestType) {
    GET,
    POST,
    PUT,
    DELETE,
    HEAD
};

// FileType enum

typedef NS_ENUM(NSInteger, FileType) {
    FileTypeImage,
    FileTypeAudio,
    FileTypeVideo,
    FileTypeDoc,
    FileTypePdf,
    FileTypeTxt
};



/********************** Error Codes ************************/

static NSInteger  kErrorCodeBadURL                   = -1000;
static NSInteger  kErrorCodeConnectionTimeout        = -1001;
static NSInteger  kErrorCodeNetworkConnectionLost    = -1005;
static NSInteger  kErrorCodeNoInternet               = -1009;
static NSInteger  kErrorCodeFileNotExists            = -1100;

static NSString *kErrorNoInternetConnection         = @"The connection failed because the device is not connected to the internet.";
static NSString *kErrorMalformedURL                 = @"The connection failed due to a malformed URL.";
static NSString *kErrorConnectionTimedout           = @"The connection timed out.";
static NSString *kErrorNetworkConnectionLost        = @"The connection failed because the network connection was lost.";
static NSString *kErrorFileNotExists                = @"The file operation failed because the file does not exist.";



/********************** Imports ************************/

//AFNetworking

#import "AFNetworking.h"
#import "UIKit+AFNetworking.h"

//Networking

#import "RSNetworkManager.h"
#import "RSDownloadManager.h"
#import "RSUploadManager.h"

#import "NetworkClient.h"

@interface RSNetworkKitConstants : NSObject

@end
