class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            int n1 = nums1.size(), n2 = nums2.size();
            int i=0, j=0, m1=-1, m2=-1;  
            for(int k=0; k<= (n1+n2)/2; k++)
            {
                m1=m2;
                if(i<n1 && (j>=n2 || nums1[i] < nums2[j]))
                    m2 = nums1[i++];
                else m2 = nums2[j++];
            }  
    
            if((n1+n2)%2 != 0)  return m2;
    
            return (m1+m2)/2.0;
        }
    };
    