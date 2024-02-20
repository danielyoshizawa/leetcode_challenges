class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lower_price{std::numeric_limits<int>::max()};
        int higher_price{0};
        int bigger_diff{0};

        for (const int& p : prices)
        {
            // Check lower
            if (p < lower_price)
            {
                lower_price = p;
                higher_price = p; // Can't use past values
            }
            // Check higher
            higher_price = std::max(p,higher_price);
            // Calc diff
            bigger_diff = std::max(bigger_diff, (higher_price - lower_price));
        }

        return bigger_diff;
    }
};