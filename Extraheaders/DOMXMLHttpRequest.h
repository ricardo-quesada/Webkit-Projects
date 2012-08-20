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

@class DOMArrayBuffer;
@class DOMBlob;
@class DOMDOMFormData;
@class DOMDocument;
@class DOMEvent;
@class DOMObject;
@class DOMXMLHttpRequestUpload;
@class NSString;
@protocol DOMEventListener;

enum {
    DOM_UNSENT = 0,
    DOM_OPENED = 1,
    DOM_HEADERS_RECEIVED = 2,
    DOM_LOADING = 3,
    DOM_DONE = 4
};

@interface DOMXMLHttpRequest : DOMObject
@property(retain) id <DOMEventListener> onabort;
@property(retain) id <DOMEventListener> onerror;
@property(retain) id <DOMEventListener> onload;
@property(retain) id <DOMEventListener> onloadend;
@property(retain) id <DOMEventListener> onloadstart;
@property(retain) id <DOMEventListener> onprogress;
@property(retain) id <DOMEventListener> onreadystatechange;
@property(readonly) unsigned short readyState;
@property BOOL asBlob;
@property BOOL withCredentials;
@property(readonly, retain) DOMXMLHttpRequestUpload *upload;
@property(readonly, copy) NSString *responseText;
@property(readonly, retain) DOMDocument *responseXML;
@property(readonly, retain) DOMBlob *responseBlob;
@property(copy) NSString *responseType;
@property(readonly, retain) DOMObject *response;
@property(readonly) unsigned short status;
@property(readonly, copy) NSString *statusText;

- (void)open:(NSString *)method url:(NSString *)url async:(BOOL)async user:(NSString *)user password:(NSString *)password;
- (void)setRequestHeader:(NSString *)header value:(NSString *)value;
- (void)send;
- (void)send:(DOMArrayBuffer *)data;
#if ENABLE(BLOB)
- (void)send:(DOMBlob *)data;
#endif
- (void)send:(DOMDocument *)data;
- (void)send:(NSString *)data;
- (void)send:(DOMDOMFormData *)data;
- (void)abort;
- (NSString *)getAllResponseHeaders;
- (NSString *)getResponseHeader:(NSString *)header;
- (void)overrideMimeType:(NSString *)override;
- (void)addEventListener:(NSString *)type listener:(id <DOMEventListener>)listener useCapture:(BOOL)useCapture;
- (void)removeEventListener:(NSString *)type listener:(id <DOMEventListener>)listener useCapture:(BOOL)useCapture;
- (BOOL)dispatchEvent:(DOMEvent *)evt;
@end

#endif
