class Solution {
public:
    bool rotateString(string s, string goal) {
        // aproach 1:
        // if( s.length() != goal.length()) return false;

        // s = s+s;
        // if(s.find(goal) != string::npos) return true;

        // return false;

        // approach 2 : shortcut of approach 1
        // return s.length() == goal.length() && (s+s).find(goal) != string::npos;

        // approach 3: 
        if(s.length() != goal.length()) return false;
        for(int i=0; i< s.length(); i++){
            string rotated = s.substr(i) + s.substr(0, i);
            if(rotated == goal) return true;
        }
        return false;
    }
};