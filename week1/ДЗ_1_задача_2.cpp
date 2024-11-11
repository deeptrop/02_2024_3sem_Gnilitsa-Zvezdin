#include <bits/stdc++.h>

using namespace std;

map<char, pair<double, double>> conv;

double convert(char from, char to, double num) {
    num = (num - conv[from].second) / conv[from].first;
    num = num * conv[to].first + conv[to].second;
    return num;
}

int main() {
    // To convert from Celsius: A * x + b
    conv['C'] = {1, 0};
    conv['F'] = {1.8, 32};
    conv['K'] = {1, 273.15};
    
    cout << "Hi! This is temperature converter!\n";
    cout << "I can work with: ";
    for (auto x : conv) cout << x.first << ' ';
    cout << "\nPlease enter your data in the format: original measurement system, target measurement system, and the value to convert.\n";
    
    char from, to;
    double num;
    cin >> from >> to >> num;
    if (!conv.contains(from) || !conv.contains(to)) {
        cout << "Invalid format!\n";
        return 0;
    }
    cout << "Here is you temperature in " << to << ": " << convert(from, to, num) << '\n';
}
