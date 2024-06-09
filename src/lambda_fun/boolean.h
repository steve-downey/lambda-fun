// lambda_fun/boolean.h                                               -*-C++-*-
#ifndef INCLUDED_LAMBDA_FUN_BOOLEAN
#define INCLUDED_LAMBDA_FUN_BOOLEAN

namespace lambda_fun {

auto constexpr inline True = [](auto t, auto /*f*/) { return t; };
auto constexpr inline False = [](auto /*t*/, auto f) { return f; };

auto constexpr inline And = [](auto x, auto y) {
    return [x, y](auto t, auto f) { return x(y(t, f), f); };
};

auto constexpr inline Or = [](auto x, auto y) {
    return [x, y](auto t, auto f) { return x(t, y(t, f)); };
};

auto constexpr inline Not = [](auto x) {
    return [x](auto t, auto f) { return x(f, t); };
};

auto constexpr inline toBool = [](auto b) { return b([]{return true;},
                                                     []{return false;}); };

} // namespace lambda_fun

#endif
