#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Time: O(N)
 * Space: O(1)
 */
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    if (nums.size()==0) return {};
    if (nums.size()==1) return {to_string(nums[0])};

    string range = to_string(nums[0]);

    for(int i=1; i<nums.size(); i++){
        if(nums[i] != nums[i-1]+1){
            if(range== to_string(nums[i-1])){
                ans.push_back(range);
                range = to_string(nums[i]);
            }
            else{
                ans.push_back(range+"->"+ to_string(nums[i-1]));
                range = to_string(nums[i]);
            }
        }
    }


    if (range != to_string(nums.back()))
        ans.push_back(range+"->"+ to_string(nums[nums.size()-1]));
    else
        ans.push_back(range);

    return ans;
}