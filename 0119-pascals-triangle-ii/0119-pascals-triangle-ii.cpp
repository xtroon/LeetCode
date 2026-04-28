class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        long long curr = 1;

        for(int i=0; i<=rowIndex; i++){
            ans[i] = curr;
            curr = curr*(rowIndex - i)/(i+1);
        }
        return ans;
    }
};