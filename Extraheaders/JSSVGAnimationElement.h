/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSSVGAnimationElement_h
#define JSSVGAnimationElement_h

#if ENABLE(SVG)

#include "JSSVGElement.h"
#include "SVGAnimationElement.h"
#include "SVGElement.h"
#include <runtime/JSObject.h>

namespace WebCore {

class JSSVGAnimationElement : public JSSVGElement {
public:
    typedef JSSVGElement Base;
    static JSSVGAnimationElement* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGAnimationElement> impl)
    {
        JSSVGAnimationElement* ptr = new (NotNull, JSC::allocateCell<JSSVGAnimationElement>(globalObject->globalData().heap)) JSSVGAnimationElement(structure, globalObject, impl);
        ptr->finishCreation(globalObject->globalData());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    static bool getOwnPropertySlot(JSC::JSCell*, JSC::ExecState*, JSC::PropertyName, JSC::PropertySlot&);
    static bool getOwnPropertyDescriptor(JSC::JSObject*, JSC::ExecState*, JSC::PropertyName, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

protected:
    JSSVGAnimationElement(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<SVGAnimationElement>);
    void finishCreation(JSC::JSGlobalData&);
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};


class JSSVGAnimationElementPrototype : public JSC::JSNonFinalObject {
public:
    typedef JSC::JSNonFinalObject Base;
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    static JSSVGAnimationElementPrototype* create(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSSVGAnimationElementPrototype* ptr = new (NotNull, JSC::allocateCell<JSSVGAnimationElementPrototype>(globalData.heap)) JSSVGAnimationElementPrototype(globalData, globalObject, structure);
        ptr->finishCreation(globalData);
        return ptr;
    }

    static const JSC::ClassInfo s_info;
    static bool getOwnPropertySlot(JSC::JSCell*, JSC::ExecState*, JSC::PropertyName, JSC::PropertySlot&);
    static bool getOwnPropertyDescriptor(JSC::JSObject*, JSC::ExecState*, JSC::PropertyName, JSC::PropertyDescriptor&);
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

private:
    JSSVGAnimationElementPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject*, JSC::Structure* structure) : JSC::JSNonFinalObject(globalData, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionGetStartTime(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionGetCurrentTime(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionGetSimpleDuration(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionHasExtension(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionBeginElement(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionBeginElementAt(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionEndElement(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsSVGAnimationElementPrototypeFunctionEndElementAt(JSC::ExecState*);
// Attributes

JSC::JSValue jsSVGAnimationElementTargetElement(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsSVGAnimationElementRequiredFeatures(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsSVGAnimationElementRequiredExtensions(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsSVGAnimationElementSystemLanguage(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsSVGAnimationElementExternalResourcesRequired(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);

} // namespace WebCore

#endif // ENABLE(SVG)

#endif