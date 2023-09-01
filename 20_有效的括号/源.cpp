#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool istrue(string str)
{
	int n = str.size();
	if (n % 2 == 1)
		return false;

	stack<char> stk;
	
	unordered_map<char, char>  pairs =
	{
		{')', '('},
		{']', '['},
		{'}', '{'}
	};

	for (char ch : str)
	{
		if (pairs.count(ch)) //���ذ����ļ�ֵ���������˴�0Ϊ�����ţ�1Ϊ������
		{
			if (stk.empty() || stk.top() != pairs[ch])//�������ж�������������Ƿ�Ϊͬ��
				return false;
			stk.pop();
		}
		else
			stk.push(ch); //������ѹ��ջ
	}
	return stk.empty();
}

int main()
{
	string str;
	cin >> str;
	if (istrue(str))
		cout << "True";
	else
		cout << "False";
	return 0;
}