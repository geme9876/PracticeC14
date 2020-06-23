#include <iostream>
#include <string>
using namespace std;

int BinToDec(const string& bin)
{
	int dec = 0;
	int pos = 0;
	for (int i = bin.length()- 1;i >= 0;i--)
	{
		if (bin[i] == '1')
			dec += 1 << pos;
		pos++;
	}
	//dec = stoi(bin, nullptr, 2);
	return dec;
}

string BinToHex(const string& bin)
{
	string answer;
	int i = 0;

	while (i < bin.length())
	{
		int CutOff = (bin.length()-i) % 4 ? (bin.length()-i) % 4 : 4;
		int dec= stoi(bin.substr(i, CutOff), nullptr, 2);
		if (dec < 10)
		{
			answer += dec + 48;
		}
		else
		{
			answer += dec + 55;
		}
		i = i + CutOff;
	}
	return answer;
}

string DecToBin(int dec)
{
	string answer;

	int div=dec;
	do
	{
		if (div % 2)
			answer += '1';
		else
			answer += '0';
		div = div / 2;
	} while (div);

	for (int i = 0;i < answer.length() / 2;i++)
	{
		char temp = answer[i];
		answer[i] = answer[answer.length() - (1 + i)];
		answer[answer.length() - (1 + i)] = temp;
	}
	return answer;

}
string DecToHex(int dec)
{
	string answer;
	int div = dec;
	do
	{
		int rest = div % 16;
		if (rest<10)
			answer += rest + 48;
		else
			answer += rest + 55;
		div = div / 16;
	} while (div);

	for (int i = 0;i < answer.length() / 2;i++)
	{
		char temp = answer[i];
		answer[i] = answer[answer.length() - (1 + i)];
		answer[answer.length() - (1 + i)] = temp;
	}

	
	return answer;
}

int HexToDec(string hex)
{
	int answer = 0;
	answer = stoi(hex, nullptr, 16);
	return answer;
}

string HexToBin(string hex)
{
	string answer;
	answer = DecToBin(HexToDec(hex));
	return answer;
}


int main()
{
	string bin = "111110000111110000";

	cout << "BinToDec :" << BinToDec(bin) << endl;
	cout << "BinToHex :" << BinToHex(bin) << endl;
	cout << " DecToBin :" << DecToBin(BinToDec(bin)) << endl;
	cout << " DecToHex :" << DecToHex(BinToDec(bin)) << endl;
	cout << " HexToBin :" << HexToBin(BinToHex(bin)) << endl;
	cout << " HexToDec :" << HexToDec(BinToHex(bin)) << endl;



	return 0;
}