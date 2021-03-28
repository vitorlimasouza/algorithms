typedef struct stack{
    int value;
    struct stack *next;
    struct stack *previous;
    struct stack *top;
}
Stack;

Stack *newNodeS(int value);
void push(Stack **stack, int value);
int pop(Stack **stack);
int peek(Stack *stack);
void freeStack(Stack **stack);

void push(Stack **stack, int value){
    if((*stack) == NULL){
        (*stack) = newNodeS(value);
        (*stack)->top = (*stack);
        (*stack)->top->previous = NULL;
    }else{
        (*stack)->top->next = newNodeS(value);
        (*stack)->top->next->previous = (*stack)->top;
        (*stack)->top = (*stack)->top->next;
    }
}

int pop(Stack **stack){
    if((*stack) == NULL){
        return -1;
    }else{
        Stack *top = (*stack)->top;
        int value = top->value;
        if(top->previous == NULL){
             (*stack) = NULL;
        }else{
            (*stack)->top = top->previous;
            (*stack)->top->next = NULL;
            free(top);
        }
        return value;
    }
}

Stack *newNodeS(int value){
    Stack *n;
    n = (Stack *) malloc(sizeof(Stack));
    if(n == NULL) exit(0);
    n->value = value;
    n->next = NULL;
    n->top = NULL;
    n->previous = NULL;
    return n;
}

void freeStack(Stack **stack){
    while((*stack) != NULL){
        Stack *temp = (*stack)->next;
        free((*stack));
        (*stack) = temp;
    }
}
