#include "king.hpp"

King::King(Board* board, bool isWhite) : Piece(board, isWhite) { }

const char* King::ToString() const { return IsWhite() ? "\u2654" : "\u265A"; }

Moves King::PossibleMoves() const {
    Moves moves {};

    auto pos = GetPosition();

    if (!pos.has_value())
        return moves;

    Position next { pos.value().row - 1, pos.value().column };

    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row - 1;
    next.column = pos.value().column - 1;

    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row;
    next.column = pos.value().column - 1;

    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row + 1;
    next.column = pos.value().column - 1;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row + 1;
    next.column = pos.value().column;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row + 1;
    next.column = pos.value().column + 1;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row;
    next.column = pos.value().column + 1;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    next.row = pos.value().row - 1;
    next.column = pos.value().column + 1;
    
    if (m_board->CheckBoundries(next) && CanMove(next))
        moves[next.row][next.column] = true;

    return moves;
}
