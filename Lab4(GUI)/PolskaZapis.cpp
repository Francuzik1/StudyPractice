#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <math.h>
#include <map>
#include <stdexcept>
#include <windows.h>
#include "PolskaZapis.h"
using namespace std;


char number[11] = { '0','1','2','3','4','5','6','7','8','9','.' };
bool can_solve;

bool find_digit(char s)//поиск чисел
{
	int i;
	bool ok;
	i = 0;
	ok = true;
	while (i < 11 && ok)
	{
		if (s == number[i])
			ok = false;
		i = i + 1;
	}
	if (ok == false)
		return true;
	else
		return false;
}

char useless_symbol[7] = { ',','!','?','=','.','\\' };
bool find_useless(char s)//поиск разделитей
{
	int i;
	bool ok;
	i = 0;
	ok = true;
	while (i < 6 && ok)
	{
		if (s == useless_symbol[i])
			ok = false;
		i = i + 1;
	}
	if (ok == false)
		return true;
	else
		return false;
}

bool isopen(char s)
{
	if (s == '(' || s == '{' || s == '[')
		return true;
	else
		return false;
}
bool isclosed(char s)
{
	if (s == ')' || s == '}' || s == ']')
		return true;
	else
		return false;
}
bool isoperator(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '$')
		return true;
	else
		return false;
}

stack <char> stack1;
bool check(string s)
{
	bool correct = true;
	int cnter;
	cnter = 0;
	while (cnter < s.size() && correct)
	{
		if (s[cnter] == '(')
			stack1.push('(');
		else if (s[cnter] == '[')
			stack1.push('[');
		else if (s[cnter] == '{')
			stack1.push('{');
		else if (s[cnter] == ')')
		{
			if (!stack1.empty())
			{
				if (stack1.top() != '(')
					correct = false;
				stack1.pop();
			}
			else
				correct = false;
		}
		else if (s[cnter] == '}')
		{
			if (!stack1.empty())
			{
				if (stack1.top() != '{')
					correct = false;
				stack1.pop();
			}
			else
				correct = false;
		}
		else if (s[cnter] == ']')
		{
			if (!stack1.empty())
			{
				if (stack1.top() != '[')
					correct = false;
				stack1.pop();
			}
			else
				correct = false;
		}
		cnter = cnter + 1;

	}
	if (!stack1.empty())
		correct = false;
	while(!stack1.empty())
 		stack1.pop();
	return correct;
}
string transform(string s)
{
	string string_result;
	bool ok;
	string num;
	int i;
	i = 0;
	ok = false;
	can_solve = true;
	num.clear();

	while (i < s.size())
	{

		if ((find_digit(s[i]) || isalpha(s[i])) && !ok)
		{
			ok = true;
			num = s[i];
		}
		else if ((find_digit(s[i]) || isalpha(s[i])) && ok)
		{
			num = num + s[i];
		}
		else if (ok && !find_digit(s[i]) && !isalpha(s[i]))
		{
			ok = false;
			string_result = string_result + num + ' ';
			num.clear();
		}

		if (s[i] == '+' || s[i] == '-')
		{

			if (isopen(s[i - 1])) {
				if (s[i] == '-') {
					while (stack1.top() == '$')
					{
						string_result = string_result + stack1.top() + ' ';
						stack1.pop();
					}
					stack1.push('$');
				}
			}
			else {
				while (stack1.top() == '+' || stack1.top() == '-' || stack1.top() == '*' || stack1.top() == '/' || stack1.top() == '^' || stack1.top() == '$')
				{
					string_result = string_result + stack1.top() + ' ';
					stack1.pop();
				}
				stack1.push(s[i]);
			}
		}
		if (s[i] == '*' || s[i] == '/')
		{
			while (stack1.top() == '*' || stack1.top() == '/' || stack1.top() == '^' || stack1.top() == '$')
			{
				string_result = string_result + stack1.top() + ' ';
				stack1.pop();
			}
			stack1.push(s[i]);
		}

		if (s[i] == '^')
		{
			while (stack1.top() == '$')
			{
				string_result = string_result + stack1.top() + ' ';
				stack1.pop();
			}
			stack1.push(s[i]);
		}

		if (s[i] == '(')
			stack1.push('(');
		else if (s[i] == '[')
			stack1.push('[');
		else if (s[i] == '{')
			stack1.push('{');
		if (s[i] == ')')
		{
			while (stack1.top() != '(' && can_solve)
			{
				string_result = string_result + stack1.top() + ' ';
				stack1.pop();
				if (stack1.empty())
				{
					can_solve = false;
					cout << "Ошибка! " << endl;
				}
			}
			if (stack1.top() == '(')
				stack1.pop();
		}
		if (s[i] == ']' && can_solve)
		{
			while (stack1.top() != '[')
			{
				string_result = string_result + stack1.top() + ' ';
				stack1.pop();
				if (stack1.empty())
				{
					can_solve = false;
					cout << "Ошибка! " << endl;
				}
			}
			if (stack1.top() == '[')
				stack1.pop();
		}
		if (s[i] == '}' && can_solve)
		{
			while (stack1.top() != '{')
			{
				string_result = string_result + stack1.top() + ' ';
				stack1.pop();
				if (stack1.empty())
				{
					can_solve = false;
					cout << "Ошибка! " << endl;
				}
			}
			if (stack1.top() == '{')
				stack1.pop();
		}
		i = i + 1;

	}
	if (ok)
		string_result = string_result + num + ' ';

	while (!stack1.empty())
	{
		string_result = string_result + stack1.top() + ' ';
		stack1.pop();
	}
	return string_result;
}

bool search_math_errors_open(string s)
{
	int i;
	bool ok = true;
	i = 0;
	while (i < s.size() - 1 && ok)
	{
		if ((s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '^') && isopen(s[i]))
			ok = false;
		i = i + 1;
	}

	return ok;
}
bool search_math_errors_closed(string s)
{
	int i;
	bool ok = true;
	i = 0;
	while (i < s.size() - 1 && ok)
	{
		if (isoperator(s[i]) && isclosed(s[i + 1]))
			ok = false;
		i = i + 1;
	}

	return ok;
}
bool no_operator(string s) {
	int i;
	bool ok = false;
	i = 0;
	while (i < s.size() - 1 && !ok)
	{
		if ((isalpha(s[i]) || find_digit(s[i])) && isopen(s[i + 1]))
			ok = true;
		if ((isalpha(s[i + 1]) || find_digit(s[i + 1])) && isclosed(s[i]))
			ok = true;
		i = i + 1;
	}

	return ok;
}

string clear_string(string s)
{
	int i = 0;
	s = s + '=';
	string x;
	while (i < s.size())
	{
		if (!find_useless(s[i]) || (s[i] == '.' && s[i + 1] != '.'))x = x + s[i];

		i = i + 1;
	}
	return x;
}
stack<double> a;
int what(string s)
{
	int ret_value = 0;
	if (isoperator(s[0]))ret_value = -1;
	else
	{
		int i = 0;
		while (i < s.size())
		{
			if (!find_digit(s[i]))ret_value = 1;
			i = i + 1;
		}
	}
	return ret_value;

	return ret_value;
}
map <string, double> words;
double solve(string s)
{
	while (!a.empty())
		a.pop();
	double q;
	string x;
	double first, second;
	stringstream in(s);
	int check = what(x);
	while (in >> x) {
		int check = what(x);
		if (check == 0)
		{
			stringstream getnum(x);
			getnum >> q;
			a.push(q);
		}
		else if (check == 1)
		{

			if (words[x] == 0) {
				cout << "Введите, пожалуйста, значение " << x << ": ";
				cin >> q;
				a.push(q);
				words[x] = q;
			}
			else
				a.push(words[x]);
		}
		else {
			if (x == "$") { first = a.top(); a.pop(); a.push(first * (-1)); }
			else {
				second = a.top();
				a.pop();
				first = a.top();
				a.pop();
				if (x == "+")a.push(first + second);
				if (x == "-")a.push(first - second);
				if (x == "*")a.push(first * second);
				if (x == "/")a.push(first / second);
				if (x == "^")a.push(pow(first, second));
			}
		}

	}

	return a.top();
}
bool two_operators(string s) {
	int i = 0;
	bool ok = false;
	while (i < s.size() - 1)
	{
		if (isoperator(s[i]) && isoperator(s[i + 1]))
			ok = true;
		i = i + 1;
	}
	return ok;
}
string getPolskaZapis(string string_first)
{
    string string_final;
	string_first = clear_string(string_first);
	try {
		if (string_first.empty())throw logic_error("Вы не ввели выражение! Проверьте, пожалуйста, файл input.txt в папке с программой!");
		else {
			string_first = '(' + string_first + ')';

			cout << "Введенное выражение: " << string_first << endl;
			//getline(get_string, string_first);
			int cnter = 0;
			if (!check(string_first))
				throw logic_error("Неправильный баланс скобок!");
			else
				string_first = '(' + string_first + ')'; if (!search_math_errors_closed(string_first))
			{
				throw logic_error("Нельзя ставить закрывающую скобку после знака операции!");
			}
				else if (!search_math_errors_open(string_first))
			{
				throw logic_error("После открывающей скобки стоит некорректный знак операции!");
			}
				else if (two_operators(string_first))
			{
				throw logic_error("Два оператора стоят рядом, расставьте, пожалуйста, скобки!");
			}
				else if (no_operator(string_first))
			{
				throw logic_error("Вы не поставили знак операции между скобкой и числом!");
			}
				else
			{
				string_final = transform(string_first);
				if (can_solve)
				{

					if (string_final.empty())throw logic_error("Вы не ввели ни одного операнда!");
					else {
						cout << "Введенное Вами выражение, переведенное в обратную польскую запись:" << endl;
						cout << string_final << endl;
                        return string_final;
					}
				}
			}
		}
	}
	catch (logic_error& a)
	{
        return "error";
	}
    return "error";
}




