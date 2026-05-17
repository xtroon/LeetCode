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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(0);
        ListNode* evenHead = new ListNode(0);
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;

        int cnt = 1;

        ListNode* temp = head;
        while(temp){
            if(cnt%2 == 1){
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            else{
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
            temp = temp->next;
            cnt++;
        }

        evenTail->next = NULL;
        oddTail->next = evenHead->next;
        return oddHead->next;
    }
};