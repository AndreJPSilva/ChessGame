#include "bishop.hpp"

Bishop::Bishop(Board* board, bool isWhite) : Piece(board, isWhite) {}

const char* Bishop::ToString() const { return IsWhite() ? "\u2657" : "\u265D"; }
