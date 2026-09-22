#pragma once

#include "board.hpp"
#include "piece.hpp"

#include <set>

class Game {

    void Construct(bool isWhite);
    
    void Draw() const;

    void Clear() const;
public:
    Game();

    ~Game();

    void Run(int argc, const char* argv[]);

private:
    Board m_board;
    bool m_is_checkmate;
    std::set<Piece*> m_pieces;
};
