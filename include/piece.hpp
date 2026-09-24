#pragma once

#include "board.hpp"
#include "position.hpp"

#include <optional>
#include <array>

using Moves = std::array<std::array<bool, Board::Dimensions>, Board::Dimensions>;

class Piece {

public:
    Piece(Board* board, bool isWhite);

    virtual ~Piece() = default;

    virtual const char* ToString() const = 0;

    virtual Moves PossibleMoves() const = 0;

    bool PossibleMove(const Position& pos) const;

    bool AnyPossibleMove() const;

    bool CanMove(const Position& pos) const;

    bool Equals(const Piece* other) const;
    
    bool IsWhite() const;

    std::optional<Position> GetPosition() const;

    void SetPosition(std::optional<Position> pos);

    void IncreaseMove();

    void DecreaseMove();

protected:  
    Board* m_board;
    int m_move_count;
private:
    bool m_is_white;
    std::optional<Position> m_pos;
};
