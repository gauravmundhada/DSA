class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int laserBeams = 0;

        int prevCount = -1;

        for (string str : bank) {
            int onesC= 0;

            for (char c : str) {
                if (c == '1') onesC++;
            }

            if (prevCount == -1) {
                prevCount = onesC;
            } else {
                laserBeams += (prevCount * onesC);

                if (onesC != 0) prevCount = onesC;
            }
        }

        return laserBeams;
    }
};