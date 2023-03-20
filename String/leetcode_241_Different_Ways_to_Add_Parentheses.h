class Solution {

	/* if this type is unordered_map, occur complie error.
	std::map 컨테이너는 std::pair<int, int> 타입을 key로 사용할 때 기본 생성자가 없어도 오류가 발생하지 않습니다. 
	그 이유는 std::map은 레드-블랙 트리(Red-Black Tree) 자료구조를 사용하여 요소를 저장하기 때문입니다.
	레드-블랙 트리는 노드의 삽입과 삭제를 할 때, 트리의 균형을 유지하기 위해 회전 연산을 수행합니다. 
	따라서 노드의 삽입과 삭제는 항상 부모 노드와 자식 노드 간의 포인터 조작만으로 이루어지며, 키 타입의 기본 생성자를 호출할 필요가 없습니다.
	반면에 std::unordered_map은 해시 테이블(Hash Table) 자료구조를 사용하여 요소를 저장합니다. 
	해시 테이블은 키 값의 해시 함수를 사용하여 요소의 위치를 계산하는데, 
	std::pair<int, int>와 같은 사용자 정의 타입의 경우 해시 함수가 제대로 구현되어 있지 않으면 컴파일 오류가 발생합니다. 
	따라서 std::unordered_map은 키 타입에 대한 기본 생성자를 반드시 필요로 합니다.
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