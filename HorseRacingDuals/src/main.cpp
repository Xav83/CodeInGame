#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    auto N{5};
    std::cin >> N; std::cin.ignore();
    std::vector<int> strengths(N);
    for (auto& strenght : strengths)
    {
        std::cin >> strenght; std::cin.ignore();
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
    std::cout << min << std::endl;
    return 0;
}
