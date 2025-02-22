class Solution {
    public:
        bool dfs(int course, vector<vector<int>>& adj, vector<int>& state) {
            if (state[course] == 1) return false; // Cycle detected
            if (state[course] == 2) return true;  // Already processed
    
            state[course] = 1; // Mark as visiting
            for (int nextCourse : adj[course]) {
                if (!dfs(nextCourse, adj, state)) return false;
            }
            state[course] = 2; // Mark as visited
            return true;
        }
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);
            for (auto& pre : prerequisites) {
                adj[pre[1]].push_back(pre[0]);
            }
    
            vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
            for (int i = 0; i < numCourses; i++) {
                if (state[i] == 0 && !dfs(i, adj, state)) {
                    return false;
                }
            }
            return true;
        }
    };
    