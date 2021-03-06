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

#import <WebCore/DOMCanvasRenderingContext.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

@class DOMCanvasGradient;
@class DOMImageData;
@class DOMTextMetrics;
@class DOMcustom;
@class NSString;

@interface DOMCanvasRenderingContext2D : DOMCanvasRenderingContext
@property float globalAlpha;
@property(copy) NSString *globalCompositeOperation;
@property float lineWidth;
@property(copy) NSString *lineCap;
@property(copy) NSString *lineJoin;
@property float miterLimit;
@property float shadowOffsetX;
@property float shadowOffsetY;
@property float shadowBlur;
@property(copy) NSString *shadowColor;
@property(copy) NSString *font;
@property(copy) NSString *textAlign;
@property(copy) NSString *textBaseline;
@property(retain) DOMcustom *strokeStyle;
@property(retain) DOMcustom *fillStyle;
- (void)save;
- (void)restore;
- (void)scale:(float)sx sy:(float)sy;
- (void)rotate:(float)angle;
- (void)translate:(float)tx ty:(float)ty;
- (void)transform:(float)m11 m12:(float)m12 m21:(float)m21 m22:(float)m22 dx:(float)dx dy:(float)dy;
- (void)setTransform:(float)m11 m12:(float)m12 m21:(float)m21 m22:(float)m22 dx:(float)dx dy:(float)dy;
- (DOMCanvasGradient *)createLinearGradient:(float)x0 y0:(float)y0 x1:(float)x1 y1:(float)y1;
- (DOMCanvasGradient *)createRadialGradient:(float)x0 y0:(float)y0 r0:(float)r0 x1:(float)x1 y1:(float)y1 r1:(float)r1;
- (void)clearRect:(float)x y:(float)y width:(float)width height:(float)height;
- (void)fillRect:(float)x y:(float)y width:(float)width height:(float)height;
- (void)beginPath;
- (void)closePath;
- (void)moveTo:(float)x y:(float)y;
- (void)lineTo:(float)x y:(float)y;
- (void)quadraticCurveTo:(float)cpx cpy:(float)cpy x:(float)x y:(float)y;
- (void)bezierCurveTo:(float)cp1x cp1y:(float)cp1y cp2x:(float)cp2x cp2y:(float)cp2y x:(float)x y:(float)y;
- (void)arcTo:(float)x1 y1:(float)y1 x2:(float)x2 y2:(float)y2 radius:(float)radius;
- (void)rect:(float)x y:(float)y width:(float)width height:(float)height;
- (void)arc:(float)x y:(float)y radius:(float)radius startAngle:(float)startAngle endAngle:(float)endAngle anticlockwise:(BOOL)anticlockwise;
- (void)fill;
- (void)stroke;
- (void)clip;
- (BOOL)isPointInPath:(float)x y:(float)y;
- (DOMTextMetrics *)measureText:(NSString *)text;
- (void)setAlpha:(float)alpha;
- (void)setCompositeOperation:(NSString *)compositeOperation;
- (void)setLineWidth:(float)width;
- (void)setLineCap:(NSString *)cap;
- (void)setLineJoin:(NSString *)join;
- (void)setMiterLimit:(float)limit;
- (void)clearShadow;
- (void)fillText;
- (void)strokeText;
- (void)setStrokeColor;
- (void)setFillColor;
- (void)strokeRect;
- (void)drawImage;
- (void)drawImageFromRect;
- (void)setShadow;
- (void)createPattern;
- (void)putImageData;
- (DOMImageData *)createImageData;
- (DOMImageData *)getImageData:(float)sx sy:(float)sy sw:(float)sw sh:(float)sh;
@end

#endif
