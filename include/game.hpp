#pragma once

#include "board.hpp"
#include "piece.hpp"

#include <set>

class Game {

	void Construct(bool isWhite);

	void Draw() const;

	void Update(const Position& pos) const;

	void Clear() const;

	void ThrowIfMoveFrom(const Position& pos) const;

	void ThrowIfMoveTo(const Position& posX, const Position& posY) const;

	void TurnRound();

	std::set<Piece*> Captured(bool isWhiteTurn) const;

	std::set<Piece*> AvailablePieces(bool isWhiteTurn) const;

	const Piece* GetKing(bool isWhiteTurn) const;

	bool IsInCheck(bool isWhiteTurn) const;

	bool IsCheckMate(bool isWhiteTurn);

	Piece* DoMove(const Position& posX, const Position& posY);

	void UndoMove(const Position& posX, const Position& posY, Piece* target);

	void Move(const Position& posX, const Position& posY);
public:
	Game();

	~Game();

	void Run(int argc, const char* argv[]);

	bool IsVulnerableEnPassant(const Piece* other) const;

private:
	Board m_board;
	bool m_is_checkmate;
	bool m_is_white_turn;
	bool m_check;
	int m_turn;
	Piece* m_vulnerableEnPassant;
	std::set<Piece*> m_pieces;
	std::set<Piece*> m_captured;
};
