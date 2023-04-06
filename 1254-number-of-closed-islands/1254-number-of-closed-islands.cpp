class Solution
{
public:
    void dfs(int i, int j,int& m,int& n, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0)
            return;
        grid[i][j] = 1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++)
        {
            dfs(i + dx[k],j + dy[k],m,n, grid);
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0||j==0 || i == m - 1 || j == n - 1) && (grid[i][j] == 0))
                    dfs(i, j,m,n, grid);
            }
        }
        int count = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j,m,n,grid);
                    count++;
                }
            }
        }
        return count;
    }
};