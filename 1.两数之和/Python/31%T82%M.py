class Solution
    def twoSum(self, nums List[int], target int) - List[int]
        l=len(nums)
        for i in range(0,l)
            try
                w=nums.index(target-nums[i])
            except
                pass
            else
                if i==w
                    continue
                return [i,w]
        return [0,0]