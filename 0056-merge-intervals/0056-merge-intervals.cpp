class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            int st = arr[i][0];
            int en = arr[i][1];

            if(!ans.empty() && en <= ans.back()[1]){
                continue;
            }

            for(int j = i+1; j<n; j++){
                if(arr[j][0] <= en){
                    en = max(en, arr[j][1]);
                }else{
                    break;
                }
            }

            ans.push_back({st, en});

        }

        return ans;
    }
};