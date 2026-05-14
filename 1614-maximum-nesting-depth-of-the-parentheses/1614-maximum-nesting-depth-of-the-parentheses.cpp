class Solution {
public:
    int maxDepth(string s) {
        int level = 0;
        int cnt = 0;
        for( char ch : s){
            if(ch == '(') cnt++;
            else if(ch== ')') cnt--;

            if(cnt > level) level = cnt;
        }
        return level;
    }
};