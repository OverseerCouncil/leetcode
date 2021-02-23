    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        sup_list = [0 for x in range(0, 1000)]
        ret = 0
        for it in dominoes:
            val = it[0] * 10 + it[1] if it[0] < it[1] else it[1] * 10 + it[0]
            ret = ret + sup_list[val]
            sup_list[val] = sup_list[val] + 1
        return ret