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

const string YES = "Yes";
const string NO = "No";

bool solve(std::vector<char> &&cs) {
  std::sort(cs.begin(), cs.end());
  std::vector<char> ex = {'1', '2', '2', '3', '3', '3'};
  for (int i = 0; i < 6; i++) {
    if (cs[i] != ex[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::vector<char> cs(6);
  for (auto &c : cs) {
    std::cin >> c;
  }
  if (solve(std::move(cs))) {
    std::cout << YES << std::endl;
  } else {
    std::cout << NO << std::endl;
  }
  return 0;
}
