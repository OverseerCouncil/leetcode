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
        ListNode* cur;
        int p,q,o,newValue;
        bool UpOne=false;
        while(l1!=NULL||l2!=NULL)
        {
            if(l1!=NULL)
            {
                p=l1->val;
                l1=l1->next;
            }
            else
            {
                p=0;
            }
            if(l2!=NULL)
            {
                q=l2->val;
                l2=l2->next;
            }
            else
            {
                q=0;
            }
            if(UpOne==true)
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
            cur=new ListNode(newValue);
            pre->next=cur;
            pre=pre->next;
        }
        if(UpOne==true)
        {
            cur=new ListNode(1);
            pre->next=cur;
        }
        return head->next;
    }
};