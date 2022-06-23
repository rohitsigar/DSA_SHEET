class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
       int prefmx[n];
        int subxmx[n];
        
        prefmx[0] = height[0];
        subxmx[n-1] = height[n-1];
        
        for(int i=1;i<n;i++)
        {
            prefmx[i] = max(prefmx[i-1] , height[i]);
        }
        
        for(int i = n-2;i>=0;i--)
        {
            subxmx[i] = max(subxmx[i+1] , height[i]);
        }
        
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res+=min(prefmx[i] , subxmx[i]) - height[i];
        }
        
        return res;
        
    }
};


//soluton with o(1) sc


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
       int mxlf =0;
        int mxrf = 0;
        
        int l = 0;
        int r = n-1;
        int res = 0;
        
        while(l<=r)
        { 
            if(height[l] <=height[r])
            {
                mxlf = max(mxlf , height[l]);
                res +=mxlf - height[l];
                l++;
            }
            else
            {
                mxrf = max(mxrf , height[r]);
                res+=mxrf - height[r];
                r--;
            }
        }
        
        return res;
        
    }
};