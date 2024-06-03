#include <iostream>
#include <stack>
#include <string>

/*
 Algorithm:-
 1) Create 2 stacks, 1 for operands, 1 for operators
 2) loop thru expr, if e == operand, operand_stack.push(e)
 3) if e == operator, if operator_stack empty or operator_stack.peek().priority < e.priority or e == '('
 		operator_stack.push(e)
 4) else if e != ')' i.e. e.priority <= operator_stack.peek().priority then
 		while ( operator_stack.peek().priority >= e.priority) do
			op = pop(operator_stack)
			call func pop_and_eval(op) defined as:-
			pop_and_eval(op) {
				int2 = pop(operand_stack)
				int1 = pop(operand_stack)
				res = eval(int1, int2, op)
				operand_stack.push(res)
			}
		operator_stack.push(e)
 5) else i.e. e == ')' then
 		while (operator_stack.peek() != '(') do
			op = pop(operator_stack)
			call func pop_and_eval(op) defined as:-
			pop_and_eval(op) {
				int2 = pop(operand_stack)
				int1 = pop(operand_stack)
				res = eval(int1, int2, op)
				operand_stack.push(res)
			}
		operator_stack.pop()
 6) after loop finished,
 	while (operator_stack not_empty)
		op = pop(operator_stack)
		pop_and_eval(op)
 7) pop(operand_stack) is answer
*/
using namespace std;

stack<int> a;
stack<char> b;

bool isOperand(char c) {
	if ( c >= 48 && c <= 57 )
		return true;
	else
		return false;
}

int getPriority(char e) {
	if (e == '+' || e == '-') {
		return 1;
	}
	if (e == '*' || e == '/') {
		return 2;
	}
	return -1;
}

int eval(int int1, int int2, char op) {
	if (op == '+')
		return int1+int2;
	if (op == '-')
		return int1-int2;
	if (op == '*')
		return int1*int2;
	if (op == '/')
		return int1/int2;
	return -1;
}

void pop_and_eval(char op) {
	int int2 = a.top();
	a.pop();
	int int1 = a.top();
	a.pop();
	int res = eval(int1, int2, op);
	a.push(res);
}

int infix_eval(string expr) {
	for (char e : expr) {
		if ( isOperand(e) ) {
			a.push((int) (e - '0'));
		}
		else {
			if (b.empty() || getPriority(e) > getPriority(b.top()) || e == '(')
				b.push(e);
			else if ( e != ')' ) {
				while ( getPriority(b.top()) >= getPriority(e) ) {
					char op = b.top();
					b.pop();
					pop_and_eval(op);
				}
				b.push(e);
			}
			else {
				char op;
				while ( (op = b.top()) != '(' ) {
					b.pop();
					pop_and_eval(op);
				}
				b.pop();
			}
		}
	}

	while (!b.empty()) {
		char op = b.top();
		b.pop();
		pop_and_eval(op);
	}

	return a.top();
}

int main() {	
	string expr = "2+(5-3*6/2)";
	cout << "Input expression: eg- (" << expr << ") ";
	if (!(cin >> expr))
		expr = "2+(5-3*6/2)";
	cout << infix_eval(expr) << '\n';
	return 0;
}
