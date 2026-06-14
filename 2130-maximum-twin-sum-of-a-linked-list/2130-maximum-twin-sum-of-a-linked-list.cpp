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
    int pairSum(ListNode* head) {
        int ans = 0;
        if (head == NULL) return ans;

        ListNode* firstPtr = head;

        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }

        ListNode* secondHalf = firstPtr;
        int cnt = 0;
        for (int i = 0; i < len / 2; i++) {
            secondHalf = secondHalf->next;
        }

        ListNode* secondPtr = reverseLL(secondHalf);

        while (firstPtr && secondPtr) {
            ans = max(ans, firstPtr->val+secondPtr->val);
            firstPtr = firstPtr->next;
            secondPtr = secondPtr->next;
        }

        return ans;
    }

    ListNode* reverseLL(ListNode* secondHalf) {
        if (secondHalf == nullptr) return nullptr;
        ListNode* prev = nullptr;

        while (secondHalf != nullptr) {
            ListNode* temp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }
        return prev;
    }
};


/*
first find n -> length of LL

I can convert it into the list and then use 2 pointers this approach will take O(n) space and O(n) Time

other approach is to iterate over the LL again and again to find the twin approx O(n^2)

Hint is also helpful - we can reverse the later half of the LL and then 2 pointers approach

*/