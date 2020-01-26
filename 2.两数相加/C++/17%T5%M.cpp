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
        ListNode* lrs=new ListNode(l1->val+l2->val);
        ListNode* cur=lrs;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL&&l2!=NULL)
        {
            cur->next=new ListNode(l1->val+l2->val);
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL)
        {
            while(l2!=NULL)
            {
                cur->next=new ListNode(l2->val);
                cur=cur->next;
                l2=l2->next;
            }
        }
        if(l2==NULL)
        {
            while(l1!=NULL)
            {
                cur->next=new ListNode(l1->val);
                cur=cur->next;
                l1=l1->next;
            }
        }
        cur=lrs;
        bool upOne=false;
        while(1)
        {
            if(upOne==true)
            {
                cur->val++;
                upOne=false;
            }
            if(cur->val>=10)
            {
                cur->val-=10;
                upOne=true;
            }
            if(cur->next!=NULL)
            {
                cur=cur->next;
                continue;
            }
            else
            {
                if(upOne==true)
                {
                    cur->next=new ListNode(1);
                }
                break;
            }
        }
        return lrs;
    }
};