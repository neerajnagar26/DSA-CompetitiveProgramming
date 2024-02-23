
# Solution-1

class Solution {
public:
    int dp[104];
    int sol(vector<int> &v, int x)
    {
        if(x<0)
            return 0;
        if(dp[x]!=-1)
            return dp[x];
        
        return dp[x]=v[x]+max(sol(v,x-2),sol(v,x-3));
            
    }
    int rob(vector<int>& v) 
    {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        return max(sol(v,n-1),sol(v,n-2));
    }
};


# Solution-2

class Solution {
public:
   
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0,sum=0;
        vector<int> vec(n+1,0);
		
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]);
        
        vec[0]=nums[0];
        vec[1]=max(nums[0],nums[1]);
        vec[2]=max(nums[1],nums[0]+nums[2]);
        
        for(int i=3;i<n;i++)
            vec[i]=nums[i]+max(vec[i-2],vec[i-3]);

        return max(vec[n-2],vec[n-1]);        
    }
};