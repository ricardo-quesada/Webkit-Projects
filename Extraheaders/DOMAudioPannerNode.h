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

#import <WebCore/DOMAudioNode.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

@class DOMAudioGain;

enum {
    DOM_EQUALPOWER = 0,
    DOM_HRTF = 1,
    DOM_SOUNDFIELD = 2,
    DOM_LINEAR_DISTANCE = 0,
    DOM_INVERSE_DISTANCE = 1,
    DOM_EXPONENTIAL_DISTANCE = 2
};

@interface DOMAudioPannerNode : DOMAudioNode
@property unsigned panningModel;
@property unsigned distanceModel;
@property float refDistance;
@property float maxDistance;
@property float rolloffFactor;
@property float coneInnerAngle;
@property float coneOuterAngle;
@property float coneOuterGain;
@property(readonly, retain) DOMAudioGain *coneGain;
@property(readonly, retain) DOMAudioGain *distanceGain;

- (void)setPosition:(float)x y:(float)y z:(float)z;
- (void)setOrientation:(float)x y:(float)y z:(float)z;
- (void)setVelocity:(float)x y:(float)y z:(float)z;
@end

#endif
