#include <iostream>
#include <vector>

using namespace std;
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    vector<int> count(amount+1);
    count[0]=0;
    if (amount==0) return 0;
    //dp
    for(int i=1; i<count.size(); i=i+1){
        // T: 這個if 要重寫，你直接iterate coins 那個 vector 就夠了
        //coins存在, dp[i]=1
        if(find(coins.begin(), coins.end(), i)!=coins.end()){
            count[i] = 1;
            //cout<<i<<" "<<count[i]<<endl;
        }
        else {
            //無法由 coin 組成（cuz 1st coin)
            if (i < coins[0])
                count[i]=-1;
            else{
                int temp_count;
                int min_count = INT_MAX;
                //將 i 與 coins （已出現過的）內每個做確認
                for (int j=0; j<coins.size() && coins[j]<i;j=j+1){
                    int temp = i - coins[j];

                    //temp not exist
                    if (temp<0)
                        min_count= -1;
                        //找到的 count[temp] 也無法由 coin 組成
                    else if (count[temp]==-1){
                        if (min_count == INT_MAX)
                            min_count = -1;
                    }
                    else{
                        temp_count = count[temp]+1;
                        if (min_count==-1||temp_count<min_count){
                            //if (temp_count<min_count){
                            min_count = temp_count;
                        }
                    }
                }
                count[i] = min_count;
            }
//            if (count[i]>0)
//                cout<<i<<"count: "<<count[i]<<endl;
        }
    }

    return count[amount];
}
int main(){

}