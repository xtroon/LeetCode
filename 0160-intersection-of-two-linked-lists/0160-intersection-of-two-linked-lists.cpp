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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        
        //list 1 legth
        int len1 = 0;
        while(temp){
            len1++;
            temp = temp->next;
        }
        
        //list 2 length
        temp = headB;
        int len2 = 0;
        while(temp){
            len2++;
            temp = temp->next;
        }

        int diff = len1 - len2;

        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        if(diff <0){
            while(diff){
                diff++;
                tempB = tempB->next;
            }
            while(tempA != nullptr){
                if(tempA == tempB) return tempA;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }else{
            while(diff){
                diff--;
                tempA = tempA->next;
            }
            while(tempA != nullptr){
                if(tempA == tempB) return tempA;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        return nullptr;
    }
};