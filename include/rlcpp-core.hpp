#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <raylib.h>
#include <raymath.h>
#include <rlcpp-text.hpp>
#include <string_view>
#include <vector>

namespace rlcore {

#define ASSERT_EQUALS(equation, value, name)                                   \
  TraceLog(LOG_INFO, equation == value ? "%s passed" : "%s failed", name)

class ConfigFlagSet {
  unsigned int mask = 0;

public:
  constexpr ConfigFlagSet() = default;

  constexpr ConfigFlagSet(std::initializer_list<::ConfigFlags> flags) {
    for (auto flag : flags) {
      mask |= static_cast<unsigned int>(flag);
    }
  }

  constexpr unsigned int to_integer() const { return mask; }
};

inline void InitWindow(int width, int height, std::string_view title) {
  const std::string tmp(title);
  ::InitWindow(width, height, tmp.c_str());
}

inline void SetConfigFlags(const ConfigFlagSet &flags) {
  ::SetConfigFlags(flags.to_integer());
}

inline void ClearWindowState(const ConfigFlagSet &flags) {
  ::ClearWindowState(flags.to_integer());
}

inline bool IsWindowState(const ConfigFlagSet &flags) {
  return ::IsWindowState(flags.to_integer());
}

template <class... Args>
inline void TraceLog(TraceLogLevel level, std::string_view fmt,
                     Args &&...args) {
  TraceLog(level, std::vformat(
                      fmt, std::make_format_args(std::forward<Args>(args)...)));
}

inline bool FileExists(const std::string &fileName) {
  return ::FileExists(fileName.c_str());
}

inline bool DirectoryExists(const std::string &dirPath) {
  return ::DirectoryExists(dirPath.c_str());
}

inline bool IsFileExtension(const std::string &fileName,
                            const std::string &ext) {
  return ::IsFileExtension(fileName.c_str(), ext.c_str());
}

inline int GetFileLength(const std::string &fileName) {
  return ::GetFileLength(fileName.c_str());
}

inline std::string GetFileExtension(const std::string &fileName) {
  return ::GetFileExtension(fileName.c_str());
}

inline std::string GetFileName(const std::string &fileName) {
  return ::GetFileName(fileName.c_str());
}

inline std::string GetFileNameWithoutExt(const std::string &filePath) {
  return ::GetFileNameWithoutExt(filePath.c_str());
}

inline std::string GetDirectoryPath(const std::string &filePath) {
  return ::GetDirectoryPath(filePath.c_str());
}

inline std::vector<unsigned char> LoadFileData(const std::string &fileName) {
  int filesize = 0;
  auto filedata = ::LoadFileData(fileName.c_str(), &filesize);

  if (filesize <= 0)
    return std::vector<unsigned char>();

  std::vector<unsigned char> data = {filedata, filedata + filesize};

  UnloadFileData(filedata);
  return data;
}

} // namespace rlcore
