#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

#define rep(i, e) for (auto i = decltype(e){}; i < e; ++i)

using ll = long long int;

bool put(const int i, const int j, const array<string, 8> &c) {
  rep(ii, c.size()) if (c[ii][j] == 'Q') return false;
  rep(jj, c.size()) if (c[i][jj] == 'Q') return false;

  for (ll ii = i, jj = j; ii < c.size() && jj < c.size(); ++ii, ++jj)
    if (c[ii][jj] == 'Q')
      return false;

  for (ll ii = i, jj = j; ii >= 0 && jj >= 0; --ii, --jj)
    if (c[ii][jj] == 'Q')
      return false;

  for (ll ii = i, jj = j; ii >= 0 && jj < c.size(); --ii, ++jj)
    if (c[ii][jj] == 'Q')
      return false;

  for (ll ii = i, jj = j; ii < c.size() && jj >= 0; ++ii, --jj)
    if (c[ii][jj] == 'Q')
      return false;

  return true;
}

bool dfs(const size_t cnt, array<string, 8> &c) {
  if (cnt == c.size())
    return true;

  rep(i, c.size()) {
    rep(j, c.size()) {
      if (c[i][j] == 'Q') {
        c[i][j] = '.';
        if (!put(i, j, c)) {
          c[i][j] = 'Q';
          return false;
        }
        c[i][j] = 'Q';
      }
    }
  }

  rep(i, c.size()) {
    rep(j, c.size()) {
      if (put(i, j, c)) {
        c[i][j] = 'Q';
        if (dfs(cnt + 1, c))
          return true;
        c[i][j] = '.';
      }
    }
  }

  return false;
}

int main() {
  array<string, 8> c;
  rep(i, c.size()) {
    string s;
    cin >> s;
    c[i] = s;
  }

  if (dfs(3, c))
    for (const auto &s : c)
      cout << s << endl;
  else
    cout << "No Answer" << endl;
}
