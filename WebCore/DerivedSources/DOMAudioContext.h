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

@class DOMAudioBuffer;
@class DOMAudioBufferSourceNode;
@class DOMAudioChannelMerger;
@class DOMAudioChannelSplitter;
@class DOMAudioDestinationNode;
@class DOMAudioGainNode;
@class DOMAudioListener;
@class DOMAudioPannerNode;
@class DOMConvolverNode;
@class DOMDelayNode;
@class DOMDynamicsCompressorNode;
@class DOMHighPass2FilterNode;
@class DOMJavaScriptAudioNode;
@class DOMLowPass2FilterNode;
@class DOMRealtimeAnalyserNode;
@protocol DOMEventListener;

@interface DOMAudioContext : DOMObject
@property(readonly, retain) DOMAudioDestinationNode *destination;
@property(readonly) float currentTime;
@property(readonly) float sampleRate;
@property(readonly, retain) DOMAudioListener *listener;
@property(retain) id <DOMEventListener> oncomplete;
- (DOMAudioBuffer *)createBuffer;
- (DOMAudioBufferSourceNode *)createBufferSource;
- (DOMAudioGainNode *)createGainNode;
- (DOMDelayNode *)createDelayNode;
- (DOMLowPass2FilterNode *)createLowPass2Filter;
- (DOMHighPass2FilterNode *)createHighPass2Filter;
- (DOMAudioPannerNode *)createPanner;
- (DOMConvolverNode *)createConvolver;
- (DOMDynamicsCompressorNode *)createDynamicsCompressor;
- (DOMRealtimeAnalyserNode *)createAnalyser;
- (DOMJavaScriptAudioNode *)createJavaScriptNode:(unsigned)bufferSize;
- (DOMAudioChannelSplitter *)createChannelSplitter;
- (DOMAudioChannelMerger *)createChannelMerger;
- (void)startRendering;
@end

#endif
