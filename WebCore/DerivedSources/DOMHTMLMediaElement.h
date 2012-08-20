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

#import <WebCore/DOMHTMLElement.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

@class DOMMediaError;
@class DOMTimeRanges;
@class NSString;

enum {
    DOM_NETWORK_EMPTY = 0,
    DOM_NETWORK_IDLE = 1,
    DOM_NETWORK_LOADING = 2,
    DOM_NETWORK_NO_SOURCE = 3,
    DOM_HAVE_NOTHING = 0,
    DOM_HAVE_METADATA = 1,
    DOM_HAVE_CURRENT_DATA = 2,
    DOM_HAVE_FUTURE_DATA = 3,
    DOM_HAVE_ENOUGH_DATA = 4
};

@interface DOMHTMLMediaElement : DOMHTMLElement
@property(readonly, retain) DOMMediaError *error;
@property(copy) NSString *src;
@property(readonly, copy) NSString *currentSrc;
@property(readonly) unsigned short networkState;
@property(copy) NSString *preload;
@property(readonly, retain) DOMTimeRanges *buffered;
@property(readonly) unsigned short readyState;
@property(readonly) BOOL seeking;
@property float currentTime;
@property(readonly) float startTime;
@property(readonly) float duration;
@property(readonly) BOOL paused;
@property float defaultPlaybackRate;
@property float playbackRate;
@property(readonly, retain) DOMTimeRanges *played;
@property(readonly, retain) DOMTimeRanges *seekable;
@property(readonly) BOOL ended;
@property BOOL autoplay;
@property BOOL loop;
@property BOOL controls;
@property float volume;
@property BOOL muted;
@property BOOL webkitPreservesPitch;
@property(readonly) BOOL webkitHasClosedCaptions;
@property BOOL webkitClosedCaptionsVisible;
- (void)load;
- (NSString *)canPlayType:(NSString *)type;
- (void)play;
- (void)pause;
@end

#endif
