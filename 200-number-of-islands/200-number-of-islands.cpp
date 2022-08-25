class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0,n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1')
                {
                    func(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
    
    void func(int i,int j,int n,int m,vector<vector<char>>& grid){
        
        if(i<0 || j<0 || i>=n || j>=m)
            return;
        if(grid[i][j]=='0')
            return;
        grid[i][j]='0';
        
        func(i+1,j,n,m,grid);
        func(i-1,j,n,m,grid);
        func(i,j-1,n,m,grid);
        func(i,j+1,n,m,grid);
    }
};