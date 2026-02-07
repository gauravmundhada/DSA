class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        vector<int> BinLeft(n);
        vector<int> AinRight(n);
        int bCount = 0;

        for (int i = 0; i < n; i++) {
            BinLeft[i] = bCount;

            if (s[i] == 'b') {
                bCount++;
            }
        }

        int aCount = 0;
        for (int i = n-1; i >= 0; i--) {
            AinRight[i] = aCount;    
            
            if (s[i] == 'a') {
                aCount++;
            }
        }

        int deletions = n;
        for (int i = 0; i < n; i++) {
            deletions = min(deletions, AinRight[i]+BinLeft[i]);
        }
        return deletions;
    }
};