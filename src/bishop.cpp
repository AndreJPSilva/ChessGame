#include "bishop.hpp"

Bishop::Bishop(Board* board, bool isWhite) : Piece(board, isWhite) {}

const char* Bishop::ToString() const { return IsWhite() ? "\u2657" : "\u265D"; }

Moves Bishop::PossibleMoves() const {
    Moves moves {};

    auto pos = GetPosition();

    if (!pos.has_value())
        return moves;

    Position next { pos.value().row - 1, pos.value().column - 1 };

    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.row--;
        next.column--;
    }

    next.row = pos.value().row - 1;
    next.column = pos.value().column + 1;
    
    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.row--;
        next.column++;
    }

    next.row = pos.value().row + 1;
    next.column = pos.value().column - 1;
    
    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.row++;
        next.column--;
    }

    next.row = pos.value().row + 1;
    next.column = pos.value().column + 1;

    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.row++;
        next.column++;
    }

    return moves;
}
