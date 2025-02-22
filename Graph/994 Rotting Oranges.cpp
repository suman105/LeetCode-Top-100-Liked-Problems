class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            queue<pair<int, int>> q;  // to store the coordinates of rotten oranges
            int freshOranges = 0;  // to count fresh oranges
            
            // Step 1: Initialize the queue with rotten oranges and count fresh oranges
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 2) {
                        q.push({i, j});  // Add rotten orange to the queue
                    } else if (grid[i][j] == 1) {
                        freshOranges++;  // Count fresh oranges
                    }
                }
            }
            
            // Directions: up, down, left, right
            vector<int> dirs = {-1, 0, 1, 0, -1, 0};
            int minutes = 0;
            
            // Step 2: Perform BFS to spread the rot
            while (!q.empty() && freshOranges > 0) {
                int size = q.size();
                for (int i = 0; i < size; ++i) {
                    auto [x, y] = q.front();
                    q.pop();
                    
                    // Explore all four directions
                    for (int j = 0; j < 4; ++j) {
                        int nx = x + dirs[j], ny = y + dirs[j + 1];
                        
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            grid[nx][ny] = 2;  // Rot the fresh orange
                            freshOranges--;  // Decrease the count of fresh oranges
                            q.push({nx, ny});  // Add the new rotten orange to the queue
                        }
                    }
                }
                minutes++;  // Increase the minutes after processing one level
            }
            
            // Step 3: Return the result
            return freshOranges == 0 ? minutes : -1;
        }
    };
    