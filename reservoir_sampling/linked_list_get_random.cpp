struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

/**
 * Chooses a node randomly from the list and returns its value.
 */
int getRandom(ListNode *head) {
    ListNode* p = head;
    int res = p->val;
    int count = 1;
    while (p) {
        if (rand() % count == 0) res = p->val;
        ++count;
        p = p->next;
    }
    return res;
}
