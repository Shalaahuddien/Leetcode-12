class Solution {
public:
    int dp[1001][1001];
    int lcs(string &text1,string &text2,int index1,int index2)
    {
        if(index1<0|| index2<0)
            return 0;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        
        if(text1[index1]==text2[index2]){
            return dp[index1][index2]=1+lcs(text1,text2,index1-1,index2-1);       
        }
        else{
           return  dp[index1][index2]=max(lcs(text1,text2,index1-1,index2),lcs(text1,text2,index1,index2-1));
        }
            // return 
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text2,text1.size()-1,text2.size()-1);
    }
};