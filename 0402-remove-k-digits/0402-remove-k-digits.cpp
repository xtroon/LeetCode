class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        // remove big numb. if got small num
        for (int i = 0; i < num.size(); i++) {
            while (!ans.empty() && k > 0 && ans.back() > num[i]) {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }

        // if k left  - remove from last
        while (k > 0) {
            ans.pop_back();
            k--;
        }

        //remove leading zeroes
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        string res = ans.substr(i);
        return res.empty() ? "0" : res;
    }
};