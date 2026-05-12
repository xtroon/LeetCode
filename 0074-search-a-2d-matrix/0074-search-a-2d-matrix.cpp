class Solution {
public:
    bool binarySearch(vector<int>& nums, int target){
        int lo = 0;
        int hi = nums.size()-1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target) return true;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();


        for(int i=0; i<n; i++){
            if(matrix[i][0] >= target || matrix[i][m-1] >= target){
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }
};