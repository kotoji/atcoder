#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
using namespace std;


void solve(long long D, long long X, std::vector<long long> A, long long Q, std::vector<long long> S, std::vector<long long> T){

}

// Generated by 2.14.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
    long long D;
    std::scanf("%lld", &D);
    long long X;
    std::scanf("%lld", &X);
    std::vector<long long> A(D-2+1);
    for(int i = 0 ; i < D-2+1 ; i++){
        std::scanf("%lld", &A[i]);
    }
    long long Q;
    std::scanf("%lld", &Q);
    std::vector<long long> S(Q);
    std::vector<long long> T(Q);
    for(int i = 0 ; i < Q ; i++){
        std::scanf("%lld", &S[i]);
        std::scanf("%lld", &T[i]);
    }
    solve(D, X, std::move(A), Q, std::move(S), std::move(T));
    return 0;
}
