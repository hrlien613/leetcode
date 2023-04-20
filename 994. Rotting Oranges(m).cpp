#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//My solution
//int orangesRotting(vector<vector<int>>& grid) {
//    queue <pair<int,int>> q;
//    queue <pair<int,int>> temp;
//    int time = 0;
//    int good = 0;
//
//    for(int i=0 ;i<grid.size();i++){
//        for(int j=0; j<grid[0].size();j++){
//            if (grid[i][j]==2)
//                q.push({i,j});
//            if (grid[i][j]==1)
//                good++;
//        }
//    }
//
//    while(!q.empty()){
//        int row = q.front().first;
//        int col = q.front().second;
//        q.pop();
//
//        if(row-1>=0 && grid[row-1][col]==1){
//            temp.push({row-1,col});
//            grid[row-1][col] = 2;
//            good--;
//        }
//
//        if(row+1<grid.size() && grid[row+1][col]==1){
//            temp.push({row+1,col});
//            grid[row+1][col]=2;
//            good--;
//        }
//
//        if(col-1>=0 && grid[row][col-1]==1){
//            temp.push({row,col-1});
//            grid[row][col-1]=2;
//            good--;
//        }
//
//        if(col+1<grid[0].size() && grid[row][col+1]==1){
//            temp.push({row,col+1});
//            grid[row][col+1]=2;
//            good--;
//        }
//
//        if(q.empty()){
//            q = temp;
//            if (!temp.empty()){
//                time++;
//                temp = {};
//            }
//        }
//    }
//
//    if (good==0)
//        return time;
//    else
//        return -1;
//}

//optimize

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0;

    for(int i=0 ;i<m;i++){
        for(int j=0; j<n;j++){
            if (grid[i][j]==2)
                q.push({i,j});
            if (grid[i][j]==1)
                fresh++;
        }
    }

    int tm = -1;
    vector<int> dir = {-1,0,1,0,-1};

    while(!q.empty()){
        int sz = q.size();

        while(sz--){
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r = p.first + dir[i];
                int c = p.second + dir[i+1];

                if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 1){
                    q.push({r,c});
                    grid[r][c] = 2;
                    fresh--;
                }
            }
        }
        tm++;
    }

    if(fresh>0)
        return -1;
    if(tm==-1)
        return 0;
    return tm;
}