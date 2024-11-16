#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

enum State {
  INITIAL,
  READ,
  BREAK,
  END,
};

std::vector<int> solve(std::string &&S) {
  std::vector<int> counts;

  State state = INITIAL;
  int count = 0;
  for (auto c : S) {
    switch (state) {
    case INITIAL:
      if (c == '|') {
        state = BREAK;
        count = 0;
        break;
      }
      break;
    case READ:
      if (c == '-') {
        state = READ;
        count++;
        break;
      }
      if (c == '|') {
        state = BREAK;
        counts.push_back(count);
        count = 0;
        break;
      }
      break;
    case BREAK:
      if (c == '-') {
        state = READ;
        count++;
        break;
      }
      if (c == '|') {
        state = BREAK;
        counts.push_back(count);
        count = 0;
        break;
      }
      if (c == '\n') {
        state = END;
        counts.push_back(count);
        count = 0;
        break;
      }
      break;
    case END:
      break;
    }
  }
  return counts;
}

int main() {
  std::string S;
  std::cin >> S;
  auto cs = solve(std::move(S));
  for (int i = 0; i < std::size(cs); i++) {
    std::cout << cs[i];
    if (i < std::size(cs) - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
