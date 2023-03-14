#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//Fail
//bool isPalindrome(string s) {
//    int n = s.size();
//
//    if (n==0) return true;
//
//    for(int i=0; i<n/2; i++){
//        if(isupper(s[i]))
//            s[i] = s[i]+32;
//        if(isupper(s[n-1-i]))
//            s[n-1-i] = s[n-1-i]+32;
//
//        if(s[i] != s[n-1-i])
//            return false;
//    }
//    return true;
//}

//pass
//time:O(N)
//space: O(1)
bool isPalindrome(string s) {
    int n = s.size();
    int i=0, j=n-1;

    if (n==0) return true;

    while(i<j){
        while(!isalnum(s[i]) && i<j) i++;
        while(!isalnum(s[j]) && i<j) j--;

        //if(isupper(s[i])) s[i]=s[i]+32;
        //if(isupper(s[j])) s[j]=s[j]+32;

        //if(s[i] != s[j])
        if(tolower(s[i]) != tolower(s[j]))
            return false;
        i++;
        j--;
    }
    return true;
}