#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, discriminant, x1, x2;

    cout << "A: ";
    cin >> a;

    cout << "B: ";
    cin >> b;

    cout << "C: ";
    cin >> c;

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << (round(x1) == 0 ? 0 : round(x1)) << (round(x2) == 0 ? 0 : round(x2)) << endl;
    } else if (discriminant == 0) {
        x1 = -b / (2 * a);
        cout << (round(x1) == 0 ? 0 : round(x1)) << endl;
    } else {
        cout << "-" << endl;
    }

    return 0;
}
