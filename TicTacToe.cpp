#include "TicTacToe.h"

TicTacToe::TicTacToe(Player p1, Player p2) :
	Game(std::move(p1), std::move(p2))
{
	for (auto& row : m_Board) {
		row.fill(' ');
	}
	Header();
}

void TicTacToe::Play() {
	std::cout << "Do you want to start first? (1)YES or (0)NO: ";
	std::cin >> m_P1Turn;
	Instructions();

	unsigned moveIndex{};
	bool won{}, draw{};
	while (!won && !draw) {
		ApplyMove(GetMove(moveIndex));

		++moveIndex;
		m_P1Turn = !m_P1Turn;

		won = Won();
		draw = Draw(moveIndex);
	}
	std::cout << (won ? (!m_P1Turn ? m_P1.Name : m_P2.Name) + " has won\n" : "It's a draw\n");
}

bool TicTacToe::Won() const {
	return Row() || Column() || Diagonal();
}

bool TicTacToe::Draw(int moveIndex) const {
	return moveIndex == Side * Side;
}

bool TicTacToe::IsValidMove(Move move) const {
	const auto maxSize{ Side * Side };
	return move.x >= 0 && move.x < maxSize && move.y >= 0 && move.y < maxSize && m_Board[move.x][move.y] == ' ';
}

void TicTacToe::ApplyMove(Move move) {
	const auto& currentPlayer{ m_P1Turn ? m_P1 : m_P2 };
	m_Board[move.x][move.y] = currentPlayer.Sign;

	std::cout << currentPlayer.Name << " has put a " << currentPlayer.Sign 
			  << " in cell " << (move.x * 3 + move.y) + 1 << '\n';
	Helper::ShowBoard(m_Board);
}

Move TicTacToe::GetMove(unsigned moveIndex) {
	Move move{ -1, -1 };
	if (m_P1Turn) {
		while (!IsValidMove(move)) {
			move = SelectMove();
		}
	}
	else {
		move = Algorithm::BestMove(*this, moveIndex);
	}
	return move;
}

void TicTacToe::Header() const {
	using namespace std;
	cout << setw(69) << setfill('-') << '\n'
		 << setw(40) << setfill(' ') << "Tic-Tac-Toe\n"
		 << setw(70) << setfill('-') << "\n\n" << setfill(' ');
}

bool TicTacToe::Row() const {
	for (const auto& row : m_Board) {
		if (row[0] == row[1] && row[1] == row[2] && row[0] != ' ') {
			return true;
		}
	}
	return false;
}

bool TicTacToe::Column() const {
	for (int i{}; i < Side; i++) {
		if (m_Board[0][i] == m_Board[1][i] && m_Board[1][i] == m_Board[2][i] && m_Board[0][i] != ' ') {
			return true;
		}
	}
	return false;
}

bool TicTacToe::Diagonal() const {
	return m_Board[0][0] == m_Board[1][1] && m_Board[1][1] == m_Board[2][2] && m_Board[0][0] != ' '
		|| m_Board[0][2] == m_Board[1][1] && m_Board[1][1] == m_Board[2][0] && m_Board[0][2] != ' ';
}

void TicTacToe::Instructions() const {
	Helper::ShowBoard({ '1', '2', '3', '4', '5', '6', '7', '8', '9' });
}

Move TicTacToe::SelectMove() const {
	std::cout << "You can insert in the following positions: ";
	for (int i{}; i < Side; ++i) {
		for (int j{}; j < Side; ++j) {
			if (m_Board[i][j] == ' ') {
				std::cout << (i * 3 + j) + 1 << ' ';
			}
		}
	}
	std::cout << "\nEnter the position: ";
	int n;
	std::cin >> n;
	--n;
	return { n / Side, n % Side };
}