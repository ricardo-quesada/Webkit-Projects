// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


#include "config.h"
#include "InspectorFrontend.h"
#include <wtf/text/WTFString.h>
#include <wtf/text/CString.h>

#if ENABLE(INSPECTOR)

#include "InspectorFrontendChannel.h"
#include "InspectorValues.h"
#include "PlatformString.h"

namespace WebCore {



InspectorFrontend::InspectorFrontend(InspectorFrontendChannel* inspectorFrontendChannel)
    : m_inspectorFrontendChannel(inspectorFrontendChannel)
    , m_inspector(inspectorFrontendChannel)
    , m_page(inspectorFrontendChannel)
    , m_console(inspectorFrontendChannel)
    , m_network(inspectorFrontendChannel)
    , m_dom(inspectorFrontendChannel)
    , m_timeline(inspectorFrontendChannel)
{
}

void InspectorFrontend::Inspector::frontendReused()
{
    RefPtr<InspectorObject> frontendReusedMessage = InspectorObject::create();
    frontendReusedMessage->setString("method", "Inspector.frontendReused");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(frontendReusedMessage->toJSONString());
}

void InspectorFrontend::Inspector::bringToFront()
{
    RefPtr<InspectorObject> bringToFrontMessage = InspectorObject::create();
    bringToFrontMessage->setString("method", "Inspector.bringToFront");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(bringToFrontMessage->toJSONString());
}

void InspectorFrontend::Inspector::disconnectFromBackend()
{
    RefPtr<InspectorObject> disconnectFromBackendMessage = InspectorObject::create();
    disconnectFromBackendMessage->setString("method", "Inspector.disconnectFromBackend");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(disconnectFromBackendMessage->toJSONString());
}

void InspectorFrontend::Inspector::reset()
{
    RefPtr<InspectorObject> resetMessage = InspectorObject::create();
    resetMessage->setString("method", "Inspector.reset");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(resetMessage->toJSONString());
}

void InspectorFrontend::Inspector::showPanel(const String& panel)
{
    RefPtr<InspectorObject> showPanelMessage = InspectorObject::create();
    showPanelMessage->setString("method", "Inspector.showPanel");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setString("panel", panel);
    showPanelMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(showPanelMessage->toJSONString());
}

void InspectorFrontend::Inspector::startUserInitiatedDebugging()
{
    RefPtr<InspectorObject> startUserInitiatedDebuggingMessage = InspectorObject::create();
    startUserInitiatedDebuggingMessage->setString("method", "Inspector.startUserInitiatedDebugging");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(startUserInitiatedDebuggingMessage->toJSONString());
}

void InspectorFrontend::Inspector::evaluateForTestInFrontend(int testCallId, const String& script)
{
    RefPtr<InspectorObject> evaluateForTestInFrontendMessage = InspectorObject::create();
    evaluateForTestInFrontendMessage->setString("method", "Inspector.evaluateForTestInFrontend");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("testCallId", testCallId);
    paramsObject->setString("script", script);
    evaluateForTestInFrontendMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(evaluateForTestInFrontendMessage->toJSONString());
}

void InspectorFrontend::Inspector::inspect(PassRefPtr<InspectorObject> object, PassRefPtr<InspectorObject> hints)
{
    RefPtr<InspectorObject> inspectMessage = InspectorObject::create();
    inspectMessage->setString("method", "Inspector.inspect");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setObject("object", object);
    paramsObject->setObject("hints", hints);
    inspectMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(inspectMessage->toJSONString());
}

void InspectorFrontend::Inspector::didCreateWorker(int id, const String& url, bool isShared)
{
    RefPtr<InspectorObject> didCreateWorkerMessage = InspectorObject::create();
    didCreateWorkerMessage->setString("method", "Inspector.didCreateWorker");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("id", id);
    paramsObject->setString("url", url);
    paramsObject->setBoolean("isShared", isShared);
    didCreateWorkerMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(didCreateWorkerMessage->toJSONString());
}

void InspectorFrontend::Inspector::didDestroyWorker(int id)
{
    RefPtr<InspectorObject> didDestroyWorkerMessage = InspectorObject::create();
    didDestroyWorkerMessage->setString("method", "Inspector.didDestroyWorker");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("id", id);
    didDestroyWorkerMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(didDestroyWorkerMessage->toJSONString());
}

void InspectorFrontend::Page::domContentEventFired(double timestamp)
{
    RefPtr<InspectorObject> domContentEventFiredMessage = InspectorObject::create();
    domContentEventFiredMessage->setString("method", "Page.domContentEventFired");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("timestamp", timestamp);
    domContentEventFiredMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(domContentEventFiredMessage->toJSONString());
}

void InspectorFrontend::Page::loadEventFired(double timestamp)
{
    RefPtr<InspectorObject> loadEventFiredMessage = InspectorObject::create();
    loadEventFiredMessage->setString("method", "Page.loadEventFired");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("timestamp", timestamp);
    loadEventFiredMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(loadEventFiredMessage->toJSONString());
}

void InspectorFrontend::Page::frameNavigated(PassRefPtr<InspectorObject> frame, const String& loaderId)
{
    RefPtr<InspectorObject> frameNavigatedMessage = InspectorObject::create();
    frameNavigatedMessage->setString("method", "Page.frameNavigated");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setObject("frame", frame);
    paramsObject->setString("loaderId", loaderId);
    frameNavigatedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(frameNavigatedMessage->toJSONString());
}

void InspectorFrontend::Page::frameDetached(const String& frameId)
{
    RefPtr<InspectorObject> frameDetachedMessage = InspectorObject::create();
    frameDetachedMessage->setString("method", "Page.frameDetached");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setString("frameId", frameId);
    frameDetachedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(frameDetachedMessage->toJSONString());
}

void InspectorFrontend::Console::messageAdded(PassRefPtr<InspectorObject> messageObj)
{
    RefPtr<InspectorObject> messageAddedMessage = InspectorObject::create();
    messageAddedMessage->setString("method", "Console.messageAdded");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setObject("messageObj", messageObj);
    messageAddedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(messageAddedMessage->toJSONString());
}

void InspectorFrontend::Console::messageRepeatCountUpdated(int count)
{
    RefPtr<InspectorObject> messageRepeatCountUpdatedMessage = InspectorObject::create();
    messageRepeatCountUpdatedMessage->setString("method", "Console.messageRepeatCountUpdated");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("count", count);
    messageRepeatCountUpdatedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(messageRepeatCountUpdatedMessage->toJSONString());
}

void InspectorFrontend::Console::messagesCleared()
{
    RefPtr<InspectorObject> messagesClearedMessage = InspectorObject::create();
    messagesClearedMessage->setString("method", "Console.messagesCleared");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(messagesClearedMessage->toJSONString());
}

void InspectorFrontend::Network::requestWillBeSent(int identifier, const String& frameId, const String& loaderId, const String& documentURL, PassRefPtr<InspectorObject> request, double timestamp, PassRefPtr<InspectorArray> stackTrace, PassRefPtr<InspectorObject> redirectResponse)
{
    RefPtr<InspectorObject> requestWillBeSentMessage = InspectorObject::create();
    requestWillBeSentMessage->setString("method", "Network.requestWillBeSent");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setString("frameId", frameId);
    paramsObject->setString("loaderId", loaderId);
    paramsObject->setString("documentURL", documentURL);
    paramsObject->setObject("request", request);
    paramsObject->setNumber("timestamp", timestamp);
    paramsObject->setArray("stackTrace", stackTrace);
    if (redirectResponse)
        paramsObject->setObject("redirectResponse", redirectResponse);
    requestWillBeSentMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(requestWillBeSentMessage->toJSONString());
}

void InspectorFrontend::Network::resourceMarkedAsCached(int identifier)
{
    RefPtr<InspectorObject> resourceMarkedAsCachedMessage = InspectorObject::create();
    resourceMarkedAsCachedMessage->setString("method", "Network.resourceMarkedAsCached");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    resourceMarkedAsCachedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(resourceMarkedAsCachedMessage->toJSONString());
}

void InspectorFrontend::Network::responseReceived(int identifier, double timestamp, const String& type, PassRefPtr<InspectorObject> response)
{
    RefPtr<InspectorObject> responseReceivedMessage = InspectorObject::create();
    responseReceivedMessage->setString("method", "Network.responseReceived");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setNumber("timestamp", timestamp);
    paramsObject->setString("type", type);
    paramsObject->setObject("response", response);
    responseReceivedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(responseReceivedMessage->toJSONString());
}

void InspectorFrontend::Network::dataReceived(int identifier, double timestamp, int dataLength, int encodedDataLength)
{
    RefPtr<InspectorObject> dataReceivedMessage = InspectorObject::create();
    dataReceivedMessage->setString("method", "Network.dataReceived");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setNumber("timestamp", timestamp);
    paramsObject->setNumber("dataLength", dataLength);
    paramsObject->setNumber("encodedDataLength", encodedDataLength);
    dataReceivedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(dataReceivedMessage->toJSONString());
}

void InspectorFrontend::Network::loadingFinished(int identifier, double timestamp)
{
    RefPtr<InspectorObject> loadingFinishedMessage = InspectorObject::create();
    loadingFinishedMessage->setString("method", "Network.loadingFinished");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setNumber("timestamp", timestamp);
    loadingFinishedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(loadingFinishedMessage->toJSONString());
}

void InspectorFrontend::Network::loadingFailed(int identifier, double timestamp, const String& errorText, bool canceled)
{
    RefPtr<InspectorObject> loadingFailedMessage = InspectorObject::create();
    loadingFailedMessage->setString("method", "Network.loadingFailed");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setNumber("timestamp", timestamp);
    paramsObject->setString("errorText", errorText);
    if (canceled)
        paramsObject->setBoolean("canceled", canceled);
    loadingFailedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(loadingFailedMessage->toJSONString());
}

void InspectorFrontend::Network::resourceLoadedFromMemoryCache(const String& frameId, const String& loaderId, const String& documentURL, double timestamp, PassRefPtr<InspectorObject> resource)
{
    RefPtr<InspectorObject> resourceLoadedFromMemoryCacheMessage = InspectorObject::create();
    resourceLoadedFromMemoryCacheMessage->setString("method", "Network.resourceLoadedFromMemoryCache");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setString("frameId", frameId);
    paramsObject->setString("loaderId", loaderId);
    paramsObject->setString("documentURL", documentURL);
    paramsObject->setNumber("timestamp", timestamp);
    paramsObject->setObject("resource", resource);
    resourceLoadedFromMemoryCacheMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(resourceLoadedFromMemoryCacheMessage->toJSONString());
}

void InspectorFrontend::Network::initialContentSet(int identifier, const String& content, const String& type)
{
    RefPtr<InspectorObject> initialContentSetMessage = InspectorObject::create();
    initialContentSetMessage->setString("method", "Network.initialContentSet");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setString("content", content);
    paramsObject->setString("type", type);
    initialContentSetMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(initialContentSetMessage->toJSONString());
}

void InspectorFrontend::Network::webSocketWillSendHandshakeRequest(int identifier, double timestamp, PassRefPtr<InspectorObject> request)
{
    RefPtr<InspectorObject> webSocketWillSendHandshakeRequestMessage = InspectorObject::create();
    webSocketWillSendHandshakeRequestMessage->setString("method", "Network.webSocketWillSendHandshakeRequest");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setNumber("timestamp", timestamp);
    paramsObject->setObject("request", request);
    webSocketWillSendHandshakeRequestMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(webSocketWillSendHandshakeRequestMessage->toJSONString());
}

void InspectorFrontend::Network::webSocketHandshakeResponseReceived(int identifier, double timestamp, PassRefPtr<InspectorObject> response)
{
    RefPtr<InspectorObject> webSocketHandshakeResponseReceivedMessage = InspectorObject::create();
    webSocketHandshakeResponseReceivedMessage->setString("method", "Network.webSocketHandshakeResponseReceived");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setNumber("timestamp", timestamp);
    paramsObject->setObject("response", response);
    webSocketHandshakeResponseReceivedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(webSocketHandshakeResponseReceivedMessage->toJSONString());
}

void InspectorFrontend::Network::webSocketCreated(int identifier, const String& url)
{
    RefPtr<InspectorObject> webSocketCreatedMessage = InspectorObject::create();
    webSocketCreatedMessage->setString("method", "Network.webSocketCreated");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setString("url", url);
    webSocketCreatedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(webSocketCreatedMessage->toJSONString());
}

void InspectorFrontend::Network::webSocketClosed(int identifier, double timestamp)
{
    RefPtr<InspectorObject> webSocketClosedMessage = InspectorObject::create();
    webSocketClosedMessage->setString("method", "Network.webSocketClosed");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("identifier", identifier);
    paramsObject->setNumber("timestamp", timestamp);
    webSocketClosedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(webSocketClosedMessage->toJSONString());
}

void InspectorFrontend::DOM::documentUpdated()
{
    RefPtr<InspectorObject> documentUpdatedMessage = InspectorObject::create();
    documentUpdatedMessage->setString("method", "DOM.documentUpdated");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(documentUpdatedMessage->toJSONString());
}

void InspectorFrontend::DOM::setChildNodes(int parentId, PassRefPtr<InspectorArray> nodes)
{
    RefPtr<InspectorObject> setChildNodesMessage = InspectorObject::create();
    setChildNodesMessage->setString("method", "DOM.setChildNodes");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("parentId", parentId);
    paramsObject->setArray("nodes", nodes);
    setChildNodesMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(setChildNodesMessage->toJSONString());
}

void InspectorFrontend::DOM::attributesUpdated(int id, PassRefPtr<InspectorArray> attributes)
{
    RefPtr<InspectorObject> attributesUpdatedMessage = InspectorObject::create();
    attributesUpdatedMessage->setString("method", "DOM.attributesUpdated");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("id", id);
    paramsObject->setArray("attributes", attributes);
    attributesUpdatedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(attributesUpdatedMessage->toJSONString());
}

void InspectorFrontend::DOM::characterDataModified(int id, const String& newValue)
{
    RefPtr<InspectorObject> characterDataModifiedMessage = InspectorObject::create();
    characterDataModifiedMessage->setString("method", "DOM.characterDataModified");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("id", id);
    paramsObject->setString("newValue", newValue);
    characterDataModifiedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(characterDataModifiedMessage->toJSONString());
}

void InspectorFrontend::DOM::childNodeCountUpdated(int id, int newValue)
{
    RefPtr<InspectorObject> childNodeCountUpdatedMessage = InspectorObject::create();
    childNodeCountUpdatedMessage->setString("method", "DOM.childNodeCountUpdated");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("id", id);
    paramsObject->setNumber("newValue", newValue);
    childNodeCountUpdatedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(childNodeCountUpdatedMessage->toJSONString());
}

void InspectorFrontend::DOM::childNodeInserted(int parentId, int prevId, PassRefPtr<InspectorObject> node)
{
    RefPtr<InspectorObject> childNodeInsertedMessage = InspectorObject::create();
    childNodeInsertedMessage->setString("method", "DOM.childNodeInserted");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("parentId", parentId);
    paramsObject->setNumber("prevId", prevId);
    paramsObject->setObject("node", node);
    childNodeInsertedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(childNodeInsertedMessage->toJSONString());
}

void InspectorFrontend::DOM::childNodeRemoved(int parentId, int id)
{
    RefPtr<InspectorObject> childNodeRemovedMessage = InspectorObject::create();
    childNodeRemovedMessage->setString("method", "DOM.childNodeRemoved");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("parentId", parentId);
    paramsObject->setNumber("id", id);
    childNodeRemovedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(childNodeRemovedMessage->toJSONString());
}

void InspectorFrontend::DOM::searchResults(PassRefPtr<InspectorArray> nodeIds)
{
    RefPtr<InspectorObject> searchResultsMessage = InspectorObject::create();
    searchResultsMessage->setString("method", "DOM.searchResults");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setArray("nodeIds", nodeIds);
    searchResultsMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(searchResultsMessage->toJSONString());
}

void InspectorFrontend::DOM::shadowRootUpdated(int hostId, PassRefPtr<InspectorObject> shadowRoot)
{
    RefPtr<InspectorObject> shadowRootUpdatedMessage = InspectorObject::create();
    shadowRootUpdatedMessage->setString("method", "DOM.shadowRootUpdated");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setNumber("hostId", hostId);
    paramsObject->setObject("shadowRoot", shadowRoot);
    shadowRootUpdatedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(shadowRootUpdatedMessage->toJSONString());
}

void InspectorFrontend::Timeline::started()
{
    RefPtr<InspectorObject> startedMessage = InspectorObject::create();
    startedMessage->setString("method", "Timeline.started");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(startedMessage->toJSONString());
}

void InspectorFrontend::Timeline::stopped()
{
    RefPtr<InspectorObject> stoppedMessage = InspectorObject::create();
    stoppedMessage->setString("method", "Timeline.stopped");
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(stoppedMessage->toJSONString());
}

void InspectorFrontend::Timeline::eventRecorded(PassRefPtr<InspectorObject> record)
{
    RefPtr<InspectorObject> eventRecordedMessage = InspectorObject::create();
    eventRecordedMessage->setString("method", "Timeline.eventRecorded");
    RefPtr<InspectorObject> paramsObject = InspectorObject::create();
    paramsObject->setObject("record", record);
    eventRecordedMessage->setObject("params", paramsObject);
    if (m_inspectorFrontendChannel)
        m_inspectorFrontendChannel->sendMessageToFrontend(eventRecordedMessage->toJSONString());
}


} // namespace WebCore

#endif // ENABLE(INSPECTOR)
