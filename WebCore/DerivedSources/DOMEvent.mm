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
#import "DOMInternal.h"

#import "DOMEvent.h"

#import "DOMBlobInternal.h"
#import "DOMCSSRuleInternal.h"
#import "DOMCSSValueInternal.h"
#import "DOMEventInternal.h"
#import "DOMEventTarget.h"
#import "DOMNodeInternal.h"
#import "DOMStyleSheetInternal.h"
#import "Event.h"
#import "ExceptionHandlers.h"
#import "JSMainThreadExecState.h"
#import "KURL.h"
#import "Node.h"
#import "ThreadCheck.h"
#import "WebCoreObjCExtras.h"
#import "WebScriptObjectPrivate.h"
#import <wtf/GetPtr.h>

#define IMPL reinterpret_cast<WebCore::Event*>(_internal)

@implementation DOMEvent

- (void)dealloc
{
    if (WebCoreObjCScheduleDeallocateOnMainThread([DOMEvent class], self))
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

- (NSString *)type
{
    WebCore::JSMainThreadNullState state;
    return IMPL->type();
}

- (id <DOMEventTarget>)target
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(IMPL->target()));
}

- (id <DOMEventTarget>)currentTarget
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(IMPL->currentTarget()));
}

- (unsigned short)eventPhase
{
    WebCore::JSMainThreadNullState state;
    return IMPL->eventPhase();
}

- (BOOL)bubbles
{
    WebCore::JSMainThreadNullState state;
    return IMPL->bubbles();
}

- (BOOL)cancelable
{
    WebCore::JSMainThreadNullState state;
    return IMPL->cancelable();
}

- (DOMTimeStamp)timeStamp
{
    WebCore::JSMainThreadNullState state;
    return IMPL->timeStamp();
}

- (BOOL)defaultPrevented
{
    WebCore::JSMainThreadNullState state;
    return IMPL->defaultPrevented();
}

- (id <DOMEventTarget>)srcElement
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(IMPL->srcElement()));
}

- (BOOL)returnValue
{
    WebCore::JSMainThreadNullState state;
    return IMPL->returnValue();
}

- (void)setReturnValue:(BOOL)newReturnValue
{
    WebCore::JSMainThreadNullState state;
    IMPL->setReturnValue(newReturnValue);
}

- (BOOL)cancelBubble
{
    WebCore::JSMainThreadNullState state;
    return IMPL->cancelBubble();
}

- (void)setCancelBubble:(BOOL)newCancelBubble
{
    WebCore::JSMainThreadNullState state;
    IMPL->setCancelBubble(newCancelBubble);
}

- (void)stopPropagation
{
    WebCore::JSMainThreadNullState state;
    IMPL->stopPropagation();
}

- (void)preventDefault
{
    WebCore::JSMainThreadNullState state;
    IMPL->preventDefault();
}

- (void)initEvent:(NSString *)eventTypeArg canBubbleArg:(BOOL)canBubbleArg cancelableArg:(BOOL)cancelableArg
{
    WebCore::JSMainThreadNullState state;
    IMPL->initEvent(eventTypeArg, canBubbleArg, cancelableArg);
}

- (void)initEvent:(NSString *)eventTypeArg :(BOOL)canBubbleArg :(BOOL)cancelableArg
{
    WebCore::JSMainThreadNullState state;
    IMPL->initEvent(eventTypeArg, canBubbleArg, cancelableArg);
}

- (void)stopImmediatePropagation
{
    WebCore::JSMainThreadNullState state;
    IMPL->stopImmediatePropagation();
}

@end

WebCore::Event* core(DOMEvent *wrapper)
{
    return wrapper ? reinterpret_cast<WebCore::Event*>(wrapper->_internal) : 0;
}

DOMEvent *kit(WebCore::Event* value)
{
    { DOM_ASSERT_MAIN_THREAD(); WebCoreThreadViolationCheckRoundOne(); };
    if (!value)
        return nil;
    if (DOMEvent *wrapper = getDOMWrapper(value))
        return [[wrapper retain] autorelease];
    DOMEvent *wrapper = [[kitClass(value) alloc] _init];
    if (!wrapper)
        return nil;
    wrapper->_internal = reinterpret_cast<DOMObjectInternal*>(value);
    value->ref();
    addDOMWrapper(wrapper, value);
    return [wrapper autorelease];
}