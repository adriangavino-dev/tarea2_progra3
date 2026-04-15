#ifndef TAREASPROGRA_CORE_NUMERIC_H
#define TAREASPROGRA_CORE_NUMERIC_H

#include <concepts>
#include <iterator>
#include <type_traits>
#include <vector>

namespace core_numeric {
    using namespace std;

    template <typename C>
    concept Iterable = requires (C c) {
        begin(c);
        end(c);
    };

    template <typename T>
    concept Addable = requires (T a, T b) {
        { a + b } -> same_as<T>;
    };

    template <typename T>
    concept Divisible = requires (T a, size_t n) {
        { a / n } -> same_as<T>;
    };

    template <typename T>
    concept Comparable = requires (T a, T b) {
        { a > b } -> convertible_to<bool>;
    };

    template <Iterable C>
    requires Addable<typename iterator_traits<decltype(begin(declval<C>()))>::value_type>
    auto sum(const C& container) {
        using T = typename iterator_traits<decltype(begin(container))>::value_type;
        T result{};
        for (const auto& val : container) result = result + val;
        return result;
    }

    template <Iterable C>
    auto mean(const C& container) {
        using T = typename iterator_traits<decltype(begin(container))>::value_type;
        auto s = sum(container);
        size_t n = 0;
        for (auto it = begin(container); it != end(container); ++it) ++n;

        if constexpr (is_integral_v<T>) {
            return static_cast<double>(s) / n;
        } else {
            return s / n;
        }
    }

    template <Iterable C>
    auto variance(const C& container) {
        auto m = mean(container);
        using RT = decltype(m);
        RT v_sum{};
        size_t n = 0;
        for (const auto& x : container) {
            auto diff = static_cast<RT>(x) - m;
            v_sum = v_sum + (diff * diff);
            ++n;
        }
        return v_sum / n;
    }

    template <Iterable C>
    requires Comparable<typename iterator_traits<decltype(begin(declval<C>()))>::value_type>
    auto max(const C& container) {
        auto it = begin(container);
        auto current_max = *it;
        for (; it != end(container); ++it) {
            if (*it > current_max) current_max = *it;
        }
        return current_max;
    }

    template <Iterable C, typename Func>
    auto transform_reduce(const C& container, Func f) {
        using T = invoke_result_t<Func, typename iterator_traits<decltype(begin(declval<C>()))>::value_type>;
        T res{};
        for (const auto& x : container) res = res + f(x);
        return res;
    }


    template <typename... Args>
    auto sum_variadic(Args... args) {
        return (... + args);
    }

    template <typename... Args>
    auto mean_variadic(Args... args) {
        auto s = sum_variadic(args...);
        return static_cast<double>(s) / sizeof...(Args);
    }

    template <typename First, typename... Args>
    auto max_variadic(First first, Args... args) {
        auto m = first;
        ((m = (args > m ? args : m)), ...);
        return m;
    }
}

#endif //TAREASPROGRA_CORE_NUMERIC_H