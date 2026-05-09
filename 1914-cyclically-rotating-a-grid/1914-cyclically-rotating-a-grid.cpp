class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int r) {
        int m = grid.size();
        int n = grid[0].size();

        int left = 0, right = n-1;
        int top = 0, down = m-1;

        while(left<right && top <down){
            vector<int> layer;

            // left-> right 
            for(int i=left; i<right; i++){
                layer.push_back(grid[top][i]);
            }

            // top->down
            for(int j=top; j<down; j++){
                layer.push_back(grid[j][right]);
            }

            //right -> left
            for(int i=right; i>left; i--){
                layer.push_back(grid[down][i]);
            }

            // down-> top 
            for(int j=down; j>top; j--){
                layer.push_back(grid[j][left]);
            }

            //rotating by 1 using inbuild fxn
            int rot = r % layer.size();
            rotate(layer.begin(), layer.begin() + rot, layer.end());

            // pushing back in array as it has updated and rotated array layer

            int k = 0;
            // left-> right 
            for(int i=left; i<right; i++){
                grid[top][i] = layer[k++];
            }

            // top->down
            for(int j=top; j<down; j++){
                grid[j][right] = layer[k++];
            }

            //right -> left
            for(int i=right; i>left; i--){
                grid[down][i] = layer[k++];
            }

            // down-> top 
            for(int j=down; j>top; j--){
                grid[j][left] = layer[k++];
            }

            //updating all
            top++;
            left++;
            down--;
            right--;
        }
        return grid;
    }
};