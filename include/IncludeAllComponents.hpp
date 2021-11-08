/**
 * @file IncludeAllComponents.hpp
 * 
 * This is a shortcut include file that,
 * when included, includes every single
 * system and component implemented in the
 * project. This is solely a cleanliness
 * file.
 */

#pragma once

#include "Controls/ControlsComponent.hpp"
#include "Controls/ControlsUpdate.hpp"

#include "Physics/PhysicsSystem.hpp"
#include "Physics/GravityComponent.hpp"
#include "Physics/2DPlaneMovement.hpp"

#include "Rendering/RenderingSystem.hpp"
#include "Rendering/SquareComponent.hpp"
#include "Rendering/SpriteRenderer.hpp"

#include "Rendering/UI/TextRenderer.hpp"
#include "Rendering/UI/AnimatedTextRenderer.hpp"
#include "Rendering/UI/Fonts.hpp"

#include "Rendering/Camera.hpp"