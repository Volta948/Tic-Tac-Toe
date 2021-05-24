#pragma once

#include "Player.h"
#include "Board.h"

class Game {
public:
	const int Side{ 3 };

	explicit Game(Player p1, Player p2) :
		m_P1{ std::move(p1) }, m_P2{ std::move(p2) }
	{}

	virtual ~Game() = default;
	virtual void Play() = 0;
	virtual bool Won() const = 0;

	Board& GetBoard() {
		return m_Board;
	}

	const Player& GetPlayer(unsigned index) const {
		return index == 1 ? m_P1 : m_P2;
	}

	unsigned GetTurn() const {
		return m_P1Turn ? 1u : 2u;
	}

protected:
	Board m_Board{};
	Player m_P1, m_P2;
	bool m_P1Turn{};
};