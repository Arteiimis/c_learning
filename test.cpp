#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int len = numbers.size();
        vector<int> res;
        if (!len) return res;
        unordered_map<int, int> map;

        for (int i = 0; i < len; i++)
        {
            if(map.find(target - numbers[i]) != map.end())
            {
                res.push_back(map[target - numbers[i]] + 1);
                res.push_back(i + 1);
                break;
            }
            else
            {
                map[numbers[i]] = i;
            }
        }

        return res;
    }
};