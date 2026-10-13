#ifndef JV_UNICODE_H
#define JV_UNICODE_H

// Returns the first byte in [in, end) that is not ASCII, or end.
static inline const char* jvp_utf8_skip_ascii(const char* in, const char* end) {
  while (in < end && !(*in & 0x80))
    in++;
  return in;
}

const char* jvp_utf8_backtrack(const char* start, const char* min, int *missing_bytes);
const char* jvp_utf8_next(const char* in, const char* end, int* codepoint);
int jvp_utf8_is_valid(const char* in, const char* end);

int jvp_utf8_decode_length(char startchar);

int jvp_utf8_encode_length(int codepoint);
int jvp_utf8_encode(int codepoint, char* out);

int jvp_codepoint_is_whitespace(int c);
#endif
