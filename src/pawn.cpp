#include "pawn.hpp"

Pawn::Pawn(Board* board, bool isWhite) : Piece(board, isWhite) {}

const char* Pawn::ToString() const { return IsWhite() ? "\u2659" : "\u265F"; }
