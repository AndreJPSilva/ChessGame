#include "game.hpp"

auto main(int argc, const char* argv[]) -> int {
    Game game{};
    game.Run(argc, argv);
    return 0;
}
