class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<string> ret;

        const string& base = words[0];

        for (int a = 0; a < base.size(); a++)
        {
            bool found = true;

            for (int i = 1; i < words.size(); i++)
            {
                auto it = words[i].find(base[a]);

                if (it == string::npos)
                {
                    found = false;
                    break;
                }

                words[i].erase(it, 1);
            }

            if (found)
            {
                string s; 
                s += base[a];
                ret.push_back(s);

            }
        }

        
        return ret;

    }
};