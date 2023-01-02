class Solution {
public:
    vector<int> diffWaysToCompute(string input) {

        vector<int> result;

        if (1 == input.size())
        {
            result.push_back(std::atoi(input.c_str()));
            return result;
        }

        for (int i = 0; i < input.size(); i++)
        {
            if ('+' == input[i] || '-' == input[i] || '*' == input[i])
            {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i + 1));

                for (int n1 : result1)
                {
                    for (int n2 : result2)
                    {
                        if ('+' == input[i])
                            result.push_back(n1 + n2);
                        else if('-' == input[i])
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }

        if (result.empty())
        {
            result.push_back(std::atoi(input.c_str()));
        }

        return result;
    }
};