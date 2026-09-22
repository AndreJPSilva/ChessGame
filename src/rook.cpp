#include "rook.hpp"

Rook::Rook(Board* board, bool isWhite) : Piece(board, isWhite) {}

const char* Rook::ToString() const { return IsWhite() ? "\u2656" : "\u265C";  }
