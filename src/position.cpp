#include "position.hpp"
#include "board.hpp"

#include <stdexcept>

std::istream& operator>>(std::istream& stream, Position& pos) {
    char col;
    int row;

    stream >> col >> row;

    if (row <= 0 || row > Board::Dimensions || col < 'a' || col > 'h' || stream.gcount() > 2) {
        stream.clear();
        throw std::runtime_error("Wrong coordinates. Please try again.");
    }

    pos.row = Board::Dimensions - row;
    pos.column = col - 'a';

    return stream;
}
