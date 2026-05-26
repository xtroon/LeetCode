class Solution {
public:
    void getComb(vector<int>& nums, int tar, int idx, vector<int>& curr, vector<vector<int>>& ans){
        if(tar == 0){
            ans.push_back(curr);
            return;
        }

        if(idx == nums.size() || tar<0){
            return;
        }

        // use current element and mvoe to next
        curr.push_back(nums[idx]);
        getComb(nums, tar-nums[idx], idx+1, curr, ans);

        //backtrack
        curr.pop_back();

        // remove similar elemnts as we want unique pairs 
        while(idx+1 < nums.size() && nums[idx]==nums[idx+1]){
            idx++;
        }

        //don't use current and move to next
        getComb(nums, tar, idx+1, curr, ans);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;

        getComb(candidates, target, 0, curr, ans);

        return ans;
    }
};