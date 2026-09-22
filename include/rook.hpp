#pragma once

#include "piece.hpp"

class Rook : public Piece {

public:
    Rook(Board* board, bool isWhite = false);

    const char* ToString() const override;
};
