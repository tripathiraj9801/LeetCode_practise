// Problem Link https://leetcode.com/problems/reducing-dishes/description/
class Solution {
    private:

    int solveMem(vector<int>& satis, int index, int time, vector<vector<int>>& dp){
        if(index>=satis.size())
        return 0;

        if(dp[index][time]!=-1)
        return dp[index][time];

        int include=((time+1)*satis[index])+solveMem(satis,index+1,time+1,dp);
        int exclude=solveMem(satis,index+1,time,dp);

        dp[index][time]=max(include,exclude);
        return dp[index][time];
    }

public:
    int maxSatisfaction(vector<int>& satis) {
        sort(satis.begin(),satis.end());
        int time=0;
        
        vector<vector<int>> dp(satis.size()+ 1,vector<int>(satis.size()+1,-1));  
        return solveMem(satis,0,time,dp);

    }
};
