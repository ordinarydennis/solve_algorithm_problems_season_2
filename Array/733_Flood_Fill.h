class Solution {

    void dfs(vector<vector<int>>& image, int sr, int sc, int origin_color, int color)
    {

        if (sr < 0 || image.size() <= sr)
        {
            return;
        }

        if (sc < 0 || image[0].size() <= sc)
        {
            return;
        }

        if (image[sr][sc] != origin_color)
        {
            return;
        }

        image[sr][sc] = color;

        dfs(image, sr, sc - 1, origin_color, color);
        dfs(image, sr, sc + 1, origin_color, color);
        dfs(image, sr + 1, sc, origin_color, color);
        dfs(image, sr - 1, sc, origin_color, color);
    }


public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        dfs(image, sr, sc - 1, image[sr][sc], color);
        dfs(image, sr, sc + 1, image[sr][sc], color);
        dfs(image, sr + 1, sc, image[sr][sc], color);
        dfs(image, sr - 1, sc, image[sr][sc], color);

        image[sr][sc] = color;

        return image;
    }
};