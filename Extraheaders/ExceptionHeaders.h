/*
 * THIS FILE WAS AUTOMATICALLY GENERATED, DO NOT EDIT.
 *
 * Copyright (C) 2011 Google Inc.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY GOOGLE, INC. ``AS IS'' AND ANY
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

#ifndef ExceptionHeaders_h
#define ExceptionHeaders_h

#include "DOMCoreException.h"
#if USE(JSC)
#include "JSDOMCoreException.h"
#elif USE(V8)
#include "V8DOMCoreException.h"
#endif
#include "EventException.h"
#if USE(JSC)
#include "JSEventException.h"
#elif USE(V8)
#include "V8EventException.h"
#endif
#if ENABLE(BLOB)
#include "FileException.h"
#if USE(JSC)
#include "JSFileException.h"
#elif USE(V8)
#include "V8FileException.h"
#endif
#endif
#if ENABLE(INDEXED_DATABASE)
#include "IDBDatabaseException.h"
#if USE(JSC)
#include "JSIDBDatabaseException.h"
#elif USE(V8)
#include "V8IDBDatabaseException.h"
#endif
#endif
#if ENABLE(BLOB)
#include "OperationNotAllowedException.h"
#if USE(JSC)
#include "JSOperationNotAllowedException.h"
#elif USE(V8)
#include "V8OperationNotAllowedException.h"
#endif
#endif
#include "RangeException.h"
#if USE(JSC)
#include "JSRangeException.h"
#elif USE(V8)
#include "V8RangeException.h"
#endif
#if ENABLE(SQL_DATABASE)
#include "SQLException.h"
#if USE(JSC)
#include "JSSQLException.h"
#elif USE(V8)
#include "V8SQLException.h"
#endif
#endif
#if ENABLE(SVG)
#include "SVGException.h"
#if USE(JSC)
#include "JSSVGException.h"
#elif USE(V8)
#include "V8SVGException.h"
#endif
#endif
#include "XMLHttpRequestException.h"
#if USE(JSC)
#include "JSXMLHttpRequestException.h"
#elif USE(V8)
#include "V8XMLHttpRequestException.h"
#endif
#include "XPathException.h"
#if USE(JSC)
#include "JSXPathException.h"
#elif USE(V8)
#include "V8XPathException.h"
#endif

#endif // ExceptionHeaders_h
