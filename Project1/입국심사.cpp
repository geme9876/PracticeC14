#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    priority_queue<int> pq;

    for (int i = 0;i < times.size();i++)
    {
        pq.push(times[i]);
    }
    int tick= 0 ;
    while (n)
    {
        for (int i = 0;i < times.size();i++)
        {
            if (times[i] <= tick)
            {
                pq.push(times[i]);
            }
        }
        while (!pq.empty())
        {
            n--;
        }
        tick++;
    }
    return tick;
}

int main()
{
    int ans = solution(6, { 7,10 });

    return 0;
}

