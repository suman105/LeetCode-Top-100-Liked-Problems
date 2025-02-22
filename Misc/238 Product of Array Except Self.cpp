class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& arr) 
        {
    
            // int n = nums.size();
            // vector<int> result(n, 1);
            
            // int leftProduct = 1;
            // for (int i = 0; i < n; ++i) {
            //     result[i] = leftProduct;
            //     leftProduct *= nums[i];
            // }
            
            // int rightProduct = 1;
            // for (int i = n - 1; i >= 0; --i) {
            //     result[i] *= rightProduct;
            //     rightProduct *= nums[i];
            // }
            
            // return result;
    
    
            int n = arr.size();
            vector<int> result(n,0);
            int count=0, prodSum=1;
            
            for(int num : arr){
                if(num==0)  count++;
                if(num!=0)  prodSum *= num;
            }  
                
            if(count >= 2) 
                return result;
            
            int k=0;
            
            for(int num : arr)
            {
                if(count)
                {
                    if(num) k++;
                    else result[k++] = prodSum;
                }
                else result[k++] = prodSum/num;
            }
            return result;
        }
    };