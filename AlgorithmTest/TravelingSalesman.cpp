
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

const static int INF = 987654321;
int n;
int map[16][16];
int memo[16][1 << 16];

int tsp(int currentCity, int visited) {
    int& ret = memo[currentCity][visited];
    if (ret != -1) return ret;

    // base case : ��� ���ø� �� �湮�� == ��� ���ð� 1��.
    if (visited == (1 << n) - 1) {
        // 0��° ���÷� �ٽ� ���ư�. (����Ŭ)
        if (map[currentCity][0] != 0) return map[currentCity][0];
        else return INF;
    }

    ret = INF;
    for (int i = 0; i < n; i++) {
        // ���� ���� �ְ� �湮�� �� ������ ����
        if (map[currentCity][i] && !(visited & (1 << i))) {
            int visit = visited | (1 << i); // ����
            ret = __min(ret, tsp(i, visit) + map[currentCity][i]);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    memset(memo, -1, sizeof(memo));
    cout << tsp(0, 1) << '\n';

    return 0;
}

