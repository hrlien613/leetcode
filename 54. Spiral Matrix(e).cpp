#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top=0, left =0;
    int right = matrix[0].size();
    int bottom = matrix.size();
    vector<int> output;

    while((top < bottom) && (left < right)){
        // every element in the top row
        for(int col=left;col<right; col++){
            output.push_back(matrix[top][col]);
        }

        top++;

        //every element in the right col
        for(int row=top; row<bottom; row++){
            output.push_back(matrix[row][right-1]);
        }

        right--;

        if (!(left<right && top<bottom)){
            break;
        }

        //every element in the bottom row
        for(int col=right-1; col>left; col--){
            output.push_back(matrix[bottom-1][col]);
        }

        bottom--;

        //every element in the left col
        for(int row=bottom; row>=top; row--){
            output.push_back(matrix[row][left]);
        }

        left++;

    }

    return output;

}
