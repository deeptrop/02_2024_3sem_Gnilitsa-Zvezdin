#ifndef GET_HPP
#define GET_HPP

#include "tuple.hpp"

// Этот шаблон позволяет определить тип элемента кортежа по его индексу.
// Например, для tuple<int, bool, double, char> тип get<2> будет double.
template<int N, typename T, typename ... argsT>
struct tuple_element {
  using type = typename tuple_element<N - 1, argsT...>::type; // Рекурсивно ищем нужный тип.
};

// Базовый случай: если индекс 0, возвращаем тип первого элемента.
template<typename T, typename ... argsT>
struct tuple_element<0, T, argsT...> {
  using type = T; // Тип текущего элемента.
};

// Эта функция позволяет получить элемент кортежа по его индексу.
// Например, get<2>(my_tuple) вернет второй (в нулевой индексации) элемент.
template<int N, typename T, typename ... argsT>
typename tuple_element<N, T, argsT...>::type& get(tuple<T, argsT...>& t) {
  if constexpr (N == 0) { // Если это первый элемент, возвращаем его.
    return t.first;
  } else { // Иначе рекурсивно ищем нужный элемент.
    return get<N - 1>(t.others);
  }
}

#endif // GET_HPP
