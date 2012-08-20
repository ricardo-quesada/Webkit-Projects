/*
 * This file is part of the WebKit open source project.
 * This file has been generated by generate-bindings.pl. DO NOT MODIFY!
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

#import "config.h"

#if ENABLE(INDEXED_DATABASE)

#import "DOMInternal.h"

#import "DOMIDBDatabase.h"

#import "DOMBlobInternal.h"
#import "DOMCSSRuleInternal.h"
#import "DOMCSSValueInternal.h"
#import "DOMDOMStringListInternal.h"
#import "DOMEventInternal.h"
#import "DOMIDBDatabaseInternal.h"
#import "DOMIDBObjectStoreInternal.h"
#import "DOMIDBTransactionInternal.h"
#import "DOMIDBVersionChangeRequestInternal.h"
#import "DOMNodeInternal.h"
#import "DOMOptionsObjectInternal.h"
#import "DOMStringList.h"
#import "DOMStyleSheetInternal.h"
#import "Event.h"
#import "EventListener.h"
#import "ExceptionHandlers.h"
#import "IDBDatabase.h"
#import "IDBObjectStore.h"
#import "IDBTransaction.h"
#import "IDBVersionChangeRequest.h"
#import "JSMainThreadExecState.h"
#import "KURL.h"
#import "ObjCEventListener.h"
#import "OptionsObject.h"
#import "ThreadCheck.h"
#import "WebCoreObjCExtras.h"
#import "WebScriptObjectPrivate.h"
#import <wtf/GetPtr.h>

#define IMPL reinterpret_cast<WebCore::IDBDatabase*>(_internal)

@implementation DOMIDBDatabase

- (void)dealloc
{
    if (WebCoreObjCScheduleDeallocateOnMainThread([DOMIDBDatabase class], self))
        return;

    if (_internal)
        IMPL->deref();
    [super dealloc];
}

- (void)finalize
{
    if (_internal)
        IMPL->deref();
    [super finalize];
}

- (NSString *)name
{
    WebCore::JSMainThreadNullState state;
    return IMPL->name();
}

- (NSString *)version
{
    WebCore::JSMainThreadNullState state;
    return IMPL->version();
}

- (DOMDOMStringList *)objectStoreNames
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(IMPL->objectStoreNames()));
}

- (id <DOMEventListener>)onabort
{
    WebCore::JSMainThreadNullState state;
    return kit(IMPL->onabort());
}

- (void)setOnabort:(id <DOMEventListener>)newOnabort
{
    WebCore::JSMainThreadNullState state;
    ASSERT(newOnabort);

    IMPL->setOnabort(WTF::getPtr(nativeEventListener));
}

- (id <DOMEventListener>)onerror
{
    WebCore::JSMainThreadNullState state;
    return kit(IMPL->onerror());
}

- (void)setOnerror:(id <DOMEventListener>)newOnerror
{
    WebCore::JSMainThreadNullState state;
    ASSERT(newOnerror);

    IMPL->setOnerror(WTF::getPtr(nativeEventListener));
}

- (id <DOMEventListener>)onversionchange
{
    WebCore::JSMainThreadNullState state;
    return kit(IMPL->onversionchange());
}

- (void)setOnversionchange:(id <DOMEventListener>)newOnversionchange
{
    WebCore::JSMainThreadNullState state;
    ASSERT(newOnversionchange);

    IMPL->setOnversionchange(WTF::getPtr(nativeEventListener));
}

- (DOMIDBObjectStore *)createObjectStore:(NSString *)inName options:(DOMOptionsObject *)options
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    DOMIDBObjectStore *result = kit(WTF::getPtr(IMPL->createObjectStore(inName, core(options), ec)));
    WebCore::raiseOnDOMError(ec);
    return result;
}

- (void)deleteObjectStore:(NSString *)inName
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    IMPL->deleteObjectStore(inName, ec);
    WebCore::raiseOnDOMError(ec);
}

- (DOMIDBVersionChangeRequest *)setVersion:(NSString *)inVersion
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    DOMIDBVersionChangeRequest *result = kit(WTF::getPtr(IMPL->setVersion(inVersion, ec)));
    WebCore::raiseOnDOMError(ec);
    return result;
}

- (DOMIDBTransaction *)transaction:(DOMDOMStringList *)storeNames mode:(unsigned short)mode
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    DOMIDBTransaction *result = kit(WTF::getPtr(IMPL->transaction(core(storeNames), mode, ec)));
    WebCore::raiseOnDOMError(ec);
    return result;
}

- (void)close
{
    WebCore::JSMainThreadNullState state;
    IMPL->close();
}

- (void)addEventListener:(NSString *)type listener:(id <DOMEventListener>)listener useCapture:(BOOL)useCapture
{
    WebCore::JSMainThreadNullState state;
    RefPtr<WebCore::EventListener> nativeEventListener = WebCore::ObjCEventListener::wrap(listener);
    IMPL->addEventListener(type, WTF::getPtr(nativeEventListener), useCapture);
}

- (void)removeEventListener:(NSString *)type listener:(id <DOMEventListener>)listener useCapture:(BOOL)useCapture
{
    WebCore::JSMainThreadNullState state;
    RefPtr<WebCore::EventListener> nativeEventListener = WebCore::ObjCEventListener::wrap(listener);
    IMPL->removeEventListener(type, WTF::getPtr(nativeEventListener), useCapture);
}

- (BOOL)dispatchEvent:(DOMEvent *)evt
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    BOOL result = IMPL->dispatchEvent(core(evt), ec);
    WebCore::raiseOnDOMError(ec);
    return result;
}

@end

WebCore::IDBDatabase* core(DOMIDBDatabase *wrapper)
{
    return wrapper ? reinterpret_cast<WebCore::IDBDatabase*>(wrapper->_internal) : 0;
}

DOMIDBDatabase *kit(WebCore::IDBDatabase* value)
{
    { DOM_ASSERT_MAIN_THREAD(); WebCoreThreadViolationCheckRoundOne(); };
    if (!value)
        return nil;
    if (DOMIDBDatabase *wrapper = getDOMWrapper(value))
        return [[wrapper retain] autorelease];
    DOMIDBDatabase *wrapper = [[DOMIDBDatabase alloc] _init];
    wrapper->_internal = reinterpret_cast<DOMObjectInternal*>(value);
    value->ref();
    addDOMWrapper(wrapper, value);
    return [wrapper autorelease];
}

#endif // ENABLE(INDEXED_DATABASE)