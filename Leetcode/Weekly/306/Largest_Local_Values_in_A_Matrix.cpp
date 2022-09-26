class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));         // ans matrix with size (n-2)*(n-2)


        // drow and dcol are the steps taken if we are at a point for eg
        //  drow[3] = 1 and dcol[3] = 0         this means if we are at (i,j) we'll access element at (i+1,j+0) i.e one step down
        int drow[] = {0,0,0,1,1,1,2,2,2};
        int dcol[] = {0,1,2,0,1,2,0,1,2};
        
        for(int i=0; i<n-2; i++)
        {
            for(int j=0; j<n-2; j++)
            {
                int maxi = INT_MIN;
                for(int k=0; k<9; k++)
                {
                    int nrow = i + drow[k];
                    int ncol = j+ dcol[k];
                    
                    maxi = max(maxi,grid[nrow][ncol]);
                }
                
                ans[i][j] = maxi;
            }
        }
        
        return ans;
    }
};