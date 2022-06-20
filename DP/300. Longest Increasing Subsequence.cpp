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

// another solution with reduced space complexity

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        
        int m = text2.size();
        
       
        
        vector<int> prev(m+1 , 0);
        vector<int> cur(m +1, 0);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    cur[j] = prev[j-1]+1;
                }
                else
                {
                    cur[j] = max(cur[j-1] , prev[j]);
                }
            }
            prev = cur;
        }
        
        return prev[m];
        
    }
};