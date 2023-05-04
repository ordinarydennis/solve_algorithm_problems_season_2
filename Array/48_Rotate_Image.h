class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int rSize = matrix.size();

        int cSize = matrix[0].size();

        int start = 0;

        for (int r = 0; r < rSize; r++)
        {
            for (int i = start; i < cSize - start; i++)
            {
                std::swap(matrix[r][i], matrix[r + i][cSize - start - 1]);
                std::swap(matrix[r][i], matrix[rSize - start - 1][cSize - i - start - 1]);
                std::swap(matrix[r][i], matrix[rSize - i - start - 1][i + start]);
            }
            start++;
        }
    }
};

//https://leetcode.com/problems/rotate-image/solutions/19002/4ms-few-lines-c-code-rotate-image-90-degree-for-o-1-space/?orderBy=most_votes
//https://leetcode.com/problems/rotate-image/solutions/18884/seven-short-solutions-1-to-7-lines/?orderBy=most_votes