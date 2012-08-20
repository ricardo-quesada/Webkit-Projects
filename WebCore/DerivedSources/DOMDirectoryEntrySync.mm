/*
 * This file is part of the WebKit open source project.
 * This file has been generated by generate-bindings.pl. DO NOT MODIFY!
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#import "config.h"

#if ENABLE(FILE_SYSTEM)

#import "DOMInternal.h"

#import "DOMDirectoryEntrySync.h"

#import "DOMBlobInternal.h"
#import "DOMCSSRuleInternal.h"
#import "DOMCSSValueInternal.h"
#import "DOMDirectoryEntrySyncInternal.h"
#import "DOMDirectoryReaderSyncInternal.h"
#import "DOMEventInternal.h"
#import "DOMFileEntrySyncInternal.h"
#import "DOMNodeInternal.h"
#import "DOMStyleSheetInternal.h"
#import "DOMWebKitFlagsInternal.h"
#import "DirectoryEntrySync.h"
#import "DirectoryReaderSync.h"
#import "ExceptionHandlers.h"
#import "FileEntrySync.h"
#import "JSMainThreadExecState.h"
#import "KURL.h"
#import "ThreadCheck.h"
#import "WebKitFlags.h"
#import "WebScriptObjectPrivate.h"
#import <wtf/GetPtr.h>

#define IMPL static_cast<WebCore::DirectoryEntrySync*>(reinterpret_cast<WebCore::Node*>(_internal))

@implementation DOMDirectoryEntrySync

- (DOMDirectoryReaderSync *)createReader
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    DOMDirectoryReaderSync *result = kit(WTF::getPtr(IMPL->createReader(ec)));
    WebCore::raiseOnDOMError(ec);
    return result;
}

- (DOMFileEntrySync *)getFile:(NSString *)path flags:(DOMWebKitFlags *)flags
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    DOMFileEntrySync *result = kit(WTF::getPtr(IMPL->getFile(path, core(flags), ec)));
    WebCore::raiseOnDOMError(ec);
    return result;
}

- (DOMDirectoryEntrySync *)getDirectory:(NSString *)path flags:(DOMWebKitFlags *)flags
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    DOMDirectoryEntrySync *result = kit(WTF::getPtr(IMPL->getDirectory(path, core(flags), ec)));
    WebCore::raiseOnDOMError(ec);
    return result;
}

- (void)removeRecursively
{
    WebCore::JSMainThreadNullState state;
    WebCore::ExceptionCode ec = 0;
    IMPL->removeRecursively(ec);
    WebCore::raiseOnDOMError(ec);
}

@end

WebCore::DirectoryEntrySync* core(DOMDirectoryEntrySync *wrapper)
{
    return wrapper ? reinterpret_cast<WebCore::DirectoryEntrySync*>(wrapper->_internal) : 0;
}

DOMDirectoryEntrySync *kit(WebCore::DirectoryEntrySync* value)
{
    { DOM_ASSERT_MAIN_THREAD(); WebCoreThreadViolationCheckRoundOne(); };
    return static_cast<DOMDirectoryEntrySync*>(kit(static_cast<WebCore::Node*>(value)));
}

#endif // ENABLE(FILE_SYSTEM)