// ------- Begin Apple Copyright -------
/*
 * Copyright (C) 2008, Apple Inc. All rights reserved.
 *
 * No license or rights are granted by Apple expressly or by implication,
 * estoppel, or otherwise, to Apple copyrights, patents, trademarks, trade
 * secrets or other rights.
 */


#include "config.h"
#include "JSTouchList.h"

#include "ExceptionCode.h"
#include "JSDOMBinding.h"
#include "JSTouch.h"
#include "Touch.h"
#include "TouchList.h"
#include <runtime/Error.h>
#include <runtime/PropertyNameArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSTouchList);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSTouchListTableValues[2] =
{
    { "length", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTouchListLength), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSTouchListTable = { 2, 1, JSTouchListTableValues, 0 };
/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSTouchListPrototypeTableValues[2] =
{
    { "item", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsTouchListPrototypeFunctionItem), (intptr_t)1 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSTouchListPrototypeTable = { 2, 1, JSTouchListPrototypeTableValues, 0 };
const ClassInfo JSTouchListPrototype::s_info = { "TouchListPrototype", &JSC::JSObjectWithGlobalObject::s_info, &JSTouchListPrototypeTable, 0 };

JSObject* JSTouchListPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTouchList>(exec, globalObject);
}

bool JSTouchListPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSTouchListPrototypeTable, this, propertyName, slot);
}

bool JSTouchListPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSTouchListPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSTouchList::s_info = { "TouchList", &JSDOMWrapper::s_info, &JSTouchListTable, 0 };

JSTouchList::JSTouchList(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TouchList> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl)
{
    ASSERT(inherits(&s_info));
}

JSObject* JSTouchList::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSTouchListPrototype(exec->globalData(), globalObject, JSTouchListPrototype::createStructure(globalObject->globalData(), globalObject->objectPrototype()));
}

bool JSTouchList::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    const HashEntry* entry = JSTouchListTable.entry(exec, propertyName);
    if (entry) {
        slot.setCustom(this, entry->propertyGetter());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(ok);
    if (ok && index < static_cast<TouchList*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    return getStaticValueSlot<JSTouchList, Base>(exec, &JSTouchListTable, this, propertyName, slot);
}

bool JSTouchList::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    const HashEntry* entry = JSTouchListTable.entry(exec, propertyName);
    if (entry) {
        PropertySlot slot;
        slot.setCustom(this, entry->propertyGetter());
        descriptor.setDescriptor(slot.getValue(exec, propertyName), entry->attributes());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(ok);
    if (ok && index < static_cast<TouchList*>(impl())->length()) {
        PropertySlot slot;
        slot.setCustomIndex(this, index, indexGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), DontDelete | ReadOnly);
        return true;
    }
    return getStaticValueDescriptor<JSTouchList, Base>(exec, &JSTouchListTable, this, propertyName, descriptor);
}

bool JSTouchList::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    if (propertyName < static_cast<TouchList*>(impl())->length()) {
        slot.setCustomIndex(this, propertyName, indexGetter);
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

JSValue jsTouchListLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSTouchList* castedThis = static_cast<JSTouchList*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    TouchList* imp = static_cast<TouchList*>(castedThis->impl());
    JSValue result = jsNumber(imp->length());
    return result;
}


void JSTouchList::getOwnPropertyNames(ExecState* exec, PropertyNameArray& propertyNames, EnumerationMode mode)
{
    ASSERT_GC_OBJECT_INHERITS(this, &s_info);
    for (unsigned i = 0; i < static_cast<TouchList*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getOwnPropertyNames(exec, propertyNames, mode);
}

EncodedJSValue JSC_HOST_CALL jsTouchListPrototypeFunctionItem(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSTouchList::s_info))
        return throwVMTypeError(exec);
    JSTouchList* castedThis = static_cast<JSTouchList*>(asObject(thisValue));
    ASSERT_GC_OBJECT_INHERITS(castedThis, &JSTouchList::s_info);
    TouchList* imp = static_cast<TouchList*>(castedThis->impl());
    unsigned index(exec->argument(0).toUInt32(exec));
    if (exec->hadException())
        return JSValue::encode(jsUndefined());


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->item(index)));
    return JSValue::encode(result);
}


JSValue JSTouchList::indexGetter(ExecState* exec, JSValue slotBase, unsigned index)
{
    JSTouchList* thisObj = static_cast<JSTouchList*>(asObject(slotBase));
    ASSERT_GC_OBJECT_INHERITS(thisObj, &s_info);
    return toJS(exec, thisObj->globalObject(), static_cast<TouchList*>(thisObj->impl())->item(index));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, TouchList* impl)
{
    return wrap<JSTouchList>(exec, globalObject, impl);
}

TouchList* toTouchList(JSC::JSValue value)
{
    return value.inherits(&JSTouchList::s_info) ? static_cast<JSTouchList*>(asObject(value))->impl() : 0;
}

}
