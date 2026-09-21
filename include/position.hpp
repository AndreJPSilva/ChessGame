#pragma once

#include <istream>

struct Position {
    int row;
    int column;
};

std::istream& operator>>(std::istream& stream, Position& pos);
