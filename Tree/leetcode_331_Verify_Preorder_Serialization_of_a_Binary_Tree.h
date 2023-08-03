class Solution {
public:
	bool isValidSerialization(string preorder) {


		std::stack<int> st;

		for (int i = 0; i < preorder.size() - 2; i++)
		{
			if (',' == preorder[i] || '#' == preorder[i])
			{
				continue;
			}

			st.push(preorder[i]);

			//leaf
			if ('#' == preorder[i + 1] && '#' == preorder[i + 2])
			{
				if (st.size())
				{
					st.pop();
				}
				else
				{
					return false;
				}
				i += 2;
			}
		}

		return st.size();

	}
};