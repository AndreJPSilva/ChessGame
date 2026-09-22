#include "board.hpp"
#include "position.hpp"
#include "piece.hpp"
#include <optional>

const Piece* Board::At(int row, int col) const { return m_pieces[row][col]; }

const Piece* Board::At(const Position& pos) const { return m_pieces[pos.row][pos.column]; }

bool Board::IsEmpty(const Position& pos) const {
    ThrowIf(pos);
    return m_pieces[pos.row][pos.column] == nullptr;
}

bool Board::CheckBoundries(const Position& pos) const {
    return pos.row >= 0 && pos.row < Dimensions && pos.column >= 0 && pos.column < Dimensions;
}

void Board::Add(Piece* piece, const Position& pos) {
    if (!IsEmpty(pos))
        throw std::runtime_error("There is a piece in that position.");

    piece->SetPosition(pos);
    m_pieces[pos.row][pos.column] = piece;
}

Piece* Board::RemoveAt(const Position& pos) {
    auto piece = m_pieces[pos.row][pos.column];

    if (!piece)
        return nullptr;

    piece->SetPosition(std::nullopt);
    m_pieces[pos.row][pos.column] = piece;
    return piece;
}

void Board::ThrowIf(const Position& pos) const {
    if (!CheckBoundries(pos))
        throw std::runtime_error("Invalid Position.");
}
