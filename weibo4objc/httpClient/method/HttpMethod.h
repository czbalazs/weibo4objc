//
//  HttpMethod.h
//  weibo4objc
//
//  Created by fanng yuan on 11/30/10.
//  Copyright 2010 fanngyuan@sina. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HttpResponse.h"
#import "HttpMethodDelegate.h"
#import "FilePart.h"

typedef enum methodEnum {
    GET = 1,
    PUT = 2,
	POST = 3
} methodEnum;

@interface HttpMethod : NSObject {
	NSObject<HttpMethodDelegate> * delegate;
	BOOL needAsyncExcute;
	NSMutableDictionary * headerFields;
	NSMutableDictionary * body;
	NSURL * url;
}

-(id) init;
-(id) initWithMethod:(methodEnum ) httpMethod;

@property (readwrite,assign) BOOL needAsyncExcute;
@property (readwrite,retain) NSMutableDictionary * headerFields;
@property (readwrite,retain) NSMutableDictionary * body;
@property (readwrite,retain) NSURL * url;

-(HttpResponse *) execute;
-(void) addPart:(FilePart *) part;

@end
