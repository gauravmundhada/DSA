class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<p, vector<p>, greater<p>> minHeap;

        for (auto& entry : freq) {
            minHeap.push({entry.second, entry.first});

            if (minHeap.size() > k) 
                minHeap.pop();
        }

        vector<int> res;

        while (!minHeap.empty()) {
            auto [freq, element] = minHeap.top();
            minHeap.pop();

            res.push_back(element);
        }
        return res;
    }
};