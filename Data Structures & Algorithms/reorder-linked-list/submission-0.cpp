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
    void reorderList(ListNode* head) {
        std::vector<ListNode*> vec;

        ListNode *cur = head;
        int length = 0;
        
        while (cur != nullptr) {
            length++;
            vec.push_back(cur);
            cur = cur->next;
        }
        ListNode* track = head;
        head = track;

        for (int i = 0; i < (length+1)/2; i++) {
            if (i != 0) {
                track->next = vec[i];
                // set front
                track = track->next;
            }
            track->next = nullptr;
            // if back = front, finish
            if (length-1-i == i) break;
            // node's next = back
            track->next = vec[length-1-i];
            track = track->next;
            track->next = nullptr;
        }
    }
};
