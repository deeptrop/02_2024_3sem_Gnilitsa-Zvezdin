#include <iostream>



// Эта функция вычисляет факториал с использованием constexpr.
// Параметры: n — число, для которого нужно вычислить факториал.
constexpr unsigned long long factorial_constexpr(int n) {
  return (n <= 1) ? 1 : n * factorial_constexpr(n - 1); // Рекурсивно уменьшаем n
}

// Здесь факториал вычисляется через шаблоны.
// Параметр шаблона N — это число, для которого вычисляется факториал.
template<int N>
struct factorial {
  static const unsigned long long value = N * factorial<N - 1>::value; // Рекурсия в шаблонах
};

// Это частичная специализация шаблона для случая, когда факториал от 0
// По определению, факториал от 0 равен 1
template<>
struct factorial<0> {
  static const unsigned long long value = 1;
};

int main() {
  // main() оставлен пустым, так как факториалы вычисляются во время компиляции.
  return 0;
}
