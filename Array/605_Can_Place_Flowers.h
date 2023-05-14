class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        for (int i = 0; i < flowerbed.size() &&  0 != n; i++)
        {
            if (0 != flowerbed[i])
                continue;

            if (0 < i && 0 != flowerbed[i - 1])
                continue;
            
            if (i < flowerbed.size() - 1 && 0 != flowerbed[i + 1])
                continue;

            flowerbed[i] = 1;

            n--;
        }

        return 0 == n;

    }
};