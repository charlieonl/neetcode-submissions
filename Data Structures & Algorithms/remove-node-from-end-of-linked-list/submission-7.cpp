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

        if (head->next == nullptr && n==1) {
            head = nullptr;
            return head;
        }

        ListNode* cur = head;
        int length = 0;

        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }

        int to_remove = length-n;
        if (to_remove == 0) {
            head = head->next;
            return head;
        }

        ListNode* cur1 = head;
        int count=1;
        while (count != to_remove) {
            cur1 = cur1->next;
            count++;
        }
        // if (count == 0) {
        //     cur1 = head->next;
        //     head->next = nullptr;
        //     head = cur1;
        //     return head;
        // }
        cur1->next = (cur1->next)->next;
        return head;
    }
};
