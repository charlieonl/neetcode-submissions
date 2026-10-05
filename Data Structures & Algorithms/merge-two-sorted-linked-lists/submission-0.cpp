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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1;
        // declare trackers for each list & result list
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* curf = new ListNode(); 
        ListNode* final = new ListNode(); 

        // decide which list to start
        if (cur1->val <= cur2->val) {
            final->val = cur1->val;
            cur1 = cur1->next;
        } else if (cur2->val < cur1->val) {
            final->val = cur2->val;
            cur2 = cur2->next;
        }
        curf = final;

        while (cur1 || cur2) {
            if (!cur1 && cur2) {
                curf->next = new ListNode(cur2->val, nullptr);
                curf = curf->next;

                cur2 = cur2->next;
            } else if (!cur2 && cur1) {
                curf->next = new ListNode(cur1->val, nullptr);
                curf = curf->next;

                cur1 = cur1->next;
            } else if (cur1->val <= cur2->val) {
                curf->next = new ListNode(cur1->val, nullptr);
                curf = curf->next;

                cur1 = cur1->next;
                
            } else if (cur2->val < cur1->val) {
                curf->next = new ListNode(cur2->val, nullptr);
                curf = curf->next;
                
                cur2 = cur2->next;
                
            }
        }
        return final;
    }
};



