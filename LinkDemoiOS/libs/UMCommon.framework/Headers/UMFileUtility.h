//
//  UMFileUtility.h
//  UMCommon
//
//  Created by San Zhang on 3/26/17.
//  Copyright © 2017 UMeng. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "UMUtils.h"

@interface UMFileUtility : NSObject

+ (BOOL)isExistAtPath:(NSString *)path;

+ (BOOL)saveData:(NSData *)data inPath:(NSString *)filePath;

+ (BOOL)removeFile:(NSString *)filePath;

+ (NSString *)umengDirectory;

+ (NSString *)bgCacheFilePath;  // storage cached data to local while (background -> exit app)

+ (NSString *)sqliteDBFilePath;

+ (NSString *)uaDBFilePath;

+ (NSString *)agManifestPath;

+ (NSMutableArray *)envelopeFiles;
+ (NSMutableArray *)envelopeFilesWithSubFolder:(NSString*)subFolder;

+ (NSMutableArray *)statelessEnvelopeFile;

+ (NSString *)generateEnvelopeNamePrefix:(NSString *)prefix withTS:(NSString *)ts;
+ (NSString *)generateEnvelopeNamePrefix:(NSString *)prefix withTS:(NSString *)ts subFolder:(NSString*)subFolder;

+ (NSString *)generateEnvelopeNamePrefix:(NSString *)prefix withTS:(NSString *)ts pathURL:(NSString *)pathURL;

+ (void)sortFileWithCreatedTime:(NSMutableArray *)array;

+ (NSString *)ucDBFilePath;
@end
