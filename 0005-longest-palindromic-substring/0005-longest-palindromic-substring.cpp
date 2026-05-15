class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i=0; i< s.size(); i++){
            int st = i, en = i;

            // check odd palindrom 
            while(st>=0 && en<s.length() &&s[st]==s[en]){
                st--;
                en++;
            }
            string temp = s.substr(st+1, en-st-1);
            if(temp.length() > res.length()) res = temp;

            // even odd palindrome
            st = i, en = i+1;
            while(st>=0 && en<s.length() && s[st]==s[en]){
                st--;
                en++;
            }
            temp = s.substr(st+1, en-st-1);
            if(temp.length() > res.length()) res = temp;

        }
        return res;
    }
};