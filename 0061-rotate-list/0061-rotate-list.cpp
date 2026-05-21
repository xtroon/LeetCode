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
    ListNode* reverse(ListNode* head, int k){
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(k--){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k == 0) return head;

        ListNode* temp = head;
        //find length
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }


        k = k % len;
        if(k == 0) return head;

        //reverse entire List
        head = reverse(head, len);

        // kth node
        temp = head;
        for(int i=1; i<k; i++){
            temp = temp->next;
        }
        //store next node address
        ListNode* nextNode = temp->next;

        //reverse first part
        ListNode* newHead = reverse(head, k);

        //reverse second part
        nextNode = reverse(nextNode, len - k);

        //connect
        head->next = nextNode;

        return newHead;
    }
};