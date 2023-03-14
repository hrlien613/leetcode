#include <iostream>
#include <unordered_map>

using namespace std;
//time:O(n)
//space:O(n)
int longestPalindrome(string s) {
    unordered_map<char, int> table;
    int length=0;
    int odd=0;

    for(auto n:s){
        table[n]++;
    }

    for(auto item:table){
        if (item.second %2 ==0)
            length += item.second;
        else{
            length += item.second -1;
            odd =1;
        }
    }
    if(odd)
        return length+1;
    else
        return length;
}
