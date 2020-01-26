# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur=head=ListNode(0)
        p=q=o=0
        while l1!=None or l2!=None:
            if l1!=None:
                p=l1.val
                l1=l1.next
            if l2!=None:
                q=l2.val
                l2=l2.next
            newValue=p+q+o
            p=q=o=0
            if newValue>=10:
                newValue-=10
                o=1
            cur.next=ListNode(newValue)
            cur=cur.next        
        if o:
            cur.next=ListNode(1)
        return head.next