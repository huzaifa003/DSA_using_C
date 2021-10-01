#include "StackArrayInt.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    StackArrayInt stack;
    stack.max = SIZE;
    stack.top = -1;
    push(&stack, 5);
    printf("%d", stack.arr[0]);
    printf("\nTop is = %d", stack.top);
    printf("\nPeeked Element is = %d",peek(&stack));
    printf("\nPopped element is = %d", pop(&stack));
    printf("\nPopped element is = %d", pop(&stack));

    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    push(&stack, 8);
    display(&stack);
    getch();
    return 0;
}
