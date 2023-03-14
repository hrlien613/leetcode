#include <iostream>
#include <vector>
#include <map>
using namespace std;

//using map
//Time:O(N)
//space:O(N)
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> pair;
    vector<int> result;

    for(int i=0; i < nums1.size(); i++){
        pair[nums1[i]]++;
    }

    for(int j=0; j<nums2.size();j++){
        if(pair[nums2[j]] > 0){
            pair[nums2[j]]--;
            result.push_back(nums2[j]);
        }
    }
    return result;
}

//using two pointer
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> result;

    int i=0, j=0;

    while(i<nums1.size() && j < nums2.size()){
        if(nums1[i]==nums2[j]){
            result.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else
            j++;
    }
    return result;
}
