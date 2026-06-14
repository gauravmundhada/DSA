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
        if (head == NULL) return 0;

        vector<int> list;
        while (head) {
            list.push_back(head->val);
            head = head->next;
        }

        int l = 0, r = list.size()-1;

        int ans = 0;
        while (l <= r) {
            ans = max(ans, list[l]+list[r]);
            l++;
            r--;
        }
        return ans;
    }
};

/*
first find n -> length of LL

I can convert it into the list and then use 2 pointers this approach will take O(n) space and O(n) Time

other approach is to iterate over the LL again and again to find the twin approx O(n^2)

Hint is also helpful - we can reverse the later half of the LL and then 2 pointers approach

*/