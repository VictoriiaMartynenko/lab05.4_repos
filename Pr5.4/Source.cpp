#include <iostream>
#include <cmath>
using namespace std;


double S0(const int N) {
    double s = 0;
    for (int i = 1; i <= N; i++) {
        s += cos(sin(i)) / (1 + pow(sin(i), 2));
    }
    return s;
}


double S1(const int i, const int N) {
    if (i > N)
        return 0;
    else
        return cos(sin(i)) / (1 + pow(sin(i), 2)) + S1(i + 1, N);
}

double S2(const int i, const int N) {
    if (i < 1)
        return 0;
    else
        return cos(sin(i)) / (1 + pow(sin(i), 2)) + S2(i - 1, N);
}

double S3(const int i, const int N, double t) {
    t += cos(sin(i)) / (1 + pow(sin(i), 2));
    if (i >= N)
        return t;
    else
        return S3(i + 1, N, t);
}

double S4(const int i, const int N, double t) {
    t += cos(sin(i)) / (1 + pow(sin(i), 2));
    if (i <= 1)
        return t;
    else
        return S4(i - 1, N, t);
}

int main() {
    int N;
    cout << "N = ";
    cin >> N;

    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(1, N) << endl;
    cout << "(rec down --) S2 = " << S2(N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(1, N, 0) << endl;
    cout << "(rec down --) S4 = " << S4(N, N, 0) << endl;

    return 0;
}
