class Solution {
public:
	bool isValidSerialization(string preorder) {

		std::stack<char> st;

		bool isNum = false;

		preorder.push_back(',');

		for (int i = 0; i < preorder.size(); i++)
		{
			if (',' == preorder[i])
			{
				if (isNum)
				{
					isNum = false;
					st.push('n');
				}

				continue;
			}

			if ('#' == preorder[i])
			{
				while (st.size() && '#' == st.top())
				{
					st.pop();

					if (st.size() && '#' != st.top())
					{
						st.pop();
					}
					else
					{
						return false;
					}
				}
				st.push(preorder[i]);
			}

			if ('#' != preorder[i])
			{
				isNum = true;
			}
		}

		return '#' == st.top() && 1 == st.size();
	}
};

class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<char> stk;
		bool isNum = false;
		preorder.push_back(','); // dummy tail

		for (auto c : preorder) {
			if (c == '#') {
				// absorb: search for pattern `#, number` backward
				while (!stk.empty() && stk.top() == '#') {
					stk.pop(); // pop `#`
					if (stk.empty() || stk.top() == '#') return false; // pattern `#,#,#`
					stk.pop(); // pop `number`
				}
				stk.push('#'); // replace `number` with `#` since it has been fully explored/validated
			}
			else if (c == ',') {
				if (isNum) stk.push('n'); // indicate this is a number instead of using the real number
				isNum = false;
			}
			else {
				isNum = true;
			}
		}

		return stk.size() == 1 && stk.top() == '#';
	}
};


//encounting '#' character twice, top of the stack value is last node.
//so the last node can be replace '#', because last node means end of tree.
//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/solutions/78605/simple-c-solution-using-stack-without-extra-splitting-function/