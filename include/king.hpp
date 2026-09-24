#pragma once

#include "piece.hpp"

class King : public Piece {

public:
    King(Board* board, bool isWhite = false);

    const char* ToString() const override;

    Moves PossibleMoves() const override;
};
