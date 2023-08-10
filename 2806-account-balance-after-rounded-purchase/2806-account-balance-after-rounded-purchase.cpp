class Solution {
public:
    int accountBalanceAfterPurchase(int pa) {
        if(pa==0) return 100;
        if(pa%10==5) return 100-(pa+5);
        else if(pa%10>5) return 100-(pa+(10-(pa%10)));
        else return 100-(pa-(pa%10));
        
    }
};