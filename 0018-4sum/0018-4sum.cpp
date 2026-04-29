class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                unordered_set<int> seen;

                for(int k=j+1; k<n; k++){
                    long long req = (long long)target - nums[i] - nums[j] - nums[k];

                    if(req > INT_MAX || req < INT_MIN) continue;
                    if(seen.find(req) != seen.end()){
                        vector<int> vec = { nums[i], nums[j], nums[k], (int)req};
                        sort(vec.begin(), vec.end());
                        ans.insert(vec);
                    }

                    seen.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};