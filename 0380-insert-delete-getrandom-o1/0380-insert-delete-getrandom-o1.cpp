class RandomizedSet {
    private: 

    vector<int>vt;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {} 
    
    bool insert(int val) {
       if(mp.find(val)!=mp.end()) return false;
        vt.push_back(val);
        mp[val] = vt.size()-1;
        return true;
    }
    
    bool remove(int val) {

        if(mp.find(val)==mp.end()) return false;

        int idx = mp[val];
        int element = vt.back();
        mp[element] = idx;
        vt[idx] = element;
        vt.back() = val;
        mp.erase(val);
        vt.pop_back();
        return true;
    }
    
    int getRandom() {
        int random_idx = (rand() % vt.size());
        return vt[random_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */