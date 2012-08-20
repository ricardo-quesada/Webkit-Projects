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


#ifndef JSTouchEvent_h
#define JSTouchEvent_h

#include "JSUIEvent.h"
#include <runtime/JSObjectWithGlobalObject.h>

namespace WebCore {

class TouchEvent;

class JSTouchEvent : public JSUIEvent {
    typedef JSUIEvent Base;
public:
    JSTouchEvent(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<TouchEvent>);
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};


class JSTouchEventPrototype : public JSC::JSObjectWithGlobalObject {
    typedef JSC::JSObjectWithGlobalObject Base;
public:
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
    JSTouchEventPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure) : JSC::JSObjectWithGlobalObject(globalData, globalObject, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsTouchEventPrototypeFunctionInitTouchEvent(JSC::ExecState*);
// Attributes

JSC::JSValue jsTouchEventTouches(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventTargetTouches(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventChangedTouches(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventScale(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventRotation(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventCtrlKey(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventShiftKey(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventAltKey(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventMetaKey(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsTouchEventConstructor(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif
// ------- End Apple Copyright   -------

