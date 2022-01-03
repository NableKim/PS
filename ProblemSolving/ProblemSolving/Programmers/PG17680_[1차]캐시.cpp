#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

string getLowerStr(string str) {

    string tmp = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            tmp += ('a' + (str[i] - 'A'));
        else
            tmp += str[i];
    }

    return tmp;
}

string getOldestCity() {
    int minVal = 987654321;
    string oldCity = "";
    unordered_map<string, int>::iterator it;
    for (it = um.begin(); it != um.end(); it++) {
        if (minVal > it->second) {
            oldCity = it->first;
            minVal = it->second;
        }
    }
    return oldCity;
}

int solution(int cacheSize, vector<string> cities) {

    int timeCpx = 0;
    for (int i = 0; i < cities.size(); i++) { // O(½Ê¸¸)

        string city = getLowerStr(cities[i]); // O(20)

        if (um.find(city)!=um.end()) {
            timeCpx += 1;
            um[city] = i + 1;
        } 
        else {
            timeCpx += 5;
            if (cacheSize == 0) continue;
            if (um.size() == cacheSize) {
                string oldCity = getOldestCity(); // O(30)
                um.erase(oldCity);
            }   
            um[city] = i + 1;
        }
    }

    return timeCpx;
}

int main() {

    int cacheSize = 3;
    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    cout << solution(cacheSize, cities);

    return 0;
}