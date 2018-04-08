#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

struct Position
{
    double longitude;
    double latitude;
};

struct Defibrilator
{
    string locationName;
    Position position;
};

double distance(const Position& first_position, const Position& second_position)
{
    //@see distance definition
    const auto x = (second_position.longitude - first_position.longitude) * cos((first_position.latitude + second_position.latitude) / 2.0);
    const auto y = second_position.latitude - first_position.latitude;
    return sqrt(pow(x, 2.0) + pow(y, 2.0)) * 6371.0;
}

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    std::replace(LON.begin(), LON.end(), ',', '.');
    std::replace(LAT.begin(), LAT.end(), ',', '.');
    Position user {stod(LON), stod(LAT)};

    int N;
    cin >> N; cin.ignore();
    Defibrilator closest {"NONE", std::numeric_limits<double>::max(), std::numeric_limits<double>::max()};
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);

        vector<string> splited_DEFIB;
        stringstream ss_DEFIB(DEFIB);
        string token;
        while(getline(ss_DEFIB, token, ';')) { splited_DEFIB.push_back(token); }
        std::replace(splited_DEFIB[splited_DEFIB.size()-2].begin(), splited_DEFIB[splited_DEFIB.size()-2].end(), ',', '.');
        std::replace(splited_DEFIB[splited_DEFIB.size()-1].begin(), splited_DEFIB[splited_DEFIB.size()-1].end(), ',', '.');
        const auto& next_DEFIB = Defibrilator {splited_DEFIB[1], {stod(splited_DEFIB[splited_DEFIB.size()-2]), stod(splited_DEFIB[splited_DEFIB.size()-1])}};
        if(distance(user, closest.position) - distance(user, next_DEFIB.position) >= 0)
        {
            closest = next_DEFIB;
        }
    }
    cout << closest.locationName << endl;
}
