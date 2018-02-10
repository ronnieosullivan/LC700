class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = 0, n = 1;
        ListNode* p = _head;
        while (p) {
            if (rand() % n == 0) res = p->val;
            p = p->next;
            n++;
        }
        return res;
    }
private:
    ListNode* _head;
};