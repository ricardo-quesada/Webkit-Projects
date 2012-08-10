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

@class DOMNode;
@class DOMRange;
@class NSString;

@interface DOMDOMSelection : DOMObject
@property(readonly, retain) DOMNode *anchorNode;
@property(readonly) int anchorOffset;
@property(readonly, retain) DOMNode *focusNode;
@property(readonly) int focusOffset;
@property(readonly) BOOL isCollapsed;
@property(readonly) int rangeCount;
@property(readonly, retain) DOMNode *baseNode;
@property(readonly) int baseOffset;
@property(readonly, retain) DOMNode *extentNode;
@property(readonly) int extentOffset;
@property(readonly, copy) NSString *type;
- (void)collapse:(DOMNode *)node index:(int)index;
- (void)collapseToEnd;
- (void)collapseToStart;
- (void)deleteFromDocument;
- (BOOL)containsNode:(DOMNode *)node allowPartial:(BOOL)allowPartial;
- (void)selectAllChildren:(DOMNode *)node;
- (void)extend:(DOMNode *)node offset:(int)offset;
- (DOMRange *)getRangeAt:(int)index;
- (void)removeAllRanges;
- (void)addRange:(DOMRange *)range;
- (void)modify:(NSString *)alter direction:(NSString *)direction granularity:(NSString *)granularity;
- (void)setBaseAndExtent:(DOMNode *)baseNode baseOffset:(int)baseOffset extentNode:(DOMNode *)extentNode extentOffset:(int)extentOffset;
- (void)setPosition:(DOMNode *)node offset:(int)offset;
- (void)empty;
@end

#endif
