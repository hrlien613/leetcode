#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q, set<pair<int,int>> &visited){
    int rows = grid.size();
    int cols = grid[0].size();

    while(!q.empty()){
        //int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int r = q.front().first;
        int c = q.front().second;

        if(visited.count({r,c}))
            continue;

        /*for(int i=0; i<4; i++){
            int d_r = r + directions[i][0];
            int d_c = c + directions[i][1];

            if((d_r>=0)&& (d_c>=0) && (d_r < rows) && (d_c < cols) && (grid[d_r][d_c]=='1')){
                q.push({d_r, d_c});
                //visited.insert({d_r,d_c});
            }
        }*/
        if (r+1<rows && grid[r+1][c]=='1')
            q.push({r+1, c});
        if (r-1>0 && grid[r-1][c] == '1')
            q.push({r-1, c});
        if (c+1 < cols && grid[r][c+1] == '1')
            q.push({r, c+1});
        if (c-1>0 && grid[r][c-1] =='1')
            q.push({r, c-1});

        visited.insert({r, c});
    }
}

//void dfs(vector<vector<char>>& grid, int x , int y, set<pair<int,int>>& visited){
//    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
//    for (auto d :directions){
//        int d_r = r + directions[i][0];
//        int d_c = c + directions[i][1];
//
//        if((d_r>=0)&& (d_c>=0) && (d_r < rows) && (d_c < cols) && (grid[d_r][d_c]=='1')){
//            dfs(grid, r, c, visited);
//        }
//    }
//}

void dfs(vector<vector<char>>& grid, int x , int y, set<pair<int,int>>& visited){
    int rows = grid.size();
    int cols = grid[0].size();

    if((x < 0)|| (y < 0) || (x >= rows) || (y >= cols) || (visited.count({x, y}) ||  grid[x][y]=='0'))
        return;

    visited.insert({x, y});
    cout<<x<<' '<<y<<endl;
    dfs(grid, x+1, y, visited);
    dfs(grid, x-1, y, visited);
    dfs(grid, x, y+1, visited);
    dfs(grid, x, y-1, visited);


}


int numIslands(vector<vector<char>>& grid) {

    int rows = grid.size();
    int cols = grid[0].size();
    int island_nums = 0;
    set<pair<int,int>> visited;
    queue<pair<int, int>> q;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if ((grid[i][j] == '1') & !(visited.count({i,j}))){
                q.push({i,j});
                bfs(grid,q, visited);
                island_nums +=1;

                //dfs
                //dfs(grid, i, j , visited);
                //island_num +=1;
            }
        }
    }

    return island_nums;

}
