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

char reverse(char c) {
  if (c > 'Z') {
    return 'A' + c - 'a';
  } else {
    return 'a' + c - 'A';
  }
}
char solve(std::string &&S, long K) {
  long long len = std::size(S);
  long count = 0;
  long long index = K;
  while (len <= index) {
    int N = 0;
    for (N = 0; len * (1 << (N + 1)) < index; N++) {
    }
    index = index % (len * (1 << N));
    count++;
  }
  return count % 2 == 0 ? S[index] : reverse(S[index]);
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
