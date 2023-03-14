#include <iostream>
#include <vector>

using namespace std;

//int climbStairs(int n) {
//    vector<int> dp(n+1);
//
//    if (n==1) return 1;
//    if (n==2) return 2;
//    dp[1] = 1;
//    dp[2] = 2;
//
//    for(int i=3; i<=n; i++){
//        dp[i] = dp[i-1]+dp[i-2];
//    }
//
//    return dp[n];
//}

int climbStairs(int n) {
    int one_step = 1;
    int two_step = 2;
    int all_steps = 0;

    if (n==1) return 1;
    if (n==2) return 2;

    for(int i=3; i<=n;i++){
        all_steps = one_step + two_step;
        one_step =all_steps;
        two_step = two_step+1;
    }

    return all_steps;
}