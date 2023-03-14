#include <iostream>
#include <vector>
using namespace std;

//pass
//Time:O(N!)
//Space:O(N!)

void solve(vector<int> &nums, vector<vector<int>>& result, int index){

//    if((nums.size())==1)
    if (index==nums.size())
        result.push_back(nums);

    for(int i=0; i<nums.size();i++){
        swap(nums[i],nums[index]);
        solve(nums, result, index+1);
        swap(nums[i],nums[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> result;
    solve(nums,result,0);
    return result;
}


int main(){
    vector<vector<int>> ans;
    vector<int> nums = {1,2,3};
    ans = permute(nums);

    for(auto x:ans){
        for(auto s:x){
            cout<<s<<endl;
        }
    }
}