#pragma once

#include <array>

class Piece;
struct Position;

class Board {

    void ThrowIf(const Position& pos) const;
public:
    static const int Dimensions { 8 };

    Board() = default;

    ~Board() = default;

    const Piece* At(int row, int col) const;

    const Piece* At(const Position& pos) const;

    Piece* At(const Position& pos);

    bool IsEmpty(const Position& pos) const;

    bool CheckBoundries(const Position& pos) const;

    void Add(Piece* piece, const Position& pos);

    Piece* RemoveAt(const Position& pos);
private:
    std::array<std::array<Piece*, Dimensions>, Dimensions> m_pieces;
};
