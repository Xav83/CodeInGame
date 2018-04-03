#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    auto N{5};
    cin >> N; cin.ignore();
    std::vector<int> strengths(N);
    cout << N << "==" << strengths.size() << endl;
    for (auto& strenght : strengths)
    {
        cin >> strenght; cin.ignore();
        cout << "Strengh " << strenght << endl;
    }
    
    std::sort(strengths.begin(), strengths.end());
    auto min = strengths.back();
    for(auto i=size_t{0}; i<strengths.size()-1; ++i)
    {
        const auto diff = std::abs(strengths[i+1] - strengths[i]);
        if(min > diff)
        {
            min = diff;
        }
    }
    cout << min << endl;
    return 0;
}
