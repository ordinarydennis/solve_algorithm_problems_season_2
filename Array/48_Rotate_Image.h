class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n - 1;
        while (a < b) {
            for (int i = 0;i < (b - a);++i) {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            ++a;
            --b;
        }
    }
};

//https://leetcode.com/problems/rotate-image/solutions/19002/4ms-few-lines-c-code-rotate-image-90-degree-for-o-1-space/?orderBy=most_votes
//https://leetcode.com/problems/rotate-image/solutions/18884/seven-short-solutions-1-to-7-lines/?orderBy=most_votes