#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Struktur untuk merepresentasikan sebuah stack karakter
typedef struct {
    char data[MAX_SIZE]; // array untuk menyimpan karakter
    int top; // indeks dari elemen teratas
} Stack;

// Fungsi untuk menginisialisasi stack
void initStack(Stack* stack) {
    stack->top = -1; // set top ke -1, artinya stack kosong
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(Stack* stack) {
    return stack->top == -1; // jika top == -1, maka stack kosong
}

// Fungsi untuk menambahkan elemen ke atas stack
void push(Stack* stack, char c) {
    if (stack->top < MAX_SIZE - 1) { // jika stack belum penuh
        stack->data[++stack->top] = c; // tambahkan elemen ke atas stack
    }
}

// Fungsi untuk menghapus elemen teratas dari stack
char pop(Stack* stack) {
    if (!isEmpty(stack)) { // jika stack tidak kosong
        return stack->data[stack->top--]; // hapus elemen teratas dan kembalikan nilai
    }
    return '\0'; // jika stack kosong, kembalikan karakter null
}

// Fungsi untuk membalikkan string menggunakan stack
void reverseString(char* str) {
    Stack stack;
    initStack(&stack); // inisialisasi stack

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]); // dorong setiap karakter ke atas stack
    }

    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack); // hapus setiap karakter dari stack dan assign ke string asli
    }
}

int main() {
    char str[] = "binus";
    printf("String asli     : %s\n", str);

    reverseString(str);
    printf("String terbalik : %s\n", str);

    return 0;
}
