/*
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Samuel Weinig <sam.weinig@gmail.com>
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

#import <WebCore/DOMObject.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

@class DOMClientRect;
@class DOMClientRectList;
@class DOMDocument;
@class DOMElement;
@class DOMInternalSettings;
@class DOMNode;
@class DOMNodeList;
@class DOMRange;
@class NSString;

@interface DOMInternals : DOMObject
@property(readonly, retain) DOMInternalSettings *settings;

- (NSString *)address:(DOMNode *)node;
- (NSString *)elementRenderTreeAsText:(DOMElement *)element;
- (BOOL)isPreloaded:(DOMDocument *)document url:(NSString *)url;
- (unsigned)numberOfScopedHTMLStyleChildren:(DOMNode *)scope;
- (DOMNode *)ensureShadowRoot:(DOMElement *)host;
- (DOMNode *)shadowRoot:(DOMElement *)host;
- (DOMNode *)youngestShadowRoot:(DOMElement *)host;
- (DOMNode *)oldestShadowRoot:(DOMElement *)host;
- (DOMNode *)youngerShadowRoot:(DOMNode *)root;
- (DOMElement *)includerFor:(DOMNode *)node;
- (NSString *)shadowPseudoId:(DOMElement *)element;
- (DOMElement *)createContentElement:(DOMDocument *)document;
- (DOMElement *)getElementByIdInShadowRoot:(DOMNode *)shadowRoot id:(NSString *)id;
- (BOOL)isValidContentSelect:(DOMElement *)contentElement;
- (DOMNode *)treeScopeRootNode:(DOMNode *)node;
- (DOMNode *)nextSiblingByWalker:(DOMNode *)node;
- (DOMNode *)firstChildByWalker:(DOMNode *)node;
- (DOMNode *)lastChildByWalker:(DOMNode *)node;
- (DOMNode *)nextNodeByWalker:(DOMNode *)node;
- (DOMNode *)previousNodeByWalker:(DOMNode *)node;
- (BOOL)attached:(DOMNode *)node;
- (NSString *)visiblePlaceholder:(DOMElement *)element;
- (DOMClientRect *)absoluteCaretBounds:(DOMDocument *)document;
- (DOMClientRect *)boundingBox:(DOMElement *)element;
- (DOMClientRectList *)inspectorHighlightRects:(DOMDocument *)document;
- (void)setBackgroundBlurOnNode:(DOMNode *)node blurLength:(int)blurLength;
- (unsigned)markerCountForNode:(DOMNode *)node markerType:(NSString *)markerType;
- (DOMRange *)markerRangeForNode:(DOMNode *)node markerType:(NSString *)markerType index:(unsigned)index;
- (NSString *)markerDescriptionForNode:(DOMNode *)node markerType:(NSString *)markerType index:(unsigned)index;
- (void)setScrollViewPosition:(DOMDocument *)document x:(int)x y:(int)y;
- (void)setPagination:(DOMDocument *)document mode:(NSString *)mode gap:(int)gap;
- (BOOL)wasLastChangeUserEdit:(DOMElement *)textField;
- (NSString *)suggestedValue:(DOMElement *)inputElement;
- (void)setSuggestedValue:(DOMElement *)inputElement value:(NSString *)value;
- (void)setEditingValue:(DOMElement *)inputElement value:(NSString *)value;
- (void)paintControlTints:(DOMDocument *)document;
- (void)scrollElementToRect:(DOMElement *)element x:(int)x y:(int)y w:(int)w h:(int)h;
- (DOMRange *)rangeFromLocationAndLength:(DOMElement *)scope rangeLocation:(int)rangeLocation rangeLength:(int)rangeLength;
- (unsigned)locationFromRange:(DOMElement *)scope range:(DOMRange *)range;
- (unsigned)lengthFromRange:(DOMElement *)scope range:(DOMRange *)range;
- (NSString *)rangeAsText:(DOMRange *)range;
- (void)setDelegatesScrolling:(BOOL)enabled document:(DOMDocument *)document;
- (int)lastSpellCheckRequestSequence:(DOMDocument *)document;
- (int)lastSpellCheckProcessedSequence:(DOMDocument *)document;
- (void)setShouldDisplayTrackKind:(DOMDocument *)document kind:(NSString *)kind enabled:(BOOL)enabled;
- (BOOL)shouldDisplayTrackKind:(DOMDocument *)document trackKind:(NSString *)trackKind;
- (unsigned)wheelEventHandlerCount:(DOMDocument *)document;
- (unsigned)touchEventHandlerCount:(DOMDocument *)document;
- (DOMNodeList *)nodesFromRect:(DOMDocument *)document x:(int)x y:(int)y topPadding:(unsigned)topPadding rightPadding:(unsigned)rightPadding bottomPadding:(unsigned)bottomPadding leftPadding:(unsigned)leftPadding ignoreClipping:(BOOL)ignoreClipping allowShadowContent:(BOOL)allowShadowContent;
- (void)emitInspectorDidBeginFrame;
- (void)emitInspectorDidCancelFrame;
- (BOOL)hasSpellingMarker:(DOMDocument *)document from:(int)from length:(int)length;
- (BOOL)hasGrammarMarker:(DOMDocument *)document from:(int)from length:(int)length;
- (unsigned)numberOfScrollableAreas:(DOMDocument *)document;
- (BOOL)isPageBoxVisible:(DOMDocument *)document pageNumber:(int)pageNumber;
- (void)suspendAnimations:(DOMDocument *)document;
- (void)resumeAnimations:(DOMDocument *)document;
- (void)allowRoundingHacks;
#if ENABLE(INSPECTOR)
- (unsigned)numberOfLiveNodes;
#endif
#if ENABLE(INSPECTOR)
- (unsigned)numberOfLiveDocuments;
#endif
- (void)webkitWillEnterFullScreenForElement:(DOMDocument *)document element:(DOMElement *)element;
- (void)webkitDidEnterFullScreenForElement:(DOMDocument *)document element:(DOMElement *)element;
- (void)webkitWillExitFullScreenForElement:(DOMDocument *)document element:(DOMElement *)element;
- (void)webkitDidExitFullScreenForElement:(DOMDocument *)document element:(DOMElement *)element;
@end

#endif
