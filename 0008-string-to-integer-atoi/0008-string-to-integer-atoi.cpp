class Solution {
public:

    int rounding(int ans, int i, int n, string s, int sign){
        if(i >= n || !isdigit(s[i])) return ans*sign;
        
        int digit = s[i] - '0';

        if(ans > (INT_MAX - digit)/10){
            return sign == 1? INT_MAX : INT_MIN;
        }
        ans = ans*10 + digit;

        return rounding(ans, i+1, n, s, sign);
    }

    int myAtoi(string s) {
        int ans = 0;
        int i =0, n = s.length();

        // remove spaces
        while(i<n && s[i]==' ') i++;
    
        // find sign
        int sign = 1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign = -1;
            i++;
        }

        //recuresive fxn with return;
        return rounding(ans, i, n, s, sign);
    }
};