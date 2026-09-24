#pragma once

#include "piece.hpp"

class Queen : public Piece {

public:
    Queen(Board* board, bool isWhite = false);

    const char* ToString() const override;

    Moves PossibleMoves() const override;
};
