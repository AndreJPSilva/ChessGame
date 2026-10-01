#include "king.hpp"
#include "game.hpp"
#include "position.hpp"
#include "rook.hpp"

King::King(Game* game, Board* board, bool isWhite) : Piece(board, isWhite), m_game(game) { }

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


    // Short Castling
    if (!WasMove() && !m_game->Check()) {
        Position rookPos { pos.value().row, pos.value().column + 3 };
        auto rook = dynamic_cast<Rook*>(m_board->At(rookPos));

        if (rook && rook->Equals(this) && !rook->WasMove()) {
            Position pos1 { pos.value().row, pos.value().column + 1 };
            Position pos2 { pos.value().row, pos.value().column + 2 };

            if (m_board->IsEmpty(pos1) && m_board->IsEmpty(pos2))
                moves[pos2.row][pos2.column] = true;
        }   
    }

    // Long Caastling
    if (!WasMove() && !m_game->Check()) {
        Position rookPos { pos.value().row, pos.value().column - 4 };
        auto rook = dynamic_cast<Rook*>(m_board->At(rookPos));

        if (rook && rook->Equals(this) && !rook->WasMove()) {
            Position pos1 { pos.value().row, pos.value().column - 1 };
            Position pos2 { pos.value().row, pos.value().column - 2 };
            Position pos3 { pos.value().row, pos.value().column - 3 };

            if (m_board->IsEmpty(pos1) && m_board->IsEmpty(pos2) && m_board->IsEmpty(pos3))
                moves[pos2.row][pos2.column] = true;
        }
    }
    
    return moves;
}
