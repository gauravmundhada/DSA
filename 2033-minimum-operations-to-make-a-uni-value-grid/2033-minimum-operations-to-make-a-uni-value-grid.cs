public class Solution {
    public int OperationCount(ref List<int> list, int x, int mid) {
        int cnt = 0;
        foreach (int l in list) {
            cnt += Math.Abs(l-mid)/x;
        }  
        return cnt;
    }

    public int MinOperations(int[][] grid, int x) {
        int m = grid.Length;
        int n = grid[0].Length;
        int res = int.MaxValue;

        int rem = grid[0][0] % x;
        List<int> list = new();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != rem)
                    return -1;

                list.Add(grid[i][j]);
            }
        }

        list.Sort();

        int l = 0, r = m*n-1;

        while (l <= r) {
            int mid = l + (r-l)/2;
            int count = OperationCount(ref list, x, list[mid]);

            if (res > count) {
                res = count;
                r = mid-1;
            } 
            else {
                l = mid+1;
            }

        }
        return res;
    }
}