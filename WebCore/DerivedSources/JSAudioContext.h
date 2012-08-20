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

#ifndef JSAudioContext_h
#define JSAudioContext_h

#if ENABLE(WEB_AUDIO)

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class AudioContext;

class JSAudioContext : public JSDOMWrapper {
    typedef JSDOMWrapper Base;
public:
    JSAudioContext(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<AudioContext>);
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue, JSC::PutPropertySlot&);
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }

    virtual void visitChildren(JSC::SlotVisitor&);

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);

    // Custom functions
    JSC::JSValue createBuffer(JSC::ExecState*);
    AudioContext* impl() const { return m_impl.get(); }

private:
    RefPtr<AudioContext> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::OverridesVisitChildren | Base::StructureFlags;
};

class JSAudioContextOwner : public JSC::WeakHandleOwner {
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld*, AudioContext*)
{
    DEFINE_STATIC_LOCAL(JSAudioContextOwner, jsAudioContextOwner, ());
    return &jsAudioContextOwner;
}

inline void* wrapperContext(DOMWrapperWorld* world, AudioContext*)
{
    return world;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, AudioContext*);
AudioContext* toAudioContext(JSC::JSValue);

class JSAudioContextPrototype : public JSC::JSObjectWithGlobalObject {
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
    JSAudioContextPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure) : JSC::JSObjectWithGlobalObject(globalData, globalObject, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::OverridesVisitChildren | Base::StructureFlags;
};

class JSAudioContextConstructor : public DOMConstructorObject {
public:
    JSAudioContextConstructor(JSC::ExecState*, JSC::Structure*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static const JSC::ClassInfo s_info;
    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount, &s_info);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
    static JSC::EncodedJSValue JSC_HOST_CALL constructJSAudioContext(JSC::ExecState*);
    virtual JSC::ConstructType getConstructData(JSC::ConstructData&);
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateBuffer(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateBufferSource(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateGainNode(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateDelayNode(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateLowPass2Filter(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateHighPass2Filter(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreatePanner(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateConvolver(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateDynamicsCompressor(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateAnalyser(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateJavaScriptNode(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateChannelSplitter(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionCreateChannelMerger(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsAudioContextPrototypeFunctionStartRendering(JSC::ExecState*);
// Attributes

JSC::JSValue jsAudioContextDestination(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsAudioContextCurrentTime(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsAudioContextSampleRate(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsAudioContextListener(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsAudioContextOncomplete(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSAudioContextOncomplete(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsAudioContextConstructor(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif // ENABLE(WEB_AUDIO)

#endif