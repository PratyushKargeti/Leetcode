class RandomizedSet {
public:
    unordered_set<int>s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it=s.find(val);
        if(it!=s.end())
        {
            return false;
        }
        else
        {
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        auto it=s.find(val);
        if(it!=s.end())
        {
            s.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int getRandom() {
        //using rand() % s.size() wouldn't work as intended because unordered sets don't have a predictable order, we dont have direct index-based access to the elements.
        vector<int>v(s.begin(),s.end());
        // Generate a random index within the range of the vector
        int ind = rand() % v.size(); //ind-> 0 to v.size()-1
        // Return the element at the random index
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */