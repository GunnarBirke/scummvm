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

#ifndef GLK_COMPREHEND_GAME_CC_H
#define GLK_COMPREHEND_GAME_CC_H

#include "glk/comprehend/game.h"

namespace Glk {
namespace Comprehend {

class CrimsonCrownGame : public ComprehendGame {
private:
	uint _diskNum;

private:
	/**
	 * Cutscene triggered when looking at crystal ball
	 */
	void crystalBallCutscene();

public:
	CrimsonCrownGame();
	~CrimsonCrownGame() override {}

	void beforeGame() override;
	void beforePrompt() override;
	void handleSpecialOpcode(uint8 operand) override;
	void synchronizeSave(Common::Serializer &s) override;

	void setupDisk(uint diskNum);
};

} // namespace Comprehend
} // namespace Glk

#endif
