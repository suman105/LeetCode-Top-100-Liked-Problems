class Solution {
    public:
        void dfs(vector<vector<char>>& grid, int i, int j) {
            int m = grid.size(), n = grid[0].size();
            if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;
    
            grid[i][j] = '0'; // Mark visited
    
            // Explore all 4 directions (Up, Down, Left, Right)
            dfs(grid, i - 1, j); // Up
            dfs(grid, i + 1, j); // Down
            dfs(grid, i, j - 1); // Left
            dfs(grid, i, j + 1); // Right
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int count = 0, m = grid.size(), n = grid[0].size();
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '1') { // Found new island
                        count++;
                        dfs(grid, i, j); // Explore entire island
                    }
                }
            }
            return count;
        }
    };
    