#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#define EXIT_FAILURE 1


typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* top = NULL;


void push(int value, int line_number) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

/* Function to print all values on the stack */
void pall(int line_number) {
    Node* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

/* Function to print the value at the top of the stack */
void pint(int line_number) {
    if (top == NULL) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", top->data);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char opcode[256];
    int value, line_number = 1;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(value, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(line_number);
        } else if (strcmp(opcode, "pint") == 0) {
            pint(line_number);
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(file);
    return 0;
}

