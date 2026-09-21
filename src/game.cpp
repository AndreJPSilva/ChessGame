#include "game.hpp"
#include "position.hpp"

#include <print>
#include <iostream>

void Game::Draw() const {

#if _WIN32
    system("cls");
#else
    system("clear");
#endif

    for (int row{}; row < Board::Dimensions; row++) {
        std::print("{0} ", Board::Dimensions - row);
        for (int col{}; col < Board::Dimensions; col++) {
            if (auto piece = m_board.At(row, col)) {
                // piece->ToString();
            } else {
                std::print("{0} ", "\u00B7");
            }
        }
        std::println("");
    }   
    std::println("  A B C D E F G H");
}

Game::Game() 
    : m_board(), m_is_checkmate() {
}

Game::~Game() {
    
}

void Game::Run(int argc, const char* argv[]) {
    // Do something with args

    Position x, y;
    
    Draw();
    
    do {
        try {
            std::print("\nFrom: ");
            std::cin >> x;

            // Update

            std::print("\nTo: ");
            std::cin >> y;

            // Move

            Draw();
        } catch (std::runtime_error& e) {
            Draw();
            std::println("\n{0}", e.what());
        }
    } while (!m_is_checkmate);
}
