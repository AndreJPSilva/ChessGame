#include "knight.hpp"

Knight::Knight(Board* board, bool isWhite) : Piece(board, isWhite) { }

const char* Knight::ToString() const { return IsWhite() ? "\u2658" : "\u265E"; }

Moves Knight::PossibleMoves() const {
    Moves moves {};

    auto pos = GetPosition();

    if (!pos.has_value())
        return moves;

    Position next { pos.value().row - 2, pos.value().column - 1 };

    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row - 2;
    next.column = pos.value().column + 1;

    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row - 1;
    next.column = pos.value().column + 2;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row - 1;
    next.column = pos.value().column - 2;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row + 2;
    next.column = pos.value().column - 1;

    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row + 2;
    next.column = pos.value().column + 1;

    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row + 1;
    next.column = pos.value().column + 2;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row + 1;
    next.column = pos.value().column - 2;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    return moves;
}
