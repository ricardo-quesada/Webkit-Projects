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

@class DOMWebKitCSSMatrix;
@class NSString;

@interface DOMWebKitCSSMatrix : DOMObject
@property double a;
@property double b;
@property double c;
@property double d;
@property double e;
@property double f;
@property double m11;
@property double m12;
@property double m13;
@property double m14;
@property double m21;
@property double m22;
@property double m23;
@property double m24;
@property double m31;
@property double m32;
@property double m33;
@property double m34;
@property double m41;
@property double m42;
@property double m43;
@property double m44;

- (void)setMatrixValue:(NSString *)string;
- (DOMWebKitCSSMatrix *)multiply:(DOMWebKitCSSMatrix *)secondMatrix;
- (DOMWebKitCSSMatrix *)inverse;
- (DOMWebKitCSSMatrix *)translate:(double)x y:(double)y z:(double)z;
- (DOMWebKitCSSMatrix *)scale:(double)scaleX scaleY:(double)scaleY scaleZ:(double)scaleZ;
- (DOMWebKitCSSMatrix *)rotate:(double)rotX rotY:(double)rotY rotZ:(double)rotZ;
- (DOMWebKitCSSMatrix *)rotateAxisAngle:(double)x y:(double)y z:(double)z angle:(double)angle;
- (DOMWebKitCSSMatrix *)skewX:(double)angle;
- (DOMWebKitCSSMatrix *)skewY:(double)angle;
- (NSString *)toString;
@end

#endif
