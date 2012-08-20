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

#if ENABLE(SVG_ANIMATION)

#import "DOMInternal.h"

#import "DOMSVGAnimationElement.h"

#import "DOMBlobInternal.h"
#import "DOMCSSRuleInternal.h"
#import "DOMCSSValueInternal.h"
#import "DOMEventInternal.h"
#import "DOMNodeInternal.h"
#import "DOMSVGAnimatedBooleanInternal.h"
#import "DOMSVGAnimationElementInternal.h"
#import "DOMSVGElementInternal.h"
#import "DOMSVGStringListInternal.h"
#import "DOMStyleSheetInternal.h"
#import "ExceptionHandlers.h"
#import "JSMainThreadExecState.h"
#import "KURL.h"
#import "SVGAnimatedBoolean.h"
#import "SVGAnimationElement.h"
#import "SVGElement.h"
#import "SVGStringList.h"
#import "ThreadCheck.h"
#import "WebScriptObjectPrivate.h"
#import <wtf/GetPtr.h>

#define IMPL static_cast<WebCore::SVGAnimationElement*>(reinterpret_cast<WebCore::Node*>(_internal))

@implementation DOMSVGAnimationElement

- (DOMSVGElement *)targetElement
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(IMPL->targetElement()));
}

- (DOMSVGStringList *)requiredFeatures
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(WebCore::SVGStaticListPropertyTearOff<WebCore::SVGStringList>::create(WebCore::GetOwnerElementForType<WebCore::SVGAnimationElement, WebCore::IsDerivedFromSVGElement<WebCore::SVGAnimationElement>::value>::ownerElement(IMPL), IMPL->requiredFeatures())));
}

- (DOMSVGStringList *)requiredExtensions
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(WebCore::SVGStaticListPropertyTearOff<WebCore::SVGStringList>::create(WebCore::GetOwnerElementForType<WebCore::SVGAnimationElement, WebCore::IsDerivedFromSVGElement<WebCore::SVGAnimationElement>::value>::ownerElement(IMPL), IMPL->requiredExtensions())));
}

- (DOMSVGStringList *)systemLanguage
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(WebCore::SVGStaticListPropertyTearOff<WebCore::SVGStringList>::create(WebCore::GetOwnerElementForType<WebCore::SVGAnimationElement, WebCore::IsDerivedFromSVGElement<WebCore::SVGAnimationElement>::value>::ownerElement(IMPL), IMPL->systemLanguage())));
}

- (DOMSVGAnimatedBoolean *)externalResourcesRequired
{
    WebCore::JSMainThreadNullState state;
    return kit(WTF::getPtr(IMPL->externalResourcesRequiredAnimated()));
}

- (float)getStartTime
{
    WebCore::JSMainThreadNullState state;
    return IMPL->getStartTime();
}

- (float)getCurrentTime
{
    WebCore::JSMainThreadNullState state;
    return IMPL->getCurrentTime();
}

- (float)getSimpleDuration
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    float result = IMPL->getSimpleDuration(ec);
    WebCore::raiseOnDOMError(ec);
    return result;
}

- (BOOL)hasExtension:(NSString *)extension
{
    WebCore::JSMainThreadNullState state;
    return IMPL->hasExtension(extension);
}

- (void)beginElement
{
    WebCore::JSMainThreadNullState state;
    IMPL->beginElement();
}

- (void)beginElementAt:(float)offset
{
    WebCore::JSMainThreadNullState state;
    IMPL->beginElementAt(offset);
}

- (void)endElement
{
    WebCore::JSMainThreadNullState state;
    IMPL->endElement();
}

- (void)endElementAt:(float)offset
{
    WebCore::JSMainThreadNullState state;
    IMPL->endElementAt(offset);
}

@end

WebCore::SVGAnimationElement* core(DOMSVGAnimationElement *wrapper)
{
    return wrapper ? reinterpret_cast<WebCore::SVGAnimationElement*>(wrapper->_internal) : 0;
}

DOMSVGAnimationElement *kit(WebCore::SVGAnimationElement* value)
{
    { DOM_ASSERT_MAIN_THREAD(); WebCoreThreadViolationCheckRoundOne(); };
    return static_cast<DOMSVGAnimationElement*>(kit(static_cast<WebCore::Node*>(value)));
}

#endif // ENABLE(SVG_ANIMATION)