#include <iostream>
#include <vector>

using namespace std;

// version 1: mine
//int toBinary(int num){
//    int count =0;
//    int remainder=0;
//
//    while(num!=0){
//        remainder = num % 2;
//        if (remainder==1)
//            count ++;
//        num = num /2;
//    }
//    return count;
//}
//
//
//vector<int> countBits(int n) {
//    vector<int> ans;
//    int count = 0;
//
//    for(int i=0; i<=n; i++){
//        count = toBinary(i);
//        ans.push_back(count);
//    }
//
//    return ans;
//}

// version 2 :
// time : O(nlogn)
// space : O(n)
//vector<int> countBits(int n){
//    vector<int> ans;
//
//    for(int i=0; i<=n;i++){
//        int count = 0;
//        int num = i;
//        while(num!=0){
//            count += num % 2;
//            num = num/2;
//        }
//        ans.push_back(count);
//    }
//    return ans;
//}

// optimal
// time: O(n)
// space: O(n)
vector<int> countBits(int n){
    vector<int> ans(n+1);
    ans[0] = 0;

    for(int i=1;i<=n;i++){
        ans[i] = ans[i/2] + i%2;
    }

    return ans;
}

