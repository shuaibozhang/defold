#ifndef DMGRAPHICS_VULKAN_DEFINES_H
#define DMGRAPHICS_VULKAN_DEFINES_H

#include <vulkan/vulkan.h>

typedef uint32_t GLuint;

#define VK_INVALID -1

// These defines don't have a Vulkan equivalent, so we
// just represent them as increasing number..
#define DMGRAPHICS_BUFFER_TYPE_COLOR_BIT      (0x1)
#define DMGRAPHICS_BUFFER_TYPE_DEPTH_BIT      (0x2)
#define DMGRAPHICS_BUFFER_TYPE_STENCIL_BIT    (0x4)

#define DMGRAPHICS_STATE_DEPTH_TEST           (0x1)
#define DMGRAPHICS_STATE_SCISSOR_TEST         (0x2)
#define DMGRAPHICS_STATE_STENCIL_TEST         (0x3)
#define DMGRAPHICS_STATE_ALPHA_TEST           (0x4)
#define DMGRAPHICS_STATE_BLEND                (0x5)
#define DMGRAPHICS_STATE_CULL_FACE            (0x6)
#define DMGRAPHICS_STATE_POLYGON_OFFSET_FILL  (0x7)
#define DMGRAPHICS_STATE_POLYGON_OFFSET_LINE  (0x8)
#define DMGRAPHICS_STATE_POLYGON_OFFSET_POINT (0x9)

#define DMGRAPHICS_TEXTURE_TYPE_2D            (0xa)
#define DMGRAPHICS_TEXTURE_TYPE_CUBE_MAP      (0xb)

// Note: We can't use VK_FILTER_LINEAR/NEAREST here since
//       mipmap and texture filtering is separated into
//       VkSamplerMipmapMode and VkFilter
#define DMGRAPHICS_TEXTURE_FILTER_LINEAR                 (0xc)
#define DMGRAPHICS_TEXTURE_FILTER_NEAREST                (0xd)
#define DMGRAPHICS_TEXTURE_FILTER_NEAREST_MIPMAP_NEAREST (0xe)
#define DMGRAPHICS_TEXTURE_FILTER_NEAREST_MIPMAP_LINEAR  (0xf)
#define DMGRAPHICS_TEXTURE_FILTER_LINEAR_MIPMAP_NEAREST  (0x10)
#define DMGRAPHICS_TEXTURE_FILTER_LINEAR_MIPMAP_LINEAR   (0x11)

#define DMGRAPHICS_RENDER_BUFFER_COLOR                   (0x12)
#define DMGRAPHICS_RENDER_BUFFER_DEPTH                   (0x13)
#define DMGRAPHICS_RENDER_BUFFER_STENCIL                 (0x14)
#define DMGRAPHICS_RENDER_BUFFER_COLOR_ATTACHMENT        (0x15)
#define DMGRAPHICS_RENDER_BUFFER_DEPTH_ATTACHMENT        (0x16)
#define DMGRAPHICS_RENDER_BUFFER_STENCIL_ATTACHMENT      (0x17)

// These defines do have a Vulkan equivalent,
// so we just use it directly.
#define DMGRAPHICS_PRIMITIVE_POINTS                         (0x1) // (VK_PRIMITIVE_TOPOLOGY_POINT_LIST)
#define DMGRAPHICS_PRIMITIVE_LINES                          (0x2) // (VK_PRIMITIVE_TOPOLOGY_LINE_LIST)
#define DMGRAPHICS_PRIMITIVE_LINE_STRIP                     (0x3) // (VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP)
#define DMGRAPHICS_PRIMITIVE_TRIANGLES                      (0x4) // (VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST)
#define DMGRAPHICS_PRIMITIVE_TRIANGLE_STRIP                 (0x5) // (VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP)
#define DMGRAPHICS_PRIMITIVE_TRIANGLE_FAN                   (0x6) // (VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN)
#define DMGRAPHICS_PRIMITIVE_LINE_LOOP                      (0x7) // (VK_INVALID)

// Types
#define DMGRAPHICS_TYPE_BYTE                                (VK_FORMAT_R8_SINT)
#define DMGRAPHICS_TYPE_UNSIGNED_BYTE                       (VK_FORMAT_R8_UINT)
#define DMGRAPHICS_TYPE_SHORT                               (VK_FORMAT_R16_SINT)
#define DMGRAPHICS_TYPE_UNSIGNED_SHORT                      (VK_FORMAT_R16_UINT)
#define DMGRAPHICS_TYPE_UNSIGNED_SHORT_4444                 (VK_FORMAT_R4G4B4A4_UNORM_PACK16)
#define DMGRAPHICS_TYPE_UNSIGNED_SHORT_565                  (VK_FORMAT_R5G6B5_UNORM_PACK16)
#define DMGRAPHICS_TYPE_INT                                 (VK_FORMAT_R32_SINT)
#define DMGRAPHICS_TYPE_UNSIGNED_INT                        (VK_FORMAT_R32_UINT)
#define DMGRAPHICS_TYPE_HALF_FLOAT                          (VK_FORMAT_R16_SFLOAT)
#define DMGRAPHICS_TYPE_FLOAT                               (VK_FORMAT_R32_SFLOAT)
#define DMGRAPHICS_TYPE_FLOAT_VEC4                          (VK_FORMAT_R32G32B32A32_SFLOAT)
#define DMGRAPHICS_TYPE_FLOAT_MAT4                          (VK_FORMAT_R32G32B32A32_SFLOAT)

// There's no sampler type in vulkan..
#define DMGRAPHICS_TYPE_SAMPLER_2D                          (VK_FORMAT_MAX_ENUM-1)
#define DMGRAPHICS_TYPE_SAMPLER_CUBE                        (VK_FORMAT_MAX_ENUM-2)

#define DMGRAPHICS_TEXTURE_FORMAT_LUMINANCE                 (VK_FORMAT_R8_UNORM)
#define DMGRAPHICS_TEXTURE_FORMAT_LUMINANCE_ALPHA           (VK_FORMAT_R8G8_UNORM)
#define DMGRAPHICS_TEXTURE_FORMAT_RGB                       (VK_FORMAT_R8G8B8_UINT)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA                      (VK_FORMAT_R8G8B8A8_UINT)

#define DMGRAPHICS_TEXTURE_WRAP_REPEAT                      (VK_SAMPLER_ADDRESS_MODE_REPEAT)
#define DMGRAPHICS_TEXTURE_WRAP_CLAMP_TO_BORDER             (VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER)
#define DMGRAPHICS_TEXTURE_WRAP_CLAMP_TO_EDGE               (VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE)
#define DMGRAPHICS_TEXTURE_WRAP_MIRRORED_REPEAT             (VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT)

#define DMGRAPHICS_BLEND_FACTOR_ZERO                        (0x0) // (VK_BLEND_FACTOR_ZERO)
#define DMGRAPHICS_BLEND_FACTOR_ONE                         (0x1) // (VK_BLEND_FACTOR_ONE)
#define DMGRAPHICS_BLEND_FACTOR_SRC_COLOR                   (0x2) // (VK_BLEND_FACTOR_SRC_COLOR)
#define DMGRAPHICS_BLEND_FACTOR_ONE_MINUS_SRC_COLOR         (0x3) // (VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR)
#define DMGRAPHICS_BLEND_FACTOR_DST_COLOR                   (0x4) // (VK_BLEND_FACTOR_DST_COLOR)
#define DMGRAPHICS_BLEND_FACTOR_ONE_MINUS_DST_COLOR         (0x5) // (VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR)
#define DMGRAPHICS_BLEND_FACTOR_SRC_ALPHA                   (0x6) // (VK_BLEND_FACTOR_SRC_ALPHA)
#define DMGRAPHICS_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA         (0x7) // (VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA)
#define DMGRAPHICS_BLEND_FACTOR_DST_ALPHA                   (0x8) // (VK_BLEND_FACTOR_DST_ALPHA)
#define DMGRAPHICS_BLEND_FACTOR_ONE_MINUS_DST_ALPHA         (0x9) // (VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA)
#define DMGRAPHICS_BLEND_FACTOR_SRC_ALPHA_SATURATE          (0xa) // (VK_BLEND_FACTOR_SRC_ALPHA_SATURATE)

#define DMGRAPHICS_COMPARE_FUNC_NEVER                       (0x0) // (VK_COMPARE_OP_NEVER)
#define DMGRAPHICS_COMPARE_FUNC_LESS                        (0x1) // (VK_COMPARE_OP_LESS)
#define DMGRAPHICS_COMPARE_FUNC_LEQUAL                      (0x2) // (VK_COMPARE_OP_LESS_OR_EQUAL)
#define DMGRAPHICS_COMPARE_FUNC_GREATER                     (0x3) // (VK_COMPARE_OP_GREATER)
#define DMGRAPHICS_COMPARE_FUNC_GEQUAL                      (0x4) // (VK_COMPARE_OP_GREATER_OR_EQUAL)
#define DMGRAPHICS_COMPARE_FUNC_EQUAL                       (0x5) // (VK_COMPARE_OP_EQUAL)
#define DMGRAPHICS_COMPARE_FUNC_NOTEQUAL                    (0x6) // (VK_COMPARE_OP_NOT_EQUAL)
#define DMGRAPHICS_COMPARE_FUNC_ALWAYS                      (0x7) // (VK_COMPARE_OP_ALWAYS)

// Stencil operation
#define DMGRAPHICS_STENCIL_OP_KEEP                          (0x0) // (VK_STENCIL_OP_KEEP)
#define DMGRAPHICS_STENCIL_OP_ZERO                          (0x1) // (VK_STENCIL_OP_ZERO)
#define DMGRAPHICS_STENCIL_OP_REPLACE                       (0x2) // (VK_STENCIL_OP_REPLACE)
#define DMGRAPHICS_STENCIL_OP_INCR                          (0x3) // (VK_STENCIL_OP_INCREMENT_AND_CLAMP)
#define DMGRAPHICS_STENCIL_OP_INCR_WRAP                     (0x4) // (VK_STENCIL_OP_INCREMENT_AND_WRAP)
#define DMGRAPHICS_STENCIL_OP_DECR                          (0x5) // (VK_STENCIL_OP_DECREMENT_AND_CLAMP)
#define DMGRAPHICS_STENCIL_OP_DECR_WRAP                     (0x6) // (VK_STENCIL_OP_DECREMENT_AND_WRAP)
#define DMGRAPHICS_STENCIL_OP_INVERT                        (0x7) // (VK_STENCIL_OP_INVERT)

#define DMGRAPHICS_BLEND_FACTOR_CONSTANT_COLOR              (VK_BLEND_FACTOR_CONSTANT_COLOR)
#define DMGRAPHICS_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR    (VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR)
#define DMGRAPHICS_BLEND_FACTOR_CONSTANT_ALPHA              (VK_BLEND_FACTOR_CONSTANT_ALPHA)
#define DMGRAPHICS_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA    (VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA)

// Note: Not sure any of this is applicable in Vulkan..
#define DMGRAPHICS_BUFFER_USAGE_STREAM_DRAW                 (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_STREAM_READ                 (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_STREAM_COPY                 (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_DYNAMIC_DRAW                (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_DYNAMIC_READ                (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_DYNAMIC_COPY                (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_STATIC_DRAW                 (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_STATIC_READ                 (VK_INVALID)
#define DMGRAPHICS_BUFFER_USAGE_STATIC_COPY                 (VK_INVALID)
#define DMGRAPHICS_BUFFER_ACCESS_READ_ONLY                  (VK_INVALID)
#define DMGRAPHICS_BUFFER_ACCESS_WRITE_ONLY                 (VK_INVALID)
#define DMGRAPHICS_BUFFER_ACCESS_READ_WRITE                 (VK_INVALID)

#define DMGRAPHICS_FACE_TYPE_FRONT                          (0x0) // (VK_CULL_MODE_FRONT_BIT)
#define DMGRAPHICS_FACE_TYPE_BACK                           (0x1) // (VK_CULL_MODE_BACK_BIT)
#define DMGRAPHICS_FACE_TYPE_FRONT_AND_BACK                 (0x2) // (VK_CULL_MODE_FRONT_AND_BACK)

#define DMGRAPHICS_RENDER_BUFFER_FORMAT_DEPTH_STENCIL       (VK_FORMAT_D24_UNORM_S8_UINT)
#define DMGRAPHICS_RENDER_BUFFER_FORMAT_DEPTH24             (VK_FORMAT_D24_UNORM_S8_UINT)
#define DMGRAPHICS_RENDER_BUFFER_FORMAT_DEPTH16             (VK_FORMAT_D16_UNORM)
#define DMGRAPHICS_RENDER_BUFFER_FORMAT_STENCIL             (VK_FORMAT_S8_UINT)

// These are taken from https://github.com/KhronosGroup/Vulkan-Samples/blob/master/external/include/vulkan/vk_format.h
#define DMGRAPHICS_TEXTURE_FORMAT_RGB_DXT1                  (VK_FORMAT_BC1_RGB_UNORM_BLOCK)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA_DXT1                 (VK_FORMAT_BC1_RGBA_UNORM_BLOCK)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA_DXT3                 (VK_FORMAT_BC3_UNORM_BLOCK)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA_DXT5                 (VK_FORMAT_BC2_UNORM_BLOCK)
#define DMGRAPHICS_TEXTURE_FORMAT_RGB_PVRTC_2BPPV1          (VK_FORMAT_UNDEFINED)
#define DMGRAPHICS_TEXTURE_FORMAT_RGB_PVRTC_4BPPV1          (VK_FORMAT_UNDEFINED)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA_PVRTC_2BPPV1         (VK_FORMAT_UNDEFINED)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA_PVRTC_4BPPV1         (VK_FORMAT_UNDEFINED)
#define DMGRAPHICS_TEXTURE_FORMAT_RGB_ETC1                  (VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK)
#define DMGRAPHICS_TEXTURE_FORMAT_RED                       (VK_FORMAT_R8_UNORM)
#define DMGRAPHICS_TEXTURE_FORMAT_RG                        (VK_FORMAT_R8G8_UNORM)
#define DMGRAPHICS_TEXTURE_FORMAT_RGB32F                    (VK_FORMAT_R32G32B32_SFLOAT)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA32F                   (VK_FORMAT_R32G32B32A32_SFLOAT)
#define DMGRAPHICS_TEXTURE_FORMAT_RGB16F                    (VK_FORMAT_R16G16B16_SFLOAT)
#define DMGRAPHICS_TEXTURE_FORMAT_RGBA16F                   (VK_FORMAT_R16G16B16A16_SFLOAT)
#define DMGRAPHICS_TEXTURE_FORMAT_R16F                      (VK_FORMAT_R16_SFLOAT)
#define DMGRAPHICS_TEXTURE_FORMAT_R32F                      (VK_FORMAT_R32_SFLOAT)
#define DMGRAPHICS_TEXTURE_FORMAT_RG16F                     (VK_FORMAT_R16G16_SFLOAT)
#define DMGRAPHICS_TEXTURE_FORMAT_RG32F                     (VK_FORMAT_R32G32_SFLOAT)

#define DMGRAPHICS_WINDOW_STATE_OPENED                      0x00020001
#define DMGRAPHICS_WINDOW_STATE_ACTIVE                      0x00020002
#define DMGRAPHICS_WINDOW_STATE_ICONIFIED                   0x00020003
#define DMGRAPHICS_WINDOW_STATE_ACCELERATED                 0x00020004
#define DMGRAPHICS_WINDOW_STATE_RED_BITS                    0x00020005
#define DMGRAPHICS_WINDOW_STATE_GREEN_BITS                  0x00020006
#define DMGRAPHICS_WINDOW_STATE_BLUE_BITS                   0x00020007
#define DMGRAPHICS_WINDOW_STATE_ALPHA_BITS                  0x00020008
#define DMGRAPHICS_WINDOW_STATE_DEPTH_BITS                  0x00020009
#define DMGRAPHICS_WINDOW_STATE_STENCIL_BITS                0x0002000A
#define DMGRAPHICS_WINDOW_STATE_REFRESH_RATE                0x0002000B
#define DMGRAPHICS_WINDOW_STATE_ACCUM_RED_BITS              0x0002000C
#define DMGRAPHICS_WINDOW_STATE_ACCUM_GREEN_BITS            0x0002000D
#define DMGRAPHICS_WINDOW_STATE_ACCUM_BLUE_BITS             0x0002000E
#define DMGRAPHICS_WINDOW_STATE_ACCUM_ALPHA_BITS            0x0002000F
#define DMGRAPHICS_WINDOW_STATE_AUX_BUFFERS                 0x00020010
#define DMGRAPHICS_WINDOW_STATE_STEREO                      0x00020011
#define DMGRAPHICS_WINDOW_STATE_WINDOW_NO_RESIZE            0x00020012
#define DMGRAPHICS_WINDOW_STATE_FSAA_SAMPLES                0x00020013

#define DMGRAPHICS_STATE_WRITE_R (0x1)
#define DMGRAPHICS_STATE_WRITE_G (0x2)
#define DMGRAPHICS_STATE_WRITE_B (0x4)
#define DMGRAPHICS_STATE_WRITE_A (0x8)

#endif