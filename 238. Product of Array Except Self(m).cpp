#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1]*nums[i-1];
        //cout<<ans[i]<<endl;
    }

    int temp = 1;
    for(int j=n-2; j>=0;j--){
        //cout<<j<<" "<<ans[j]<<" "<<nums[j+1]<<endl;
        ans[j] = temp*ans[j]*nums[j+1];
        temp = temp*nums[j+1];
    }

    return ans;
}
