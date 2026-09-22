#include "knight.hpp"

Knight::Knight(Board* board, bool isWhite) : Piece(board, isWhite) { }

const char* Knight::ToString() const { return IsWhite() ? "\u2658" : "\u265E"; }
