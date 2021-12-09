// Time Complexity : O(N*logN)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int& n : nums) m[n]++;

        vector<pair<int, int>> v;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            v.push_back({ it->first, it->second });

        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
            });

        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(v[i].first);
        return result;
    }
};