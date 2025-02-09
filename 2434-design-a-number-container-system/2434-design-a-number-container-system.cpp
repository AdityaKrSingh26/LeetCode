class NumberContainers {
public:
    unordered_map<int, int> mp;
    // store the number and its indices in increasing order as set
    map<int, set<int>> numToIndices;
    NumberContainers() {}

    void change(int index, int number) {
        // index already has a number
        if(mp.find(index) != mp.end()){
            int old = mp[index];
            numToIndices[old].erase(index);
            // remove the number map if no index left
            if (numToIndices[old].empty()) {
                numToIndices.erase(old);
            }
        }

        mp[index]= number;
        numToIndices[number].insert(index);
    }

    int find(int number) {
        if(numToIndices[number].empty() || numToIndices.find(number) == numToIndices.end())
            return -1;
        return *numToIndices[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */