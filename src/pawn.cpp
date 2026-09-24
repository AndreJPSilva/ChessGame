#include "pawn.hpp"
#include "position.hpp"

Pawn::Pawn(Board* board, bool isWhite) : Piece(board, isWhite) {}

const char* Pawn::ToString() const { return IsWhite() ? "\u2659" : "\u265F"; }

Moves Pawn::PossibleMoves() const {
    Moves moves {};

    auto pos = GetPosition();

    if (!pos.has_value())
        return moves;

    Position next { }, next2 { };

    if (IsWhite()) {
        next.row = pos.value().row - 1;
        next.column = pos.value().column;

        if (m_board->CheckBoundries(next) && m_board->At(next) == nullptr)
            moves[next.row][next.column] = true;

        next2.row = pos.value().row - 2;
        next2.column = pos.value().column;

        if (m_board->CheckBoundries(next) && m_board->At(next) == nullptr &&
            m_board->CheckBoundries(next2) && m_board->At(next2) == nullptr && m_move_count == 0)
            moves[next2.row][next2.column] = true;

        next.row = pos.value().row - 1;
        next.column = pos.value().column - 1;

        if (m_board->CheckBoundries(next) && m_board->At(next) != nullptr && !m_board->At(next)->Equals(this))
            moves[next.row][next.column] = true;

        next.row = pos.value().row - 1;
        next.column = pos.value().column + 1;

        if (m_board->CheckBoundries(next) && m_board->At(next) != nullptr && !m_board->At(next)->Equals(this))
            moves[next.row][next.column] = true;
    } else {
        next.row = pos.value().row + 1;
        next.column = pos.value().column;

        if (m_board->CheckBoundries(next) && m_board->At(next) == nullptr)
            moves[next.row][next.column] = true;

        next2.row = pos.value().row + 2;
        next2.column = pos.value().column;

        if (m_board->CheckBoundries(next) && m_board->At(next) == nullptr &&
            m_board->CheckBoundries(next2) && m_board->At(next2) == nullptr && m_move_count == 0)
            moves[next2.row][next2.column] = true;

        next.row = pos.value().row + 1;
        next.column = pos.value().column - 1;

        if (m_board->CheckBoundries(next) && m_board->At(next) != nullptr && !m_board->At(next)->Equals(this))
            moves[next.row][next.column] = true;

        next.row = pos.value().row + 1;
        next.column = pos.value().column + 1;

        if (m_board->CheckBoundries(next) && m_board->At(next) != nullptr && !m_board->At(next)->Equals(this))
            moves[next.row][next.column] = true;
    }
    
    return moves;
}
