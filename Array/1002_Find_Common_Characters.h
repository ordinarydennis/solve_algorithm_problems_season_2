class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        int length = INT_MAX;

        for (auto& s : words)
        {
            sort(s.begin(), s.end());

            length = std::min(length, static_cast<int>(s.length()));
        }

        vector<string> ret;

        for (int i = 0; i < length; i++)
        {
            char pre = words[i][0];
            bool check = true;
            for (int a = 0; a < words.size(); a++)
            {
                if (pre != words[a][i])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                string s = pre;
                ret.push_back(s);
            }
        }

        return ret;

    }
};