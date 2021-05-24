#include "Algorithm.h"

int Algorithm::Minimax(Game& game, unsigned depth, bool isAI) {
	if (game.Won()) {
		return isAI ? -1 : +1;
	}
	else if (depth >= 9u) {
		return 0;
	}

	int score{}, bestScore{ isAI ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max() };
	for (auto& row : game.GetBoard()) {
		for (auto& elem : row) {
			if (elem == ' ') {
				elem = isAI ? game.GetPlayer(2).Sign : game.GetPlayer(1).Sign;
				score = Minimax(game, depth + 1u, !isAI);
				elem = ' ';
				bestScore = isAI ? std::max(score, bestScore) : std::min(score, bestScore);
			}
		}
	}
	return bestScore;
}

Move Algorithm::BestMove(Game& game, unsigned moveIndex) {
	Move move{ -1, -1 };
	int score{}, bestScore{ std::numeric_limits<int>::min() };

	for (int i{}; i < game.Side; ++i) {
		for (int j{}; j < game.Side; ++j) {
			auto& elem{ game.GetBoard()[i][j] };
			if (elem == ' ') {
				elem = game.GetPlayer(game.GetTurn()).Sign;
				score = Minimax(game, moveIndex + 1u, false);
				elem = ' ';

				if (score > bestScore) {
					bestScore = score;
					move = { i, j };
				}
			}
		}
	}
	return move;
}