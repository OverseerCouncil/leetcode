    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int customers_num = customers.size();
        int base_cnt = 0;
        for (int i = 0; i < customers_num; i++) {
            base_cnt += customers[i] * (1 - grumpy[i]);
        }
        int more_cnt = 0;
        for (int i = 0; i < X; i++) {
            more_cnt += customers[i] * grumpy[i];
        }
        int res_cnt = more_cnt;
        for (int i = X; i < customers_num; i++) {
            more_cnt = more_cnt + customers[i] * grumpy[i] - customers[i - X] * grumpy[i - X];
            res_cnt = max(more_cnt, res_cnt);
        }
        return res_cnt + base_cnt;
    }