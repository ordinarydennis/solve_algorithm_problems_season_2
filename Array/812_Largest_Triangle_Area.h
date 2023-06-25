class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {


        std::sort(points.begin(), points.end(), [](const vector<int>& l, const vector<int>& r) {

            if (l[0] > r[0])
            {
                return true;
            }

            if (l[0] < r[0])
            {
                return false;
            }

            if (l[0] == r[0])
            {
                if (l[1] > r[1])
                {
                    return true;
                }

                if (l[1] < r[1])
                {
                    return false;
                }
            }

            return true;

            }
        );

        return (points[0][0] - points[points.size() - 1][0] * points[1][1] - points[points.size() - 1][1]) / 2;

    }
};