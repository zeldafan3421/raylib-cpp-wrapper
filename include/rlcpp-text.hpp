#pragma once

#include <exception>
#include <format>
#include <raylib.h>
#include <string>

#define RL_TEXT rltext
namespace RL_TEXT {
inline void DrawText(const std::string &text, int posX, int posY, int fontSize,
                     Color color) {
  ::DrawText(text.c_str(), posX, posY, fontSize, color);
}

inline void DrawFPS(int posX = 10, int posY = 10) { ::DrawFPS(posX, posY); }

inline void TextCopy(std::string &dst, std::string &src) { dst = src; }

inline bool TextIsEqual(const std::string &text1, const std::string &text2) {
  return text1.compare(text2) == 0;
}

inline unsigned int TextLength(const std::string &text) {
  return static_cast<unsigned int>(text.length());
}

inline const std::string TextSubtext(const std::string &text, int position,
                                     int length) {
  std::string substr = {};
  try {
    substr = text.substr(position, length);
  } catch (const std::exception &e) {
    TraceLog(LOG_WARNING, "Invalid substring: %s", e.what());
    substr = "";
  }
  return substr;
}

template <class... Args>
inline std::string TextFormat(std::string_view fmt, Args &&...args) {
  return std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...));
}

inline std::string TextReplace(const std::string &text,
                               const std::string &search,
                               const std::string &replacement) {
  const auto pos = text.find(search);
  if (pos == std::string::npos)
    return text;

  std::string response = std::string(text);
  try {
    response.replace(pos, search.length(), replacement);
  } catch (const std::exception &e) {
    TraceLog(LOG_WARNING, "Text replacement error : %s", e.what());
  }
  return response;
}

}; // namespace RL_TEXT
