#include <algorithm>
#include <bit>
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

char reverse_case(char c) {
  if (std::islower(c)) {
    return std::toupper(c);
  } else {
    return std::tolower(c);
  }
}
char solve(std::string &&S, long K) {
  int cnt = std::popcount(K / std::size(S));
  int idx = K % std::size(S);
  return cnt % 2 == 0 ? S[idx] : reverse_case(S[idx]);
}

int main() {
  std::string S;
  int Q;
  std::cin >> S;
  std::cin >> Q;

  std::vector<long> Ks(Q);
  for (int i = 0; i < Q; i++) {
    std::cin >> Ks[i];
  }

  std::vector<char> Cs;
  for (auto K : Ks) {
    Cs.push_back(solve(std::move(S), K - 1));
  }
  for (int i = 0; i < Q; i++) {
    std::cout << Cs[i];
    if (i < Q - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}
