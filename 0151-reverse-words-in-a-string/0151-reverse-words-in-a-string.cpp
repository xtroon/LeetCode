class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size();

        while(i>=0){

            while(i>=0 && s[i]==' ') i--;
            if(i <0) break;
            
            int en = i;
            while(i>=0 && s[i] != ' ')i--;
            int st = i;

            string res = s.substr(st+1, en-st);

            if(!ans.empty()){
                ans += " ";
            }

            ans += res;
        }
        return ans;
    }
};