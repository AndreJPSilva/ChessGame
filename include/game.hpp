#pragma once

#include "board.hpp"
#include "piece.hpp"

#include <set>

class Game {

    void Construct(bool isWhite);
    
    void Draw() const;

    void Clear() const;

    void ThrowIfMoveFrom(const Position& pos) const;

    void ThrowIfMoveTo(const Position& posX, const Position& posY) const;
    
    Piece* DoMove(const Position& posX, const Position posY);
public:
    Game();

    ~Game();

    void Run(int argc, const char* argv[]);

private:
    Board m_board;
    bool m_is_checkmate;
    bool m_is_white_turn;
    bool m_check;
    int m_turn;
    std::set<Piece*> m_pieces;
    std::set<Piece*> m_captured;
};
