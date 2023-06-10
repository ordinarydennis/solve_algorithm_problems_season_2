class Solution {
public:
    int calPoints(vector<string>& operations) {

        int size = operations.size();

        std::vector<int> list;

        for (int i = 0; i < size; i++)
        {
            string o = operations[i];

            if ("D" == o)
            {
                list.push_back(list[list.size() - 1] * 2);
            }
            else if ("+" == o)
            {
                int sum = list[list.size() - 1] + list[list.size() - 2];
                list.push_back(sum);
            }
            else if ("C" == o)
            {
                list.pop_back();
            }
            else
            {
                list.push_back(std::stoi(o));
            }
        }

        return std::accumulate(list.begin(), list.end(), 0);
    }
};