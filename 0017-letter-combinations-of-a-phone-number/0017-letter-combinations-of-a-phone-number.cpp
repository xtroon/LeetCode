class Solution {
public:
    void getmap(string& digits, unordered_map<char, string>& mapping, int idx, string& str, vector<string>& ans){

        if( idx == digits.size()){
            ans.push_back(str);
            return;
        }

        // letters mapped at current digit
        string letters = mapping[digits[idx]];

        // try every letter with this dig
        for(char ch: letters){
            str.push_back(ch);
            getmap(digits, mapping, idx+1, str, ans);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        //table
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string str = "";
        getmap(digits, digitToLetters, 0, str, ans);
        return ans;
    }
};