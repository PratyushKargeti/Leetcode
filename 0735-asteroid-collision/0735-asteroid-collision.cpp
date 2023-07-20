class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
	    for(int a : asteroids) {
		    bool destroyed = false;
		    while(res.size() && res.back() > 0 && a < 0 && !destroyed) {
			    if(abs(res.back()) >= abs(a)) destroyed = true;
			    if(abs(res.back()) <= abs(a)) res.pop_back();
                //NOTE HERE TWO IFS ARE BACK TO BACK FOR HANDING abs(res.back())==abs(a) case
                //then current asteroid 'a' will be destroyed(will note be added) and last
                //element of res will also be destroyed,i.e, both will be destroyed
		    }
		    if(destroyed==false) res.push_back(a);
	    }
	    return res;
    }
};