/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* pre=head;
        int p=0,q=0,o=0,newValue=0;
        bool UpOne=false;
        while(l1||l2)
        {
            if(l1)
            {
                p=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                q=l2->val;
                l2=l2->next;
            }
            if(UpOne)
            {
                o=1;
                UpOne=false;
            }
            newValue=p+q+o;
            p=q=o=0;
            if(newValue>=10)
            {
                newValue-=10;
                UpOne=true;
            }
            ListNode* cur=new ListNode(newValue);
            pre->next=cur;
            pre=pre->next;
        }
        if(UpOne)
        {
            ListNode* cur=new ListNode(1);
            pre->next=cur;
        }
        return head->next;
    }
};