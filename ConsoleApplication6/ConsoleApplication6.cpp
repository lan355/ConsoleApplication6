#include <string>
#include <map>
#include <stack>
#include<windows.h>
#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string stroct;
	cout << "Введите строку:" << "\n";
	cin >> stroct;
	map<char, char> mp{ { '(', ')' }, { '[', ']' }, { '{', '}'} };
	stack<char> stack;
	int i = 0;
	for (i = 0; i < stroct.size(); ++i)
	{
		if ('(' == stroct[i] || '[' == stroct[i] || '{' == stroct[i])
		{
			stack.push(stroct[i]);
		}
		else if (!stack.empty())
		{
			char c = stack.top();
			stack.pop();
			if (mp[c] != stroct[i])
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	cout << (i == stroct.size() && stack.empty() ? "Right" : "Wrong") << "\n";

	system("pause");
	return 0;
}