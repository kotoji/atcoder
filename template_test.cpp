#include "template.cpp"

void test_fmap() {
  {
    vec<int> xs = {1, 2, 3};
    auto ys = fmap([](int x) { return x * 2; }, std::move(xs));
    assert(ys == vec<int>({2, 4, 6}));
  }
  {
    vec<int> xs = {1, 2, 3};
    auto ys = fmap([](int x) { return x * 2; }, xs);
    assert(ys == vec<int>({2, 4, 6}));
  }
  {
    vec<int> xs = {1, 2, 3};
    auto ys = fmap([](int x) { return vec<int>{x, x}; }, xs);
    assert(ys == vec2<int>({vec<int>{1, 1}, vec<int>{2, 2}, vec<int>{3, 3}}));
  }
  {
    vec<string> xs = {"a", "bc"};
    auto ys = fmap([](string x) { return x + x; }, xs);
    assert(ys == vec<string>({"aa", "bcbc"}));
  }
  {
    vec<string> xs = {"a", "bc", "defe"};
    auto ys = fmap([](string x) { return size(x); }, xs);
    assert(ys == vec<size_t>({1, 2, 4}));
  }
  cout << "[PASSED] test_fmap" << endl;
}

void test_filter() {
  {
    vec<int> xs = {1, 2, 3, 4, 5, 6};
    auto ys = filter([](int x) { return x % 2 == 0; }, xs);
    assert(ys == vec<int>({2, 4, 6}));
  }
  {
    vec2<int> xs = {{1}, {2, 2}, {3}, {4, 4, 4}, {5, 5}, {6, 6, 6, 6}};
    auto ys = filter([](vec<int> x) { return size(x) > 2; }, xs);
    assert(ys == vec2<int>({{4, 4, 4}, {6, 6, 6, 6}}));
  }
  cout << "[PASSED] test_filter" << endl;
}

void test_split() {
  {
    string input = "a b c d e";
    vec<string> out = split(input, ' ');
    assert(out == vec<string>({"a", "b", "c", "d", "e"}));
  }
  {
    string input = "a,bb,ccc,dddd,eeeee";
    vec<string> out = split(input, ',');
    assert(out == vec<string>({"a", "bb", "ccc", "dddd", "eeeee"}));
  }
  {
    string input = ",a,bb,ccc,";
    vec<string> out = split(input, ',');
    assert(out == vec<string>({"", "a", "bb", "ccc", ""}));
  }
  {
    string input = "a";
    vec<string> out = split(input, ',');
    assert(out == vec<string>({"a"}));
  }
  {
    string input = "";
    vec<string> out = split(input, ',');
    assert(out == vec<string>({}));
  }
  {
    string input = "abbcccddddeeeee";
    vec<string> out = split(input);
    assert(out == vec<string>({"a", "bb", "ccc", "dddd", "eeeee"}));
  }
  {
    string input = "abbcccddddeeeeef";
    vec<string> out = split(input);
    assert(out == vec<string>({"a", "bb", "ccc", "dddd", "eeeee", "f"}));
  }
  {
    string input = "a";
    vec<string> out = split(input);
    assert(out == vec<string>({"a"}));
  }
  {
    string input = "";
    vec<string> out = split(input);
    assert(out == vec<string>({}));
  }
  cout << "[PASSED] test_split" << endl;
}

void test_rtrim() {
  {
    string input = "..ab.cde...";
    string out = rtrim(input, '.');
    assert(out == "..ab.cde");
  }
  cout << "[PASSED] test_rtrim" << endl;
}

void test_ltrim() {
  {
    string input = "..ab.cde...";
    string out = ltrim(input, '.');
    assert(out == "ab.cde...");
  }
  cout << "[PASSED] test_ltrim" << endl;
}

void test_trim() {
  {
    string input = "..ab.cde...";
    string out = trim(input, '.');
    assert(out == "ab.cde");
  }
  cout << "[PASSED] test_trim" << endl;
}

void test_mkstring() {
  {
    vec<string> input = {"a", "bb", "ccc", "dddd", "eeeee"};
    string out = mkstring(input, ",");
    assert(out == "a,bb,ccc,dddd,eeeee");
  }
  cout << "[PASSED] test_mkstring" << endl;
}

int main() {
  init();
  test_fmap();
  test_filter();
  test_split();
  test_rtrim();
  test_ltrim();
  test_trim();
  test_mkstring();
}
