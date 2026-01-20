#include "raylib.h"
#include "raymath.h"
#include "resource_dir.h"
#include "rlcpp-core.hpp"

constexpr int WindowWidth = 1280;
constexpr int WindowHeight = 800;
constexpr Color BackgroundColorDefault = WHITE;

int main() {
  raylib::SetConfigFlags({FLAG_WINDOW_HIGHDPI, FLAG_VSYNC_HINT});
  raylib::InitWindow(WindowWidth, WindowHeight, "Hello Raylib");
  SearchAndSetResourceDir("resources");

  raylib::ConfigFlags test = {FLAG_WINDOW_HIGHDPI, FLAG_VSYNC_HINT};
  ASSERT_EQUALS(test.to_integer(), FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT,
                "ConfigFlagsTest1");
  ASSERT_EQUALS(raylib::IsWindowState(test), true, "IsWindowStateTest1");
  raylib::ClearWindowState(test);
  ASSERT_EQUALS(raylib::IsWindowState(test), false, "ClearWindowStateTest1");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BackgroundColorDefault);
    EndDrawing();
  }

  CloseWindow();
}
