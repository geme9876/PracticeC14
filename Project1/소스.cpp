//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(string s) {
//    int answer = s.size();
//    for (int i = 1;i <= s.length()/2;++i)
//    {
//        int len = s.length();
//        int Compress = 0;
//        bool bCompress = true;
//        string cluster = s.substr(0, i);
//        for (int j = i;j <= s.length();j += i)
//        {
//            //���� ���� ����
//            if (cluster == s.substr(j, i))
//            {
//                if (bCompress)
//                {
//                    Compress++;
//                    bCompress = false;
//                }
//                
//                //���డ��
//                len -= i;
//            }
//            else
//            {
//                //����Ұ���
//                cluster = s.substr(j, i);
//                bCompress = true;
//            }
//        }
//        len += Compress;
//        if (len < answer)
//        {
//            answer = len;
//        }
//    }
//    return answer;
//}
//
//void main()
//{
//    string s = "aabbaccc";
//   
//
//    solution(s);
//    return;
//}