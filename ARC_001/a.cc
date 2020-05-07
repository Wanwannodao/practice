#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

#define rep(i, e) for (auto i = decltype(e){}; i < e; ++i)

using ll = long long int;

int main() {
  size_t n;
  string c;
  cin >> n >> c;
  array<size_t, 4> hist{};
  rep(i, n) hist[(c[i] - '0') - 1]++;
  cout << *max_element(hist.begin(), hist.end()) << " " << *min_element(hist.begin(), hist.end()) << endl;
}
