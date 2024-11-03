#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int max;
} Stack;

void init(Stack *stack, int max) {
    stack->data = (int*)malloc(max * sizeof(int));
    stack->top = -1;
    stack->max = max;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == stack->max - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack penuh!\n");
    } else {
        stack->data[++stack->top] = value;
        printf("Data %d ditambahkan ke stack.\n", value);
    }
}

void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong!\n");
    } else {
        printf("Data %d dihapus dari stack.\n", stack->data[stack->top--]);
    }
}

void stackTop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong!\n");
    } else {
        printf("Data teratas pada stack adalah: %d\n", stack->data[stack->top]);
    }
}

int stackCount(Stack *stack) {
    return stack->top + 1;
}

void destroyStack(Stack *stack) {
    free(stack->data);
    stack->top = -1;
    printf("Semua data di stack telah dihapus.\n");
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong!\n");
    } else {
        printf("Isi stack: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d", stack->data[i]);
            if (i < stack->top) {
                printf(" -> ");
            }
        }
        printf(" -> NULL\n");
    }
}

int main() {
    Stack stack;
    int max;
    printf("Masukkan ukuran maksimum stack: ");
    scanf("%d", &max);
    init(&stack, max);

    char choice;
    int value;

    do {
        printf("\nPILIHAN:\n");
        printf("1. Tambah data diatas (Push)\n");
        printf("2. Hapus data diatas (Pop)\n");
        printf("3. Tampilkan data teratas (Stack Top)\n");
        printf("4. Cek stack kosong (Empty Stack)\n");
        printf("5. Cek stack penuh (Full Count)\n");
        printf("6. Hitung data (Stack Count)\n");
        printf("7. Kosongkan semua data (Destroy Stack)\n");
        printf("0. Cetak isi stack\n");
        printf("Masukkan pilihan (tekan 'q' untuk keluar): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Masukkan data: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case '2':
                pop(&stack);
                break;
            case '3':
                stackTop(&stack);
                break;
            case '4':
                printf(isEmpty(&stack) ? "Stack kosong.\n" : "Stack terisi.\n");
                break;
            case '5':
                printf(isFull(&stack) ? "Stack penuh.\n" : "Stack belum penuh.\n");
                break;
            case '6':
                printf("Jumlah data di stack: %d\n", stackCount(&stack));
                break;
            case '7':
                destroyStack(&stack);
                break;
            case '0':
                printStack(&stack);
                break;
            case 'q':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 'q');

    destroyStack(&stack);
    return 0;
}
