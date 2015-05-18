//
//  GHODictionary_IMP.h
//  GHODictionary
//
//  Created by Gabriel on 5/13/15.
//  Copyright (c) 2015 Gabriel Handford. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GHODictionary : NSObject <NSFastEnumeration>

@property (readonly) NSUInteger count;

- (instancetype)initWithCapacity:(NSUInteger)capacity;
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
+ (instancetype)dictionary;
+ (instancetype)dictionaryWithDictionary:(NSDictionary *)dictionary;
// Shorthand when using literal
+ (instancetype)d:(NSDictionary *)dictionary;

- (void)setObject:(id)object forKey:(id)key;
- (id)objectForKey:(id)key;

- (void)removeObjectForKey:(id)key;

- (void)setObject:(id)obj forKeyedSubscript:(id<NSCopying>)key;
- (id)objectForKeyedSubscript:(id)key;

- (void)sortKeysUsingSelector:(SEL)selector deepSort:(BOOL)deepSort;
- (NSArray *)allKeys;

- (void)addEntriesFromOrderedDictionary:(GHODictionary *)dictionary;
- (void)addEntriesFromDictionary:(NSDictionary *)dictionary;

- (NSEnumerator *)keyEnumerator;
- (NSEnumerator *)reverseKeyEnumerator;

- (NSDictionary *)toDictionary;

- (NSArray *)map:(id (^)(id key, id value))block;
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(id key, id obj, BOOL *stop))block;

/*!
 Add object to key entry.
 This is to make it easier to create a dictionary of key to array values.
 */
- (void)addObject:(id)object forKey:(id)key;

@end

#define GHODict(DICT) ([GHODictionary dictionaryWithDictionary:DICT])
