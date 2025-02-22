class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) 
        {
            stack<int> st;
            int n = heights.size();
            int maxArea=0;
    
            for(int i=0; i<=n; i++)
            {
                int h = (i==n) ? 0 : heights[i];
                while(!st.empty() && heights[st.top()]>h){
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i :  (i-st.top()-1);
                    maxArea = max(maxArea, height*width);
                }
                st.push(i);
            }   
    
            return maxArea; 
        }
    };