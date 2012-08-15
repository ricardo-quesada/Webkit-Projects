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

#ifndef JSInternalSettings_h
#define JSInternalSettings_h

#include "InternalSettings.h"
#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class JSInternalSettings : public JSDOMWrapper {
public:
    typedef JSDOMWrapper Base;
    static JSInternalSettings* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<InternalSettings> impl)
    {
        JSInternalSettings* ptr = new (NotNull, JSC::allocateCell<JSInternalSettings>(globalObject->globalData().heap)) JSInternalSettings(structure, globalObject, impl);
        ptr->finishCreation(globalObject->globalData());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    static void destroy(JSC::JSCell*);
    ~JSInternalSettings();
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

    InternalSettings* impl() const { return m_impl; }
    void releaseImpl() { m_impl->deref(); m_impl = 0; }

    void releaseImplIfNotNull() { if (m_impl) { m_impl->deref(); m_impl = 0; } }

private:
    InternalSettings* m_impl;
protected:
    JSInternalSettings(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<InternalSettings>);
    void finishCreation(JSC::JSGlobalData&);
    static const unsigned StructureFlags = Base::StructureFlags;
};

class JSInternalSettingsOwner : public JSC::WeakHandleOwner {
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld*, InternalSettings*)
{
    DEFINE_STATIC_LOCAL(JSInternalSettingsOwner, jsInternalSettingsOwner, ());
    return &jsInternalSettingsOwner;
}

inline void* wrapperContext(DOMWrapperWorld* world, InternalSettings*)
{
    return world;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, InternalSettings*);
InternalSettings* toInternalSettings(JSC::JSValue);

class JSInternalSettingsPrototype : public JSC::JSNonFinalObject {
public:
    typedef JSC::JSNonFinalObject Base;
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    static JSInternalSettingsPrototype* create(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSInternalSettingsPrototype* ptr = new (NotNull, JSC::allocateCell<JSInternalSettingsPrototype>(globalData.heap)) JSInternalSettingsPrototype(globalData, globalObject, structure);
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
    JSInternalSettingsPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject*, JSC::Structure* structure) : JSC::JSNonFinalObject(globalData, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetInspectorResourcesDataSizeLimits(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetForceCompositingMode(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetEnableCompositingForFixedPosition(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetEnableCompositingForScrollableFrames(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetAcceleratedDrawingEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetAcceleratedFiltersEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetMockScrollbarsEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetPasswordEchoEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetPasswordEchoDurationInSeconds(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetFixedElementsLayoutRelativeToFrame(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetUnifiedTextCheckingEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionUnifiedTextCheckingEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetPageScaleFactor(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetTouchEventEmulationEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetDeviceSupportsTouch(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetShadowDOMEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetStandardFontFamily(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetSerifFontFamily(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetSansSerifFontFamily(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetFixedFontFamily(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetCursiveFontFamily(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetFantasyFontFamily(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetPictographFontFamily(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetEnableScrollAnimator(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionScrollAnimatorEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetCSSExclusionsEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetMediaPlaybackRequiresUserGesture(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetEditingBehavior(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetFixedPositionCreatesStackingContext(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetSyncXHRInDocumentsEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetJavaScriptProfilingEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsInternalSettingsPrototypeFunctionSetWindowFocusRestricted(JSC::ExecState*);

} // namespace WebCore

#endif