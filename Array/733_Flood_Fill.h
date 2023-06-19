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

		if (image[sr][sc] == color)
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

        dfs(image, sr, sc, image[sr][sc], color);

        return image;
    }
};

//https://leetcode.com/problems/flood-fill/solutions/1590584/c-simple-dfs-97-6-faster-91-6-better-memory-use/