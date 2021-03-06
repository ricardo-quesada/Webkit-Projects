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

#ifndef JSDocument_h
#define JSDocument_h

#include "Document.h"
#include "JSDOMBinding.h"
#include "JSNode.h"
#include <runtime/JSObject.h>
#include <runtime/Lookup.h>
#include <wtf/AlwaysInline.h>

namespace WebCore {

class JSDocument : public JSNode {
public:
    typedef JSNode Base;
    static JSDocument* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<Document> impl)
    {
        JSDocument* ptr = new (NotNull, JSC::allocateCell<JSDocument>(globalObject->globalData().heap)) JSDocument(structure, globalObject, impl);
        ptr->finishCreation(globalObject->globalData());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    static bool getOwnPropertySlot(JSC::JSCell*, JSC::ExecState*, JSC::PropertyName, JSC::PropertySlot&);
    static bool getOwnPropertyDescriptor(JSC::JSObject*, JSC::ExecState*, JSC::PropertyName, JSC::PropertyDescriptor&);
    static void put(JSC::JSCell*, JSC::ExecState*, JSC::PropertyName, JSC::JSValue, JSC::PutPropertySlot&);
    static const JSC::ClassInfo s_info;

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);

    // Custom attributes
    JSC::JSValue location(JSC::ExecState*) const;
    void setLocation(JSC::ExecState*, JSC::JSValue);
    Document* impl() const
    {
        return static_cast<Document*>(Base::impl());
    }
protected:
    JSDocument(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<Document>);
    void finishCreation(JSC::JSGlobalData&);
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

ALWAYS_INLINE bool JSDocument::getOwnPropertySlot(JSC::JSCell* cell, JSC::ExecState* exec, JSC::PropertyName propertyName, JSC::PropertySlot& slot)
{
    JSDocument* thisObject = JSC::jsCast<JSDocument*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, &s_info);
    return JSC::getStaticValueSlot<JSDocument, Base>(exec, s_info.staticPropHashTable, thisObject, propertyName, slot);
}

ALWAYS_INLINE bool JSDocument::getOwnPropertyDescriptor(JSC::JSObject* object, JSC::ExecState* exec, JSC::PropertyName propertyName, JSC::PropertyDescriptor& descriptor)
{
    JSDocument* thisObject = JSC::jsCast<JSDocument*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, &s_info);
    return JSC::getStaticValueDescriptor<JSDocument, Base>(exec, s_info.staticPropHashTable, thisObject, propertyName, descriptor);
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, Document*);
Document* toDocument(JSC::JSValue);

class JSDocumentPrototype : public JSC::JSNonFinalObject {
public:
    typedef JSC::JSNonFinalObject Base;
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    static JSDocumentPrototype* create(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSDocumentPrototype* ptr = new (NotNull, JSC::allocateCell<JSDocumentPrototype>(globalData.heap)) JSDocumentPrototype(globalData, globalObject, structure);
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
    JSDocumentPrototype(JSC::JSGlobalData& globalData, JSC::JSGlobalObject*, JSC::Structure* structure) : JSC::JSNonFinalObject(globalData, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

class JSDocumentConstructor : public DOMConstructorObject {
private:
    JSDocumentConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);

public:
    typedef DOMConstructorObject Base;
    static JSDocumentConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSDocumentConstructor* ptr = new (NotNull, JSC::allocateCell<JSDocumentConstructor>(*exec->heap())) JSDocumentConstructor(structure, globalObject);
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

JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateElement(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateDocumentFragment(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateTextNode(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateComment(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateCDATASection(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateProcessingInstruction(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateAttribute(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateEntityReference(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetElementsByTagName(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionImportNode(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateElementNS(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateAttributeNS(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetElementsByTagNameNS(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetElementById(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionAdoptNode(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateEvent(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateRange(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateNodeIterator(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateTreeWalker(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetOverrideStyle(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateExpression(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCreateNSResolver(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionEvaluate(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionExecCommand(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionQueryCommandEnabled(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionQueryCommandIndeterm(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionQueryCommandState(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionQueryCommandSupported(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionQueryCommandValue(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetElementsByName(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionElementFromPoint(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionCaretRangeFromPoint(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetSelection(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetCSSCanvasContext(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionGetElementsByClassName(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionQuerySelector(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionQuerySelectorAll(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionWebkitCancelFullScreen(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionWebkitExitFullscreen(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDocumentPrototypeFunctionWebkitGetFlowByName(JSC::ExecState*);
// Attributes

JSC::JSValue jsDocumentDoctype(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentImplementation(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentDocumentElement(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentInputEncoding(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentXMLEncoding(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentXMLVersion(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentXMLVersion(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentXMLStandalone(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentXMLStandalone(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentDocumentURI(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentDocumentURI(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentDefaultView(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentStyleSheets(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentTitle(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentTitle(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentReferrer(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentDomain(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentDomain(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentURL(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentCookie(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentCookie(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentBody(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentBody(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentHead(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentImages(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentApplets(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentLinks(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentForms(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentAnchors(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentLastModified(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentLocation(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentLocation(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentCharset(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentCharset(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentDefaultCharset(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentReadyState(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentCharacterSet(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentPreferredStylesheetSet(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentSelectedStylesheetSet(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentSelectedStylesheetSet(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentCompatMode(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentWebkitIsFullScreen(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentWebkitFullScreenKeyboardInputAllowed(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentWebkitCurrentFullScreenElement(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentWebkitFullscreenEnabled(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentWebkitFullscreenElement(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
JSC::JSValue jsDocumentOnabort(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnabort(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnblur(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnblur(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnchange(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnchange(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnclick(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnclick(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOncontextmenu(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOncontextmenu(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndblclick(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndblclick(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndrag(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndrag(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndragend(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndragend(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndragenter(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndragenter(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndragleave(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndragleave(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndragover(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndragover(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndragstart(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndragstart(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOndrop(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOndrop(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnerror(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnerror(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnfocus(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnfocus(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOninput(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOninput(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOninvalid(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOninvalid(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnkeydown(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnkeydown(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnkeypress(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnkeypress(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnkeyup(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnkeyup(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnload(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnload(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnmousedown(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnmousedown(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnmousemove(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnmousemove(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnmouseout(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnmouseout(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnmouseover(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnmouseover(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnmouseup(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnmouseup(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnmousewheel(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnmousewheel(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnreadystatechange(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnreadystatechange(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnscroll(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnscroll(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnselect(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnselect(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnsubmit(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnsubmit(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnbeforecut(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnbeforecut(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOncut(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOncut(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnbeforecopy(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnbeforecopy(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOncopy(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOncopy(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnbeforepaste(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnbeforepaste(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnpaste(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnpaste(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnreset(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnreset(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnsearch(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnsearch(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnselectstart(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnselectstart(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsDocumentOnselectionchange(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnselectionchange(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
#if ENABLE(TOUCH_EVENTS)
JSC::JSValue jsDocumentOntouchstart(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOntouchstart(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
#endif
#if ENABLE(TOUCH_EVENTS)
JSC::JSValue jsDocumentOntouchmove(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOntouchmove(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
#endif
#if ENABLE(TOUCH_EVENTS)
JSC::JSValue jsDocumentOntouchend(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOntouchend(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
#endif
#if ENABLE(TOUCH_EVENTS)
JSC::JSValue jsDocumentOntouchcancel(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOntouchcancel(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
#endif
#if ENABLE(FULLSCREEN_API)
JSC::JSValue jsDocumentOnwebkitfullscreenchange(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnwebkitfullscreenchange(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
#endif
#if ENABLE(FULLSCREEN_API)
JSC::JSValue jsDocumentOnwebkitfullscreenerror(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
void setJSDocumentOnwebkitfullscreenerror(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
#endif
#if ENABLE(PAGE_VISIBILITY_API)
JSC::JSValue jsDocumentWebkitVisibilityState(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
#endif
#if ENABLE(PAGE_VISIBILITY_API)
JSC::JSValue jsDocumentWebkitHidden(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);
#endif
JSC::JSValue jsDocumentConstructor(JSC::ExecState*, JSC::JSValue, JSC::PropertyName);

} // namespace WebCore

#endif
