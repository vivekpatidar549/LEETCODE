class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rowlen= matrix.size();
        int collen= matrix[0].size();
        vector<vector<int>> ans(collen,vector<int>(rowlen));
        for(int row=0;row<rowlen;row++){
            for(int col=0;col<collen;col++){   
                ans[col][row]=matrix[row][col];
            }
        }
        return ans;
        
    }
};