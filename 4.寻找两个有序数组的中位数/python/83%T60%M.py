class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n=len(nums1)
        m=len(nums2)
        lb=0
        hb=2*n
        if n>m:
            return self.findMedianSortedArrays(nums2,nums1)
        while lb<=hb:
            c1=(lb+hb)//2
            c2=m+n-c1
            if c1==0:
                lmax1=float("-inf")
            else:
                lmax1=nums1[(c1-1)//2]
            if c1==2*n:
                rmin1=float("inf")
            else:
                rmin1=nums1[c1//2]
            if c2==0:
                lmax2=float("-inf")
            else:
                lmax2=nums2[(c2-1)//2]
            if c2==2*m:
                rmin2=float("inf")
            else:
                rmin2=nums2[c2//2]
            if lmax1>rmin2:
                hb=int(c1-1)
            elif lmax2>rmin1:
                lb=int(c1+1)
            else:
                break
        return (max(lmax1,lmax2)+min(rmin1,rmin2))/2.0