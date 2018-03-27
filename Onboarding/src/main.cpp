#include <iostream>
#include <limits>
#include <string>

using namespace std;

#ifdef __clang__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#endif
struct Enemy
{
    std::string name{""};
    int distance{std::numeric_limits<int>::min()};
};
#ifdef __clang__
#pragma GCC diagnostic pop
#endif

inline Enemy closestEnemy(const Enemy& firstEnemy, const Enemy& secondEnemy)
{
    return firstEnemy.distance < secondEnemy.distance ? firstEnemy : secondEnemy;
}

int main()
{
    Enemy myFirstEnemy, mySecondEnemy;
    while (1) {
        cin >> myFirstEnemy.name; cin.ignore();
        cin >> myFirstEnemy.distance; cin.ignore();
        cin >> mySecondEnemy.name; cin.ignore();
        cin >> mySecondEnemy.distance; cin.ignore();

        cout << closestEnemy(myFirstEnemy, mySecondEnemy).name << endl;
    }
}
