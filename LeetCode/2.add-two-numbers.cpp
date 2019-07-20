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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* l = ret;
        for (int c = 0; c > 0 || l1 != NULL || l2 != NULL; c /= 10) {
            if (l1 != NULL) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                c += l2->val;
                l2 = l2->next;
            }
            l->next = new ListNode(c % 10);
            l = l->next;
        }
        return ret->next;
    }
};
