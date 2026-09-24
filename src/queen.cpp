#include "queen.hpp"

Queen::Queen(Board* board, bool isWhite) : Piece(board, isWhite) {}

const char* Queen::ToString() const { return IsWhite() ? "\u2655" : "\u265B"; }

Moves Queen::PossibleMoves() const {
    Moves moves {};

    auto pos = GetPosition();

    if (!pos.has_value())
        return moves;

    Position next { pos.value().row - 1, pos.value().column };

    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.row--;
    }

    next.row = pos.value().row - 1;
    next.column = pos.value().column - 1;
    
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

    next.row = pos.value().row;
    next.column = pos.value().column - 1;
    
    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.column--;
    }

    next.row = pos.value().row;
    next.column = pos.value().column + 1;
    
    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.column++;
    }

    next.row = pos.value().row + 1;
    next.column = pos.value().column;
    
    while (m_board->CheckBoundries(next) && CanMove(next)) {
        moves[next.row][next.column] = true;
        if (m_board->At(next) && !m_board->At(next)->Equals(this))
            break;
        next.row++;
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
