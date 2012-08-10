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

#import <WebCore/DOMCanvasRenderingContext.h>

#if WEBKIT_VERSION_MAX_ALLOWED >= WEBKIT_VERSION_LATEST

@class DOMArrayBuffer;
@class DOMArrayBufferView;
@class DOMFloat32Array;
@class DOMHTMLCanvasElement;
@class DOMHTMLImageElement;
@class DOMImageData;
@class DOMInt32Array;
@class DOMWebGLActiveInfo;
@class DOMWebGLBuffer;
@class DOMWebGLContextAttributes;
@class DOMWebGLFramebuffer;
@class DOMWebGLProgram;
@class DOMWebGLRenderbuffer;
@class DOMWebGLShader;
@class DOMWebGLTexture;
@class DOMWebGLUniformLocation;
@class NSString;

enum {
    DOM_DEPTH_BUFFER_BIT = 0x00000100,
    DOM_STENCIL_BUFFER_BIT = 0x00000400,
    DOM_COLOR_BUFFER_BIT = 0x00004000,
    DOM_POINTS = 0x0000,
    DOM_LINES = 0x0001,
    DOM_LINE_LOOP = 0x0002,
    DOM_LINE_STRIP = 0x0003,
    DOM_TRIANGLES = 0x0004,
    DOM_TRIANGLE_STRIP = 0x0005,
    DOM_TRIANGLE_FAN = 0x0006,
    DOM_ZERO = 0,
    DOM_ONE = 1,
    DOM_SRC_COLOR = 0x0300,
    DOM_ONE_MINUS_SRC_COLOR = 0x0301,
    DOM_SRC_ALPHA = 0x0302,
    DOM_ONE_MINUS_SRC_ALPHA = 0x0303,
    DOM_DST_ALPHA = 0x0304,
    DOM_ONE_MINUS_DST_ALPHA = 0x0305,
    DOM_DST_COLOR = 0x0306,
    DOM_ONE_MINUS_DST_COLOR = 0x0307,
    DOM_SRC_ALPHA_SATURATE = 0x0308,
    DOM_FUNC_ADD = 0x8006,
    DOM_BLEND_EQUATION = 0x8009,
    DOM_BLEND_EQUATION_RGB = 0x8009,
    DOM_BLEND_EQUATION_ALPHA = 0x883D,
    DOM_FUNC_SUBTRACT = 0x800A,
    DOM_FUNC_REVERSE_SUBTRACT = 0x800B,
    DOM_BLEND_DST_RGB = 0x80C8,
    DOM_BLEND_SRC_RGB = 0x80C9,
    DOM_BLEND_DST_ALPHA = 0x80CA,
    DOM_BLEND_SRC_ALPHA = 0x80CB,
    DOM_CONSTANT_COLOR = 0x8001,
    DOM_ONE_MINUS_CONSTANT_COLOR = 0x8002,
    DOM_CONSTANT_ALPHA = 0x8003,
    DOM_ONE_MINUS_CONSTANT_ALPHA = 0x8004,
    DOM_BLEND_COLOR = 0x8005,
    DOM_ARRAY_BUFFER = 0x8892,
    DOM_ELEMENT_ARRAY_BUFFER = 0x8893,
    DOM_ARRAY_BUFFER_BINDING = 0x8894,
    DOM_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895,
    DOM_STREAM_DRAW = 0x88E0,
    DOM_STATIC_DRAW = 0x88E4,
    DOM_DYNAMIC_DRAW = 0x88E8,
    DOM_BUFFER_SIZE = 0x8764,
    DOM_BUFFER_USAGE = 0x8765,
    DOM_CURRENT_VERTEX_ATTRIB = 0x8626,
    DOM_FRONT = 0x0404,
    DOM_BACK = 0x0405,
    DOM_FRONT_AND_BACK = 0x0408,
    DOM_TEXTURE_2D = 0x0DE1,
    DOM_CULL_FACE = 0x0B44,
    DOM_BLEND = 0x0BE2,
    DOM_DITHER = 0x0BD0,
    DOM_STENCIL_TEST = 0x0B90,
    DOM_DEPTH_TEST = 0x0B71,
    DOM_SCISSOR_TEST = 0x0C11,
    DOM_POLYGON_OFFSET_FILL = 0x8037,
    DOM_SAMPLE_ALPHA_TO_COVERAGE = 0x809E,
    DOM_SAMPLE_COVERAGE = 0x80A0,
    DOM_NO_ERROR = 0,
    DOM_INVALID_ENUM = 0x0500,
    DOM_INVALID_VALUE = 0x0501,
    DOM_INVALID_OPERATION = 0x0502,
    DOM_OUT_OF_MEMORY = 0x0505,
    DOM_CW = 0x0900,
    DOM_CCW = 0x0901,
    DOM_LINE_WIDTH = 0x0B21,
    DOM_ALIASED_POINT_SIZE_RANGE = 0x846D,
    DOM_ALIASED_LINE_WIDTH_RANGE = 0x846E,
    DOM_CULL_FACE_MODE = 0x0B45,
    DOM_FRONT_FACE = 0x0B46,
    DOM_DEPTH_RANGE = 0x0B70,
    DOM_DEPTH_WRITEMASK = 0x0B72,
    DOM_DEPTH_CLEAR_VALUE = 0x0B73,
    DOM_DEPTH_FUNC = 0x0B74,
    DOM_STENCIL_CLEAR_VALUE = 0x0B91,
    DOM_STENCIL_FUNC = 0x0B92,
    DOM_STENCIL_FAIL = 0x0B94,
    DOM_STENCIL_PASS_DEPTH_FAIL = 0x0B95,
    DOM_STENCIL_PASS_DEPTH_PASS = 0x0B96,
    DOM_STENCIL_REF = 0x0B97,
    DOM_STENCIL_VALUE_MASK = 0x0B93,
    DOM_STENCIL_WRITEMASK = 0x0B98,
    DOM_STENCIL_BACK_FUNC = 0x8800,
    DOM_STENCIL_BACK_FAIL = 0x8801,
    DOM_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802,
    DOM_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803,
    DOM_STENCIL_BACK_REF = 0x8CA3,
    DOM_STENCIL_BACK_VALUE_MASK = 0x8CA4,
    DOM_STENCIL_BACK_WRITEMASK = 0x8CA5,
    DOM_VIEWPORT = 0x0BA2,
    DOM_SCISSOR_BOX = 0x0C10,
    DOM_COLOR_CLEAR_VALUE = 0x0C22,
    DOM_COLOR_WRITEMASK = 0x0C23,
    DOM_UNPACK_ALIGNMENT = 0x0CF5,
    DOM_PACK_ALIGNMENT = 0x0D05,
    DOM_MAX_TEXTURE_SIZE = 0x0D33,
    DOM_MAX_VIEWPORT_DIMS = 0x0D3A,
    DOM_SUBPIXEL_BITS = 0x0D50,
    DOM_RED_BITS = 0x0D52,
    DOM_GREEN_BITS = 0x0D53,
    DOM_BLUE_BITS = 0x0D54,
    DOM_ALPHA_BITS = 0x0D55,
    DOM_DEPTH_BITS = 0x0D56,
    DOM_STENCIL_BITS = 0x0D57,
    DOM_POLYGON_OFFSET_UNITS = 0x2A00,
    DOM_POLYGON_OFFSET_FACTOR = 0x8038,
    DOM_TEXTURE_BINDING_2D = 0x8069,
    DOM_SAMPLE_BUFFERS = 0x80A8,
    DOM_SAMPLES = 0x80A9,
    DOM_SAMPLE_COVERAGE_VALUE = 0x80AA,
    DOM_SAMPLE_COVERAGE_INVERT = 0x80AB,
    DOM_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2,
    DOM_COMPRESSED_TEXTURE_FORMATS = 0x86A3,
    DOM_DONT_CARE = 0x1100,
    DOM_FASTEST = 0x1101,
    DOM_NICEST = 0x1102,
    DOM_GENERATE_MIPMAP_HINT = 0x8192,
    DOM_BYTE = 0x1400,
    DOM_UNSIGNED_BYTE = 0x1401,
    DOM_SHORT = 0x1402,
    DOM_UNSIGNED_SHORT = 0x1403,
    DOM_INT = 0x1404,
    DOM_UNSIGNED_INT = 0x1405,
    DOM_FLOAT = 0x1406,
    DOM_DEPTH_COMPONENT = 0x1902,
    DOM_ALPHA = 0x1906,
    DOM_RGB = 0x1907,
    DOM_RGBA = 0x1908,
    DOM_LUMINANCE = 0x1909,
    DOM_LUMINANCE_ALPHA = 0x190A,
    DOM_UNSIGNED_SHORT_4_4_4_4 = 0x8033,
    DOM_UNSIGNED_SHORT_5_5_5_1 = 0x8034,
    DOM_UNSIGNED_SHORT_5_6_5 = 0x8363,
    DOM_FRAGMENT_SHADER = 0x8B30,
    DOM_VERTEX_SHADER = 0x8B31,
    DOM_MAX_VERTEX_ATTRIBS = 0x8869,
    DOM_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB,
    DOM_MAX_VARYING_VECTORS = 0x8DFC,
    DOM_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
    DOM_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C,
    DOM_MAX_TEXTURE_IMAGE_UNITS = 0x8872,
    DOM_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD,
    DOM_SHADER_TYPE = 0x8B4F,
    DOM_DELETE_STATUS = 0x8B80,
    DOM_LINK_STATUS = 0x8B82,
    DOM_VALIDATE_STATUS = 0x8B83,
    DOM_ATTACHED_SHADERS = 0x8B85,
    DOM_ACTIVE_UNIFORMS = 0x8B86,
    DOM_ACTIVE_ATTRIBUTES = 0x8B89,
    DOM_SHADING_LANGUAGE_VERSION = 0x8B8C,
    DOM_CURRENT_PROGRAM = 0x8B8D,
    DOM_NEVER = 0x0200,
    DOM_LESS = 0x0201,
    DOM_EQUAL = 0x0202,
    DOM_LEQUAL = 0x0203,
    DOM_GREATER = 0x0204,
    DOM_NOTEQUAL = 0x0205,
    DOM_GEQUAL = 0x0206,
    DOM_ALWAYS = 0x0207,
    DOM_KEEP = 0x1E00,
    DOM_REPLACE = 0x1E01,
    DOM_INCR = 0x1E02,
    DOM_DECR = 0x1E03,
    DOM_INVERT = 0x150A,
    DOM_INCR_WRAP = 0x8507,
    DOM_DECR_WRAP = 0x8508,
    DOM_VENDOR = 0x1F00,
    DOM_RENDERER = 0x1F01,
    DOM_VERSION = 0x1F02,
    DOM_NEAREST = 0x2600,
    DOM_LINEAR = 0x2601,
    DOM_NEAREST_MIPMAP_NEAREST = 0x2700,
    DOM_LINEAR_MIPMAP_NEAREST = 0x2701,
    DOM_NEAREST_MIPMAP_LINEAR = 0x2702,
    DOM_LINEAR_MIPMAP_LINEAR = 0x2703,
    DOM_TEXTURE_MAG_FILTER = 0x2800,
    DOM_TEXTURE_MIN_FILTER = 0x2801,
    DOM_TEXTURE_WRAP_S = 0x2802,
    DOM_TEXTURE_WRAP_T = 0x2803,
    DOM_TEXTURE = 0x1702,
    DOM_TEXTURE_CUBE_MAP = 0x8513,
    DOM_TEXTURE_BINDING_CUBE_MAP = 0x8514,
    DOM_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
    DOM_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
    DOM_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
    DOM_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
    DOM_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
    DOM_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,
    DOM_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C,
    DOM_TEXTURE0 = 0x84C0,
    DOM_TEXTURE1 = 0x84C1,
    DOM_TEXTURE2 = 0x84C2,
    DOM_TEXTURE3 = 0x84C3,
    DOM_TEXTURE4 = 0x84C4,
    DOM_TEXTURE5 = 0x84C5,
    DOM_TEXTURE6 = 0x84C6,
    DOM_TEXTURE7 = 0x84C7,
    DOM_TEXTURE8 = 0x84C8,
    DOM_TEXTURE9 = 0x84C9,
    DOM_TEXTURE10 = 0x84CA,
    DOM_TEXTURE11 = 0x84CB,
    DOM_TEXTURE12 = 0x84CC,
    DOM_TEXTURE13 = 0x84CD,
    DOM_TEXTURE14 = 0x84CE,
    DOM_TEXTURE15 = 0x84CF,
    DOM_TEXTURE16 = 0x84D0,
    DOM_TEXTURE17 = 0x84D1,
    DOM_TEXTURE18 = 0x84D2,
    DOM_TEXTURE19 = 0x84D3,
    DOM_TEXTURE20 = 0x84D4,
    DOM_TEXTURE21 = 0x84D5,
    DOM_TEXTURE22 = 0x84D6,
    DOM_TEXTURE23 = 0x84D7,
    DOM_TEXTURE24 = 0x84D8,
    DOM_TEXTURE25 = 0x84D9,
    DOM_TEXTURE26 = 0x84DA,
    DOM_TEXTURE27 = 0x84DB,
    DOM_TEXTURE28 = 0x84DC,
    DOM_TEXTURE29 = 0x84DD,
    DOM_TEXTURE30 = 0x84DE,
    DOM_TEXTURE31 = 0x84DF,
    DOM_ACTIVE_TEXTURE = 0x84E0,
    DOM_REPEAT = 0x2901,
    DOM_CLAMP_TO_EDGE = 0x812F,
    DOM_MIRRORED_REPEAT = 0x8370,
    DOM_FLOAT_VEC2 = 0x8B50,
    DOM_FLOAT_VEC3 = 0x8B51,
    DOM_FLOAT_VEC4 = 0x8B52,
    DOM_INT_VEC2 = 0x8B53,
    DOM_INT_VEC3 = 0x8B54,
    DOM_INT_VEC4 = 0x8B55,
    DOM_BOOL = 0x8B56,
    DOM_BOOL_VEC2 = 0x8B57,
    DOM_BOOL_VEC3 = 0x8B58,
    DOM_BOOL_VEC4 = 0x8B59,
    DOM_FLOAT_MAT2 = 0x8B5A,
    DOM_FLOAT_MAT3 = 0x8B5B,
    DOM_FLOAT_MAT4 = 0x8B5C,
    DOM_SAMPLER_2D = 0x8B5E,
    DOM_SAMPLER_CUBE = 0x8B60,
    DOM_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622,
    DOM_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623,
    DOM_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624,
    DOM_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625,
    DOM_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
    DOM_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645,
    DOM_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
    DOM_COMPILE_STATUS = 0x8B81,
    DOM_SHADER_COMPILER = 0x8DFA,
    DOM_LOW_FLOAT = 0x8DF0,
    DOM_MEDIUM_FLOAT = 0x8DF1,
    DOM_HIGH_FLOAT = 0x8DF2,
    DOM_LOW_INT = 0x8DF3,
    DOM_MEDIUM_INT = 0x8DF4,
    DOM_HIGH_INT = 0x8DF5,
    DOM_FRAMEBUFFER = 0x8D40,
    DOM_RENDERBUFFER = 0x8D41,
    DOM_RGBA4 = 0x8056,
    DOM_RGB5_A1 = 0x8057,
    DOM_RGB565 = 0x8D62,
    DOM_DEPTH_COMPONENT16 = 0x81A5,
    DOM_STENCIL_INDEX = 0x1901,
    DOM_STENCIL_INDEX8 = 0x8D48,
    DOM_DEPTH_STENCIL = 0x84F9,
    DOM_RENDERBUFFER_WIDTH = 0x8D42,
    DOM_RENDERBUFFER_HEIGHT = 0x8D43,
    DOM_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44,
    DOM_RENDERBUFFER_RED_SIZE = 0x8D50,
    DOM_RENDERBUFFER_GREEN_SIZE = 0x8D51,
    DOM_RENDERBUFFER_BLUE_SIZE = 0x8D52,
    DOM_RENDERBUFFER_ALPHA_SIZE = 0x8D53,
    DOM_RENDERBUFFER_DEPTH_SIZE = 0x8D54,
    DOM_RENDERBUFFER_STENCIL_SIZE = 0x8D55,
    DOM_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
    DOM_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
    DOM_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
    DOM_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
    DOM_COLOR_ATTACHMENT0 = 0x8CE0,
    DOM_DEPTH_ATTACHMENT = 0x8D00,
    DOM_STENCIL_ATTACHMENT = 0x8D20,
    DOM_DEPTH_STENCIL_ATTACHMENT = 0x821A,
    DOM_NONE = 0,
    DOM_FRAMEBUFFER_COMPLETE = 0x8CD5,
    DOM_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
    DOM_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
    DOM_FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9,
    DOM_FRAMEBUFFER_UNSUPPORTED = 0x8CDD,
    DOM_FRAMEBUFFER_BINDING = 0x8CA6,
    DOM_RENDERBUFFER_BINDING = 0x8CA7,
    DOM_MAX_RENDERBUFFER_SIZE = 0x84E8,
    DOM_INVALID_FRAMEBUFFER_OPERATION = 0x0506,
    DOM_UNPACK_FLIP_Y_WEBGL = 0x9240,
    DOM_UNPACK_PREMULTIPLY_ALPHA_WEBGL = 0x9241,
    DOM_CONTEXT_LOST_WEBGL = 0x9242,
    DOM_UNPACK_COLORSPACE_CONVERSION_WEBGL = 0x9243,
    DOM_BROWSER_DEFAULT_WEBGL = 0x9244
};

@interface DOMWebGLRenderingContext : DOMCanvasRenderingContext
- (void)activeTexture:(unsigned)texture;
- (void)attachShader:(DOMWebGLProgram *)program shader:(DOMWebGLShader *)shader;
- (void)bindAttribLocation:(DOMWebGLProgram *)program index:(unsigned)index name:(NSString *)name;
- (void)bindBuffer:(unsigned)target buffer:(DOMWebGLBuffer *)buffer;
- (void)bindFramebuffer:(unsigned)target framebuffer:(DOMWebGLFramebuffer *)framebuffer;
- (void)bindRenderbuffer:(unsigned)target renderbuffer:(DOMWebGLRenderbuffer *)renderbuffer;
- (void)bindTexture:(unsigned)target texture:(DOMWebGLTexture *)texture;
- (void)blendColor:(float)red green:(float)green blue:(float)blue alpha:(float)alpha;
- (void)blendEquation:(unsigned)mode;
- (void)blendEquationSeparate:(unsigned)modeRGB modeAlpha:(unsigned)modeAlpha;
- (void)blendFunc:(unsigned)sfactor dfactor:(unsigned)dfactor;
- (void)blendFuncSeparate:(unsigned)srcRGB dstRGB:(unsigned)dstRGB srcAlpha:(unsigned)srcAlpha dstAlpha:(unsigned)dstAlpha;
- (void)bufferData:(unsigned)target data:(DOMArrayBuffer *)data usage:(unsigned)usage;
- (void)bufferData:(unsigned)target data:(DOMArrayBufferView *)data usage:(unsigned)usage;
- (void)bufferData:(unsigned)target size:(int)size usage:(unsigned)usage;
- (void)bufferSubData:(unsigned)target offset:(int)offset data:(DOMArrayBuffer *)data;
- (void)bufferSubData:(unsigned)target offset:(int)offset data:(DOMArrayBufferView *)data;
- (unsigned)checkFramebufferStatus:(unsigned)target;
- (void)clear:(unsigned)mask;
- (void)clearColor:(float)red green:(float)green blue:(float)blue alpha:(float)alpha;
- (void)clearDepth:(float)depth;
- (void)clearStencil:(int)s;
- (void)colorMask:(BOOL)red green:(BOOL)green blue:(BOOL)blue alpha:(BOOL)alpha;
- (void)compileShader:(DOMWebGLShader *)shader;
- (void)copyTexImage2D:(unsigned)target level:(int)level internalformat:(unsigned)internalformat x:(int)x y:(int)y width:(int)width height:(int)height border:(int)border;
- (void)copyTexSubImage2D:(unsigned)target level:(int)level xoffset:(int)xoffset yoffset:(int)yoffset x:(int)x y:(int)y width:(int)width height:(int)height;
- (DOMWebGLBuffer *)createBuffer;
- (DOMWebGLFramebuffer *)createFramebuffer;
- (DOMWebGLProgram *)createProgram;
- (DOMWebGLRenderbuffer *)createRenderbuffer;
- (DOMWebGLShader *)createShader:(unsigned)type;
- (DOMWebGLTexture *)createTexture;
- (void)cullFace:(unsigned)mode;
- (void)deleteBuffer:(DOMWebGLBuffer *)buffer;
- (void)deleteFramebuffer:(DOMWebGLFramebuffer *)framebuffer;
- (void)deleteProgram:(DOMWebGLProgram *)program;
- (void)deleteRenderbuffer:(DOMWebGLRenderbuffer *)renderbuffer;
- (void)deleteShader:(DOMWebGLShader *)shader;
- (void)deleteTexture:(DOMWebGLTexture *)texture;
- (void)depthFunc:(unsigned)func;
- (void)depthMask:(BOOL)flag;
- (void)depthRange:(float)zNear zFar:(float)zFar;
- (void)detachShader:(DOMWebGLProgram *)program shader:(DOMWebGLShader *)shader;
- (void)disable:(unsigned)cap;
- (void)disableVertexAttribArray:(unsigned)index;
- (void)drawArrays:(unsigned)mode first:(int)first count:(int)count;
- (void)drawElements:(unsigned)mode count:(int)count type:(unsigned)type offset:(int)offset;
- (void)enable:(unsigned)cap;
- (void)enableVertexAttribArray:(unsigned)index;
- (void)finish;
- (void)flush;
- (void)framebufferRenderbuffer:(unsigned)target attachment:(unsigned)attachment renderbuffertarget:(unsigned)renderbuffertarget renderbuffer:(DOMWebGLRenderbuffer *)renderbuffer;
- (void)framebufferTexture2D:(unsigned)target attachment:(unsigned)attachment textarget:(unsigned)textarget texture:(DOMWebGLTexture *)texture level:(int)level;
- (void)frontFace:(unsigned)mode;
- (void)generateMipmap:(unsigned)target;
- (DOMWebGLActiveInfo *)getActiveAttrib:(DOMWebGLProgram *)program index:(unsigned)index;
- (DOMWebGLActiveInfo *)getActiveUniform:(DOMWebGLProgram *)program index:(unsigned)index;
- (void)getAttachedShaders:(DOMWebGLProgram *)program;
- (int)getAttribLocation:(DOMWebGLProgram *)program name:(NSString *)name;
- (void)getBufferParameter;
- (DOMWebGLContextAttributes *)getContextAttributes;
- (unsigned)getError;
- (void)getExtension:(NSString *)name;
- (void)getFramebufferAttachmentParameter;
- (void)getParameter;
- (void)getProgramParameter;
- (NSString *)getProgramInfoLog:(DOMWebGLProgram *)program;
- (void)getRenderbufferParameter;
- (void)getShaderParameter;
- (NSString *)getShaderInfoLog:(DOMWebGLShader *)shader;
- (NSString *)getShaderSource:(DOMWebGLShader *)shader;
- (void)getSupportedExtensions;
- (void)getTexParameter;
- (void)getUniform;
- (DOMWebGLUniformLocation *)getUniformLocation:(DOMWebGLProgram *)program name:(NSString *)name;
- (void)getVertexAttrib;
- (int)getVertexAttribOffset:(unsigned)index pname:(unsigned)pname;
- (void)hint:(unsigned)target mode:(unsigned)mode;
- (BOOL)isBuffer:(DOMWebGLBuffer *)buffer;
- (BOOL)isContextLost;
- (BOOL)isEnabled:(unsigned)cap;
- (BOOL)isFramebuffer:(DOMWebGLFramebuffer *)framebuffer;
- (BOOL)isProgram:(DOMWebGLProgram *)program;
- (BOOL)isRenderbuffer:(DOMWebGLRenderbuffer *)renderbuffer;
- (BOOL)isShader:(DOMWebGLShader *)shader;
- (BOOL)isTexture:(DOMWebGLTexture *)texture;
- (void)lineWidth:(float)width;
- (void)linkProgram:(DOMWebGLProgram *)program;
- (void)pixelStorei:(unsigned)pname param:(int)param;
- (void)polygonOffset:(float)factor units:(float)units;
- (void)readPixels:(int)x y:(int)y width:(int)width height:(int)height format:(unsigned)format type:(unsigned)type pixels:(DOMArrayBufferView *)pixels;
- (void)releaseShaderCompiler;
- (void)renderbufferStorage:(unsigned)target internalformat:(unsigned)internalformat width:(int)width height:(int)height;
- (void)sampleCoverage:(float)value invert:(BOOL)invert;
- (void)scissor:(int)x y:(int)y width:(int)width height:(int)height;
- (void)shaderSource:(DOMWebGLShader *)shader string:(NSString *)string;
- (void)stencilFunc:(unsigned)func ref:(int)ref mask:(unsigned)mask;
- (void)stencilFuncSeparate:(unsigned)face func:(unsigned)func ref:(int)ref mask:(unsigned)mask;
- (void)stencilMask:(unsigned)mask;
- (void)stencilMaskSeparate:(unsigned)face mask:(unsigned)mask;
- (void)stencilOp:(unsigned)fail zfail:(unsigned)zfail zpass:(unsigned)zpass;
- (void)stencilOpSeparate:(unsigned)face fail:(unsigned)fail zfail:(unsigned)zfail zpass:(unsigned)zpass;
- (void)texParameterf:(unsigned)target pname:(unsigned)pname param:(float)param;
- (void)texParameteri:(unsigned)target pname:(unsigned)pname param:(int)param;
- (void)texImage2D:(unsigned)target level:(int)level internalformat:(unsigned)internalformat width:(int)width height:(int)height border:(int)border format:(unsigned)format type:(unsigned)type pixels:(DOMArrayBufferView *)pixels;
- (void)texImage2D:(unsigned)target level:(int)level internalformat:(unsigned)internalformat format:(unsigned)format type:(unsigned)type pixels:(DOMImageData *)pixels;
- (void)texImage2D:(unsigned)target level:(int)level internalformat:(unsigned)internalformat format:(unsigned)format type:(unsigned)type image:(DOMHTMLImageElement *)image;
- (void)texImage2D:(unsigned)target level:(int)level internalformat:(unsigned)internalformat format:(unsigned)format type:(unsigned)type canvas:(DOMHTMLCanvasElement *)canvas;
- (void)texSubImage2D:(unsigned)target level:(int)level xoffset:(int)xoffset yoffset:(int)yoffset width:(int)width height:(int)height format:(unsigned)format type:(unsigned)type pixels:(DOMArrayBufferView *)pixels;
- (void)texSubImage2D:(unsigned)target level:(int)level xoffset:(int)xoffset yoffset:(int)yoffset format:(unsigned)format type:(unsigned)type pixels:(DOMImageData *)pixels;
- (void)texSubImage2D:(unsigned)target level:(int)level xoffset:(int)xoffset yoffset:(int)yoffset format:(unsigned)format type:(unsigned)type image:(DOMHTMLImageElement *)image;
- (void)texSubImage2D:(unsigned)target level:(int)level xoffset:(int)xoffset yoffset:(int)yoffset format:(unsigned)format type:(unsigned)type canvas:(DOMHTMLCanvasElement *)canvas;
- (void)uniform1f:(DOMWebGLUniformLocation *)location x:(float)x;
- (void)uniform1fv:(DOMWebGLUniformLocation *)location v:(DOMFloat32Array *)v;
- (void)uniform1i:(DOMWebGLUniformLocation *)location x:(int)x;
- (void)uniform1iv:(DOMWebGLUniformLocation *)location v:(DOMInt32Array *)v;
- (void)uniform2f:(DOMWebGLUniformLocation *)location x:(float)x y:(float)y;
- (void)uniform2fv:(DOMWebGLUniformLocation *)location v:(DOMFloat32Array *)v;
- (void)uniform2i:(DOMWebGLUniformLocation *)location x:(int)x y:(int)y;
- (void)uniform2iv:(DOMWebGLUniformLocation *)location v:(DOMInt32Array *)v;
- (void)uniform3f:(DOMWebGLUniformLocation *)location x:(float)x y:(float)y z:(float)z;
- (void)uniform3fv:(DOMWebGLUniformLocation *)location v:(DOMFloat32Array *)v;
- (void)uniform3i:(DOMWebGLUniformLocation *)location x:(int)x y:(int)y z:(int)z;
- (void)uniform3iv:(DOMWebGLUniformLocation *)location v:(DOMInt32Array *)v;
- (void)uniform4f:(DOMWebGLUniformLocation *)location x:(float)x y:(float)y z:(float)z w:(float)w;
- (void)uniform4fv:(DOMWebGLUniformLocation *)location v:(DOMFloat32Array *)v;
- (void)uniform4i:(DOMWebGLUniformLocation *)location x:(int)x y:(int)y z:(int)z w:(int)w;
- (void)uniform4iv:(DOMWebGLUniformLocation *)location v:(DOMInt32Array *)v;
- (void)uniformMatrix2fv:(DOMWebGLUniformLocation *)location transpose:(BOOL)transpose array:(DOMFloat32Array *)array;
- (void)uniformMatrix3fv:(DOMWebGLUniformLocation *)location transpose:(BOOL)transpose array:(DOMFloat32Array *)array;
- (void)uniformMatrix4fv:(DOMWebGLUniformLocation *)location transpose:(BOOL)transpose array:(DOMFloat32Array *)array;
- (void)useProgram:(DOMWebGLProgram *)program;
- (void)validateProgram:(DOMWebGLProgram *)program;
- (void)vertexAttrib1f:(unsigned)indx x:(float)x;
- (void)vertexAttrib1fv:(unsigned)indx values:(DOMFloat32Array *)values;
- (void)vertexAttrib2f:(unsigned)indx x:(float)x y:(float)y;
- (void)vertexAttrib2fv:(unsigned)indx values:(DOMFloat32Array *)values;
- (void)vertexAttrib3f:(unsigned)indx x:(float)x y:(float)y z:(float)z;
- (void)vertexAttrib3fv:(unsigned)indx values:(DOMFloat32Array *)values;
- (void)vertexAttrib4f:(unsigned)indx x:(float)x y:(float)y z:(float)z w:(float)w;
- (void)vertexAttrib4fv:(unsigned)indx values:(DOMFloat32Array *)values;
- (void)vertexAttribPointer:(unsigned)indx size:(int)size type:(unsigned)type normalized:(BOOL)normalized stride:(int)stride offset:(int)offset;
- (void)viewport:(int)x y:(int)y width:(int)width height:(int)height;
@end

#endif
