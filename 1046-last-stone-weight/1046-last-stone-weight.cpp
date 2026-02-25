class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq(stones.begin(), stones.end()); // by default max heap in cpp

        while (pq.size() > 1) {
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();

            if (top1 == top2) continue;

            pq.push(abs(top1-top2));
        }
        return (pq.empty()) ? 0 : pq.top();
    }
};