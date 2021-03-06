//
// C++ Implementation: EntityCreatorMovement
//
// Description:
//
//
// Author: Erik Hjortsberg <erik.hjortsberg@gmail.com>, (C) 2009
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.//
//
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "EntityCreatorMovement.h"
#include "EntityCreatorMovementBridge.h"

namespace Ember
{
namespace OgreView
{

namespace Gui
{

EntityCreatorMovement::EntityCreatorMovement(EntityCreatorCreationInstance& creationInstance, const Camera::MainCamera& camera, Authoring::DetachedEntity& entity, Ogre::SceneNode* node) :
    mMoveAdapter(camera)
{
  // When the point is moved, an instance of this will be created and the movement handled by it.
  // Note that ownership will be transferred to the adapter, so we shouldn't keep a reference
  EntityCreatorMovementBridge* bridge = new EntityCreatorMovementBridge(creationInstance, entity, node);
  mMoveAdapter.attachToBridge(bridge);
  mMoveAdapter.update();
}

EntityCreatorMovement::~EntityCreatorMovement()
{
  mMoveAdapter.detach();
}

}

}
}
