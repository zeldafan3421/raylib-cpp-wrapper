#include "raylib.h"
#include "raymath.h"
#include "resource_dir.h"
#include "rlcpp-core.hpp"
#include "rlcpp-text.hpp"

constexpr int WindowWidth = 1280;
constexpr int WindowHeight = 800;
constexpr Color BackgroundColorDefault = WHITE;

int main() {
  rlcore::SetConfigFlags({FLAG_WINDOW_HIGHDPI, FLAG_VSYNC_HINT});
  rlcore::InitWindow(WindowWidth, WindowHeight, "Hello Raylib");
  SearchAndSetResourceDir("resources");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BackgroundColorDefault);

    rltext::DrawText("Hello, World", 100, 100, 14, BLACK);

    EndDrawing();
  }

  CloseWindow();
}
