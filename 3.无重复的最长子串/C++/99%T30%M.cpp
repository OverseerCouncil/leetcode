class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> HashMap;
        int ans=0;
        int i,j;
        for(i=0,j=0;j<s.size();j++)
        {
            if(HashMap.count(s[j]))
            {
                i=max(i,HashMap.at(s[j]));
            }
            ans=max(ans,j-i+1);
            HashMap[s[j]]=j+1;
            if(s.size()-i<ans)
            {
                break;
            }
        }
        return ans;
    }
};