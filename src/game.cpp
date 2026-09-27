#include "game.hpp"
#include "position.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "knight.hpp"

#include <print>
#include <iostream>
#include <stdexcept>

void Game::Construct(bool isWhite) {
    for (int col{}; col < Board::Dimensions; col++) {
        auto pawn = new Pawn(&m_board, isWhite);
        m_board.Add(pawn, { isWhite ? 6 : 1, col });
        m_pieces.insert(pawn);
    }

    auto rook = new Rook(&m_board, isWhite);
    m_board.Add(rook, { isWhite ? 7 : 0, 0});
    m_pieces.insert(rook);

    rook = new Rook(&m_board, isWhite);
    m_board.Add(rook, { isWhite ? 7 : 0, 7 });
    m_pieces.insert(rook);

    auto king = new King(&m_board, isWhite);
    m_board.Add(king, { isWhite ? 7 : 0, 4 });
    m_pieces.insert(king);

    auto queen = new Queen(&m_board, isWhite);
    m_board.Add(queen, { isWhite ? 7 : 0, 3 });
    m_pieces.insert(queen);
    
    auto bishop = new Bishop(&m_board, isWhite);
    m_board.Add(bishop, { isWhite ? 7 : 0, 2});
    m_pieces.insert(bishop);

    bishop = new Bishop(&m_board, isWhite);
    m_board.Add(bishop, { isWhite ? 7 : 0, 5});

    auto knight = new Knight(&m_board, isWhite);
    m_board.Add(knight, { isWhite ? 7 : 0, 1 });
    m_pieces.insert(knight);

    knight = new Knight(&m_board, isWhite);
    m_board.Add(knight, { isWhite ? 7 : 0, 6 });
    m_pieces.insert(knight);
}

void Game::Draw() const {
    for (int row{}; row < Board::Dimensions; row++) {
        std::print("{0} ", Board::Dimensions - row);
        for (int col{}; col < Board::Dimensions; col++) {
            if (auto piece = m_board.At(row, col)) {
                std::print("{0} ", piece->ToString());
            } else {
                std::print("{0} ", "\u00B7");
            }
        }
        std::println("");
    }   
    std::println("  A B C D E F G H");
}

void Game::Update(const Position& pos) const {
    auto moves = m_board.At(pos)->PossibleMoves();

    for (int row{}; row < Board::Dimensions; row++) {
        std::print("{0} ", Board::Dimensions - row);
        for (int col{}; col < Board::Dimensions; col++) {
            if (moves[row][col]) {
                if (row > pos.row && col == pos.column)
                    std::print("{0} ", "\u2193");
                else if (row < pos.row && col == pos.column) 
                    std::print("{0} ", "\u2191");
                else if (row == pos.row && col < pos.column)
                    std::print("{0} ", "\u2190");
                else if (row == pos.row && col > pos.column)
                    std::print("{0} ", "\u2192");
                else if (row > pos.row && col > pos.column)
                    std::print("{0} ", "\u2198");
                else if (row < pos.row && col > pos.column)
                    std::print("{0} ", "\u2197");
                else if (row > pos.row && col < pos.column)
                    std::print("{0} ", "\u2199");
                else if (row < pos.row && col < pos.column)
                    std::print("{0} ", "\u2196");
            } else {
                if (auto piece = m_board.At(row, col))
                    std::print("{0} ", piece->ToString());
                else 
                    std::print("{0} ", "\u00B7");
            }
        }
        std::println("");
    }
    std::println("  A B C D E F G H");
}

void Game::Clear() const {
#if _WIN32
    system("cls");
#else
    system("clear");
#endif   
}

Game::Game() 
    : m_board(), m_is_checkmate(), m_is_white_turn(true), m_check(), m_turn(1) {
}

Game::~Game() {
    for (auto piece : m_pieces)
        delete piece;
}

void Game::Run(int argc, const char* argv[]) {
    // Do something with args
    Construct(true);

    Construct(false);

    Position x, y;

    Clear();
    
    Draw();
    
    do {
        try {
            std::print("\nFrom: ");
            std::cin >> x;
            ThrowIfMoveFrom(x);

            Clear();
            
            Update(x);

            std::print("\nTo: ");
            std::cin >> y;
            ThrowIfMoveTo(x, y);

            // Move

            DoMove(x, y);
            
            Clear();
            
            Draw();
        } catch (std::runtime_error& e) {
            Clear();
            
            Draw();
            
            std::println("\n{0}", e.what());
        }
    } while (!m_is_checkmate);
}

void Game::ThrowIfMoveFrom(const Position& pos) const {
    if (m_board.IsEmpty(pos))
        throw std::runtime_error("There is no piece the chosen position.");

    if (!(m_board.At(pos)->IsWhite() && m_is_white_turn))
        throw std::runtime_error("The chosen piece is not yours.");

    if (!m_board.At(pos)->AnyPossibleMove())
        throw std::runtime_error("The are not possible movements to that piece.");    
}

void Game::ThrowIfMoveTo(const Position& posX, const Position& posY) const {
    if (!m_board.At(posX)->PossibleMove(posY))
        throw std::runtime_error("Invalid movement.");
}

Piece* Game::DoMove(const Position& posX, const Position posY) {
    auto self = m_board.RemoveAt(posX);
    self->IncreaseMove();

    auto target = m_board.RemoveAt(posY);

    if (target)
        m_captured.insert(target);

    m_board.Add(self, posY);

    return target;
}
