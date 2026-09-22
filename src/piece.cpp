#include "piece.hpp"
#include "position.hpp"

Piece::Piece(Board* board, bool isWhite) {
    m_board = board;
    m_is_white = isWhite;
    m_move_count = 0;
    m_pos = std::nullopt;
}

bool Piece::IsWhite() const { return m_is_white; }

std::optional<Position> Piece::GetPosition() const { return m_pos; }

void Piece::SetPosition(std::optional<Position> pos) { m_pos = pos; }

void Piece::IncreaseMove() { m_move_count++; }

void Piece::DecreaseMove() { m_move_count--; }
