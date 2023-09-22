
struct Node
{
	int mIndex = 0;
	string mS;

	Node(int index, const string& s)
		:mIndex(index), mS(s)
	{

	}
};



class Solution {
public:
	int numMatchingSubseq(string S, vector<string>& words) {

		vector<Node> bucket[26];

		for (auto& w : words)
		{
			bucket[w[0] - 'a'].emplace_back(0, w);
		}

		int ret = 0;

		for (char c : S)
		{
			auto temp = std::move(bucket[c - 'a']);

			for (auto& node : temp)
			{
				node.mIndex++;

				if (node.mIndex == node.mS.size())
				{
					ret++;
				}
				else
				{
					bucket[node.mS[node.mIndex] - 'a'].push_back(node);
				}
			}

		}

		return ret;

	}
};

//leetcode.com/problems/number-of-matching-subsequences/solutions/1290406/c-java-python-process-by-bucket-picture-explain-o-n-s/
//leetcode.com/problems/number-of-matching-subsequences/solutions/117634/efficient-and-simple-go-through-words-in-parallel-with-explanation/

