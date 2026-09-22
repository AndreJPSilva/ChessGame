#include "queen.hpp"

Queen::Queen(Board* board, bool isWhite) : Piece(board, isWhite) {}

const char* Queen::ToString() const { return IsWhite() ? "\u2655" : "\u265B"; }
