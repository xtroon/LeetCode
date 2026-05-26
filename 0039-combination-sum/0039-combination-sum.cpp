class Solution {
public:
    void getAllCombination(vector<int>& nums, int target, set<vector<int>>&ans, vector<int>& curr, int idx){

        if(idx == nums.size() || target < 0) return;

        if(target == 0){
            if(ans.find(curr) == ans.end()){
                ans.insert(curr);
                return;
            }
        }   

        //include this and move to next
        curr.push_back(nums[idx]);
        getAllCombination(nums, target-nums[idx], ans, curr, idx+1);

        // include this multiple time
        getAllCombination(nums, target-nums[idx], ans, curr, idx);

        //backtrack
        curr.pop_back();

        // exclude this and move to next
        getAllCombination(nums, target, ans, curr, idx+1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> curr;

        getAllCombination(candidates, target, ans, curr, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};