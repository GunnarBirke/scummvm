/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "petka/objects/text.h"
#include "petka/interfaces/interface.h"
#include "petka/q_system.h"
#include "petka/petka.h"
#include "petka/objects/object_cursor.h"

namespace Petka {

Interface::Interface()
	: _objUnderCursor(nullptr), _startIndex(0) {}

void Interface::setText(const Common::U32String &text, uint32 rgb) {
	_objs.push_back(new QText(text, rgb));
}

QVisibleObject *Interface::findObject(int resourceId) {
	for (uint i = 0; i < _objs.size(); ++i) {
		if (_objs[i]->_resourceId == resourceId) {
			return _objs[i];
		}
	}
	return nullptr;
}

void Interface::initCursor(int id, bool show, bool animate) {
	QObjectCursor *cursor = g_vm->getQSystem()->_cursor.get();
	_objs.push_back(cursor);
	cursor->_resourceId = id;
	cursor->_isShown = show;
	cursor->_animate = animate;
	cursor->_actionType = kActionLook;
	cursor->setCursorPos(cursor->_x, cursor->_y, 0);
}

} // End of namespace Petka