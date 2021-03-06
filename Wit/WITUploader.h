//
//  Uploader.h
//  Wit
//
//  Created by Willy Blandin on 12. 9. 3..
//  Copyright (c) 2012년 Willy Blandin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WITRecorder.h"

@protocol WITUploaderDelegate;

/**
* Uploader class that will upload the wav file and return back the response as NSString to the delegate
*/
@interface WITUploader : NSObject  <NSStreamDelegate>
@property (nonatomic, weak) id<WITUploaderDelegate> delegate;

-(BOOL)startRequestWithContext:(NSDictionary *)context;
-(void)sendChunk:(NSData *)chunk;
-(void)endRequest;

- (instancetype)initWithAudioFormat:(AudioFormatID)audioFormat;
@end

@protocol WITUploaderDelegate <NSObject>
-(void)gotResponse:(NSDictionary *)resp error:(NSError *)err;
@end
