# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head=ListNode(0)
        cur=head
        p=q=o=0
        while l1!=None or l2!=None:
            if l1!=None:
                p=l1.val
            if l2!=None:
                q=l2.val
            newValue=p+q+o
            p=q=o=0
            if newValue>=10:
                newValue-=10
                o=1
            newNode=ListNode(newValue)
            cur.next=newNode
            cur=cur.next
            if l1!=None:
                l1=l1.next
            if l2!=None:
                l2=l2.next
        if o==1:
            newNode=ListNode(1)
            cur.next=newNode
        return head.next