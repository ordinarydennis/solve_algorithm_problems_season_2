class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        vector<vector<int>> ret;

        for (int x = 0; x < matrix[0].size(); x++)
        {
            vector<int> list;

            for (int y = 0; y < matrix.size(); y++)
            {
                list.push_back(matrix[y][x]);
            }

            ret.emplace_back(std::move(list));
        }

        return ret;
    }
};