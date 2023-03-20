class Solution {

	/* if this type is unordered_map, occur complie error.
	std::map �����̳ʴ� std::pair<int, int> Ÿ���� key�� ����� �� �⺻ �����ڰ� ��� ������ �߻����� �ʽ��ϴ�. 
	�� ������ std::map�� ����-�� Ʈ��(Red-Black Tree) �ڷᱸ���� ����Ͽ� ��Ҹ� �����ϱ� �����Դϴ�.
	����-�� Ʈ���� ����� ���԰� ������ �� ��, Ʈ���� ������ �����ϱ� ���� ȸ�� ������ �����մϴ�. 
	���� ����� ���԰� ������ �׻� �θ� ���� �ڽ� ��� ���� ������ ���۸����� �̷������, Ű Ÿ���� �⺻ �����ڸ� ȣ���� �ʿ䰡 �����ϴ�.
	�ݸ鿡 std::unordered_map�� �ؽ� ���̺�(Hash Table) �ڷᱸ���� ����Ͽ� ��Ҹ� �����մϴ�. 
	�ؽ� ���̺��� Ű ���� �ؽ� �Լ��� ����Ͽ� ����� ��ġ�� ����ϴµ�, 
	std::pair<int, int>�� ���� ����� ���� Ÿ���� ��� �ؽ� �Լ��� ����� �����Ǿ� ���� ������ ������ ������ �߻��մϴ�. 
	���� std::unordered_map�� Ű Ÿ�Կ� ���� �⺻ �����ڸ� �ݵ�� �ʿ�� �մϴ�.
	*/
	std::map<std::pair<int, int>, std::vector<int>> memo;

	std::vector<int> calc(string& expression, int begin, int end)
	{
		auto findIt= memo.find(std::pair<int, int> {begin, end});

		if (memo.end() != findIt)
		{
			return findIt->second;
		}

		std::vector<int> results;

		string s;
		for (int i = begin; i < end; i++)
		{
			char c = expression[i];
			if ('+' == c || '-' == c || '*' == c)
			{
				auto lList = calc(expression, begin, i);
				auto rList = calc(expression, i + 1, end);

				for (auto l : lList)
				{
					for (auto r : rList)
					{
						if ('+' == c)
						{
							results.push_back(l + r);
						}
						else if ('-' == c)
						{
							results.push_back(l - r);
						}
						else
						{
							results.push_back(l * r);
						}
					}
				}			
			}
			else
			{
				s.push_back(c);
			}
		}

		if (results.empty())
		{
			results.push_back(stoi(s.c_str()));
		}

		memo.emplace(std::pair<int, int> { begin, end }, results);

		return results;
	}


public:
	vector<int> diffWaysToCompute(string expression) {

		return calc(expression, 0, expression.size());

	}
};


//https://leetcode.com/problems/different-ways-to-add-parentheses/solutions/66331/c-4ms-recursive-dp-solution-with-brief-explanation/?orderBy=most_votes