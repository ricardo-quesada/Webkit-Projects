// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef InspectorFrontend_h
#define InspectorFrontend_h


#include "InspectorValues.h"//Ricardo: agregando referencias para q me aparezca lo necesario de database
#include <PlatformString.h>
#include <wtf/PassRefPtr.h>

namespace WebCore {

class InspectorArray;
class InspectorFrontendChannel;
class InspectorObject;

typedef String ErrorString;

class InspectorFrontend {
public:
    InspectorFrontend(InspectorFrontendChannel*);


    class Inspector {
    public:
        Inspector(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        void frontendReused();
        void bringToFront();
        void disconnectFromBackend();
        void reset();
        void showPanel(const String& panel);
        void startUserInitiatedDebugging();
        void evaluateForTestInFrontend(int testCallId, const String& script);
        void inspect(PassRefPtr<InspectorObject> object, PassRefPtr<InspectorObject> hints);
        void didCreateWorker(int id, const String& url, bool isShared);
        void didDestroyWorker(int id);
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };

    Inspector* inspector() { return &m_inspector; }

    class Page {
    public:
        Page(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        void domContentEventFired(double timestamp);
        void loadEventFired(double timestamp);
        void frameNavigated(PassRefPtr<InspectorObject> frame, const String& loaderId);
        void frameDetached(const String& frameId);
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };

    Page* page() { return &m_page; }

    class Console {
    public:
        Console(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        void messageAdded(PassRefPtr<InspectorObject> messageObj);
        void messageRepeatCountUpdated(int count);
        void messagesCleared();
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };

    Console* console() { return &m_console; }

    class Network {
    public:
        Network(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        void requestWillBeSent(int identifier, const String& frameId, const String& loaderId, const String& documentURL, PassRefPtr<InspectorObject> request, double timestamp, PassRefPtr<InspectorArray> stackTrace, PassRefPtr<InspectorObject> redirectResponse);
        void resourceMarkedAsCached(int identifier);
        void responseReceived(int identifier, double timestamp, const String& type, PassRefPtr<InspectorObject> response);
        void dataReceived(int identifier, double timestamp, int dataLength, int encodedDataLength);
        void loadingFinished(int identifier, double timestamp);
        void loadingFailed(int identifier, double timestamp, const String& errorText, bool canceled);
        void resourceLoadedFromMemoryCache(const String& frameId, const String& loaderId, const String& documentURL, double timestamp, PassRefPtr<InspectorObject> resource);
        void initialContentSet(int identifier, const String& content, const String& type);
        void webSocketWillSendHandshakeRequest(int identifier, double timestamp, PassRefPtr<InspectorObject> request);
        void webSocketHandshakeResponseReceived(int identifier, double timestamp, PassRefPtr<InspectorObject> response);
        void webSocketCreated(int identifier, const String& url);
        void webSocketClosed(int identifier, double timestamp);
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };

    Network* network() { return &m_network; }

    
    
    //Ricardo: Agregando las porciones de database
    
//#if ENABLE(SQL_DATABASE)
    class Database {
    public:
        Database(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        
        void sqlTransactionFailed(int transactionId, PassRefPtr<InspectorObject> sqlError);
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };
    
    Database* database() { return &m_database; }
    
//#endif // ENABLE(SQL_DATABASE)
//#if ENABLE(INDEXED_DATABASE)
    
    
//#endif // ENABLE(INDEXED_DATABASE)

    
    
    
    
//#if ENABLE(JAVASCRIPT_DEBUGGER)
    class Profiler {
    public:
        Profiler(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        //void addProfileHeader(PassRefPtr<TypeBuilder::Profiler::ProfileHeader> header);
        void addHeapSnapshotChunk(int uid, const String& chunk);
        void finishHeapSnapshot(int uid);
        void setRecordingProfile(bool isProfiling);
        void resetProfiles();
        void reportHeapSnapshotProgress(int done, int total);
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };
    
    Profiler* profiler() { return &m_profiler; }
    
//#endif // ENABLE(JAVASCRIPT_DEBUGGER)
    
    //////////////Hasta aqui //////////////////


    class DOM {
    public:
        DOM(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        void documentUpdated();
        void setChildNodes(int parentId, PassRefPtr<InspectorArray> nodes);
        void attributesUpdated(int id, PassRefPtr<InspectorArray> attributes);
        void characterDataModified(int id, const String& newValue);
        void childNodeCountUpdated(int id, int newValue);
        void childNodeInserted(int parentId, int prevId, PassRefPtr<InspectorObject> node);
        void childNodeRemoved(int parentId, int id);
        void searchResults(PassRefPtr<InspectorArray> nodeIds);
        void shadowRootUpdated(int hostId, PassRefPtr<InspectorObject> shadowRoot);
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };

    DOM* dom() { return &m_dom; }

    class Timeline {
    public:
        Timeline(InspectorFrontendChannel* inspectorFrontendChannel) : m_inspectorFrontendChannel(inspectorFrontendChannel) { }
        void started();
        void stopped();
        void eventRecorded(PassRefPtr<InspectorObject> record);
        void setInspectorFrontendChannel(InspectorFrontendChannel* inspectorFrontendChannel) { m_inspectorFrontendChannel = inspectorFrontendChannel; }
        InspectorFrontendChannel* getInspectorFrontendChannel() { return m_inspectorFrontendChannel; }
    private:
        InspectorFrontendChannel* m_inspectorFrontendChannel;
    };

    Timeline* timeline() { return &m_timeline; }


private:
    InspectorFrontendChannel* m_inspectorFrontendChannel;
    Inspector m_inspector;
    Page m_page;
    Console m_console;
    Network m_network;

    //Ricardo: agregando esta parte tamb
//#if ENABLE(SQL_DATABASE)
    Database m_database;
//#endif // ENABLE(SQL_DATABASE)
//#if ENABLE(JAVASCRIPT_DEBUGGER)
    Profiler m_profiler;
//#endif // ENABLE(JAVASCRIPT_DEBUGGER)

    ///////////// hasta aqui tamb ////////////
    DOM m_dom;
    Timeline m_timeline;
};

} // namespace WebCore
#endif // !defined(InspectorFrontend_h)

