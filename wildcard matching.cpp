// Problem Link https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    bool isMatch(string s, string p) {
        
        int size1=p.size();
        int size2=s.size();
        
        vector<vector<bool>> dp(size1+1,vector<bool>(size2+1));
        
        dp[size1][size2]=true;
        
        for(int row=size1-1;row>=0;row--){
            
            for(int col=size2;col>=0;col--){
                if((p[row]==s[col] || p[row]=='?') && row+1<=size1 && col+1<=size2 && dp[row+1][col+1]==true){
                    dp[row][col]=true;
                }
                else if(p[row]=='*' ){
                    if(row+1<=size1 && dp[row+1][col]==true){
                        dp[row][col]=true;
                    }   
                    else if(row+1<=size1 && col+1<=size2 && dp[row][col+1]==true){
                        dp[row][col]=true;
                    }
                }
            }
        }
        return dp[0][0];
    }
};