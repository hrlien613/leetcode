#include <iostream>
#include <stack>
#include <string>
using namespace std;

//pass
//using stack
//Time:O(M+N)
//Space:O(M+N)
/*bool backspaceCompare(string s, string t) {
    stack<char> s_q;
    stack<char> t_q;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '#')
            s_q.push(s[i]);
        else
            if(!s_q.empty())
                s_q.pop();
    }

    for (int j = 0; j < t.size(); j++) {
        if (t[j] != '#')
            t_q.push(t[j]);
        else
            if(!t_q.empty())
                t_q.pop();
    }

    if(s_q == t_q)
        return true;
    else
        return false;
}*/

bool backspaceCompare(string s, string t) {
    int si = 0;
    int ti = 0;

    for(int i=0; i<s.size(); i++){
        if( s[i] != '#'){
            s[si] = s[i];
            ++si;
        }
        else if(si>0)
            --si;
    }

    for(int i=0; i<t.size(); i++){
        if(t[i]!='#'){
            t[ti] = t[i];
            ++ti;
        }
        else if(ti>0)
            --ti;
    }

    if (si != ti) return false;

    for(int i=0; i<si; i++){
        if(s[i]!=t[i])
            return false;
    }
    return true;
}
