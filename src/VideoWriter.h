//
//  VideoWriter.h
//  Created by lukasz karluk on 15/06/12.
//  http://www.julapy.com
//

#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>

@protocol VideoWriterDelegate <NSObject>
@optional
- (void)videoWriterComplete:(NSURL *)url;
- (void)videoWriterCancelled;
- (void)videoWriterSavedToCameraRoll;
- (void)videoWriterError:(NSError *)error;
- (void)videoWriterLog:(NSString *)message;
@end

@interface VideoWriter : NSObject {
    id<VideoWriterDelegate> delegate;
    dispatch_queue_t videoWriterQueue;
}

@property(nonatomic, assign) id delegate;
@property(nonatomic, assign) CGSize videoSize;
@property(nonatomic, retain) EAGLContext * context;
@property(nonatomic, retain) AVAssetWriter * assetWriter;
@property(nonatomic, retain) AVAssetWriterInput * assetWriterVideoInput;
@property(nonatomic, retain) AVAssetWriterInput * assetWriterAudioInput;
@property(nonatomic, retain) AVAssetWriterInputPixelBufferAdaptor * assetWriterInputPixelBufferAdaptor;
@property(nonatomic, retain) NSURL * outputURL;
@property(nonatomic, assign) BOOL enableTextureCache;
@property(nonatomic, assign) BOOL expectsMediaDataInRealTime;

@property(nonatomic, retain) AVCaptureDevice *audioDevice;
@property(nonatomic, retain) AVCaptureDeviceInput *audioInput;
@property(nonatomic, retain) AVCaptureSession *captureSession;
@property(nonatomic, retain) AVCaptureAudioDataOutput *audioOutput;
//@property(nonatomic, assign) MPMoviePlayerViewController *moviePlayerViewController;

- (id)initWithFile:(NSString *)file andVideoSize:(CGSize)size;
- (id)initWithPath:(NSString *)path andVideoSize:(CGSize)size;
- (id)initWithURL:(NSURL *)fileURL andVideoSize:(CGSize)size;

- (void)startRecording;
- (void)cancelRecording;
- (void)finishRecording;
- (BOOL)isWriting;

- (BOOL)addFrameAtTime:(CMTime)frameTime;
- (BOOL)addAudio:(CMSampleBufferRef)audioBuffer;
- (void)newAudioSample:(CMSampleBufferRef)sampleBuffer;

- (BOOL)isTextureCached;
- (unsigned int)textureCacheID;
- (int)textureCacheTarget;

- (void)saveMovieToCameraRoll;
- (NSString *)playVideo;

@end
