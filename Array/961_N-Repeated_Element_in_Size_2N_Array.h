class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        std::unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            if (s.count(nums[i]))
            {
                return nums[i];
            }

            s.insert(nums[i]);            
        }


        return 0;
    }
};

//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/solutions/208563/java-c-python-o-1-solution/
class Solution {
public:
    //Only one number is repeated, so the other number appears only one out of two times.
    int repeatedNTimes(vector<int>& A) {
        for (auto i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2]) return A[i];
        return A[A.size() - 1];
    }
};


