#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisikan struktur untuk menyimpan data karyawan
typedef struct Employee {
    int id;                    // Employee ID
    char name[31];             // Nama Lengkap
    char birthplace[31];       // Tempat Lahir
    char birthdate[11];        // Tanggal Lahir (format DD-MM-YYYY)
    char position[51];         // Jabatan
    struct Employee* next;     // Pointer ke karyawan berikutnya dalam linked list
} Employee;

Employee* head = NULL;         // Pointer ke head dari linked list
int employeeCount = 0;         // Menghitung jumlah karyawan dalam database

void printLine() {
    printf("=========================================\n");
}

// Fungsi untuk menambahkan data karyawan baru
void pushEmployee() {
    if (employeeCount >= 5) {
        printf("Jumlah data karyawan maksimal adalah 5.\n");
        return;
    }

    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->next = NULL;

    printLine();
    printf("Masukkan data karyawan baru:\n");

    // Input Employee ID dan validasi
    printf("Employee ID (maksimal 5 angka): ");
    scanf("%d", &newEmployee->id);
    if (newEmployee->id > 99999) {
        printf("Employee ID tidak valid!\n");
        free(newEmployee);
        return;
    }

    // Input Nama Lengkap dan validasi
    printf("Nama Lengkap (maksimal 30 karakter): ");
    scanf(" %[^\n]", newEmployee->name);
    if (strlen(newEmployee->name) > 30) {
        printf("Nama Lengkap tidak valid!\n");
        free(newEmployee);
        return;
    }

    // Input Tempat Lahir dan validasi
    printf("Tempat Lahir (maksimal 30 karakter): ");
    scanf(" %[^\n]", newEmployee->birthplace);
    if (strlen(newEmployee->birthplace) > 30) {
        printf("Tempat Lahir tidak valid!\n");
        free(newEmployee);
        return;
    }

    // Input Tanggal Lahir dan validasi
    printf("Tanggal Lahir (DD-MM-YYYY): ");
    scanf(" %[^\n]", newEmployee->birthdate);
    if (strlen(newEmployee->birthdate) > 10) {
        printf("Tanggal Lahir tidak valid!\n");
        free(newEmployee);
        return;
    }

    // Input Jabatan dan validasi
    printf("Jabatan (maksimal 50 karakter): ");
    scanf(" %[^\n]", newEmployee->position);
    if (strlen(newEmployee->position) > 50) {
        printf("Jabatan tidak valid!\n");
        free(newEmployee);
        return;
    }

    // Menyisipkan karyawan baru dalam urutan yang terurut berdasarkan Employee ID
    if (head == NULL || head->id > newEmployee->id) {
        newEmployee->next = head;
        head = newEmployee;
    } else {
        Employee* current = head;
        while (current->next != NULL && current->next->id < newEmployee->id) {
            current = current->next;
        }
        newEmployee->next = current->next;
        current->next = newEmployee;
    }

    employeeCount++;
    printf("Data karyawan berhasil ditambahkan!\n");
    printLine();
}

// Fungsi untuk menampilkan semua data karyawan
void displayEmployees() {
    printLine();
    if (head == NULL) {
        printf("Database karyawan kosong.\n");
    } else {
        Employee* current = head;
        printf("Daftar Karyawan:\n");
        while (current != NULL) {
            printf("ID           : %d\n", current->id);
            printf("Nama         : %s\n", current->name);
            printf("Tempat Lahir : %s\n", current->birthplace);
            printf("Tanggal Lahir: %s\n", current->birthdate);
            printf("Jabatan      : %s\n", current->position);
            printf("-------------------------------\n");
            current = current->next;
        }
    }
    printLine();
}

// Fungsi untuk menghapus karyawan berdasarkan Employee ID
void deleteEmployee() {
    if (head == NULL) {
        printf("Database karyawan kosong.\n");
        return;
    }

    int id;
    printf("Masukkan Employee ID yang ingin dihapus: ");
    scanf("%d", &id);

    // Jika karyawan yang ingin dihapus adalah head
    if (head->id == id) {
        Employee* temp = head;
        head = head->next;
        free(temp);
        employeeCount--;
        printf("Data karyawan berhasil dihapus.\n");
        return;
    }

    // Mencari karyawan dalam linked list
    Employee* current = head;
    while (current->next != NULL && current->next->id != id) {
        current = current->next;
    }

    // Jika karyawan ditemukan, hapus dari linked list
    if (current->next == NULL) {
        printf("Employee ID tidak ditemukan.\n");
    } else {
        Employee* temp = current->next;
        current->next = current->next->next;
        free(temp);
        employeeCount--;
        printf("Data karyawan berhasil dihapus.\n");
    }
}

// Fungsi untuk menghapus semua data karyawan
void deleteAllEmployees() {
    Employee* current = head;
    while (current != NULL) {
        Employee* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    employeeCount = 0;
    printf("Semua data karyawan telah dihapus.\n");
}

int main() {
    int choice;
    while (1) {
        printLine();
        printf("Menu:\n");
        printf("1. Push data karyawan\n");
        printf("2. Menampilkan semua daftar karyawan\n");
        printf("3. Hapus data karyawan\n");
        printf("4. Hapus semua data karyawan\n");
        printf("5. Keluar\n");
        printLine();
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pushEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                deleteAllEmployees();
                break;
            case 5:
                deleteAllEmployees();
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }
    return 0;
}
