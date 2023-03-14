#include <iostream>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

//pass
//time: O(n*nums)
//space: O()
/*bool canPartition(vector<int>& nums) {
    int n = nums.size();
    set<int> all;
    set<int> temp;
    int target = accumulate(nums.begin(), nums.end(), 0);

    if(target%2 !=0)
        return false;
    else
        target = target/2;

    for(int i=0; i<n; i++){
        for(const auto &s :all){
            temp.insert(s+nums[i]);
        }
        all.insert(temp.begin(), temp.end());
        all.insert(nums[i]);
        temp.clear();

        if(all.count(target))
            return true;
    }

    return false;
}*/

//optimize
//time: O(N*sum)
//space: O(sum)
bool canPartition(vector<int>& nums) {
    int target = accumulate(nums.begin(), nums.end(), 0);

    if(target%2 !=0)
        return false;
    else
        target = target/2;

    vector<bool>dp(target+1, false);
    dp[0] = true;                               //0 is always achievable

    for(auto &n:nums){
        for(int i=target; i>=n; i--){
            if(dp[i-n])                         //if i-n achievable, then add num to it make i achievable
                dp[i] = true;
            if(dp[target])
                return true;
        }
    }
    return dp[target];

}
