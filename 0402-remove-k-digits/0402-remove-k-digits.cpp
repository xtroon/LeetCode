class Solution {
public:
    string removeKdigits(string num, int k) {
        //simple condn. early exit
        if(k >= num.size()) return "0";

        // build stack
        stack<char> st;
        for(char ch : num){
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        //if still k left - remove form back
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        // move to stirng 
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        // remove leading zeroes - curretly we hv reversed strign as popped from stack
        while(!ans.empty() && ans.back() == '0') ans.pop_back();

        //reverse and return
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};