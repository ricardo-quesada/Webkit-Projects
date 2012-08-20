/*
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Samuel Weinig <sam.weinig@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#import <WebCore/DOMObject.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

@class DOMDOMStringList;
@class DOMIDBIndex;
@class DOMIDBKey;
@class DOMIDBKeyRange;
@class DOMIDBRequest;
@class DOMOptionsObject;
@class NSString;

@interface DOMIDBObjectStore : DOMObject
@property(readonly, copy) NSString *name;
@property(readonly, copy) NSString *keyPath;
@property(readonly, retain) DOMDOMStringList *indexNames;
- (DOMIDBRequest *)put:(NSString *)value key:(DOMIDBKey *)key;
- (DOMIDBRequest *)add:(NSString *)value key:(DOMIDBKey *)key;
- (DOMIDBRequest *)delete:(DOMIDBKey *)key;
- (DOMIDBRequest *)clear;
- (DOMIDBRequest *)get:(DOMIDBKey *)key;
- (DOMIDBRequest *)openCursor:(DOMIDBKeyRange *)range direction:(unsigned short)direction;
- (DOMIDBIndex *)createIndex:(NSString *)name keyPath:(NSString *)keyPath options:(DOMOptionsObject *)options;
- (DOMIDBIndex *)index:(NSString *)name;
- (void)deleteIndex:(NSString *)name;
@end

#endif
