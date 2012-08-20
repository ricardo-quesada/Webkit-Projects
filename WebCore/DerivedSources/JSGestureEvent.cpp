// ------- Begin Apple Copyright -------
/*
 * Copyright (C) 2008, Apple Inc. All rights reserved.
 *
 * No license or rights are granted by Apple expressly or by implication,
 * estoppel, or otherwise, to Apple copyrights, patents, trademarks, trade
 * secrets or other rights.
 */


#include "config.h"
#include "JSGestureEvent.h"

#include "EventTarget.h"
#include "ExceptionCode.h"
#include "GestureEvent.h"
#include "JSDOMBinding.h"
#include "JSDOMWindow.h"
#include "JSEventTarget.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSGestureEvent);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSGestureEventTableValues[9] =
{
    { "target", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventTarget), (intptr_t)0 THUNK_GENERATOR(0) },
    { "scale", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventScale), (intptr_t)0 THUNK_GENERATOR(0) },
    { "rotation", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventRotation), (intptr_t)0 THUNK_GENERATOR(0) },
    { "ctrlKey", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventCtrlKey), (intptr_t)0 THUNK_GENERATOR(0) },
    { "shiftKey", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventShiftKey), (intptr_t)0 THUNK_GENERATOR(0) },
    { "altKey", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventAltKey), (intptr_t)0 THUNK_GENERATOR(0) },
    { "metaKey", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventMetaKey), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsGestureEventConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSGestureEventTable = { 17, 15, JSGestureEventTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSGestureEventConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSGestureEventConstructorTable = { 1, 0, JSGestureEventConstructorTableValues, 0 };
class JSGestureEventConstructor : public DOMConstructorObject {
public:
    JSGestureEventConstructor(JSC::ExecState*, JSC::Structure*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSGestureEventConstructor::s_info = { "GestureEventConstructor", &DOMConstructorObject::s_info, &JSGestureEventConstructorTable, 0 };

JSGestureEventConstructor::JSGestureEventConstructor(ExecState* exec, Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSGestureEventPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSGestureEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSGestureEventConstructor, JSDOMWrapper>(exec, &JSGestureEventConstructorTable, this, propertyName, slot);
}

bool JSGestureEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSGestureEventConstructor, JSDOMWrapper>(exec, &JSGestureEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSGestureEventPrototypeTableValues[2] =
{
    { "initGestureEvent", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsGestureEventPrototypeFunctionInitGestureEvent), (intptr_t)16 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSGestureEventPrototypeTable = { 2, 1, JSGestureEventPrototypeTableValues, 0 };
const ClassInfo JSGestureEventPrototype::s_info = { "GestureEventPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSGestureEventPrototypeTable, 0 };

JSObject* JSGestureEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSGestureEvent>(exec, globalObject);
}

bool JSGestureEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSGestureEventPrototypeTable, this, propertyName, slot);
}

bool JSGestureEventPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSGestureEventPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSGestureEvent::s_info = { "GestureEvent", &JSUIEvent::s_info, &JSGestureEventTable, 0 };

JSGestureEvent::JSGestureEvent(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<GestureEvent> impl)
    : JSUIEvent(structure, globalObject, impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSGestureEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSGestureEventPrototype(exec->globalData(), globalObject, JSGestureEventPrototype::createStructure(exec->globalData(), JSUIEventPrototype::self(exec, globalObject)));
}

bool JSGestureEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSGestureEvent, Base>(exec, &JSGestureEventTable, this, propertyName, slot);
}

bool JSGestureEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSGestureEvent, Base>(exec, &JSGestureEventTable, this, propertyName, descriptor);
}

JSValue jsGestureEventTarget(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->target()));
    return result;
}


JSValue jsGestureEventScale(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    JSValue result = jsNumber(imp->scale());
    return result;
}


JSValue jsGestureEventRotation(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    JSValue result = jsNumber(imp->rotation());
    return result;
}


JSValue jsGestureEventCtrlKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->ctrlKey());
    return result;
}


JSValue jsGestureEventShiftKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->shiftKey());
    return result;
}


JSValue jsGestureEventAltKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->altKey());
    return result;
}


JSValue jsGestureEventMetaKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->metaKey());
    return result;
}


JSValue jsGestureEventConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSGestureEvent* domObject = static_cast<JSGestureEvent*>(asObject(slotBase));
    return JSGestureEvent::getConstructor(exec, domObject->globalObject());
}

JSValue JSGestureEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSGestureEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsGestureEventPrototypeFunctionInitGestureEvent(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSGestureEvent::s_info))
        return throwVMTypeError(exec);
    JSGestureEvent* castedThis = static_cast<JSGestureEvent*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSGestureEvent::s_info);
    GestureEvent* imp = static_cast<GestureEvent*>(castedThis->impl());
    const String& type(ustringToString(exec->argument(0).toString(exec)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool canBubble(exec->argument(1).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool cancelable(exec->argument(2).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    DOMWindow* view(toDOMWindow(exec->argument(3)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    int detail(exec->argument(4).toInt32(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    int screenX(exec->argument(5).toInt32(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    int screenY(exec->argument(6).toInt32(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    int clientX(exec->argument(7).toInt32(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    int clientY(exec->argument(8).toInt32(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool ctrlKey(exec->argument(9).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool altKey(exec->argument(10).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool shiftKey(exec->argument(11).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    bool metaKey(exec->argument(12).toBoolean(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    EventTarget* target(toEventTarget(exec->argument(13)));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    float scale(exec->argument(14).toFloat(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());
    float rotation(exec->argument(15).toFloat(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());

    imp->initGestureEvent(type, canBubble, cancelable, view, detail, screenX, screenY, clientX, clientY, ctrlKey, altKey, shiftKey, metaKey, target, scale, rotation);
    return JSValue::encode(jsUndefined());
}


}
