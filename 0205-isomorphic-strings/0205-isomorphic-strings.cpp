class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> v(256,1000);
        //checking t with perspective of s
        for(int i=0; i<s.size();i++){
            int idx = (int)s[i];
            if(v[idx]==1000) v[idx] = s[i] - t[i];
            else if(v[idx]!=(s[i]-t[i])) return false;
        }
        //checking t with perspective of s
        for(int i=0; i<v.size();i++) v[i] = 1000; //reset array

        for(int i=0; i<t.size();i++){
            int idx = (int)t[i];
            if(v[idx]==1000) v[idx] = t[i] - s[i];
            else if(v[idx]!=(t[i]-s[i])) return false;
        }

        return true;
    }
};