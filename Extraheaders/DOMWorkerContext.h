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

@class DOMArrayBufferConstructor;
@class DOMBlobConstructor;
@class DOMDOMFileSystemSync;
@class DOMDOMURLConstructor;
@class DOMDataViewConstructor;
@class DOMDatabase;
@class DOMDatabaseCallback;
@class DOMDatabaseSync;
@class DOMEntryCallback;
@class DOMEntrySync;
@class DOMErrorCallback;
@class DOMEvent;
@class DOMEventSourceConstructor;
@class DOMFileErrorConstructor;
@class DOMFileExceptionConstructor;
@class DOMFileReaderConstructor;
@class DOMFileReaderSyncConstructor;
@class DOMFileSystemCallback;
@class DOMFloat32ArrayConstructor;
@class DOMFloat64ArrayConstructor;
@class DOMIDBCursorConstructor;
@class DOMIDBDatabaseConstructor;
@class DOMIDBDatabaseExceptionConstructor;
@class DOMIDBFactory;
@class DOMIDBFactoryConstructor;
@class DOMIDBIndexConstructor;
@class DOMIDBKeyRangeConstructor;
@class DOMIDBObjectStoreConstructor;
@class DOMIDBRequestConstructor;
@class DOMIDBTransactionConstructor;
@class DOMInt16ArrayConstructor;
@class DOMInt32ArrayConstructor;
@class DOMInt8ArrayConstructor;
@class DOMMessageChannelConstructor;
@class DOMMessageEventConstructor;
@class DOMTimeoutHandler;
@class DOMUint16ArrayConstructor;
@class DOMUint32ArrayConstructor;
@class DOMUint8ArrayConstructor;
@class DOMWebKitBlobBuilderConstructor;
@class DOMWebSocketConstructor;
@class DOMWorkerLocation;
@class DOMWorkerLocationConstructor;
@class DOMWorkerNavigator;
@class DOMXMLHttpRequestConstructor;
@class NSString;
@protocol DOMEventListener;

enum {
#if ENABLE(FILE_SYSTEM)
    DOM_TEMPORARY = 0,
#endif
#if ENABLE(FILE_SYSTEM)
    DOM_PERSISTENT = 1
#endif

};

@interface DOMWorkerContext : DOMObject
@property(retain) DOMWorkerLocation *location;
@property(retain) id <DOMEventListener> onerror;
@property(retain) DOMWorkerNavigator *navigator;
@property(retain) DOMMessageEventConstructor *MessageEvent;
@property(retain) DOMWorkerLocationConstructor *WorkerLocation;
@property(retain) DOMMessageChannelConstructor *MessageChannel;
@property(retain) DOMEventSourceConstructor *EventSource;
@property(retain) DOMXMLHttpRequestConstructor *XMLHttpRequest;
@property(retain) DOMWebKitBlobBuilderConstructor *WebKitBlobBuilder;
@property(retain) DOMBlobConstructor *Blob;
@property(retain) DOMFileReaderConstructor *FileReader;
@property(retain) DOMFileReaderSyncConstructor *FileReaderSync;
@property(retain) DOMDOMURLConstructor *webkitURL;
@property(retain) DOMArrayBufferConstructor *ArrayBuffer;
@property(retain) DOMInt8ArrayConstructor *Int8Array;
@property(retain) DOMUint8ArrayConstructor *Uint8Array;
@property(retain) DOMUint8ArrayConstructor *Uint8ClampedArray;
@property(retain) DOMInt16ArrayConstructor *Int16Array;
@property(retain) DOMUint16ArrayConstructor *Uint16Array;
@property(retain) DOMInt32ArrayConstructor *Int32Array;
@property(retain) DOMUint32ArrayConstructor *Uint32Array;
@property(retain) DOMFloat32ArrayConstructor *Float32Array;
@property(retain) DOMFloat64ArrayConstructor *Float64Array;
@property(retain) DOMDataViewConstructor *DataView;
@property(retain) DOMWebSocketConstructor *WebSocket;
@property(readonly, retain) DOMIDBFactory *webkitIndexedDB;
@property(retain) DOMIDBCursorConstructor *webkitIDBCursor;
@property(retain) DOMIDBDatabaseConstructor *webkitIDBDatabase;
@property(retain) DOMIDBDatabaseExceptionConstructor *webkitIDBDatabaseException;
@property(retain) DOMIDBFactoryConstructor *webkitIDBFactory;
@property(retain) DOMIDBIndexConstructor *webkitIDBIndex;
@property(retain) DOMIDBKeyRangeConstructor *webkitIDBKeyRange;
@property(retain) DOMIDBObjectStoreConstructor *webkitIDBObjectStore;
@property(retain) DOMIDBRequestConstructor *webkitIDBRequest;
@property(retain) DOMIDBTransactionConstructor *webkitIDBTransaction;
@property(retain) DOMFileErrorConstructor *FileError;
@property(retain) DOMFileExceptionConstructor *FileException;

- (void)close;
- (void)importScripts;
- (int)setTimeout:(DOMTimeoutHandler *)handler timeout:(int)timeout;
- (void)clearTimeout:(int)handle;
- (int)setInterval:(DOMTimeoutHandler *)handler timeout:(int)timeout;
- (void)clearInterval:(int)handle;
- (void)addEventListener:(NSString *)type listener:(id <DOMEventListener>)listener useCapture:(BOOL)useCapture;
- (void)removeEventListener:(NSString *)type listener:(id <DOMEventListener>)listener useCapture:(BOOL)useCapture;
- (BOOL)dispatchEvent:(DOMEvent *)evt;
#if ENABLE(SQL_DATABASE)
- (DOMDatabase *)openDatabase:(NSString *)name version:(NSString *)version displayName:(NSString *)displayName estimatedSize:(unsigned)estimatedSize creationCallback:(DOMDatabaseCallback *)creationCallback;
#endif
#if ENABLE(SQL_DATABASE)
- (DOMDatabaseSync *)openDatabaseSync:(NSString *)name version:(NSString *)version displayName:(NSString *)displayName estimatedSize:(unsigned)estimatedSize creationCallback:(DOMDatabaseCallback *)creationCallback;
#endif
#if ENABLE(FILE_SYSTEM)
- (void)webkitRequestFileSystem:(unsigned short)type size:(long long)size successCallback:(DOMFileSystemCallback *)successCallback errorCallback:(DOMErrorCallback *)errorCallback;
#endif
#if ENABLE(FILE_SYSTEM)
- (DOMDOMFileSystemSync *)webkitRequestFileSystemSync:(unsigned short)type size:(long long)size;
#endif
#if ENABLE(FILE_SYSTEM)
- (void)webkitResolveLocalFileSystemURL:(NSString *)url successCallback:(DOMEntryCallback *)successCallback errorCallback:(DOMErrorCallback *)errorCallback;
#endif
#if ENABLE(FILE_SYSTEM)
- (DOMEntrySync *)webkitResolveLocalFileSystemSyncURL:(NSString *)url;
#endif
@end

#endif
