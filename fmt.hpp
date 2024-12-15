#pragma once

#ifndef __cplusplus
#error "This header is for C++ only"
#endif

#include <cstdarg>
#include <cstring>
#include <string>

#if defined(_WIN32)
#define FMT_ATTR(fmt, args)
#else
#define FMT_ATTR(fmt, args) __attribute__((format(printf, fmt, args)))
#endif

FMT_ATTR(1, 2)
static std::string fmt(const char* fmt, ...) {
  va_list ap;
  va_list ap2;
  va_start(ap, fmt);
  va_copy(ap2, ap);
  const int size = vsnprintf(NULL, 0, fmt, ap);
  std::string buf;
  buf.resize(size);
  const int size2 =
      vsnprintf(const_cast<char*>(buf.data()), buf.size() + 1, fmt, ap2);
  va_end(ap2);
  va_end(ap);

  return buf;
}

