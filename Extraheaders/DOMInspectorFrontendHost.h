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

@class DOMDOMObject;
@class DOMMouseEvent;
@class NSString;

@interface DOMInspectorFrontendHost : DOMObject
- (void)loaded;
- (void)closeWindow;
- (void)bringToFront;
- (void)setZoomFactor:(float)zoom;
- (void)inspectedURLChanged:(NSString *)newURL;
- (void)requestAttachWindow;
- (void)requestDetachWindow;
- (void)requestSetDockSide:(NSString *)side;
- (void)setAttachedWindowHeight:(unsigned)height;
- (void)moveWindowBy:(float)x y:(float)y;
- (void)setInjectedScriptForOrigin:(NSString *)origin script:(NSString *)script;
- (NSString *)localizedStringsURL;
- (NSString *)hiddenPanels;
- (void)copyText:(NSString *)text;
- (void)openInNewTab:(NSString *)url;
- (BOOL)canSave;
- (void)save:(NSString *)url content:(NSString *)content forceSaveAs:(BOOL)forceSaveAs;
- (void)append:(NSString *)url content:(NSString *)content;
- (NSString *)platform;
- (NSString *)port;
- (void)showContextMenu:(DOMMouseEvent *)event items:(DOMDOMObject *)items;
- (void)sendMessageToBackend:(NSString *)message;
- (void)recordActionTaken:(unsigned)actionCode;
- (void)recordPanelShown:(unsigned)panelCode;
- (void)recordSettingChanged:(unsigned)settingChanged;
- (NSString *)loadResourceSynchronously:(NSString *)url;
@end

#endif
