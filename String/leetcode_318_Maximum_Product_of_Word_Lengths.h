class Solution {
public:
    int maxProduct(vector<string>& words) {

        int mask = 0;

        std::vector<int> masks(words.size());


        for (int a = 0; a < words.size(); a++)
        {
            for (char c : words[a])
            {
                masks[a] |= 1 << (c - 'a');
            }
        }

        int max = 0;

        for (int a = 0; a < words.size(); a++)
        {
            for (int b = 1; b < words.size(); b++)
            {
                if (!(masks[a] & masks[b]))
                {
                    max = std::max(max, (int)(words[a].size() * words[b].size()));
                }
            }
        }

        return max;
    }
};