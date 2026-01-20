#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <raylib.h>
#include <raymath.h>
#include <string_view>
#include <vector>

#define CPPRL raylib

namespace CPPRL {

#ifdef USE_RAII
#define
class Window {
public:
  inline Window(int width, int height, std::string_view title) {
    InitWindow(width, height, static_cast<const char *>(title.data()));
  }
  inline ~Window() { CloseWindow(); }
};
#else

inline void InitWindow(int width, int height, std::string_view title) {
  ::InitWindow(width, height, static_cast<const char *>(title.data()));
}
#endif

#define ASSERT_EQUALS(equation, value, name)                                   \
  TraceLog(LOG_INFO, equation == value ? "%s passed" : "%s failed", name)

class ConfigFlags {
  std::vector<::ConfigFlags> flags;

public:
  ConfigFlags(std::initializer_list<::ConfigFlags> _flags) {
    flags.reserve(_flags.size());
    flags.assign(_flags);
  }

  unsigned int to_integer() const {
    unsigned int response = 0;
    std::for_each(flags.begin(), flags.end(),
                  [&response](const ::ConfigFlags &flag) {
                    response |= static_cast<unsigned int>(flag);
                  });

    return response;
  }
};

inline void SetConfigFlags(const ConfigFlags &flags) {
  ::SetConfigFlags(flags.to_integer());
}

inline void ClearWindowState(const ConfigFlags &flags) {
  ::ClearWindowState(flags.to_integer());
}

inline bool IsWindowState(const ConfigFlags &flags) {
  return ::IsWindowState(flags.to_integer());
}

} // namespace CPPRL
