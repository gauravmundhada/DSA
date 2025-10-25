class Solution {
public:
    int totalMoney(int n) {
        int weeks = n/7; // weeks
        int days  = n%7; // days

        int total = 0;
        int weekCount = 0;

        while (weeks != weekCount) {
            int curWeek = 28 + 7 * weekCount;
            total += curWeek;
            weekCount++;
        }

        if (days > 0) {
            int daySave = (days * (weeks+1)) + (((days-1)*days)/2);
            total += daySave;
        }

        return total;
    }
};

