class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) 
        {
            vector<int> result;
            if(!matrix.size())  return result;
            int top = 0, bottom = matrix.size()-1;
            int left = 0, right = matrix[0].size()-1;    
    
            while(top <= bottom && left <= right)
            {
                for(int i = left; i<=right; i++)    result.push_back(matrix[top][i]);
                top++;
    
                for(int j = top; j<=bottom; j++)    result.push_back(matrix[j][right]);
                right--;
    
                if(top <= bottom){
                    for (int i = right; i >= left; i--)   result.push_back(matrix[bottom][i]);
                    bottom--;
                }
    
                if(left <= right)
                {
                    for(int j = bottom; j>=top; j--)    result.push_back(matrix[j][left]);
                    left++;
                }
            }
    
            return result;
        }
    };