#include <stdio.h>

int st[5] = {0};  // Correct array name
int stckpointer = -1;

void push(int ele)
{
    if (stckpointer < 4)
    {
        stckpointer++;
        st[stckpointer] = ele;
        printf("Element pushed successfully: %d\n", ele);
    }

    else
    {
        printf("Stack overflow\n");
    }
}
int pop(void)
{
    int x;
    if (stckpointer > -1)
    {
        x = st[stckpointer];
        stckpointer--;
        printf("Element popped successfully: %d\n", x);
        return x;
    }
    else
    {
        printf("Stack underflow\n");
        return -1;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);  // Stack overflow

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());  // Stack underflow

    return 0;
}
