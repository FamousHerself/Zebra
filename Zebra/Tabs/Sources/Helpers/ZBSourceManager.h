//
//  ZBSourceManager.h
//  Zebra
//
//  Created by Wilson Styres on 11/30/18.
//  Copyright © 2018 Wilson Styres. All rights reserved.
//

@class ZBSource;
@class ZBBaseSource;

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZBSourceManager : NSObject
@property (nonatomic) NSMutableSet <ZBBaseSource *> *verifiedSources;
+ (id)sharedInstance;
- (NSMutableDictionary <NSNumber *, ZBSource *> *)repos;
- (void)addSourcesFromString:(NSString *)sourcesString response:(void (^)(BOOL success, BOOL multiple, NSString *error, NSArray<NSURL *> *failedURLs))respond;
- (void)deleteSource:(ZBSource *)delRepo;
- (void)deleteBaseSource:(ZBBaseSource *)baseSource;
- (void)addDebLine:(NSString *)sourceLine;
- (void)transferFromCydia;
- (void)transferFromSileo;
- (void)transferFromInstaller;
- (void)needRecaching;
- (void)mergeSourcesFrom:(NSURL *)fromURL into:(NSURL *)destinationURL completion:(void (^)(NSError *error))completion;
@end

NS_ASSUME_NONNULL_END
