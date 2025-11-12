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
    ListNode* recursive(ListNode* head, ListNode* prev) {
        if (head == nullptr)
            return prev;

        ListNode* temp = head->next;
        head->next = prev;

        return recursive(temp, head);
    }

    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = nullptr;
        // ListNode* cur = head;

        // while (cur) {
        //     ListNode* temp = cur->next;
        //     cur->next = prev;
        //     prev = cur;
        //     cur = temp;
        // }
        // return prev;

        return recursive(head, nullptr);
    }
};