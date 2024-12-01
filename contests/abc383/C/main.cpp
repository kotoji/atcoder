#include <algorithm>
#include <bit>
#include <bitset>
#include <cassert>
#include <cmath>
#include <concepts>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

using llong = long long;
using ullong = unsigned long long;
template <typename T> using vec = vector<T>;
template <typename T> using vec2 = vector<vector<T>>;
template <typename T> using vec3 = vector<vector<vector<T>>>;

#define rep(i, from, until) for (size_t i = (from); i < (size_t)(until); i++)
#define all(xs) (xs).begin(), (xs).end()
#define rall(xs) (xs).rbegin(), (xs).rend()
#define init() cin.tie(0), ios::sync_with_stdio(0)
#define debug(x) std::cerr << #x << " = " << (x) << std::endl

template <typename T, typename Fn>
inline decltype(auto) fmap(Fn f, vector<T> &&xs) {
  vector<invoke_result_t<Fn, T>> ys(xs.size());
  for (size_t i = 0; i < xs.size(); i++) {
    ys[i] = f(xs[i]);
  }
  return ys;
}
template <typename T, typename Fn>
inline decltype(auto) fmap(Fn f, const vector<T> &xs) {
  vector<invoke_result_t<Fn, T>> ys(xs.size());
  for (size_t i = 0; i < xs.size(); i++) {
    ys[i] = f(xs[i]);
  }
  return ys;
}
template <typename T, typename Fn>
inline decltype(auto) filter(Fn f, const vector<T> &xs) {
  vector<T> ys;
  std::copy_if(xs.begin(), xs.end(), std::back_inserter(ys), f);
  return ys;
}
inline vector<string> split(const string &s, char sep) {
  if (s.empty()) {
    return {};
  }
  vector<string> out;
  string tmp;
  for (char c : s) {
    if (c == sep) {
      out.push_back(tmp);
      tmp.clear();
    } else {
      tmp.push_back(c);
    }
  }
  out.push_back(tmp);
  return out;
}
inline vector<string> split(const string &s) {
  if (s.empty()) {
    return {};
  }
  vector<string> out;
  string tmp;
  char now = s[0];
  for (char c : s) {
    if (c != now) {
      out.push_back(tmp);
      tmp.clear();
      tmp.push_back(c);
      now = c;
    } else {
      tmp.push_back(c);
    }
  }
  out.push_back(tmp);
  return out;
}
inline string rtrim(const string &s, char c) {
  for (size_t i = s.size(); i > 0; i--) {
    if (s[i - 1] != c) {
      return s.substr(0, i);
    }
  }
  return "";
}
inline string ltrim(const string &s, char c) {
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] != c) {
      return s.substr(i);
    }
  }
  return "";
}
inline string trim(const string &s, char c) { return rtrim(ltrim(s, c), c); }
inline string mkstring(const vector<string> &xs, string &&sep) {
  string out;
  for (size_t i = 0; i < xs.size(); i++) {
    out += xs[i];
    if (i < xs.size() - 1) {
      out += sep;
    }
  }
  return std::move(out);
}
template <typename T> inline void println(const vector<T> &xs, string &&sep) {
  for (size_t i = 0; i < xs.size(); i++) {
    cout << xs[i];
    if (i < xs.size() - 1) {
      cout << sep;
    }
  }
  cout << endl;
}
template <typename T, typename Int> inline void readln(vector<T> &xs, Int &n) {
  static_assert(is_integral<Int>::value);
  cin >> n;
  for (Int i = 0; i < n; i++) {
    T x;
    cin >> x;
    xs.push_back(move(x));
  }
}

int tansaku(pair<int, int> p, vec<vec<char>> &S, int D, vec<vec<int>> &SSS) {
  int H = S.size();
  int W = S[0].size();

  int Y = p.first;
  int X = p.second;

  queue<pair<int, pair<int, int>>> q;
  q.push({1, {Y + 1, X}});
  q.push({1, {Y, X + 1}});
  q.push({1, {Y, X - 1}});
  q.push({1, {Y - 1, X}});

  int count = 0;
  while (!q.empty()) {
    auto [c, dd] = q.front();
    q.pop();
    int i = dd.first;
    int j = dd.second;

    if (c > D) {
      continue;
    }
    if (i < 0 || i >= H || j < 0 || j >= W) {
      continue;
    }
    if (S[i][j] == '#') {
      continue;
    }

    if (c >= SSS[i][j]) {
      continue;
    }
    SSS[i][j] = c;

    if (S[i][j] == '.') {
      S[i][j] = 'H';
      count++;
    }

    q.push({c + 1, {i + 1, j}});
    q.push({c + 1, {i, j + 1}});
    q.push({c + 1, {i, j - 1}});
    q.push({c + 1, {i - 1, j}});
  }
  return count;
}

void solve(int H, int W, int D, vec<vec<char>> S) {
  vec<pair<int, int>> ps;

  rep(i, 0, H) {
    rep(j, 0, W) {
      if (S[i][j] == 'H') {
        ps.push_back({i, j});
      }
    }
  }

  int count = 0;
  auto SSS = vec<vec<int>>(H, vec<int>(W, 10000000));
  rep(k, 0, ps.size()) {
    count++;
    count += tansaku(ps[k], S, D, SSS);
  }

  cout << count << endl;
}

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vec<vec<char>> S(H, vec<char>(W));
  rep(i, 0, H) {
    rep(j, 0, W) {
      char c;
      cin >> c;
      S[i][j] = c;
    }
  }
  solve(H, W, D, std::move(S));
  return 0;
}