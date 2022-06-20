class Solution {
public:
    
    int ans(vector<int>& nums)
    {
        int n = nums.size();

        
        int ans = -1e9;
        
        int cur = 1;
        bool bl = false;
        bool hpn = false;
        bool zero = false;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                bl = false;
                cur = 1;
                zero = true;
                continue;
            }
            hpn = true;
            cur = cur*nums[i];
            ans = max(ans , cur);
        }
        
        if(!hpn)
            return 0;
        
        if(zero)
            return max(ans , 0);
        
        return ans;
        
        
        
    }
    int maxProduct(vector<int>& nums) {
        
        int fin = ans(nums);
        reverse(nums.begin() , nums.end());
        fin = max(fin , ans(nums));
        
        return fin;
        
        
        
    }
};