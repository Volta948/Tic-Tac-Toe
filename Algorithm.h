#pragma once

#include <algorithm>
#include <limits>
#include "Game.h"
#include "Move.h"

namespace Algorithm {
	int Minimax(Game& game, unsigned depth, bool isAI);
	Move BestMove(Game& game, unsigned moveIndex);
}