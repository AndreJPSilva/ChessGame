#pragma once

class Game {

public:
    Game();

    ~Game();

    void Run(int argc, const char* argv[]);

private:
    bool m_is_checkmate;
};
