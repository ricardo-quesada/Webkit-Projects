// ------- Begin Apple Copyright -------
/*
 * Copyright (C) 2008, Apple Inc. All rights reserved.
 *
 * Permission is granted by Apple to use this file to the extent
 * necessary to relink with LGPL WebKit files.
 *
 * No license or rights are granted by Apple expressly or by
 * implication, estoppel, or otherwise, to Apple patents and
 * trademarks. For the sake of clarity, no license or rights are
 * granted by Apple expressly or by implication, estoppel, or otherwise,
 * under any Apple patents, copyrights and trademarks to underlying
 * implementations of any application programming interfaces (APIs)
 * or to any functionality that is invoked by calling any API.
 */


#ifndef JSTouch_h
#define JSTouch_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class Touch;

class JSTouch : public JSDOMWrapper {
    typedef JSDOMWrapper Base;
public:
    JSTouch(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<Touch>);
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }

    Touch* impl() const { return m_impl.get(); }

private:
    RefPtr<Touch> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, Touch*);
Touch* toTouch(JSC::JSValue);
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Touch*);

class JSTouchPrototype : public JSC::JSObjectWithGlobalObject {
    typedef JSC::JSObjectWithGlobalObject Base;
public:
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
    JSTouchPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure) : JSC::JSObjectWithGlobalObject(globalData, globalObject, structure) { }
protected:
    static const unsigned StructureFlags = Base::StructureFlags;
};

// Attributes

JSC::JSValue jsTouchTarget(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchIdentifier(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchClientX(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchClientY(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchPageX(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchPageY(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchScreenX(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchScreenY(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif
// ------- End Apple Copyright   -------

