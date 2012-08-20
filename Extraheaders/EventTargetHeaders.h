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

#ifndef EventTargetHeaders_h
#define EventTargetHeaders_h

#if ENABLE(WEB_AUDIO)
#include "AudioContext.h"
#if USE(JSC)
#include "JSAudioContext.h"
#elif USE(V8)
#include "V8AudioContext.h"
#endif
#endif
#if ENABLE(BATTERY_STATUS)
#include "BatteryManager.h"
#if USE(JSC)
#include "JSBatteryManager.h"
#elif USE(V8)
#include "V8BatteryManager.h"
#endif
#endif
#include "DOMApplicationCache.h"
#if USE(JSC)
#include "JSDOMApplicationCache.h"
#elif USE(V8)
#include "V8DOMApplicationCache.h"
#endif
#include "DOMWindow.h"
#if USE(JSC)
#include "JSDOMWindow.h"
#elif USE(V8)
#include "V8DOMWindow.h"
#endif
#if ENABLE(WORKERS)
#include "DedicatedWorkerContext.h"
#if USE(JSC)
#include "JSDedicatedWorkerContext.h"
#elif USE(V8)
#include "V8DedicatedWorkerContext.h"
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#include "DeprecatedPeerConnection.h"
#if USE(JSC)
#include "JSDeprecatedPeerConnection.h"
#elif USE(V8)
#include "V8DeprecatedPeerConnection.h"
#endif
#endif
#include "EventSource.h"
#if USE(JSC)
#include "JSEventSource.h"
#elif USE(V8)
#include "V8EventSource.h"
#endif
#if ENABLE(BLOB)
#include "FileReader.h"
#if USE(JSC)
#include "JSFileReader.h"
#elif USE(V8)
#include "V8FileReader.h"
#endif
#endif
#if ENABLE(FILE_SYSTEM)
#include "FileWriter.h"
#if USE(JSC)
#include "JSFileWriter.h"
#elif USE(V8)
#include "V8FileWriter.h"
#endif
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBDatabase.h"
#if USE(JSC)
#include "JSIDBDatabase.h"
#elif USE(V8)
#include "V8IDBDatabase.h"
#endif
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBRequest.h"
#if USE(JSC)
#include "JSIDBRequest.h"
#elif USE(V8)
#include "V8IDBRequest.h"
#endif
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBTransaction.h"
#if USE(JSC)
#include "JSIDBTransaction.h"
#elif USE(V8)
#include "V8IDBTransaction.h"
#endif
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBVersionChangeRequest.h"
#if USE(JSC)
#include "JSIDBVersionChangeRequest.h"
#elif USE(V8)
#include "V8IDBVersionChangeRequest.h"
#endif
#endif
#if ENABLE(WEB_AUDIO)
#include "JavaScriptAudioNode.h"
#if USE(JSC)
#include "JSJavaScriptAudioNode.h"
#elif USE(V8)
#include "V8JavaScriptAudioNode.h"
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#include "LocalMediaStream.h"
#if USE(JSC)
#include "JSLocalMediaStream.h"
#elif USE(V8)
#include "V8LocalMediaStream.h"
#endif
#endif
#if ENABLE(VIDEO)
#include "MediaController.h"
#if USE(JSC)
#include "JSMediaController.h"
#elif USE(V8)
#include "V8MediaController.h"
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#include "MediaStream.h"
#if USE(JSC)
#include "JSMediaStream.h"
#elif USE(V8)
#include "V8MediaStream.h"
#endif
#endif
#include "MessagePort.h"
#if USE(JSC)
#include "JSMessagePort.h"
#elif USE(V8)
#include "V8MessagePort.h"
#endif
#if ENABLE(NETWORK_INFO)
#include "NetworkInfoConnection.h"
#if USE(JSC)
#include "JSNetworkInfoConnection.h"
#elif USE(V8)
#include "V8NetworkInfoConnection.h"
#endif
#endif
#include "Node.h"
#if USE(JSC)
#include "JSNode.h"
#elif USE(V8)
#include "V8Node.h"
#endif
#if ENABLE(NOTIFICATIONS) || ENABLE(LEGACY_NOTIFICATIONS)
#include "Notification.h"
#if USE(JSC)
#include "JSNotification.h"
#elif USE(V8)
#include "V8Notification.h"
#endif
#endif
#if ENABLE(MEDIA_STREAM)
#include "PeerConnection00.h"
#if USE(JSC)
#include "JSPeerConnection00.h"
#elif USE(V8)
#include "V8PeerConnection00.h"
#endif
#endif
#if ENABLE(SVG)
#include "SVGElementInstance.h"
#if USE(JSC)
#include "JSSVGElementInstance.h"
#elif USE(V8)
#include "V8SVGElementInstance.h"
#endif
#endif
#if ENABLE(SHARED_WORKERS)
#include "SharedWorker.h"
#if USE(JSC)
#include "JSSharedWorker.h"
#elif USE(V8)
#include "V8SharedWorker.h"
#endif
#endif
#if ENABLE(SHARED_WORKERS)
#include "SharedWorkerContext.h"
#if USE(JSC)
#include "JSSharedWorkerContext.h"
#elif USE(V8)
#include "V8SharedWorkerContext.h"
#endif
#endif
#if ENABLE(SCRIPTED_SPEECH)
#include "SpeechRecognition.h"
#if USE(JSC)
#include "JSSpeechRecognition.h"
#elif USE(V8)
#include "V8SpeechRecognition.h"
#endif
#endif
#if ENABLE(VIDEO_TRACK)
#include "TextTrack.h"
#if USE(JSC)
#include "JSTextTrack.h"
#elif USE(V8)
#include "V8TextTrack.h"
#endif
#endif
#if ENABLE(VIDEO_TRACK)
#include "TextTrackCue.h"
#if USE(JSC)
#include "JSTextTrackCue.h"
#elif USE(V8)
#include "V8TextTrackCue.h"
#endif
#endif
#if ENABLE(VIDEO_TRACK)
#include "TextTrackList.h"
#if USE(JSC)
#include "JSTextTrackList.h"
#elif USE(V8)
#include "V8TextTrackList.h"
#endif
#endif
#if ENABLE(WEB_SOCKETS)
#include "WebSocket.h"
#if USE(JSC)
#include "JSWebSocket.h"
#elif USE(V8)
#include "V8WebSocket.h"
#endif
#endif
#if ENABLE(WORKERS)
#include "Worker.h"
#if USE(JSC)
#include "JSWorker.h"
#elif USE(V8)
#include "V8Worker.h"
#endif
#endif
#include "XMLHttpRequest.h"
#if USE(JSC)
#include "JSXMLHttpRequest.h"
#elif USE(V8)
#include "V8XMLHttpRequest.h"
#endif
#include "XMLHttpRequestUpload.h"
#if USE(JSC)
#include "JSXMLHttpRequestUpload.h"
#elif USE(V8)
#include "V8XMLHttpRequestUpload.h"
#endif

#endif // EventTargetHeaders_h
