#pragma once
#include <vector>

//���� 2293 DP 
/*
����
n���� ������ ������ �ִ�.������ ������ ��Ÿ���� ��ġ�� �ٸ���.�� ������ ������ ����ؼ�,
�� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�.�� ����� ���� ���Ͻÿ�.������ ������ �� ���� ����� �� �ִ�.

����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10, 000)
���� n���� �ٿ��� ������ ������ ��ġ�� �־�����.������ ��ġ�� 100, 000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ����� ���� ����Ѵ�.����� ���� 2^31���� �۴�.
*/

namespace Coin1
{
	int Solution(int iNumCoin, int TargetNum, std::vector<int> CoinValues)
	{
		int answer = 0 ;
		std::vector<int> memo;
		memo.resize(TargetNum + 1);
		memo[0] = 1;
		for (int i = 1; i <= iNumCoin; i++ )
		{
			for (int j=1; j<=TargetNum; j++)
			{
				if (j >= CoinValues[i])
				{
					memo[j] += memo[(j - CoinValues[i])];
				}

			}
		}
		answer = memo[TargetNum];
		return answer;
	}
}