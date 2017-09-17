#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaConstGL.h"

#include "LuaInclude.h"

#include "LuaUtils.h"
#include "Rendering/GL/myGL.h"

/******************************************************************************/
/******************************************************************************/

bool
LuaConstGL::PushEntries(lua_State* L)
{
#define PUSH_GL(cmd) LuaPushNamedNumber(L, #cmd, GL_##cmd)

    // Drawing Primitives
    PUSH_GL(POINTS);
    PUSH_GL(LINES);
    PUSH_GL(LINE_LOOP);
    PUSH_GL(LINE_STRIP);
    PUSH_GL(TRIANGLES);
    PUSH_GL(TRIANGLE_STRIP);
    PUSH_GL(TRIANGLE_FAN);
    PUSH_GL(QUADS);
    PUSH_GL(QUAD_STRIP);
    PUSH_GL(POLYGON);

    // BlendingFactorDest
    PUSH_GL(ZERO);
    PUSH_GL(ONE);
    PUSH_GL(SRC_COLOR);
    PUSH_GL(ONE_MINUS_SRC_COLOR);
    PUSH_GL(SRC_ALPHA);
    PUSH_GL(ONE_MINUS_SRC_ALPHA);
    PUSH_GL(DST_ALPHA);
    PUSH_GL(ONE_MINUS_DST_ALPHA);

    // BlendingFactorSrc
    // GL_ZERO
    // GL_ONE
    PUSH_GL(DST_COLOR);
    PUSH_GL(ONE_MINUS_DST_COLOR);
    PUSH_GL(SRC_ALPHA_SATURATE);

    // AlphaFunction and  DepthFunction
    PUSH_GL(NEVER);
    PUSH_GL(LESS);
    PUSH_GL(EQUAL);
    PUSH_GL(LEQUAL);
    PUSH_GL(GREATER);
    PUSH_GL(NOTEQUAL);
    PUSH_GL(GEQUAL);
    PUSH_GL(ALWAYS);

    // LogicOp
    PUSH_GL(CLEAR);
    PUSH_GL(AND);
    PUSH_GL(AND_REVERSE);
    PUSH_GL(COPY);
    PUSH_GL(AND_INVERTED);
    PUSH_GL(NOOP);
    PUSH_GL(XOR);
    PUSH_GL(OR);
    PUSH_GL(NOR);
    PUSH_GL(EQUIV);
    PUSH_GL(INVERT);
    PUSH_GL(OR_REVERSE);
    PUSH_GL(COPY_INVERTED);
    PUSH_GL(OR_INVERTED);
    PUSH_GL(NAND);
    PUSH_GL(SET);

    // Culling
    PUSH_GL(BACK);
    PUSH_GL(FRONT);
    PUSH_GL(FRONT_AND_BACK);

    // PolygonMode
    PUSH_GL(POINT);
    PUSH_GL(LINE);
    PUSH_GL(FILL);

    // Clear Bits
    PUSH_GL(DEPTH_BUFFER_BIT);
    PUSH_GL(ACCUM_BUFFER_BIT);
    PUSH_GL(STENCIL_BUFFER_BIT);
    PUSH_GL(COLOR_BUFFER_BIT);

    // ShadeModel
    PUSH_GL(FLAT);
    PUSH_GL(SMOOTH);

    // MatrixMode
    PUSH_GL(MODELVIEW);
    PUSH_GL(PROJECTION);
    PUSH_GL(TEXTURE);

    // Texture Filtering
    PUSH_GL(NEAREST);
    PUSH_GL(LINEAR);
    PUSH_GL(NEAREST_MIPMAP_NEAREST);
    PUSH_GL(LINEAR_MIPMAP_NEAREST);
    PUSH_GL(NEAREST_MIPMAP_LINEAR);
    PUSH_GL(LINEAR_MIPMAP_LINEAR);

    // Texture Clamping
    PUSH_GL(REPEAT);
    PUSH_GL(MIRRORED_REPEAT);
    PUSH_GL(CLAMP);
    PUSH_GL(CLAMP_TO_EDGE);
    PUSH_GL(CLAMP_TO_BORDER);

    // Texture Environment
    PUSH_GL(TEXTURE_ENV);
    PUSH_GL(TEXTURE_ENV_MODE);
    PUSH_GL(TEXTURE_ENV_COLOR);
    PUSH_GL(MODULATE);
    PUSH_GL(DECAL);
    PUSH_GL(BLEND);
    PUSH_GL(REPLACE);
    PUSH_GL(TEXTURE_FILTER_CONTROL);
    PUSH_GL(TEXTURE_LOD_BIAS);

    // Texture Generation
    PUSH_GL(TEXTURE_GEN_MODE);
    PUSH_GL(EYE_PLANE);
    PUSH_GL(OBJECT_PLANE);
    PUSH_GL(EYE_LINEAR);
    PUSH_GL(OBJECT_LINEAR);
    PUSH_GL(SPHERE_MAP);
    PUSH_GL(NORMAL_MAP);
    PUSH_GL(REFLECTION_MAP);
    PUSH_GL(S);
    PUSH_GL(T);
    PUSH_GL(R);
    PUSH_GL(Q);

    // glPushAttrib() bits
    PUSH_GL(CURRENT_BIT);
    PUSH_GL(POINT_BIT);
    PUSH_GL(LINE_BIT);
    PUSH_GL(POLYGON_BIT);
    PUSH_GL(POLYGON_STIPPLE_BIT);
    PUSH_GL(PIXEL_MODE_BIT);
    PUSH_GL(LIGHTING_BIT);
    PUSH_GL(FOG_BIT);
    PUSH_GL(DEPTH_BUFFER_BIT);
    PUSH_GL(ACCUM_BUFFER_BIT);
    PUSH_GL(STENCIL_BUFFER_BIT);
    PUSH_GL(VIEWPORT_BIT);
    PUSH_GL(TRANSFORM_BIT);
    PUSH_GL(ENABLE_BIT);
    PUSH_GL(COLOR_BUFFER_BIT);
    PUSH_GL(HINT_BIT);
    PUSH_GL(EVAL_BIT);
    PUSH_GL(LIST_BIT);
    PUSH_GL(TEXTURE_BIT);
    PUSH_GL(SCISSOR_BIT);
    // PUSH_GL(ALL_ATTRIB_BITS);  // floating point clip
    LuaPushNamedNumber(L, "ALL_ATTRIB_BITS", -1.0f);

    // glHint() targets
    PUSH_GL(FOG_HINT);
    PUSH_GL(LINE_SMOOTH_HINT);
    PUSH_GL(POINT_SMOOTH_HINT);
    PUSH_GL(POLYGON_SMOOTH_HINT);
    PUSH_GL(PERSPECTIVE_CORRECTION_HINT);
    // glHint() modes
    PUSH_GL(DONT_CARE);
    PUSH_GL(FASTEST);
    PUSH_GL(NICEST);

    // Light Specification
    PUSH_GL(AMBIENT);
    PUSH_GL(DIFFUSE);
    PUSH_GL(SPECULAR);
    PUSH_GL(POSITION);
    PUSH_GL(SPOT_DIRECTION);
    PUSH_GL(SPOT_EXPONENT);
    PUSH_GL(SPOT_CUTOFF);
    PUSH_GL(CONSTANT_ATTENUATION);
    PUSH_GL(LINEAR_ATTENUATION);
    PUSH_GL(QUADRATIC_ATTENUATION);

    return true;
}

/******************************************************************************/
/******************************************************************************/
