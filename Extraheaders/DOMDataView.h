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

#import <WebCore/DOMArrayBufferView.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

@class DOMDOMObject;

@interface DOMDataView : DOMArrayBufferView
- (DOMDOMObject *)getInt8;
- (DOMDOMObject *)getUint8;
- (short)getInt16:(unsigned)byteOffset littleEndian:(BOOL)littleEndian;
- (unsigned short)getUint16:(unsigned)byteOffset littleEndian:(BOOL)littleEndian;
- (int)getInt32:(unsigned)byteOffset littleEndian:(BOOL)littleEndian;
- (unsigned)getUint32:(unsigned)byteOffset littleEndian:(BOOL)littleEndian;
- (float)getFloat32:(unsigned)byteOffset littleEndian:(BOOL)littleEndian;
- (double)getFloat64:(unsigned)byteOffset littleEndian:(BOOL)littleEndian;
- (void)setInt8;
- (void)setUint8;
- (void)setInt16:(unsigned)byteOffset value:(short)value littleEndian:(BOOL)littleEndian;
- (void)setUint16:(unsigned)byteOffset value:(unsigned short)value littleEndian:(BOOL)littleEndian;
- (void)setInt32:(unsigned)byteOffset value:(int)value littleEndian:(BOOL)littleEndian;
- (void)setUint32:(unsigned)byteOffset value:(unsigned)value littleEndian:(BOOL)littleEndian;
- (void)setFloat32:(unsigned)byteOffset value:(float)value littleEndian:(BOOL)littleEndian;
- (void)setFloat64:(unsigned)byteOffset value:(double)value littleEndian:(BOOL)littleEndian;
@end

#endif
