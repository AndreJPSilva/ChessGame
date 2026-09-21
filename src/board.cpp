#include "board.hpp"

const Piece* Board::At(int row, int col) const { return m_pieces[row][col]; }
