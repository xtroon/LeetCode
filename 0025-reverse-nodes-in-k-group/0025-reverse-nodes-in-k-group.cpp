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
    
    ListNode* reverse(ListNode* head, ListNode* nexxt, int k){
        ListNode* temp = head;
        ListNode* prev = nexxt;

        while(k--){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;

        // count lenght
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }

        //new LL
        ListNode* dummy = new ListNode(-1);
        ListNode* prevTail = dummy;

        temp = head;

        while(len >= k){

            // finding kth node
            ListNode* kth = temp;
            for(int i=1; i<k; i++){
                kth = kth->next;
            }

            // find next group;
            ListNode* nextGroup = kth->next;

            // reverse and add head of kth grp
            ListNode* newHead = reverse(temp, nextGroup, k);

            prevTail->next = newHead;
            prevTail = temp;

            temp = nextGroup;

            len -= k;
        }

        // add remainig nodes
        prevTail->next = temp;

        return dummy->next;

    }
};