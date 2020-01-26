class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i=ans=0
        n=len(s)
        dictionary={}
        for j in range(0,n):
            if s[j] in dictionary:
                i=max(i,dictionary[s[j]])
            dictionary[s[j]]=j+1
            ans=max(j-i+1,ans)
        return ans