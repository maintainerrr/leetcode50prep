class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int x = 0, y =0;
        for(int len = 2;len<=n;len++){
            for(int j =0;j<=n-len;j++){
                if(len ==2) {
                    if(s[j]==s[j+1]){
                        x = j;
                        y= j+1;
                        dp[x][y] = 1;
                    }
                }else if(s[j]==s[j+len-1] && dp[j+1][j+len-2]==1){
                    x = j;
                    y = j+ len -1;
                    dp[x][y] =1;
                }
            }
        }
        
        string ans = s.substr(x,y-x+1);
        return ans;
        
    }
};
