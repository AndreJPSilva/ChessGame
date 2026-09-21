#pragma once

#include <array>

class Piece;

class Board {

public:
    static const int Dimensions { 8 };

    Board() = default;

    ~Board() = default;

    const Piece* At(int row, int col) const;

private:
    std::array<std::array<Piece*, Dimensions>, Dimensions> m_pieces;
};
