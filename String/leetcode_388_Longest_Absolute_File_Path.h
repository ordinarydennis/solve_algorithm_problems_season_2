class Solution {
public:
    int lengthLongestPath(string input) {

        string s;

        int tCount = 0;

        std::unordered_map<int, int> m;

        int isDir = 1;

        int ret = 0;

        for (int i = 0; i <= input.size(); i++)
        {
            if ('\n' == input[i] || '\0' == input[i])
            {
                int size = 0;

                if (0 < tCount)
                {
                    size = m[tCount - 1] + s.size() + isDir;
                }
                else
                {
                    size = s.size() + isDir;
                }

                m[tCount] = size;

                if (0 == isDir)
                {
                    ret = max(ret, size);
                }

                s.clear();
                tCount = 0;
                isDir = 1;
            }
            else if ('\t' == input[i])
            {
                tCount++;
            }
            else if ('.' == input[i])
            {
                isDir = 0;
                s += input[i];
            }
            else
            {
                s += input[i];
            }
        }

        return ret;
    }
};