#pragma once

#include "piece.hpp"

class Game;

class Pawn : public Piece {

public:
    Pawn(Game* game, Board* board, bool isWhite = false);

    const char* ToString() const override;

    Moves PossibleMoves() const override;

private:
    Game* m_game;
};
