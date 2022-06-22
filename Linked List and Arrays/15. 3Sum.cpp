class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            int l = i+1;
            int r = n-1;
            
            while(l < r)
            {
                int value = nums[i] + nums[l] + nums[r];
                
                if(value > 0)
                    r--;
                else if(value < 0)
                    l++;
                else
                {
               
                    vector<int> v = {nums[i] , nums[l] , nums[r]};
                    ans.push_back(v);
                    
                    l++;
                    r--;
                    
                   
                    
                    while(l < r && nums[l]==nums[l-1])
                        l++;
                    
                    while(r > l && nums[r]==nums[r+1])
                        r--;
                 
                }
                
                
            }
            
           while(i+1  < n && nums[i]==nums[i+1])
               i++;
        }
        
        return ans;
        
    }
};