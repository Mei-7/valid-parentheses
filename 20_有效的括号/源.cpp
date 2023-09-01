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
		if (pairs.count(ch)) //返回包含的键值对数量，此处0为左括号，1为右括号
		{
			if (stk.empty() || stk.top() != pairs[ch])//右括号判断最近的左括号是否为同类
				return false;
			stk.pop();
		}
		else
			stk.push(ch); //左括号压入栈
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