class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)<2:
            return s
        supstr="#"
        for i in range(0,len(s)):
            supstr+=s[i]
            supstr+="#"
        p=[0 for _ in supstr]
        maxRight=center=start=mirror=left=right=0
        maxLen=1
        for i in range(0,len(supstr)):
            if i<maxRight:
                mirror=2*center-i
                p[i]=min(maxRight-i,p[mirror])
            left=i-1-p[i]
            right=i+1+p[i]
            while left>=0 and right<len(supstr) and supstr[left]==supstr[right]:
                p[i]+=1
                left-=1
                right+=1
            if i+p[i]>maxRight:
                maxRight=i+p[i]
                center=i
            if p[i]>maxLen:
                maxLen=p[i]
                start=(i-maxLen)//2
        return s[start:start+maxLen]