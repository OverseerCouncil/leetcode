class Solution {
public
    vectorint twoSum(vectorint& nums, int target) {
        vectorint Solut;
        mapint,int M;
        mapint,intiterator iter;
        for(int i=0;inums.size();i++)
        {
            iter=M.find(nums[i]);
            if(iter!=M.end())
            {
                Solut.push_back(iter-second);
                Solut.push_back(i);
                return Solut;
            }
            M.insert({target-nums[i],i});
        }
        return Solut;
    }
};