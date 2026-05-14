class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        int i = s.size();

        while(i >= 0){

            while(i>=0 && s[i]==' ') i--;

            if(i<0) break;

            int end = i;
            while(i >=0 && s[i] != ' ') i--;

            string res = s.substr(i+1, end-i);

            if(!ans.empty()){
                ans += ' ';
            }
            ans += res;
        }
        return ans;
    }
};