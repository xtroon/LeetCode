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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;

        while(temp){
            cnt++;
            temp = temp->next;
        }

        if(cnt == n) return head->next;
        int todel  = cnt - n;
        temp = head;

        for(int i=1; i<todel; i++){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};