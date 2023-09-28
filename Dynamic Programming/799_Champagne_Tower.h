class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        int totalCount = 0;
        int preTotalCount = 0;

        for (int i = 0; i <= query_row; i++)
        {
            totalCount += i + 1;

            if (i == query_row - 1)
            {
                preTotalCount = totalCount;
            }
        }

        int remain = poured - preTotalCount;


        int needTo = totalCount - preTotalCount;

        double ret = static_cast<double>(remain) / needTo;

        return (1.0f < ret) ? 1.0f : ret;

    }
};