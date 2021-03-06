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

#ifndef JSNodeFilter_h
#define JSNodeFilter_h

#include "JSDOMBinding.h"
#include "NodeFilter.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class JSNodeFilter : public JSDOMWrapper {
public:
    typedef JSDOMWrapper Base;
    static JSNodeFilter* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<NodeFilter> impl)
    {
        JSNodeFilter* ptr = new (NotNull, JSC::allocateCell<JSNodeFilter>(globalObject->globalData().heap)) JSNodeFilter(structure, globalObject, impl);
        ptr->finishCreation(globalObject->globalData());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    static bool getOwnPropertySlot(JSC::JSCell*, JSC::ExecState*, JSC::PropertyName, JSC::PropertySlot&);
    static bool getOwnPropertyDescriptor(JSC::JSObject*, JSC::ExecState*, JSC::PropertyName, JSC::PropertyDescriptor&);
    static void destroy(JSC::JSCell*);
    ~JSNodeFilter();
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);
    static void visitChildren(JSCell*, JSC::SlotVisitor&);

    NodeFilter* impl() const { return m_impl; }
    void releaseImpl() { m_impl->deref(); m_impl = 0; }

    void releaseImplIfNotNull() { if (m_impl) { m_impl->deref(); m_impl = 0; } }

private:
    NodeFilter* m_impl;
protected:
    JSNodeFilter(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<NodeFilter>);
    void finishCreation(JSC::JSGlobalData&);
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::OverridesVisitChildren | Base::StructureFlags;
};

class JSNodeFilterOwner : public JSC::WeakHandleOwner {
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld*, NodeFilter*)
{
    DEFINE_STATIC_LOCAL(JSNodeFilterOwner, jsNodeFilterOwner, ());
    return &jsNodeFilterOwner;
}

inline void* wrapperContext(DOMWrapperWorld* world, NodeFilter*)
{
    return world;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, NodeFilter*);
PassRefPtr<NodeFilter> toNodeFilter(JSC::JSGlobalData&, JSC::JSValue);

class JSNodeFilterPrototype : public JSC::JSNonFinalObject {
public:
    typedef JSC::JSNonFinalObject Base;
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    static JSNodeFilterPrototype* create(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSNodeFilterPrototype* ptr = new (NotNull, JSC::allocateCell<JSNodeFilterPrototype>(globalData.heap)) JSNodeFilterPrototype(globalData, globalObject, structure);
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
    JSNodeFilterPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject*, JSC::Structure* structure) : JSC::JSNonFinalObject(globalData, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::OverridesVisitChildren | Base::StructureFlags;
};

class JSNodeFilterConstructor : public DOMConstructorObject {
private:
    JSNodeFilterConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSNodeFilterConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSNodeFilterConstructor* ptr = new (NotNull, JSC::allocateCell<JSNodeFilterConstructor>(*exec->heap())) JSNodeFilterConstructor(structure, globalObject);
        ptr->finishCreation(exec, globalObject);
        return ptr;
    }

    static bool getOwnPropertySlot(JSC::JSCell*, JSC::ExecState*, JSC::PropertyName, JSC::PropertySlot&);
    static bool getOwnPropertyDescriptor(JSC::JSObject*, JSC::ExecState*, JSC::PropertyName, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsNodeFilterPrototypeFunctionAcceptNode(JSC::ExecState*);
// Attributes

JSC::JSValue jsNodeFilterConstructor(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
// Constants

JSC::JSValue jsNodeFilterFILTER_ACCEPT(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterFILTER_REJECT(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterFILTER_SKIP(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_ALL(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_ELEMENT(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_ATTRIBUTE(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_TEXT(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_CDATA_SECTION(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_ENTITY_REFERENCE(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_ENTITY(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_PROCESSING_INSTRUCTION(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_COMMENT(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_DOCUMENT(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_DOCUMENT_TYPE(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_DOCUMENT_FRAGMENT(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsNodeFilterSHOW_NOTATION(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);

} // namespace WebCore

#endif
