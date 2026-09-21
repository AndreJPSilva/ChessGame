#pragma once

#include "board.hpp"

class Game {

    void Draw() const;
public:
    Game();

    ~Game();

    void Run(int argc, const char* argv[]);

private:
    Board m_board;
    bool m_is_checkmate;
};
