class Solution {
public:
    void generate(int st, int en, int n, string curr, vector<string>& res){
        if(curr.length() == 2*n){
            res.push_back(curr);
            return;
        }
        if(st < n) generate(st +1, en, n, curr + '(', res);
        if(en < st) generate(st, en + 1, n, curr + ')', res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0, 0, n, "", res);
        return res;
    }
};