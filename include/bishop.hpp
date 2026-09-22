#pragma once

#include "piece.hpp"

class Bishop : public Piece {

public:
    Bishop(Board* board, bool isWhite = false);

    const char* ToString() const override;
};
