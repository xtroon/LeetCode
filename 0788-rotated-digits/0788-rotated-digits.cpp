class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n+1, 0);
        int cnt = 0;

        // 0 -> invalid
        // 1 -> ok but not changed
        //2 -> changed

        for(int i=0; i<=n; i++){
            if( i < 10){
                if(i==0 || i==1 || i==8) dp[i] =1;
                else if(i==3 || i==4 || i==7) dp[i] = 0;
                else dp[i] = 2;
            }
            else{
                int a = dp[i/10];
                int b = dp[i%10];

                if( a==1 && b==1) dp[i] = 1;
                else if(a==0 || b==0) dp[i] = 0;
                else dp[i] = 2;
            }

            if(dp[i] == 2) cnt++;
        }
        return cnt;
    }
};