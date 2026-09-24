#include "piece.hpp"
#include "position.hpp"

Piece::Piece(Board* board, bool isWhite) {
    m_board = board;
    m_is_white = isWhite;
    m_move_count = 0;
    m_pos = std::nullopt;
}

bool Piece::PossibleMove(const Position& pos) const {
    return PossibleMoves()[pos.row][pos.column];
}

bool Piece::AnyPossibleMove() const {
    auto moves = PossibleMoves();

    for (int row{}; row < Board::Dimensions; row++) {
        for (int col{}; col < Board::Dimensions; col++)
            if (moves[row][col])
                return true;
    }

    return false;
}

bool Piece::CanMove(const Position& pos) const {
    auto other = m_board->At(pos);
    return other == nullptr || !Equals(other);    
}

bool Piece::Equals(const Piece* other) const {
    if (other == nullptr)
        return false;

    return (IsWhite() && other->IsWhite()) || (!IsWhite() && !other->IsWhite()); 
}

bool Piece::IsWhite() const { return m_is_white; }

std::optional<Position> Piece::GetPosition() const { return m_pos; }

void Piece::SetPosition(std::optional<Position> pos) { m_pos = pos; }

void Piece::IncreaseMove() { m_move_count++; }

void Piece::DecreaseMove() { m_move_count--; }
