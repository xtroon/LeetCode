class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lo = 0, hi = n-1;

        while(lo<m && hi>=0){
            if(matrix[lo][hi] == target) return true;
            else if(matrix[lo][hi] > target) hi--;
            else lo++;
        }
        return false;
    }
};