public class Solution {
    int n;
    public bool FindRotation(int[][] mat, int[][] target) {
        n = mat.Length;

        for (int i = 0; i < 4; i++) {
            if (AreEqual(mat, target)) {
                return true;
            }
            Rotate(mat);
        }
        return false;
    }

    // transpose then reverse the row
    public void Rotate(int[][] mat) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                (mat[i][j], mat[j][i]) = (mat[j][i], mat[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            Array.Reverse(mat[i]);
        }
    }

    public bool AreEqual(int[][] a, int[][] b) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }
}