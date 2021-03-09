    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> res(cols, vector<int>(rows));
        for(int i = 0; i < cols * rows; i++) {
            res[i / rows][i % rows] = matrix[i % rows][i / rows];
        }
        return res;
    }