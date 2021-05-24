#include "TicTacToe.h"
#include <memory>

enum class GameType {
	TicTacToe
};

std::unique_ptr<Game> SelectGame(GameType type) {
	Player p0{ 'X', "Human" }, p1{ 'O', "Computer" };
	switch (type) {
	case GameType::TicTacToe:
		return std::make_unique<TicTacToe>(std::move(p0), std::move(p1));
		break;
	}
	return {};
}

int main() {
	bool play{ true };
	while (play) {
		auto game{ SelectGame(GameType::TicTacToe) };
		game->Play();

		std::cout << "Another game? 0(NO) or 1(YES)\n";
		std::cin >> play;
		system("cls"); // clear the console (Windows only)
	}
	std::cout << "Goodbye!\n";
}