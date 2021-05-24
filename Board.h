#pragma once

#include <iostream>
#include <iomanip>
#include <array>
#include "Sign.h"

using Board = std::array<std::array<Sign, 3>, 3>;

namespace Helper {
	inline void ShowBoard(const Board& board) {
		std::cout << "\n\t\t\t " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << '\n';
		std::cout << "\t\t\t-----------\n";
		std::cout << "\t\t\t " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << '\n';
		std::cout << "\t\t\t-----------\n";
		std::cout << "\t\t\t " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
	}
}