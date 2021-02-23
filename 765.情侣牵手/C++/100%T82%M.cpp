    int find(vector<int>& f, int x) {
        return x == f[x] ? x : (f[x] = find(f, f[x]));
    }

    void merge(vector<int>& f, int x, int y) {
        f[find(f, x)] = find(f, y);
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int tot = n / 2;
        vector<int> f(tot);

        //初始化并查集
        for (int i = 0; i < tot; i++) {
            f[i] = i;
        }
        for (int i = 0; i < n; i += 2) {
            merge(f, row[i] / 2, row[i + 1] / 2);
        }

        //成环
        unordered_map<int, int> m;
        for (int i = 0; i < tot; i++) {
            m[find(f, i)]++;
        }
        
        //计算结果
        int ret = 0;
        for (const auto& [f, size]: m) {
            ret += size - 1;
        }
        return ret;
    }