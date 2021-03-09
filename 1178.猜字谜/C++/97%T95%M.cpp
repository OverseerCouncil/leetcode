        unordered_map<int, int> word_map;
        for (auto& word : words) {
            int key = 0;
            for (auto& ch : word) {
                key |= 1 << (ch -'a');
            }
            word_map[key]++;
        }

        vector<int> res(puzzles.size());
        int p_num = 0;
        for (auto& p : puzzles) {
            res[p_num] = dfs(p, 1, word_map, 1 << (p[0] - 'a'));
            p_num++;
        }
        return res;
    }

    int dfs(string& puzzle, int idx, unordered_map<int, int>& word_map, int key) {
        if (idx == puzzle.size()) {
            return (word_map.count(key) ? word_map[key] : 0);
        }
        return dfs(puzzle, idx + 1, word_map, key) + 
                dfs(puzzle, idx + 1, word_map, key | 1 << (puzzle[idx] - 'a'));
    }