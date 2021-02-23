        A.sort()
        B.sort()
        sumA, sumB = sum(A), sum(B)
        target = (sumA - sumB) / 2
        i = 0
        j = 0
        while A[i] - B[j] != target:
            if A[i] - B[j] > target:
                j += 1
            else:
                i += 1
        return [A[i], B[j]]