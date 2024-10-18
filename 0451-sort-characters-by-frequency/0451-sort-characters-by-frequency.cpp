class Solution {
public:
    string frequencySort(string s) {
        cout << s.size() << "\n";
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        for (auto i : mp) {
            pq.push({i.second, i.first});
        }
        string ans = "";
        while (!pq.empty()) {
            pair<int, char> atif = pq.top();
            pq.pop();
            // cout << atif.first << "->" << atif.second << "\n";
            ans.append(atif.first, atif.second);
            // ans.append(3, 'a');
            // append a 3 times
        }
        cout << ans;
        return ans;
    }
};