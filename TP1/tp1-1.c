
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
int data;
struct Node* next;
} Node;

typedef struct Stack {
Node* top;
} Stack;

void initStack(Stack* s) {
s->top = NULL;
}

int isEmpty(Stack s) {
return (s.top == NULL);
}

void push(Stack* s, int value) {
Node* newNode = (Node*)malloc(sizeof(Node));
if (newNode == NULL) {
return;
}
newNode->data = value;
newNode->next = s->top;
s->top = newNode;
}

int pop(Stack* s) {
if (isEmpty(*s)) {
return -1;
}
Node* temp = s->top;
int poppedValue = temp->data;
s->top = s->top->next;
free(temp);
return poppedValue;
}

int peek(Stack s) {
if (isEmpty(s)) {
return -1;
}
return s.top->data;
}

int evaluatePostfix(char* exp) {
Stack s;
initStack(&s);

for (int i = 0; exp[i] != '\0'; i++) {
if (exp[i] == ' ') continue;

if (isdigit(exp[i])) {
push(&s, exp[i] - '0');
} else {
int val2 = pop(&s);
int val1 = pop(&s);

switch (exp[i]) {
case '+': push(&s, val1 + val2); break;
case '-': push(&s, val1 - val2); break;
case '*': push(&s, val1 * val2); break;
case '/':
if (val2 != 0) push(&s, val1 / val2);
break;
}
}
}
return pop(&s);
}

int main() {
printf("=== Part 1 ===\n");
Stack s1;
initStack(&s1);

char str[] = "(A+B)=C";

for (int i = 0; str[i] != '\0'; i++) {
push(&s1, str[i]);
}

printf("Pop output: ");
while (!isEmpty(s1)) {
printf("%c", (char)pop(&s1));
}
printf("\n\n");

printf("=== Part 2 ===\n");
char postfixExp[] = "6 3 + 2 * 4 /";
int result = evaluatePostfix(postfixExp);
printf("Postfix: %s\n", postfixExp);
printf("Result = %d\n", result);

return 0;
}
