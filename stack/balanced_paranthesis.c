#include "my_stack.h"

int main() {
	int n = 5;
	char s[5] = "[(()]";
	stack st = createStack(n);

	for (int i=0; i<n; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(&st, s[i]);
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			char pop_elem = pop(&st);
			if ((s[i] == ')' && pop_elem == '(') ||
				(s[i] == ']' && pop_elem == '[') ||
				(s[i] == '}' && pop_elem == '{') )
				continue;
			else {
				printf("Parenthesis are not balanced!\n");
				break;
			}
		}
	}

	if (isEmpty(&st)) {
		printf("Paranthesis are balanced!\n");
	}
	return 0;
}
