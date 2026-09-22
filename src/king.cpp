#include "king.hpp"

King::King(Board* board, bool isWhite) : Piece(board, isWhite) { }

const char* King::ToString() const { return IsWhite() ? "\u2654" : "\u265A"; }
