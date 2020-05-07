#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

#define rep(i, e) for (auto i = decltype(e){}; i < e; ++i)

using ll = long long int;

int main() {
  int a, b;
  cin >> a >> b;
  auto diff = abs(b - a);
  auto cnt  = diff / 10;
  diff %= 10;
  array<int, 10> table{0, 1, 2, 3, 2, 1, 2, 3, 3, 2};
  cnt += table[diff];
  cout << cnt << endl;
}
