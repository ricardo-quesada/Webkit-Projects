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

#import <WebCore/DOMCSSValueList.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

enum {
    DOM_CSS_TRANSLATE = 1,
    DOM_CSS_TRANSLATEX = 2,
    DOM_CSS_TRANSLATEY = 3,
    DOM_CSS_ROTATE = 4,
    DOM_CSS_SCALE = 5,
    DOM_CSS_SCALEX = 6,
    DOM_CSS_SCALEY = 7,
    DOM_CSS_SKEW = 8,
    DOM_CSS_SKEWX = 9,
    DOM_CSS_SKEWY = 10,
    DOM_CSS_MATRIX = 11,
    DOM_CSS_TRANSLATEZ = 12,
    DOM_CSS_TRANSLATE3D = 13,
    DOM_CSS_ROTATEX = 14,
    DOM_CSS_ROTATEY = 15,
    DOM_CSS_ROTATEZ = 16,
    DOM_CSS_ROTATE3D = 17,
    DOM_CSS_SCALEZ = 18,
    DOM_CSS_SCALE3D = 19,
    DOM_CSS_PERSPECTIVE = 20,
    DOM_CSS_MATRIX3D = 21
};

@interface DOMWebKitCSSTransformValue : DOMCSSValueList
@property(readonly) unsigned short operationType;
@end

#endif
