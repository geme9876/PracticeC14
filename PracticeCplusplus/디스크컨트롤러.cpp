//#include <string>
//#include <vector>
//#include <queue>
//using namespace std;
//
//
//struct cmp
//{
//    bool operator()(vector<int> left, vector<int> right)
//    {
//        return left[1]> right[1];
//    }
//};
//
//int solution(vector<vector<int>> jobs) {
//    int answer = 0;
//    priority_queue<vector<int>, vector<vector<int>>, cmp> jobqueue;
//    int tick = 0;
//    int unfinishjob = jobs.size();
//    bool IsProcessing = false;
//    int JobTimer = 0;
//    int JobStartTime = 0;
//
//    vector<int> currentJob;
//    while (unfinishjob)
//    {
//        for (int i = 0;i < jobs.size();i++)
//        {
//            if (jobs[i][0] == tick)
//            {
//                jobqueue.push(jobs[i]);
//            }
//        }
//
//        if (IsProcessing && JobTimer == 0)
//        {
//            unfinishjob--;
//            IsProcessing = false;
//            answer += JobStartTime - currentJob[0] + currentJob[1];
//        }
//        if (!IsProcessing && !jobqueue.empty())
//        {
//            currentJob = jobqueue.top();
//            JobStartTime = tick;
//            JobTimer = currentJob[1];
//            jobqueue.pop();
//            IsProcessing = true;
//        }
//        
//        JobTimer--;
//        tick++;
//    }
//
//
//    return answer/jobs.size();
//}
//int main()
//{
//    vector<vector<int>> jobs{ {0,3},{1,9},{2,6} };
//
//    solution(jobs);
//    return 0;
//}