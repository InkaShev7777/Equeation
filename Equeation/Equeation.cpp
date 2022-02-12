#include <iostream>
#include<string>
using namespace std;
int main()
{
    string str;
	cout << "Enter equation: ";
	cin >> str;
    string::iterator it = str.begin();
	string a;
	string b;
	string oper;
	int res;
	int pos1, pos2;
	int k = 0;
	int e = 0;
	if (!str.empty())
	{
		while (it != str.end())
		{
			if (*it == '*' || *it == '/')
			{
				e = 0;
				oper = *it;
				while (it != str.begin() && *it != '+' || *it != '-')
				{
					it--;
					k++;
					if (it == str.begin()) break;
					if (*it == '*')break;
					if (*it == '+') break;
					if (*it == '-') break;
				}

				for (int i = 0; i < k; i++)
				{
					if (*it > 47 && *it < 58)
					{
						a += *it;
						if (e == 0)
						{
							pos1 = std::distance(str.begin(), it);
							e = 1;
						}
					}
					it++;
				}
				if (!a.empty())
				{
					while (it != str.end())
					{
						it++;
						if (it == str.end()) break;
						if (*it == '*')break;
						if (*it == '+') break;
						if (*it == '-') break;
						if (*it > 47 && *it < 58)
						{
							b += *it;
							pos2 = std::distance(str.begin(), it);
						}
					}
				}
				if (!a.empty() && !b.empty())
				{
					if (oper == "*")
					{
						res = atoi(a.c_str()) * atoi(b.c_str());
						std::cout << str << "\n";
						std::cout << "Res: " << res << "\n";
						str.replace(pos1, pos2 - pos1 + 1, std::to_string(res));
					}
					if (oper == "/")
					{
						if (a == "0" || b == "0")
						{
							std::cout << "Error!!!\n";
							return 0;
						}
						else
						{
							res = atoi(a.c_str()) / atoi(b.c_str());
							std::cout << str << "\n";
							std::cout << "Res: " << res << "\n";
							str.replace(pos1, pos2 - pos1 + 1, std::to_string(res));
						}
					}
					a.clear();
					b.clear();
					oper.clear();
					k = 0;
					pos1 = 0;
					pos2 = 0;
					it = str.begin();
				}
			}
			it++;
		}
		it = str.begin();
		while (it != str.end())
		{
			if (*it == '+' || *it == '-')
			{
				e = 0;
				oper = *it;
				while (it != str.begin() && *it != '+' || *it != '-')
				{
					it--;
					k++;
					if (it == str.begin()) break;
				}
				for (int i = 0; i < k; i++)
				{
					if (*it > 47 && *it < 58)
					{
						a += *it;
						if (e == 0)
						{
							pos1 = std::distance(str.begin(), it);
							e = 1;
						}
					}
					it++;
				}
				if (!a.empty())
				{
					while (it != str.end())
					{
						it++;
						if (it == str.end()) break;
						if (*it == '*')break;
						if (*it == '+') break;
						if (*it == '-') break;
						if (*it > 47 && *it < 58)
						{
							b += *it;
							pos2 = std::distance(str.begin(), it);
						}
					}
				}
				if (!a.empty() && !b.empty())
				{
					std::cout << str << "\n";
					if (oper == "+")
					{
						res = atoi(a.c_str()) + atoi(b.c_str());
						str.replace(pos1, pos2 - pos1 + 1, std::to_string(res));
						std::cout << "Res: " << res << "\n";
					}
					if (oper == "-")
					{
						res = atoi(a.c_str()) - atoi(b.c_str());
						str.replace(pos1, pos2 - pos1 + 1, std::to_string(res));
						std::cout << "Res: " << res << "\n";
					}
					a.clear();
					b.clear();
					oper.clear();
					k = 0;
					pos1 = 0;
					pos2 = 0;
					it = str.begin();
				}
			}
			it++;
		}
	}
	else
	{
		cout << "String is empty!!!\n\n";
	}
}

