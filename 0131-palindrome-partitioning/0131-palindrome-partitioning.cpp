class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;

            l++;
            r--;
        }
        return true;
    }

    void getPart(string s, int idx, vector<string>& temp, vector<vector<string>>& ans){

        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i< s.size(); i++){
            if(isPalindrome(s, idx, i)){

                temp.push_back(s.substr(idx, i - idx + 1));

                getPart(s, i + 1, temp, ans);

                // backtrack
                temp.pop_back();
            }
        }
 
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        getPart(s, 0, temp, ans);
        return ans;
    }
};