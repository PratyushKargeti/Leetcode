class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
	    for(int a : asteroids) {
		    bool destroyed = false;
		    while(res.size() && res.back() > 0 && a < 0 && !destroyed) {
			    if(abs(res.back()) >= abs(a)) destroyed = true;
			    if(abs(res.back()) <= abs(a)) res.pop_back();
		    }
		    if(destroyed==false) res.push_back(a);
	    }
	    return res;
    }
};