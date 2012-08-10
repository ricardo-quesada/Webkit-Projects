// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


#include "config.h"
#include "InspectorBackendDispatcher.h"
#include <wtf/text/WTFString.h>
#include <wtf/text/CString.h>

#if ENABLE(INSPECTOR)

#include "InspectorAgent.h"
#include "InspectorCSSAgent.h"
#include "InspectorConsoleAgent.h"
#include "InspectorDOMAgent.h"
#include "InspectorFrontendChannel.h"
#include "InspectorPageAgent.h"
#include "InspectorResourceAgent.h"
#include "InspectorRuntimeAgent.h"
#include "InspectorTimelineAgent.h"
#include "InspectorValues.h"
#include "PlatformString.h"

namespace WebCore {

const char* InspectorBackendDispatcher::Page_addScriptToEvaluateOnLoadCmd = "Page.addScriptToEvaluateOnLoad";
const char* InspectorBackendDispatcher::Page_removeAllScriptsToEvaluateOnLoadCmd = "Page.removeAllScriptsToEvaluateOnLoad";
const char* InspectorBackendDispatcher::Page_reloadCmd = "Page.reload";
const char* InspectorBackendDispatcher::Page_openCmd = "Page.open";
const char* InspectorBackendDispatcher::Page_getCookiesCmd = "Page.getCookies";
const char* InspectorBackendDispatcher::Page_deleteCookieCmd = "Page.deleteCookie";
const char* InspectorBackendDispatcher::Page_getResourceTreeCmd = "Page.getResourceTree";
const char* InspectorBackendDispatcher::Page_getResourceContentCmd = "Page.getResourceContent";
const char* InspectorBackendDispatcher::Page_searchInResourcesCmd = "Page.searchInResources";
const char* InspectorBackendDispatcher::Runtime_evaluateCmd = "Runtime.evaluate";
const char* InspectorBackendDispatcher::Runtime_evaluateOnCmd = "Runtime.evaluateOn";
const char* InspectorBackendDispatcher::Runtime_getPropertiesCmd = "Runtime.getProperties";
const char* InspectorBackendDispatcher::Runtime_setPropertyValueCmd = "Runtime.setPropertyValue";
const char* InspectorBackendDispatcher::Runtime_releaseObjectCmd = "Runtime.releaseObject";
const char* InspectorBackendDispatcher::Runtime_releaseObjectGroupCmd = "Runtime.releaseObjectGroup";
const char* InspectorBackendDispatcher::Console_enableCmd = "Console.enable";
const char* InspectorBackendDispatcher::Console_disableCmd = "Console.disable";
const char* InspectorBackendDispatcher::Console_clearConsoleMessagesCmd = "Console.clearConsoleMessages";
const char* InspectorBackendDispatcher::Console_setMonitoringXHREnabledCmd = "Console.setMonitoringXHREnabled";
const char* InspectorBackendDispatcher::Console_addInspectedNodeCmd = "Console.addInspectedNode";
const char* InspectorBackendDispatcher::Network_enableCmd = "Network.enable";
const char* InspectorBackendDispatcher::Network_disableCmd = "Network.disable";
const char* InspectorBackendDispatcher::Network_setUserAgentOverrideCmd = "Network.setUserAgentOverride";
const char* InspectorBackendDispatcher::Network_setExtraHeadersCmd = "Network.setExtraHeaders";
const char* InspectorBackendDispatcher::DOM_getDocumentCmd = "DOM.getDocument";
const char* InspectorBackendDispatcher::DOM_getChildNodesCmd = "DOM.getChildNodes";
const char* InspectorBackendDispatcher::DOM_querySelectorCmd = "DOM.querySelector";
const char* InspectorBackendDispatcher::DOM_querySelectorAllCmd = "DOM.querySelectorAll";
const char* InspectorBackendDispatcher::DOM_setNodeNameCmd = "DOM.setNodeName";
const char* InspectorBackendDispatcher::DOM_setNodeValueCmd = "DOM.setNodeValue";
const char* InspectorBackendDispatcher::DOM_removeNodeCmd = "DOM.removeNode";
const char* InspectorBackendDispatcher::DOM_setAttributeCmd = "DOM.setAttribute";
const char* InspectorBackendDispatcher::DOM_removeAttributeCmd = "DOM.removeAttribute";
const char* InspectorBackendDispatcher::DOM_getEventListenersForNodeCmd = "DOM.getEventListenersForNode";
const char* InspectorBackendDispatcher::DOM_copyNodeCmd = "DOM.copyNode";
const char* InspectorBackendDispatcher::DOM_getOuterHTMLCmd = "DOM.getOuterHTML";
const char* InspectorBackendDispatcher::DOM_setOuterHTMLCmd = "DOM.setOuterHTML";
const char* InspectorBackendDispatcher::DOM_performSearchCmd = "DOM.performSearch";
const char* InspectorBackendDispatcher::DOM_cancelSearchCmd = "DOM.cancelSearch";
const char* InspectorBackendDispatcher::DOM_pushNodeToFrontendCmd = "DOM.pushNodeToFrontend";
const char* InspectorBackendDispatcher::DOM_setInspectModeEnabledCmd = "DOM.setInspectModeEnabled";
const char* InspectorBackendDispatcher::DOM_highlightNodeCmd = "DOM.highlightNode";
const char* InspectorBackendDispatcher::DOM_hideNodeHighlightCmd = "DOM.hideNodeHighlight";
const char* InspectorBackendDispatcher::DOM_highlightFrameCmd = "DOM.highlightFrame";
const char* InspectorBackendDispatcher::DOM_hideFrameHighlightCmd = "DOM.hideFrameHighlight";
const char* InspectorBackendDispatcher::DOM_pushNodeByPathToFrontendCmd = "DOM.pushNodeByPathToFrontend";
const char* InspectorBackendDispatcher::DOM_resolveNodeCmd = "DOM.resolveNode";
const char* InspectorBackendDispatcher::CSS_getStylesForNodeCmd = "CSS.getStylesForNode";
const char* InspectorBackendDispatcher::CSS_getComputedStyleForNodeCmd = "CSS.getComputedStyleForNode";
const char* InspectorBackendDispatcher::CSS_getInlineStyleForNodeCmd = "CSS.getInlineStyleForNode";
const char* InspectorBackendDispatcher::CSS_getAllStyleSheetsCmd = "CSS.getAllStyleSheets";
const char* InspectorBackendDispatcher::CSS_getStyleSheetCmd = "CSS.getStyleSheet";
const char* InspectorBackendDispatcher::CSS_getStyleSheetTextCmd = "CSS.getStyleSheetText";
const char* InspectorBackendDispatcher::CSS_setStyleSheetTextCmd = "CSS.setStyleSheetText";
const char* InspectorBackendDispatcher::CSS_setPropertyTextCmd = "CSS.setPropertyText";
const char* InspectorBackendDispatcher::CSS_togglePropertyCmd = "CSS.toggleProperty";
const char* InspectorBackendDispatcher::CSS_setRuleSelectorCmd = "CSS.setRuleSelector";
const char* InspectorBackendDispatcher::CSS_addRuleCmd = "CSS.addRule";
const char* InspectorBackendDispatcher::CSS_getSupportedCSSPropertiesCmd = "CSS.getSupportedCSSProperties";
const char* InspectorBackendDispatcher::Timeline_startCmd = "Timeline.start";
const char* InspectorBackendDispatcher::Timeline_stopCmd = "Timeline.stop";

void InspectorBackendDispatcher::Page_addScriptToEvaluateOnLoad(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_scriptSource = getString(paramsContainer.get(), "scriptSource", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_pageAgent->addScriptToEvaluateOnLoad(&error, in_scriptSource);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_removeAllScriptsToEvaluateOnLoad(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_pageAgent->removeAllScriptsToEvaluateOnLoad(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_reload(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        bool in_ignoreCache = getBoolean(paramsContainer.get(), "ignoreCache", true, protocolErrors.get());

        if (!protocolErrors->length())
            m_pageAgent->reload(&error, &in_ignoreCache);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_open(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_url = getString(paramsContainer.get(), "url", false, protocolErrors.get());
        bool in_newWindow = getBoolean(paramsContainer.get(), "newWindow", true, protocolErrors.get());

        if (!protocolErrors->length())
            m_pageAgent->open(&error, in_url, &in_newWindow);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_getCookies(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    RefPtr<InspectorArray> out_cookies = InspectorArray::create();
    String out_cookiesString = "";

    ErrorString error;

    if (!protocolErrors->length())
        m_pageAgent->getCookies(&error, &out_cookies, &out_cookiesString);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setArray("cookies", out_cookies);
        result->setString("cookiesString", out_cookiesString);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_deleteCookie(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_cookieName = getString(paramsContainer.get(), "cookieName", false, protocolErrors.get());
        String in_domain = getString(paramsContainer.get(), "domain", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_pageAgent->deleteCookie(&error, in_cookieName, in_domain);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_getResourceTree(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    RefPtr<InspectorObject> out_frameTree = InspectorObject::create();

    ErrorString error;

    if (!protocolErrors->length())
        m_pageAgent->getResourceTree(&error, &out_frameTree);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("frameTree", out_frameTree);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_getResourceContent(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    String out_content = "";

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_frameId = getString(paramsContainer.get(), "frameId", false, protocolErrors.get());
        String in_url = getString(paramsContainer.get(), "url", false, protocolErrors.get());
        bool in_base64Encode = getBoolean(paramsContainer.get(), "base64Encode", true, protocolErrors.get());

        if (!protocolErrors->length())
            m_pageAgent->getResourceContent(&error, in_frameId, in_url, &in_base64Encode, &out_content);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setString("content", out_content);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Page_searchInResources(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_pageAgent)
        protocolErrors->pushString("Page handler is not available.");

    RefPtr<InspectorArray> out_result = InspectorArray::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_text = getString(paramsContainer.get(), "text", false, protocolErrors.get());
        bool in_caseSensitive = getBoolean(paramsContainer.get(), "caseSensitive", true, protocolErrors.get());
        bool in_isRegex = getBoolean(paramsContainer.get(), "isRegex", true, protocolErrors.get());

        if (!protocolErrors->length())
            m_pageAgent->searchInResources(&error, in_text, &in_caseSensitive, &in_isRegex, &out_result);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setArray("result", out_result);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Runtime_evaluate(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_runtimeAgent)
        protocolErrors->pushString("Runtime handler is not available.");

    RefPtr<InspectorObject> out_result = InspectorObject::create();
    bool out_wasThrown = false;

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_expression = getString(paramsContainer.get(), "expression", false, protocolErrors.get());
        String in_objectGroup = getString(paramsContainer.get(), "objectGroup", true, protocolErrors.get());
        bool in_includeCommandLineAPI = getBoolean(paramsContainer.get(), "includeCommandLineAPI", true, protocolErrors.get());

        if (!protocolErrors->length())
            m_runtimeAgent->evaluate(&error, in_expression, &in_objectGroup, &in_includeCommandLineAPI, &out_result, &out_wasThrown);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("result", out_result);
        if (out_wasThrown)
            result->setBoolean("wasThrown", out_wasThrown);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Runtime_evaluateOn(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_runtimeAgent)
        protocolErrors->pushString("Runtime handler is not available.");

    RefPtr<InspectorObject> out_result = InspectorObject::create();
    bool out_wasThrown = false;

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_objectId = getString(paramsContainer.get(), "objectId", false, protocolErrors.get());
        String in_expression = getString(paramsContainer.get(), "expression", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_runtimeAgent->evaluateOn(&error, in_objectId, in_expression, &out_result, &out_wasThrown);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("result", out_result);
        if (out_wasThrown)
            result->setBoolean("wasThrown", out_wasThrown);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Runtime_getProperties(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_runtimeAgent)
        protocolErrors->pushString("Runtime handler is not available.");

    RefPtr<InspectorArray> out_result = InspectorArray::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_objectId = getString(paramsContainer.get(), "objectId", false, protocolErrors.get());
        bool in_ignoreHasOwnProperty = getBoolean(paramsContainer.get(), "ignoreHasOwnProperty", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_runtimeAgent->getProperties(&error, in_objectId, in_ignoreHasOwnProperty, &out_result);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setArray("result", out_result);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Runtime_setPropertyValue(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_runtimeAgent)
        protocolErrors->pushString("Runtime handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_objectId = getString(paramsContainer.get(), "objectId", false, protocolErrors.get());
        String in_propertyName = getString(paramsContainer.get(), "propertyName", false, protocolErrors.get());
        String in_expression = getString(paramsContainer.get(), "expression", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_runtimeAgent->setPropertyValue(&error, in_objectId, in_propertyName, in_expression);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Runtime_releaseObject(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_runtimeAgent)
        protocolErrors->pushString("Runtime handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_objectId = getString(paramsContainer.get(), "objectId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_runtimeAgent->releaseObject(&error, in_objectId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Runtime_releaseObjectGroup(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_runtimeAgent)
        protocolErrors->pushString("Runtime handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_objectGroup = getString(paramsContainer.get(), "objectGroup", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_runtimeAgent->releaseObjectGroup(&error, in_objectGroup);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Console_enable(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_consoleAgent)
        protocolErrors->pushString("Console handler is not available.");

    int out_expiredMessagesCount = 0;

    ErrorString error;

    if (!protocolErrors->length())
        m_consoleAgent->enable(&error, &out_expiredMessagesCount);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setNumber("expiredMessagesCount", out_expiredMessagesCount);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Console_disable(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_consoleAgent)
        protocolErrors->pushString("Console handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_consoleAgent->disable(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Console_clearConsoleMessages(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_consoleAgent)
        protocolErrors->pushString("Console handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_consoleAgent->clearConsoleMessages(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Console_setMonitoringXHREnabled(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_consoleAgent)
        protocolErrors->pushString("Console handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        bool in_enabled = getBoolean(paramsContainer.get(), "enabled", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_consoleAgent->setMonitoringXHREnabled(&error, in_enabled);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Console_addInspectedNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_consoleAgent)
        protocolErrors->pushString("Console handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_consoleAgent->addInspectedNode(&error, in_nodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Network_enable(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_resourceAgent)
        protocolErrors->pushString("Network handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_resourceAgent->enable(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Network_disable(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_resourceAgent)
        protocolErrors->pushString("Network handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_resourceAgent->disable(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Network_setUserAgentOverride(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_resourceAgent)
        protocolErrors->pushString("Network handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_userAgent = getString(paramsContainer.get(), "userAgent", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_resourceAgent->setUserAgentOverride(&error, in_userAgent);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Network_setExtraHeaders(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_resourceAgent)
        protocolErrors->pushString("Network handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        RefPtr<InspectorObject> in_headers = getObject(paramsContainer.get(), "headers", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_resourceAgent->setExtraHeaders(&error, in_headers);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_getDocument(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    RefPtr<InspectorObject> out_root = InspectorObject::create();

    ErrorString error;

    if (!protocolErrors->length())
        m_domAgent->getDocument(&error, &out_root);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("root", out_root);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_getChildNodes(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->getChildNodes(&error, in_nodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_querySelector(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    int out_nodeId = 0;

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_selectors = getString(paramsContainer.get(), "selectors", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->querySelector(&error, in_nodeId, in_selectors, &out_nodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setNumber("nodeId", out_nodeId);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_querySelectorAll(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    RefPtr<InspectorArray> out_nodeIds = InspectorArray::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_selectors = getString(paramsContainer.get(), "selectors", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->querySelectorAll(&error, in_nodeId, in_selectors, &out_nodeIds);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setArray("nodeIds", out_nodeIds);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_setNodeName(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    int out_outNodeId = 0;

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_name = getString(paramsContainer.get(), "name", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->setNodeName(&error, in_nodeId, in_name, &out_outNodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setNumber("outNodeId", out_outNodeId);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_setNodeValue(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_value = getString(paramsContainer.get(), "value", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->setNodeValue(&error, in_nodeId, in_value);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_removeNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->removeNode(&error, in_nodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_setAttribute(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_name = getString(paramsContainer.get(), "name", false, protocolErrors.get());
        String in_value = getString(paramsContainer.get(), "value", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->setAttribute(&error, in_nodeId, in_name, in_value);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_removeAttribute(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_name = getString(paramsContainer.get(), "name", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->removeAttribute(&error, in_nodeId, in_name);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_getEventListenersForNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    RefPtr<InspectorArray> out_listeners = InspectorArray::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->getEventListenersForNode(&error, in_nodeId, &out_listeners);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setArray("listeners", out_listeners);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_copyNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->copyNode(&error, in_nodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_getOuterHTML(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    String out_outerHTML = "";

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->getOuterHTML(&error, in_nodeId, &out_outerHTML);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setString("outerHTML", out_outerHTML);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_setOuterHTML(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    int out_newNodeId = 0;

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_outerHTML = getString(paramsContainer.get(), "outerHTML", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->setOuterHTML(&error, in_nodeId, in_outerHTML, &out_newNodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setNumber("newNodeId", out_newNodeId);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_performSearch(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_query = getString(paramsContainer.get(), "query", false, protocolErrors.get());
        bool in_runSynchronously = getBoolean(paramsContainer.get(), "runSynchronously", true, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->performSearch(&error, in_query, &in_runSynchronously);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_cancelSearch(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_domAgent->cancelSearch(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_pushNodeToFrontend(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    int out_nodeId = 0;

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_objectId = getString(paramsContainer.get(), "objectId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->pushNodeToFrontend(&error, in_objectId, &out_nodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setNumber("nodeId", out_nodeId);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_setInspectModeEnabled(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        bool in_enabled = getBoolean(paramsContainer.get(), "enabled", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->setInspectModeEnabled(&error, in_enabled);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_highlightNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());
        String in_mode = getString(paramsContainer.get(), "mode", true, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->highlightNode(&error, in_nodeId, &in_mode);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_hideNodeHighlight(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_domAgent->hideNodeHighlight(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_highlightFrame(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_frameId = getString(paramsContainer.get(), "frameId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->highlightFrame(&error, in_frameId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_hideFrameHighlight(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_domAgent->hideFrameHighlight(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_pushNodeByPathToFrontend(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    int out_nodeId = 0;

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_path = getString(paramsContainer.get(), "path", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->pushNodeByPathToFrontend(&error, in_path, &out_nodeId);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setNumber("nodeId", out_nodeId);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::DOM_resolveNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_domAgent)
        protocolErrors->pushString("DOM handler is not available.");

    RefPtr<InspectorObject> out_object = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_domAgent->resolveNode(&error, in_nodeId, &out_object);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("object", out_object);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_getStylesForNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_styles = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->getStylesForNode(&error, in_nodeId, &out_styles);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("styles", out_styles);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_getComputedStyleForNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_style = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->getComputedStyleForNode(&error, in_nodeId, &out_style);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("style", out_style);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_getInlineStyleForNode(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_style = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_nodeId = getInt(paramsContainer.get(), "nodeId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->getInlineStyleForNode(&error, in_nodeId, &out_style);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("style", out_style);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_getAllStyleSheets(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorArray> out_headers = InspectorArray::create();

    ErrorString error;

    if (!protocolErrors->length())
        m_cssAgent->getAllStyleSheets(&error, &out_headers);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setArray("headers", out_headers);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_getStyleSheet(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_styleSheet = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_styleSheetId = getString(paramsContainer.get(), "styleSheetId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->getStyleSheet(&error, in_styleSheetId, &out_styleSheet);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("styleSheet", out_styleSheet);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_getStyleSheetText(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    String out_text = "";

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_styleSheetId = getString(paramsContainer.get(), "styleSheetId", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->getStyleSheetText(&error, in_styleSheetId, &out_text);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setString("text", out_text);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_setStyleSheetText(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        String in_styleSheetId = getString(paramsContainer.get(), "styleSheetId", false, protocolErrors.get());
        String in_text = getString(paramsContainer.get(), "text", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->setStyleSheetText(&error, in_styleSheetId, in_text);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_setPropertyText(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_style = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        RefPtr<InspectorObject> in_styleId = getObject(paramsContainer.get(), "styleId", false, protocolErrors.get());
        int in_propertyIndex = getInt(paramsContainer.get(), "propertyIndex", false, protocolErrors.get());
        String in_text = getString(paramsContainer.get(), "text", false, protocolErrors.get());
        bool in_overwrite = getBoolean(paramsContainer.get(), "overwrite", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->setPropertyText(&error, in_styleId, in_propertyIndex, in_text, in_overwrite, &out_style);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("style", out_style);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_toggleProperty(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_style = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        RefPtr<InspectorObject> in_styleId = getObject(paramsContainer.get(), "styleId", false, protocolErrors.get());
        int in_propertyIndex = getInt(paramsContainer.get(), "propertyIndex", false, protocolErrors.get());
        bool in_disable = getBoolean(paramsContainer.get(), "disable", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->toggleProperty(&error, in_styleId, in_propertyIndex, in_disable, &out_style);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("style", out_style);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_setRuleSelector(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_rule = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        RefPtr<InspectorObject> in_ruleId = getObject(paramsContainer.get(), "ruleId", false, protocolErrors.get());
        String in_selector = getString(paramsContainer.get(), "selector", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->setRuleSelector(&error, in_ruleId, in_selector, &out_rule);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("rule", out_rule);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_addRule(long callId, InspectorObject* requestMessageObject)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorObject> out_rule = InspectorObject::create();

    ErrorString error;

    if (RefPtr<InspectorObject> paramsContainer = requestMessageObject->getObject("params")) {
        int in_contextNodeId = getInt(paramsContainer.get(), "contextNodeId", false, protocolErrors.get());
        String in_selector = getString(paramsContainer.get(), "selector", false, protocolErrors.get());

        if (!protocolErrors->length())
            m_cssAgent->addRule(&error, in_contextNodeId, in_selector, &out_rule);
    } else
        protocolErrors->pushString("'params' property with type 'object' was not found.");

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setObject("rule", out_rule);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::CSS_getSupportedCSSProperties(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_cssAgent)
        protocolErrors->pushString("CSS handler is not available.");

    RefPtr<InspectorArray> out_cssProperties = InspectorArray::create();

    ErrorString error;

    if (!protocolErrors->length())
        m_cssAgent->getSupportedCSSProperties(&error, &out_cssProperties);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
        result->setArray("cssProperties", out_cssProperties);
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Timeline_start(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_timelineAgent)
        protocolErrors->pushString("Timeline handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_timelineAgent->start(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::Timeline_stop(long callId, InspectorObject*)
{
    RefPtr<InspectorArray> protocolErrors = InspectorArray::create();

    if (!m_timelineAgent)
        protocolErrors->pushString("Timeline handler is not available.");

    ErrorString error;

    if (!protocolErrors->length())
        m_timelineAgent->stop(&error);

    // use InspectorFrontend as a marker of WebInspector availability

    if (protocolErrors->length()) {
        reportProtocolError(&callId, InvalidParams, protocolErrors);
        return;
    }

    if (error.length()) {
        reportProtocolError(&callId, ServerError, error);
        return;
    }

    RefPtr<InspectorObject> responseMessage = InspectorObject::create();
    RefPtr<InspectorObject> result = InspectorObject::create();
    responseMessage->setObject("result", result);

    responseMessage->setNumber("id", callId);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseMessage->toJSONString());
}

void InspectorBackendDispatcher::dispatch(const String& message)
{
    RefPtr<InspectorBackendDispatcher> protect = this;
    typedef void (InspectorBackendDispatcher::*CallHandler)(long callId, InspectorObject* messageObject);
    typedef HashMap<String, CallHandler> DispatchMap;
    DEFINE_STATIC_LOCAL(DispatchMap, dispatchMap, );
    long callId = 0;

    if (dispatchMap.isEmpty()) {
        dispatchMap.add(Page_addScriptToEvaluateOnLoadCmd, &InspectorBackendDispatcher::Page_addScriptToEvaluateOnLoad);
        dispatchMap.add(Page_removeAllScriptsToEvaluateOnLoadCmd, &InspectorBackendDispatcher::Page_removeAllScriptsToEvaluateOnLoad);
        dispatchMap.add(Page_reloadCmd, &InspectorBackendDispatcher::Page_reload);
        dispatchMap.add(Page_openCmd, &InspectorBackendDispatcher::Page_open);
        dispatchMap.add(Page_getCookiesCmd, &InspectorBackendDispatcher::Page_getCookies);
        dispatchMap.add(Page_deleteCookieCmd, &InspectorBackendDispatcher::Page_deleteCookie);
        dispatchMap.add(Page_getResourceTreeCmd, &InspectorBackendDispatcher::Page_getResourceTree);
        dispatchMap.add(Page_getResourceContentCmd, &InspectorBackendDispatcher::Page_getResourceContent);
        dispatchMap.add(Page_searchInResourcesCmd, &InspectorBackendDispatcher::Page_searchInResources);
        dispatchMap.add(Runtime_evaluateCmd, &InspectorBackendDispatcher::Runtime_evaluate);
        dispatchMap.add(Runtime_evaluateOnCmd, &InspectorBackendDispatcher::Runtime_evaluateOn);
        dispatchMap.add(Runtime_getPropertiesCmd, &InspectorBackendDispatcher::Runtime_getProperties);
        dispatchMap.add(Runtime_setPropertyValueCmd, &InspectorBackendDispatcher::Runtime_setPropertyValue);
        dispatchMap.add(Runtime_releaseObjectCmd, &InspectorBackendDispatcher::Runtime_releaseObject);
        dispatchMap.add(Runtime_releaseObjectGroupCmd, &InspectorBackendDispatcher::Runtime_releaseObjectGroup);
        dispatchMap.add(Console_enableCmd, &InspectorBackendDispatcher::Console_enable);
        dispatchMap.add(Console_disableCmd, &InspectorBackendDispatcher::Console_disable);
        dispatchMap.add(Console_clearConsoleMessagesCmd, &InspectorBackendDispatcher::Console_clearConsoleMessages);
        dispatchMap.add(Console_setMonitoringXHREnabledCmd, &InspectorBackendDispatcher::Console_setMonitoringXHREnabled);
        dispatchMap.add(Console_addInspectedNodeCmd, &InspectorBackendDispatcher::Console_addInspectedNode);
        dispatchMap.add(Network_enableCmd, &InspectorBackendDispatcher::Network_enable);
        dispatchMap.add(Network_disableCmd, &InspectorBackendDispatcher::Network_disable);
        dispatchMap.add(Network_setUserAgentOverrideCmd, &InspectorBackendDispatcher::Network_setUserAgentOverride);
        dispatchMap.add(Network_setExtraHeadersCmd, &InspectorBackendDispatcher::Network_setExtraHeaders);
        dispatchMap.add(DOM_getDocumentCmd, &InspectorBackendDispatcher::DOM_getDocument);
        dispatchMap.add(DOM_getChildNodesCmd, &InspectorBackendDispatcher::DOM_getChildNodes);
        dispatchMap.add(DOM_querySelectorCmd, &InspectorBackendDispatcher::DOM_querySelector);
        dispatchMap.add(DOM_querySelectorAllCmd, &InspectorBackendDispatcher::DOM_querySelectorAll);
        dispatchMap.add(DOM_setNodeNameCmd, &InspectorBackendDispatcher::DOM_setNodeName);
        dispatchMap.add(DOM_setNodeValueCmd, &InspectorBackendDispatcher::DOM_setNodeValue);
        dispatchMap.add(DOM_removeNodeCmd, &InspectorBackendDispatcher::DOM_removeNode);
        dispatchMap.add(DOM_setAttributeCmd, &InspectorBackendDispatcher::DOM_setAttribute);
        dispatchMap.add(DOM_removeAttributeCmd, &InspectorBackendDispatcher::DOM_removeAttribute);
        dispatchMap.add(DOM_getEventListenersForNodeCmd, &InspectorBackendDispatcher::DOM_getEventListenersForNode);
        dispatchMap.add(DOM_copyNodeCmd, &InspectorBackendDispatcher::DOM_copyNode);
        dispatchMap.add(DOM_getOuterHTMLCmd, &InspectorBackendDispatcher::DOM_getOuterHTML);
        dispatchMap.add(DOM_setOuterHTMLCmd, &InspectorBackendDispatcher::DOM_setOuterHTML);
        dispatchMap.add(DOM_performSearchCmd, &InspectorBackendDispatcher::DOM_performSearch);
        dispatchMap.add(DOM_cancelSearchCmd, &InspectorBackendDispatcher::DOM_cancelSearch);
        dispatchMap.add(DOM_pushNodeToFrontendCmd, &InspectorBackendDispatcher::DOM_pushNodeToFrontend);
        dispatchMap.add(DOM_setInspectModeEnabledCmd, &InspectorBackendDispatcher::DOM_setInspectModeEnabled);
        dispatchMap.add(DOM_highlightNodeCmd, &InspectorBackendDispatcher::DOM_highlightNode);
        dispatchMap.add(DOM_hideNodeHighlightCmd, &InspectorBackendDispatcher::DOM_hideNodeHighlight);
        dispatchMap.add(DOM_highlightFrameCmd, &InspectorBackendDispatcher::DOM_highlightFrame);
        dispatchMap.add(DOM_hideFrameHighlightCmd, &InspectorBackendDispatcher::DOM_hideFrameHighlight);
        dispatchMap.add(DOM_pushNodeByPathToFrontendCmd, &InspectorBackendDispatcher::DOM_pushNodeByPathToFrontend);
        dispatchMap.add(DOM_resolveNodeCmd, &InspectorBackendDispatcher::DOM_resolveNode);
        dispatchMap.add(CSS_getStylesForNodeCmd, &InspectorBackendDispatcher::CSS_getStylesForNode);
        dispatchMap.add(CSS_getComputedStyleForNodeCmd, &InspectorBackendDispatcher::CSS_getComputedStyleForNode);
        dispatchMap.add(CSS_getInlineStyleForNodeCmd, &InspectorBackendDispatcher::CSS_getInlineStyleForNode);
        dispatchMap.add(CSS_getAllStyleSheetsCmd, &InspectorBackendDispatcher::CSS_getAllStyleSheets);
        dispatchMap.add(CSS_getStyleSheetCmd, &InspectorBackendDispatcher::CSS_getStyleSheet);
        dispatchMap.add(CSS_getStyleSheetTextCmd, &InspectorBackendDispatcher::CSS_getStyleSheetText);
        dispatchMap.add(CSS_setStyleSheetTextCmd, &InspectorBackendDispatcher::CSS_setStyleSheetText);
        dispatchMap.add(CSS_setPropertyTextCmd, &InspectorBackendDispatcher::CSS_setPropertyText);
        dispatchMap.add(CSS_togglePropertyCmd, &InspectorBackendDispatcher::CSS_toggleProperty);
        dispatchMap.add(CSS_setRuleSelectorCmd, &InspectorBackendDispatcher::CSS_setRuleSelector);
        dispatchMap.add(CSS_addRuleCmd, &InspectorBackendDispatcher::CSS_addRule);
        dispatchMap.add(CSS_getSupportedCSSPropertiesCmd, &InspectorBackendDispatcher::CSS_getSupportedCSSProperties);
        dispatchMap.add(Timeline_startCmd, &InspectorBackendDispatcher::Timeline_start);
        dispatchMap.add(Timeline_stopCmd, &InspectorBackendDispatcher::Timeline_stop);
    }

    RefPtr<InspectorValue> parsedMessage = InspectorValue::parseJSON(message);
    if (!parsedMessage) {
        reportProtocolError(0, ParseError, "Message should be in JSON format.");
        return;
    }

    RefPtr<InspectorObject> messageObject = parsedMessage->asObject();
    if (!messageObject) {
        reportProtocolError(0, InvalidRequest, "Invalid message format. The message should be a JSONified object.");
        return;
    }

    RefPtr<InspectorValue> callIdValue = messageObject->get("id");
    if (!callIdValue) {
        reportProtocolError(0, InvalidRequest, "Invalid message format. 'id' property was not found in the request.");
        return;
    }

    if (!callIdValue->asNumber(&callId)) {
        reportProtocolError(0, InvalidRequest, "Invalid message format. The type of 'id' property should be number.");
        return;
    }

    RefPtr<InspectorValue> methodValue = messageObject->get("method");
    if (!methodValue) {
        reportProtocolError(&callId, InvalidRequest, "Invalid message format. 'method' property wasn't found.");
        return;
    }

    String method;
    if (!methodValue->asString(&method)) {
        reportProtocolError(&callId, InvalidRequest, "Invalid message format. The type of 'method' property should be string.");
        return;
    }

    HashMap<String, CallHandler>::iterator it = dispatchMap.find(method);
    if (it == dispatchMap.end()) {
        reportProtocolError(&callId, MethodNotFound, "Invalid method name was received. '" + method + "' wasn't found.");
        return;
    }

    ((*this).*it->second)(callId, messageObject.get());
}

void InspectorBackendDispatcher::reportProtocolError(const long* const callId, CommonErrorCode code, const String& customText) const
{
    RefPtr<InspectorArray> data = InspectorArray::create();
    data->pushString(customText);
    reportProtocolError(callId, code, data.release());
}

void InspectorBackendDispatcher::reportProtocolError(const long* const callId, CommonErrorCode code, PassRefPtr<InspectorArray> data) const
{
    DEFINE_STATIC_LOCAL(Vector<String>,s_commonErrors,);
    if (!s_commonErrors.size()) {
        s_commonErrors.insert(ParseError, "{\"code\":-32700,\"message\":\"Parse error.\"}");
        s_commonErrors.insert(InvalidRequest, "{\"code\":-32600,\"message\":\"Invalid Request.\"}");
        s_commonErrors.insert(MethodNotFound, "{\"code\":-32601,\"message\":\"Method not found.\"}");
        s_commonErrors.insert(InvalidParams, "{\"code\":-32602,\"message\":\"Invalid params.\"}");
        s_commonErrors.insert(InternalError, "{\"code\":-32603,\"message\":\"Internal error.\"}");
        s_commonErrors.insert(ServerError, "{\"code\":-32000,\"message\":\"Server error.\"}");
    }
    ASSERT(code >=0);
    ASSERT((unsigned)code < s_commonErrors.size());
    ASSERT(s_commonErrors[code]);
    ASSERT(InspectorObject::parseJSON(s_commonErrors[code]));
    RefPtr<InspectorObject> error = InspectorObject::parseJSON(s_commonErrors[code])->asObject();
    ASSERT(error);
    error->setArray("data", data);
    RefPtr<InspectorObject> message = InspectorObject::create();
    message->setObject("error", error);
    if (callId)
        message->setNumber("id", *callId);
    else
        message->setValue("id", InspectorValue::null());
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(message->toJSONString());
}

PassRefPtr<InspectorArray> InspectorBackendDispatcher::getArray(InspectorObject* object, const String& name, bool optional, InspectorArray* protocolErrors)
{
    ASSERT(object);
    ASSERT(protocolErrors);

    RefPtr<InspectorArray> value = InspectorArray::create();
    InspectorObject::const_iterator end = object->end();
    InspectorObject::const_iterator valueIterator = object->find(name);

    if (valueIterator == end) {
        if (!optional)
            protocolErrors->pushString(String::format("Parameter '%s' with type 'Array' was not found.", name.utf8().data()));
        return value;
    }

    if (!valueIterator->second->asArray(&value))
        protocolErrors->pushString(String::format("Parameter '%s' has wrong type. It should be 'Array'.", name.utf8().data()));
    return value;
}

int InspectorBackendDispatcher::getInt(InspectorObject* object, const String& name, bool optional, InspectorArray* protocolErrors)
{
    ASSERT(object);
    ASSERT(protocolErrors);

    int value = 0;
    InspectorObject::const_iterator end = object->end();
    InspectorObject::const_iterator valueIterator = object->find(name);

    if (valueIterator == end) {
        if (!optional)
            protocolErrors->pushString(String::format("Parameter '%s' with type 'Number' was not found.", name.utf8().data()));
        return value;
    }

    if (!valueIterator->second->asNumber(&value))
        protocolErrors->pushString(String::format("Parameter '%s' has wrong type. It should be 'Number'.", name.utf8().data()));
    return value;
}

String InspectorBackendDispatcher::getString(InspectorObject* object, const String& name, bool optional, InspectorArray* protocolErrors)
{
    ASSERT(object);
    ASSERT(protocolErrors);

    String value = "";
    InspectorObject::const_iterator end = object->end();
    InspectorObject::const_iterator valueIterator = object->find(name);

    if (valueIterator == end) {
        if (!optional)
            protocolErrors->pushString(String::format("Parameter '%s' with type 'String' was not found.", name.utf8().data()));
        return value;
    }

    if (!valueIterator->second->asString(&value))
        protocolErrors->pushString(String::format("Parameter '%s' has wrong type. It should be 'String'.", name.utf8().data()));
    return value;
}

bool InspectorBackendDispatcher::getBoolean(InspectorObject* object, const String& name, bool optional, InspectorArray* protocolErrors)
{
    ASSERT(object);
    ASSERT(protocolErrors);

    bool value = false;
    InspectorObject::const_iterator end = object->end();
    InspectorObject::const_iterator valueIterator = object->find(name);

    if (valueIterator == end) {
        if (!optional)
            protocolErrors->pushString(String::format("Parameter '%s' with type 'Boolean' was not found.", name.utf8().data()));
        return value;
    }

    if (!valueIterator->second->asBoolean(&value))
        protocolErrors->pushString(String::format("Parameter '%s' has wrong type. It should be 'Boolean'.", name.utf8().data()));
    return value;
}

PassRefPtr<InspectorObject> InspectorBackendDispatcher::getObject(InspectorObject* object, const String& name, bool optional, InspectorArray* protocolErrors)
{
    ASSERT(object);
    ASSERT(protocolErrors);

    RefPtr<InspectorObject> value = InspectorObject::create();
    InspectorObject::const_iterator end = object->end();
    InspectorObject::const_iterator valueIterator = object->find(name);

    if (valueIterator == end) {
        if (!optional)
            protocolErrors->pushString(String::format("Parameter '%s' with type 'Object' was not found.", name.utf8().data()));
        return value;
    }

    if (!valueIterator->second->asObject(&value))
        protocolErrors->pushString(String::format("Parameter '%s' has wrong type. It should be 'Object'.", name.utf8().data()));
    return value;
}
bool InspectorBackendDispatcher::getCommandName(const String& message, String* result)
{
    RefPtr<InspectorValue> value = InspectorValue::parseJSON(message);
    if (!value)
        return false;

    RefPtr<InspectorObject> object = value->asObject();
    if (!object)
        return false;

    if (!object->getString("method", result))
        return false;

    return true;
}


} // namespace WebCore

#endif // ENABLE(INSPECTOR)
