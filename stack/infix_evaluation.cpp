#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return true;
	else
		return false;
}

int getPriority(char c) {
	if ( c == ')' || c == '(' )
		return 0;
	if ( c == '+' || c == '-' )
		return 1;
	if ( c == '*' || c == '/' )
		return 2;
}

int miniEval(int int_1, int int_2, char c) {
	if (c == '+')
		return int_1 + int_2;
	if (c == '-')
		return int_1 - int_2;
	if (c == '*')
		return int_1*int_2;
	if (c == '/')
		return int_1/int_2;
	return -1;
}

void pop_and_eval(stack<int> &operand_stack, char c) {
	int int_2 = operand_stack.pop();
	int int_1 = operand_stack.pop();
	int res = miniEval(int_1, int_2, c);
	operand_stack.push(res);
}

int evaluate(char expr[], int n) {
	stack<int> operand_stack;
	stack<char> operator_stack;

	for (int i=0; i<n; i++) {
		if ( isOperator(expr[i]) ) {
			if ( operator_stack.empty() || expr[i] == '(' )
				operator_stack.push(expr[i]);
			else if (expr[i] == ')') {
				char pop_char = operator_stack.pop();
				while ( pop_char != '(' ) {
					pop_and_eval(operand_stack, pop_char);
					pop_char = operator_stack.pop();
				}
			}
			else {
				char peek_char = operator_stack.top();
				if (getPriority(peek_char) >= getPriority(expr[i]) ) {
					char pop_char = operator_stack.pop();
					while ( getPriority(pop_char) >= getPriority(expr[i]) ) {
						pop_and_eval(operand_stack, pop_char);
						pop_char = operator_stack.pop();
					}
					operator_stack.push(pop_char);
				}
				operator_stack.push(expr[i]);
			}
		}
		else {
			operand_stack.push(expr[i]);
		}
	}

	while (!isEmpty(&operator_stack)) {
		char c = operator_stack.pop();
		pop_and_eval(operand_stack, c);
	}

	return operand_stack.pop();
}

int main() {
	int n=11;
	char expr[] = "2+(5-3*6/2)";

	printf("%d\n", evaluate(expr, n));
	return 0;
}

