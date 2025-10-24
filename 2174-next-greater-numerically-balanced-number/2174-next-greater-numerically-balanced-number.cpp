class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> allBeautifulNum;
        vector<int> count(10, 0); // freq count of digit -> 0-9
        generate(0, count, allBeautifulNum);
        sort(allBeautifulNum.begin(), allBeautifulNum.end());

        for (int num : allBeautifulNum) {
            if (num > n) return num;
        }
        return -1;
    }

    void generate(long num, vector<int>& count, vector<int>& allBeautifulNum) {
        if (num > 0 && isBeautiful(count)) {
            allBeautifulNum.push_back(num);
        }

        if (num > 1224444) return;

        for (int i = 1; i < 8; i++) {
            if (count[i] < i) {
                count[i]++;
                generate(num*10+i, count, allBeautifulNum);
                count[i]--;
            }
        }
    }

    bool isBeautiful(vector<int> &count) {
        for (int i = 1; i < 8; i++) {
            if (count[i] != 0 && count[i] != i) {
                return false;
            }
        }
        return true;
    }
};