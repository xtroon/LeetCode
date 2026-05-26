class Solution {
public:
    void getComb(vector<int>& nums, int idx, int tar, vector<int>&curr, vector<vector<int>>& ans){
        //Base Case
        if(idx == nums.size() || tar < 0){
            return;
        }
        if(tar == 0){
            ans.push_back(curr);
            return;
        }

        // include + dont move next
        curr.push_back(nums[idx]);
        getComb(nums, idx, tar-nums[idx], curr, ans);

        //backtrack
        curr.pop_back();

        //exclude + move next
        getComb(nums, idx+1, tar, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        getComb(candidates, 0, target, curr, ans);
        return ans;
    }
};