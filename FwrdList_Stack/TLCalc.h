#pragma once
#include<iostream>
#include<string>
#include "TLStack.h"


class TLCalc
{
private:
	std::string infix;                           
	std::string postfix;                          

	TLStack<char> C = TLStack<char>();      
	TLStack<double> D = TLStack<double>(); 

	int priority(char op) {
		switch (op)
		{
		case '+':
			return 1;
		case '-':
			return 1;
		case '/':
			return 2;
		case '*':
			return 2;
		case '^':
			return 3;
		case '(':
			return 0;
		case ')':
			return 0;
		default:
			break;
		}
	}; 
	void ToPostfix() {
		C.ClearStack();
		std::string str = '(' + infix + ')';

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				C.Push('(');
			}

			if ((str[i] >= '0') && (str[i] <= '9'))
			{
				postfix += str[i];
			}

			if (str[i] == ')')
			{
				char OperationEl = C.Pop();
				while (OperationEl != '(')
				{
					postfix += OperationEl;
					OperationEl = C.Pop();
				}
			}

			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
			{
				char OperationEl = C.Pop();
				while (priority(OperationEl) >= priority(str[i]))
				{
					postfix += OperationEl;
					OperationEl = C.Pop();
				}
				C.Push(OperationEl);
				C.Push(str[i]);
			}
		}
	}; 

public:
	std::string GetInfix() { return infix; }                   
	std::string GetPostfix() { return postfix; }               
	void SetInfix(std::string _infix) { infix = _infix; }      

	TLCalc(std::string _infix) :infix(_infix) { this->ToPostfix(); } 
	bool CheckExpression()
	{
		
		if (C.empty() == false)
		{
			this->C.ClearStack();
		}
		int res = 0;
		for (int i = 0; i < infix.size(); i++)
		{
			if (infix[i] == '(')
			{
				C.Push(infix[i]);
			}
			if (infix[i] == ')')
			{
				if (!C.empty())
				{
					C.Pop();
				}
				else
					res = 1;
			}
		}
		if (!C.empty())
			res = 1;
		if (res == 0)
		{
			return true;
		}
		else
			return false;
	}
	double CalcPostfix() {
		//this->ToPostfix();
		D.ClearStack();

		for (int i = 0; i < postfix.length(); i++)
		{
			if ((postfix[i] >= '0') && (postfix[i] <= '9'))
			{
				D.Push(postfix[i] - '0');
			}

			if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^'))
			{
				double x1, x2, y;
				x1 = D.Pop(); x2 = D.Pop();
				switch (postfix[i])
				{
				case '+':
					y = x1 + x2;
					break;
				case '-':
					y = x2 - x1;
					break;
				case '*':
					y = x1 * x2;
					break;
				case '/':
					y = x1 / x2;
					break;
				case '^':
					y = pow(x1, x2);
					break;
				default:
					break;
				}
				D.Push(y);
			}
		}

		double result = D.Pop();
		if (!D.empty())
		{
			throw "В TStack::Calculate не пустой стек при возврате result";
		}
		return result;
	};  
	double Calc() {
		C.ClearStack(); D.ClearStack();
		std::string str = '(' + infix + ')';

		for (int i = 0; i < str.size(); i++)
		{
			int flag = 0;
			if (str[i] == '(')
			{   
				flag = 1;
				C.Push('(');
			}

			if (str[i] == ')')
			{
				flag = 1;
				if (C.empty())
				{
					throw "Stack Error";
				}
				char element = C.Pop();
				while (element != '(')
				{
					double x2 = D.Pop();
					double x1 = D.Pop();
					double y;
					switch (element)
					{
					case '+':
						y = x1 + x2;
						break;
					case '-':
						y = x1 - x2;
						break;
					case '*':
						y = x1 * x2;
						break;
					case '/':
						y = x1 / x2;
						break;
					case '^':
						y = pow(x1, x2);
						break;
					default:
						break;
					}
					D.Push(y);
					if (C.empty())
					{
						throw "Stack Error";
					}
					element = C.Pop();
				}
			}

			if ((str[i] >= '0') && (str[i] <= '9'))
			{
				flag = 1;
				size_t position;
				D.Push(std::stod(&str[i], &position));
				i += (position - 1);
			}

			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
			{
				flag = 1;
				if (C.empty())
				{
					throw "Stack Error";
				}
				char OperationEl = C.Pop();
				while (priority(OperationEl) >= priority(str[i]))
				{
					double x2 = D.Pop();
					double x1 = D.Pop();
					double y;
					switch (OperationEl)
					{
					case '+':
						y = x1 + x2;
						break;
					case '-':
						y = x1 - x2;
						break;
					case '*':
						y = x1 * x2;
						break;
					case '/':
						y = x1 / x2;
						break;
					case '^':
						y = pow(x1, x2);
						break;
					default:
						break;
					}
					D.Push(y);
					if (C.empty())
					{
						throw "Stack Error";
					}
					OperationEl = C.Pop();
				}
				C.Push(OperationEl);
				C.Push(str[i]);
			}

			if (flag == 0)
			{
				throw std::exception();
			}
		}

		double result = D.Pop();
		if (!D.empty())
		{
			throw std::exception();
		}
		if (!C.empty())
		{
			throw std::exception();
		}
		return result;
	};  

	
};

