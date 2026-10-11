/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {   //(I changed the list1,2 name to head1,2)
        ListNode* dummy= new ListNode(0);
        ListNode* curr=dummy;
        while(head1!=NULL && head2!=NULL){
            if(head1->val < head2->val){
                curr->next=head1;
                head1=head1->next;
            }
            else{
                curr->next=head2;
                head2=head2->next;
            }
            curr=curr->next;
        }
        if(head1!=NULL){
            curr->next=head1;
        }
        else{
            curr->next=head2;
        }
        return dummy->next;
    }
};