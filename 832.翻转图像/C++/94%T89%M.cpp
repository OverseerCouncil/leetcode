    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row_size = A.size();
        int col_size = A[0].size();
        int start, end;
		for (int i = 0; i < row_size; i++) {
			start = 0, end = col_size - 1;
			while (start < end) {
				if (A[i][start] == A[i][end]) {
					A[i][start] = !A[i][start];
					A[i][end] = !A[i][end];
				}
                start++;
				end--;
			}
			if (start == end) {
				A[i][start] = !A[i][start];
			}
		}
		return A;
    }