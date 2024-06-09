// lambda_fun/pair.h                                               -*-C++-*-
#ifndef INCLUDED_LAMBDA_FUN_PAIR
#define INCLUDED_LAMBDA_FUN_PAIR

#include <lambda_fun/boolean.h>

namespace lambda_fun {

auto constexpr inline Pair = [](auto f, auto s) { return [f,s](auto b){return b(f,s);}; };
auto constexpr inline Fst = [](auto p) { return p(True); };
auto constexpr inline Snd = [](auto p) { return p(False); };

} // namespace lambda_fun

#endif
