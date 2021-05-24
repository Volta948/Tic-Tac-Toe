#pragma once

#include "Algorithm.h"

class TicTacToe final : public Game {
public:
	explicit TicTacToe(Player p1, Player p2);

	void Play() override;
	bool Won() const override;

private:
	void Header() const;

	bool Row() const;
	bool Column() const;
	bool Diagonal() const;
	bool Draw(int moveIndex) const;

	void Instructions() const;
	Move SelectMove() const;
	bool IsValidMove(Move move) const;
	void ApplyMove(Move move);
	Move GetMove(unsigned moveIndex);
};