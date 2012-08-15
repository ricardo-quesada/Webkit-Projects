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

@class NSString;

@interface DOMInternalSettings : DOMObject
- (void)setInspectorResourcesDataSizeLimits:(int)maximumResourcesContentSize maximumSingleResourceContentSize:(int)maximumSingleResourceContentSize;
- (void)setForceCompositingMode:(BOOL)enabled;
- (void)setEnableCompositingForFixedPosition:(BOOL)enabled;
- (void)setEnableCompositingForScrollableFrames:(BOOL)enabled;
- (void)setAcceleratedDrawingEnabled:(BOOL)enabled;
- (void)setAcceleratedFiltersEnabled:(BOOL)enabled;
- (void)setMockScrollbarsEnabled:(BOOL)enabled;
- (void)setPasswordEchoEnabled:(BOOL)enabled;
- (void)setPasswordEchoDurationInSeconds:(double)durationInSeconds;
- (void)setFixedElementsLayoutRelativeToFrame:(BOOL)enabled;
- (void)setUnifiedTextCheckingEnabled:(BOOL)enabled;
- (BOOL)unifiedTextCheckingEnabled;
- (void)setPageScaleFactor:(float)scaleFactor x:(int)x y:(int)y;
- (void)setTouchEventEmulationEnabled:(BOOL)enabled;
- (void)setDeviceSupportsTouch:(BOOL)enabled;
- (void)setShadowDOMEnabled:(BOOL)enabled;
- (void)setStandardFontFamily:(NSString *)family script:(NSString *)script;
- (void)setSerifFontFamily:(NSString *)family script:(NSString *)script;
- (void)setSansSerifFontFamily:(NSString *)family script:(NSString *)script;
- (void)setFixedFontFamily:(NSString *)family script:(NSString *)script;
- (void)setCursiveFontFamily:(NSString *)family script:(NSString *)script;
- (void)setFantasyFontFamily:(NSString *)family script:(NSString *)script;
- (void)setPictographFontFamily:(NSString *)family script:(NSString *)script;
- (void)setEnableScrollAnimator:(BOOL)enabled;
- (BOOL)scrollAnimatorEnabled;
- (void)setCSSExclusionsEnabled:(BOOL)enabled;
- (void)setMediaPlaybackRequiresUserGesture:(BOOL)enabled;
- (void)setEditingBehavior:(NSString *)behavior;
- (void)setFixedPositionCreatesStackingContext:(BOOL)creates;
- (void)setSyncXHRInDocumentsEnabled:(BOOL)enabled;
- (void)setJavaScriptProfilingEnabled:(BOOL)creates;
- (void)setWindowFocusRestricted:(BOOL)restricted;
@end

#endif
