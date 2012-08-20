/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2011 Google Inc.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY GOOGLE, INC. ``AS IS'' AND ANY
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

#ifndef EventHeaders_h
#define EventHeaders_h

#if ENABLE(WEB_AUDIO)
#include "AudioProcessingEvent.h"
#if USE(JSC)
#include "JSAudioProcessingEvent.h"
#elif USE(V8)
#include "V8AudioProcessingEvent.h"
#endif
#endif
#include "BeforeLoadEvent.h"
#if USE(JSC)
#include "JSBeforeLoadEvent.h"
#elif USE(V8)
#include "V8BeforeLoadEvent.h"
#endif
#include "CloseEvent.h"
#if USE(JSC)
#include "JSCloseEvent.h"
#elif USE(V8)
#include "V8CloseEvent.h"
#endif
#include "CompositionEvent.h"
#if USE(JSC)
#include "JSCompositionEvent.h"
#elif USE(V8)
#include "V8CompositionEvent.h"
#endif
#include "CustomEvent.h"
#if USE(JSC)
#include "JSCustomEvent.h"
#elif USE(V8)
#include "V8CustomEvent.h"
#endif
#if ENABLE(DEVICE_ORIENTATION)
#include "DeviceMotionEvent.h"
#if USE(JSC)
#include "JSDeviceMotionEvent.h"
#elif USE(V8)
#include "V8DeviceMotionEvent.h"
#endif
#endif
#if ENABLE(DEVICE_ORIENTATION)
#include "DeviceOrientationEvent.h"
#if USE(JSC)
#include "JSDeviceOrientationEvent.h"
#elif USE(V8)
#include "V8DeviceOrientationEvent.h"
#endif
#endif
#include "ErrorEvent.h"
#if USE(JSC)
#include "JSErrorEvent.h"
#elif USE(V8)
#include "V8ErrorEvent.h"
#endif
#include "Event.h"
#if USE(JSC)
#include "JSEvent.h"
#elif USE(V8)
#include "V8Event.h"
#endif
#include "HashChangeEvent.h"
#if USE(JSC)
#include "JSHashChangeEvent.h"
#elif USE(V8)
#include "V8HashChangeEvent.h"
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBVersionChangeEvent.h"
#if USE(JSC)
#include "JSIDBVersionChangeEvent.h"
#elif USE(V8)
#include "V8IDBVersionChangeEvent.h"
#endif
#endif
#include "KeyboardEvent.h"
#if USE(JSC)
#include "JSKeyboardEvent.h"
#elif USE(V8)
#include "V8KeyboardEvent.h"
#endif
#if ENABLE(ENCRYPTED_MEDIA)
#include "MediaKeyEvent.h"
#if USE(JSC)
#include "JSMediaKeyEvent.h"
#elif USE(V8)
#include "V8MediaKeyEvent.h"
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaStreamEvent.h"
#if USE(JSC)
#include "JSMediaStreamEvent.h"
#elif USE(V8)
#include "V8MediaStreamEvent.h"
#endif
#endif
#include "MessageEvent.h"
#if USE(JSC)
#include "JSMessageEvent.h"
#elif USE(V8)
#include "V8MessageEvent.h"
#endif
#include "MouseEvent.h"
#if USE(JSC)
#include "JSMouseEvent.h"
#elif USE(V8)
#include "V8MouseEvent.h"
#endif
#include "MutationEvent.h"
#if USE(JSC)
#include "JSMutationEvent.h"
#elif USE(V8)
#include "V8MutationEvent.h"
#endif
#if ENABLE(WEB_AUDIO)
#include "OfflineAudioCompletionEvent.h"
#if USE(JSC)
#include "JSOfflineAudioCompletionEvent.h"
#elif USE(V8)
#include "V8OfflineAudioCompletionEvent.h"
#endif
#endif
#include "OverflowEvent.h"
#if USE(JSC)
#include "JSOverflowEvent.h"
#elif USE(V8)
#include "V8OverflowEvent.h"
#endif
#include "PageTransitionEvent.h"
#if USE(JSC)
#include "JSPageTransitionEvent.h"
#elif USE(V8)
#include "V8PageTransitionEvent.h"
#endif
#include "PopStateEvent.h"
#if USE(JSC)
#include "JSPopStateEvent.h"
#elif USE(V8)
#include "V8PopStateEvent.h"
#endif
#include "ProgressEvent.h"
#if USE(JSC)
#include "JSProgressEvent.h"
#elif USE(V8)
#include "V8ProgressEvent.h"
#endif
#if ENABLE(SVG)
#include "SVGZoomEvent.h"
#if USE(JSC)
#include "JSSVGZoomEvent.h"
#elif USE(V8)
#include "V8SVGZoomEvent.h"
#endif
#endif
#if ENABLE(INPUT_SPEECH)
#include "SpeechInputEvent.h"
#if USE(JSC)
#include "JSSpeechInputEvent.h"
#elif USE(V8)
#include "V8SpeechInputEvent.h"
#endif
#endif
#if ENABLE(SCRIPTED_SPEECH)
#include "SpeechRecognitionEvent.h"
#if USE(JSC)
#include "JSSpeechRecognitionEvent.h"
#elif USE(V8)
#include "V8SpeechRecognitionEvent.h"
#endif
#endif
#include "StorageEvent.h"
#if USE(JSC)
#include "JSStorageEvent.h"
#elif USE(V8)
#include "V8StorageEvent.h"
#endif
#include "TextEvent.h"
#if USE(JSC)
#include "JSTextEvent.h"
#elif USE(V8)
#include "V8TextEvent.h"
#endif
#if ENABLE(TOUCH_EVENTS)
#include "TouchEvent.h"
#if USE(JSC)
#include "JSTouchEvent.h"
#elif USE(V8)
#include "V8TouchEvent.h"
#endif
#endif
#if ENABLE(VIDEO_TRACK)
#include "TrackEvent.h"
#if USE(JSC)
#include "JSTrackEvent.h"
#elif USE(V8)
#include "V8TrackEvent.h"
#endif
#endif
#include "UIEvent.h"
#if USE(JSC)
#include "JSUIEvent.h"
#elif USE(V8)
#include "V8UIEvent.h"
#endif
#if ENABLE(WEBGL)
#include "WebGLContextEvent.h"
#if USE(JSC)
#include "JSWebGLContextEvent.h"
#elif USE(V8)
#include "V8WebGLContextEvent.h"
#endif
#endif
#include "WebKitAnimationEvent.h"
#if USE(JSC)
#include "JSWebKitAnimationEvent.h"
#elif USE(V8)
#include "V8WebKitAnimationEvent.h"
#endif
#include "WebKitTransitionEvent.h"
#if USE(JSC)
#include "JSWebKitTransitionEvent.h"
#elif USE(V8)
#include "V8WebKitTransitionEvent.h"
#endif
#include "WheelEvent.h"
#if USE(JSC)
#include "JSWheelEvent.h"
#elif USE(V8)
#include "V8WheelEvent.h"
#endif
#include "XMLHttpRequestProgressEvent.h"
#if USE(JSC)
#include "JSXMLHttpRequestProgressEvent.h"
#elif USE(V8)
#include "V8XMLHttpRequestProgressEvent.h"
#endif

#endif // EventHeaders_h
