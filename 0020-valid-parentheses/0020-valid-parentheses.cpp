class Solution {
public:
    bool isValid(string s) {
        string str;

        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                str.push_back(ch);
            }
            else{
                if(str.empty()) return false;
                if(str.back() == '(' && ch == ')' ||
                    str.back() == '[' && ch == ']' ||
                    str.back() == '{' && ch == '}'){
                        str.pop_back();
                    }
                else return false;
            }

        }

        return str.empty();
    }
};