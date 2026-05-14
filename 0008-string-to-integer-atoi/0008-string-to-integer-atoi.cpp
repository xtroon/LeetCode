class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();

        int ans = 0;

        // remove leading spacess
        while (i < n && s[i] == ' ')
            i++;


        // check sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }


        // ignore 0 and non digit
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';

            //overflow handle
            if(ans > (INT_MAX - digit)/10){
                return sign ==1 ? INT_MAX : INT_MIN; 
            }

            ans = ans*10 + digit;   
            i++;
        }

        return sign*ans;
    }
};