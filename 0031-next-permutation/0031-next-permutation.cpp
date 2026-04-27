class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // finding largest prefix match from back
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        // if didnt find then its last element:
        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //find smallest prefix value from end in arr
        for(int i=n-1; i>=0; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // remaining part will need to be sorted,  it would  need a reverse only 
        sort(nums.begin() + idx + 1, nums.end()); 
    }
};