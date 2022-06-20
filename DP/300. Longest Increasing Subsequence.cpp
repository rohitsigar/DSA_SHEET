class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        int n = nums.size();
        
        set<int> s;
        
        for(auto e : nums)
        {
            s.insert(e);
        }
        
        vector<int> nums2;
        
        for(auto e : s)
        {
            nums2.push_back(e);
        }
        
        int m = nums2.size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
                dp[i][j] = 0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                if(nums[i-1]==nums2[j-1])
                {
                    dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + 1);
                }
                
            }
        }
    
        return dp[n][m];
        
    }
};


// another soluton with time complexity nlogn 



    #include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]);
        int ans = 1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] > temp.back())
            {
               temp.push_back(nums[i]);
                ans++;
            }
            else
            {
                int ind = 
                    (int)(lower_bound(temp.begin() , temp.end() , nums[i])-temp.begin());
                temp[ind] = nums[i];
            }
        }
        return ans;

        
    }
};