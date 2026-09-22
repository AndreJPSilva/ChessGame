#pragma once

#include "piece.hpp"

class Pawn : public Piece {

public:
    Pawn(Board* board, bool isWhite = false);

    const char* ToString() const override;
};
