#pragma once

#include "piece.hpp"

class Knight : public Piece {

public:
    Knight(Board* board, bool isWhite = false);

    const char* ToString() const override;
};
