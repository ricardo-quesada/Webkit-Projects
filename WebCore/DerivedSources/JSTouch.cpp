// ------- Begin Apple Copyright -------
/*
 * Copyright (C) 2008, Apple Inc. All rights reserved.
 *
 * No license or rights are granted by Apple expressly or by implication,
 * estoppel, or otherwise, to Apple copyrights, patents, trademarks, trade
 * secrets or other rights.
 */


#include "config.h"
#include "JSTouch.h"

#include "EventTarget.h"
#include "JSEventTarget.h"
#include "Touch.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSTouch);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSTouchTableValues[9] =
{
    { "target", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchTarget), (intptr_t)0 THUNK_GENERATOR(0) },
    { "identifier", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchIdentifier), (intptr_t)0 THUNK_GENERATOR(0) },
    { "clientX", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchClientX), (intptr_t)0 THUNK_GENERATOR(0) },
    { "clientY", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchClientY), (intptr_t)0 THUNK_GENERATOR(0) },
    { "pageX", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchPageX), (intptr_t)0 THUNK_GENERATOR(0) },
    { "pageY", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchPageY), (intptr_t)0 THUNK_GENERATOR(0) },
    { "screenX", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchScreenX), (intptr_t)0 THUNK_GENERATOR(0) },
    { "screenY", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchScreenY), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSTouchTable = { 17, 15, JSTouchTableValues, 0 };
/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSTouchPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSTouchPrototypeTable = { 1, 0, JSTouchPrototypeTableValues, 0 };
const ClassInfo JSTouchPrototype::s_info = { "TouchPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSTouchPrototypeTable, 0 };

JSObject* JSTouchPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTouch>(exec, globalObject);
}

const ClassInfo JSTouch::s_info = { "Touch", &JSDOMWrapper::s_info, &JSTouchTable, 0 };

JSTouch::JSTouch(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<Touch> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSTouch::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSTouchPrototype(exec->globalData(), globalObject, JSTouchPrototype::createStructure(globalObject->globalData(), globalObject->objectPrototype()));
}

bool JSTouch::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueSlot<JSTouch, Base>(exec, &JSTouchTable, this, propertyName, slot);
}

bool JSTouch::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    return getStaticValueDescriptor<JSTouch, Base>(exec, &JSTouchTable, this, propertyName, descriptor);
}

JSValue jsTouchTarget(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->target()));
    return result;
}


JSValue jsTouchIdentifier(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = jsNumber(imp->identifier());
    return result;
}


JSValue jsTouchClientX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = jsNumber(imp->clientX());
    return result;
}


JSValue jsTouchClientY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = jsNumber(imp->clientY());
    return result;
}


JSValue jsTouchPageX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = jsNumber(imp->pageX());
    return result;
}


JSValue jsTouchPageY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = jsNumber(imp->pageY());
    return result;
}


JSValue jsTouchScreenX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = jsNumber(imp->screenX());
    return result;
}


JSValue jsTouchScreenY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouch* castedThis = static_cast<JSTouch*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Touch* imp = static_cast<Touch*>(castedThis->impl());
    JSValue result = jsNumber(imp->screenY());
    return result;
}


JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, Touch* impl)
{
    return wrap<JSTouch>(exec, globalObject, impl);
}

Touch* toTouch(JSC::JSValue value)
{
    return value.inherits(&JSTouch::s_info) ? static_cast<JSTouch*>(asObject(value))->impl() : 0;
}

}
