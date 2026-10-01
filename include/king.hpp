#pragma once

#include "piece.hpp"

class Game;

class King : public Piece {

public:
    King(Game* game, Board* board, bool isWhite = false);

    const char* ToString() const override;

    Moves PossibleMoves() const override;

private:
    Game* m_game;
};
