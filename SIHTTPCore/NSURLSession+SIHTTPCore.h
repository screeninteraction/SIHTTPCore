//
//  SINotworking.h
//  SINotworking
//
//  Created by Seivan Heidari on 2013-10-29.
//  Copyright (c) 2013 Seivan Heidari. All rights reserved.
//



#import "SIURLSessionTaskSharedBlocks.h"

@class SIURLSessionRequestSerializer;
@class SIURLSessionResponseSerializer;

@interface NSURLSession (SIHTTPCore)


#pragma mark - Properties
//Yes, strong until the session is invalidated, then it's set to nil.

@property(strong,setter = SI_setDelegate:)   id<NSURLSessionDataDelegate,NSURLSessionDownloadDelegate>     SI_delegate;

@property(readonly) NSURL       * SI_baseURL;
@property(readonly) NSString    * SI_sessionName;

@property(assign,setter = SI_setAutoResume:,getter = SI_isAutoResume) BOOL SI_autoResume;

@property(nonatomic,copy) NSDictionary * SI_HTTPAdditionalHeaders;
-(void)SI_setValue:(id)value forHTTPHeaderField:(NSString *)theHTTPHeaderField;


#pragma mark - Init

+(instancetype)SI_sessionWithName:(NSString *)theSessionName
                            withBaseURLString:(NSString *)theBaseURLString;


+(instancetype)SI_sessionWithName:(NSString *)theSessionName
                     withBaseURLString:(NSString *)theBaseURLString
               andSessionConfiguration:(NSURLSessionConfiguration *)theSessionConfiguration;


+(instancetype)SI_sessionWithName:(NSString *)theSessionName
                     withBaseURLString:(NSString *)theBaseURLString
               andSessionConfiguration:(NSURLSessionConfiguration *)theSessionConfiguration
                  andRequestSerializer:(SIURLSessionRequestSerializer *)theRequestSerializer
                 andResponseSerializer:(SIURLSessionResponseSerializer *)theResponseSerializer
                        operationQueue:(NSOperationQueue *)theOperationQueue;

#pragma mark - Mama-san keeps track of the staff.
+(instancetype)SI_fetchSessionWithName:(NSString *)theSessionName;



#pragma mark - Task Uploads turned to Downloads for progress handlers

-(NSURLSessionTask *)SI_taskGETResource:(NSString *)theResource
                             withParams:(id<NSFastEnumeration>)theParams
                          completeBlock:(SIURLSessionTaskRequestCompleteBlock)theBlock;

-(NSURLSessionTask *)SI_taskPOSTResource:(NSString *)theResource
                              withParams:(id<NSFastEnumeration>)theParams
                           completeBlock:(SIURLSessionTaskRequestCompleteBlock)theBlock;


-(NSURLSessionTask *)SI_taskPUTResource:(NSString*)theResource
                             withParams:(id<NSFastEnumeration>)theParams
                          completeBlock:(SIURLSessionTaskRequestCompleteBlock)theBlock;


-(NSURLSessionTask *)SI_taskPATCHResource:(NSString *)theResource
                               withParams:(id<NSFastEnumeration>)theParams
                            completeBlock:(SIURLSessionTaskRequestCompleteBlock)theBlock;


-(NSURLSessionTask *)SI_taskDELETEResource:(NSString *)theResource
                                withParams:(id<NSFastEnumeration>)theParams
                             completeBlock:(SIURLSessionTaskRequestCompleteBlock)theBlock;



#pragma mark - Custom Tasks
-(NSURLSessionTask *)SI_buildTaskWithHTTPMethodString:(NSString *)theMethodString
                                           onResource:(NSString *)theResource
                                               params:(id<NSFastEnumeration>)theParams
                                        completeBlock:(SIURLSessionTaskRequestCompleteBlock)theBlock;


typedef NSURLRequest * (^SIURLSessionMutableRequestModifierBlock)(NSMutableURLRequest * modifierRequest);

-(NSURLSessionTask *)SI_buildTaskWithDataTaskOnResource:(NSString *)theResource
                                     withParams:(id<NSFastEnumeration>)theParams
                           requestModifierBlock:(SIURLSessionMutableRequestModifierBlock)theRequestModifierBlock
                              completeDataBlock:(SIURLSessionTaskRequestDataCompleteBlock)theDataCompleteBlock;



@end
