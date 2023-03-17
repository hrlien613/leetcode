#include <iostream>
#include <vector>

using namespace std;

// My solution
// Time: O(MN)
// Space: O(2M)
//vector<vector<int>> subsets(vector<int>& nums) {
//    vector<vector<int>> output;
//    output.push_back({});
//    int n = nums.size();
//    vector<vector<int>> temp;
//    temp = output;
//
//    for(int i=0; i<n;i++){
//        for(auto c:output){
//            c.push_back(nums[i]);
//            temp.push_back(c);
//        }
//        output = temp;
//    }
//
//    return output;
//}

//iterate
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs = {{}};
    for (int num : nums) {
        int n = subs.size();
        for (int i = 0; i < n; i++) {
            subs.push_back(subs[i]);
            subs.back().push_back(num);
        }
    }
    return subs;
}

//bit manipulation
//vector<vector<int>> subsets(vector<int>& nums) {
//    int n = nums.size(), p = 1 << n;
//    vector<vector<int>> subs(p);
//    for (int i = 0; i < p; i++) {
//        for (int j = 0; j < n; j++) {
//            if ((i >> j) & 1) { //if jth bit is set
//                subs[i].push_back(nums[j]);
//            }
//        }
//    }
//    return subs;
//
//}