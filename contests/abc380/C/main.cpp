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

enum State { START, READ_0, READ_1, END };

std::string solve(std::string &&S, long K) {
  std::vector<int> counts;
  char start_bit = '-';
  State state = START;
  int count = 0;
  for (auto b : S + "\n") {
    switch (state) {
    case START:
      if (b == '0') {
        state = READ_0;
      } else if (b == '1') {
        state = READ_1;
      }
      start_bit = b;
      count++;
      break;
    case READ_0:
      if (b == '0') {
        count++;
      } else if (b == '1') {
        counts.push_back(count);
        state = READ_1;
        count = 1;
      } else {
        counts.push_back(count);
        count = 0;
        state = END;
      }
      break;
    case READ_1:
      if (b == '1') {
        count++;
      } else if (b == '0') {
        counts.push_back(count);
        state = READ_0;
        count = 1;
      } else {
        counts.push_back(count);
        count = 0;
        state = END;
      }
      break;
    case END:
      break;
    }
  }

  std::vector<int> counts2;
  if (start_bit == '0') {
    for (int i = 0; i < counts.size(); i++) {
      if (i == 2 * K - 1) {
        counts2[2 * K - 1 - 2] += counts[i];
      } else if (i == 2 * K) {
        counts2[2 * K - 2] += counts[i];
      } else {
        counts2.push_back(counts[i]);
      }
    }
  } else {
    for (int i = 0; i < counts.size(); i++) {
      if (i == 2 * K - 2) {
        counts2[2 * K - 2 - 2] += counts[i];
      } else if (i == 2 * K - 1) {
        counts2[2 * K - 1 - 2] += counts[i];
      } else {
        counts2.push_back(counts[i]);
      }
    }
  }

  std::string out = "";
  char bit = start_bit;
  for (int i = 0; i < counts2.size(); i++) {
    for (int j = 0; j < counts2[i]; j++) {
      out += bit;
    }
    bit = bit == '0' ? '1' : '0';
  }
  return out;
}

int main() {
  long N, K;
  std::string S;
  std::cin >> N >> K;
  std::cin >> S;
  auto out = solve(std::move(S), K);
  std::cout << out << std::endl;
  return 0;
}
