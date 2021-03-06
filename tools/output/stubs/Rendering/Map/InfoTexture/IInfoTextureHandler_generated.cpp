#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IInfoTextureHandler.h"
#include "Legacy/LegacyInfoTextureHandler.h"
#include "Modern/InfoTextureHandler.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GlobalRendering.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"

IInfoTextureHandler* infoTextureHandler = nullptr;

void
IInfoTextureHandler::Create()
{
    if (globalRendering->haveGLSL && globalRendering->supportNPOTs &&
        glGenerateMipmap && FBO::IsSupported() && GLEW_ARB_texture_query_lod &&
        GLEW_VERSION_3_0) {
        try {
            infoTextureHandler = new CInfoTextureHandler();
        } catch (const opengl_error& glerr) {
            infoTextureHandler = nullptr;
        }
    }

    if (infoTextureHandler == nullptr) {
        infoTextureHandler = new CLegacyInfoTextureHandler();
    }

    if (!!dynamic_cast<CInfoTextureHandler*>(infoTextureHandler)) {
        LOG("InfoTexture: shaders");
    } else {
        LOG("InfoTexture: legacy");
    }
}
