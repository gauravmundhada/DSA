class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();

        if (s1 == s2) return true;

        string evenStr = "";
        string oddStr = "";

        string evenStr2 = "";
        string oddStr2 = "";

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenStr  += s1[i];
                evenStr2 += s2[i];
            }
            else {
                oddStr  += s1[i];
                oddStr2 += s2[i];
            }
        }

        sort(evenStr.begin(), evenStr.end());
        sort(evenStr2.begin(), evenStr2.end());
        sort(oddStr.begin(), oddStr.end());
        sort(oddStr2.begin(), oddStr2.end());

        return (evenStr == evenStr2) && (oddStr == oddStr2);

    }
};

/*
which numbers difference will be even -> (odd - odd), (even - even)

abcdba
even - a, c, b
odd  - b, d, a

cabdab
even - c, b, a
odd  - a, d, b 
*/