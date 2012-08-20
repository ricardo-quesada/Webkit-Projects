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

@interface DOMPerformanceTiming : DOMObject
@property(readonly) unsigned long long navigationStart;
@property(readonly) unsigned long long unloadEventStart;
@property(readonly) unsigned long long unloadEventEnd;
@property(readonly) unsigned long long redirectStart;
@property(readonly) unsigned long long redirectEnd;
@property(readonly) unsigned long long fetchStart;
@property(readonly) unsigned long long domainLookupStart;
@property(readonly) unsigned long long domainLookupEnd;
@property(readonly) unsigned long long connectStart;
@property(readonly) unsigned long long connectEnd;
@property(readonly) unsigned long long secureConnectionStart;
@property(readonly) unsigned long long requestStart;
@property(readonly) unsigned long long responseStart;
@property(readonly) unsigned long long responseEnd;
@property(readonly) unsigned long long domLoading;
@property(readonly) unsigned long long domInteractive;
@property(readonly) unsigned long long domContentLoadedEventStart;
@property(readonly) unsigned long long domContentLoadedEventEnd;
@property(readonly) unsigned long long domComplete;
@property(readonly) unsigned long long loadEventStart;
@property(readonly) unsigned long long loadEventEnd;
@end

#endif
