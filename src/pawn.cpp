#include "pawn.hpp"
#include "position.hpp"
#include "game.hpp"

Pawn::Pawn(Game* game, Board* board, bool isWhite) : Piece(board, isWhite), m_game(game) {}

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

    if (pos.value().row == 3) {
        Position leftPos { pos.value().row, pos.value().column - 1 };
        
        if (m_board->CheckBoundries(leftPos) && !m_board->IsEmpty(leftPos) &&
            !m_board->At(leftPos)->Equals(this) && m_game->IsVulnerableEnPassant(m_board->At(leftPos)))
            moves[leftPos.row - 1][leftPos.column] = true;

        Position rightPos { pos.value().row, pos.value().column + 1 };
        
        if (m_board->CheckBoundries(rightPos) && !m_board->IsEmpty(rightPos) &&
            !m_board->At(rightPos)->Equals(this) && m_game->IsVulnerableEnPassant(m_board->At(rightPos)))
            moves[rightPos.row - 1][rightPos.column] = true;
    } else if (pos.value().row == 4) {
        
        Position leftPos { pos.value().row, pos.value().column - 1 };
        
        if (m_board->CheckBoundries(leftPos) && !m_board->IsEmpty(leftPos) &&
            !m_board->At(leftPos)->Equals(this) && m_game->IsVulnerableEnPassant(m_board->At(leftPos)))
            moves[leftPos.row + 1][leftPos.column] = true;

        Position rightPos { pos.value().row, pos.value().column + 1 };
        
        if (m_board->CheckBoundries(rightPos) && !m_board->IsEmpty(rightPos) &&
            !m_board->At(rightPos)->Equals(this) && m_game->IsVulnerableEnPassant(m_board->At(rightPos)))
            moves[rightPos.row + 1][rightPos.column] = true;
    }
    
    return moves;
}
