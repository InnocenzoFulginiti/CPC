#include <climits>
#include <cstdlib>
#include <iostream>

#define N 3

using namespace std;

int quadratic_solution(int h[]) {
    int a[N];
    int res = 0;

    for (int i = 0; i < N; i++) {
        int max_left = 0;
        int max_right = 0;

        for (int j = 0; j < i; j++) {
            if (h[j] > max_left) max_left = h[j];
        }

        for (int j = i + 1; j < N; j++) {
            if (h[j] > max_right) max_right = h[j];
        }

        a[i] = max_left < max_right ? max_left - h[i] : max_right - h[i];

        if (a[i] < 0) a[i] = 0;

        res += a[i]; 
    }

    return res;
}

int linear_solution(int h[]) {
    int a[N];
    int res = 0;

    int ll[N], rl[N];
    
    ll[0] = h[0];
    for (int i = 1; i < N; i++) {
        ll[i] = h[i] > ll[i - 1] ? h[i] : ll[i - 1];
    }

    rl[N - 1] = h[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        rl[i] = h[i] > rl[i + 1] ? h[i] : rl[i + 1];
    }

    for (int i = 0; i < N; i++) {
        a[i] = ll[i] < rl[i] ? ll[i] - h[i] : rl[i] - h[i];
        
        if (a[i] < 0) a[i] = 0;

        res += a[i]; 
    }

    return res;
}

int main(int argc, char **argv) {
    int h[N];

    for (int i = 0; i < N; i++) {
        cin >> h[i];

        if (h[i] < 0) {
            return -1;
        }
    }

    cout << "Res (quadratic) = " << quadratic_solution(h) << endl;
    cout << "Res (linear) = " << linear_solution(h) << endl;

    return 0;
}