class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();

        k %= n;

        vector<int> temp(k);
        int j = 0;
        for (int i = n-k; i < n; i++) {
            temp[j] = arr[i];
            j++;
        }

        for (int i = n-1-k; i >= 0; i--) {
            arr[i+k] = arr[i];
        }

        for (int i = 0; i < temp.size(); i++) {
            arr[i] = temp[i];
        }
    }
};