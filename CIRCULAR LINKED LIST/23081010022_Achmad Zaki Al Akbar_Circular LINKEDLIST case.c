#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAHASISWA 20
#define MAX_MAHASISWI 20

typedef struct Node {
    char nama[50];
    char jenis_kelamin;
    struct Node* next;
} Node;

Node* headMahasiswa = NULL;
Node* headMahasiswi = NULL;
int jumlahMahasiswa = 0;
int jumlahMahasiswi = 0;

Node* createNode(char* nama, char jenis_kelamin) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->nama, nama);
    newNode->jenis_kelamin = jenis_kelamin;
    newNode->next = newNode;
    return newNode;
}

void addToCircle(Node** head, int* count, char* nama, char jenis_kelamin, int max_capacity) {
    if (*count >= max_capacity) {
        printf("Lingkaran penuh, tidak bisa menambah %s.\n", nama);
        return;
    }

    Node* newNode = createNode(nama, jenis_kelamin);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    (*count)++;
}

void addToCircleFront(Node** head, int* count, char* nama, char jenis_kelamin, int max_capacity) {
    if (*count >= max_capacity) {
        printf("Lingkaran penuh, tidak bisa menambah %s di depan.\n", nama);
        return;
    }

    Node* newNode = createNode(nama, jenis_kelamin);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
    (*count)++;
}

void removeFromCircle(Node** head, int* count, char* nama) {
    if (*head == NULL) {
        printf("Lingkaran kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    if (strcmp(nama, "Irsyad") == 0 || strcmp(nama, "Arsyad") == 0) {
        removeFromCircle(head, count, "Irsyad");
        removeFromCircle(head, count, "Arsyad");
        return;
    }

    if (strcmp(temp->nama, nama) == 0) {
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
            (*count)--;
            return;
        }

        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        (*count)--;
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && strcmp(temp->nama, nama) != 0);

    if (temp == *head) {
        printf("%s tidak ditemukan di lingkaran.\n", nama);
        return;
    }

    prev->next = temp->next;
    free(temp);
    (*count)--;
}

void printCircle(Node* head) {
    if (head == NULL) {
        printf("Lingkaran kosong.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%s (%c) -> ", temp->nama, temp->jenis_kelamin);
        temp = temp->next;
    } while (temp != head);
    printf("%s (back to start)\n", head->nama);
}

void printGabungan(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    if (head1 == NULL && head2 == NULL) {
        printf("Lingkaran besar kosong.\n");
        return;
    }

    printf("Lingkaran Gabungan:\n");

    if (temp1 != NULL) {
        do {
            printf("%s (%c) -> ", temp1->nama, temp1->jenis_kelamin);
            temp1 = temp1->next;
        } while (temp1 != head1);
    }

    if (temp2 != NULL) {
        do {
            printf("%s (%c) -> ", temp2->nama, temp2->jenis_kelamin);
            temp2 = temp2->next;
        } while (temp2 != head2);
    }

    printf("(back to start)\n");
}

int main() {
    int pilihan;
    char nama[50];
    char jenis_kelamin;

    while (1) {
        printf("\n--- Pilihan Menu ---\n");
        printf("1. Tambahkan mahasiswa/mahasiswi ke lingkaran (akhir)\n");
        printf("2. Tambahkan mahasiswa/mahasiswi ke lingkaran (tengah)\n");
        printf("3. Tambahkan mahasiswa/mahasiswi ke lingkaran (depan)\n");
        printf("4. Tambahkan mahasiswa/mahasiswi setelah mahasiswa/mahasiswi tertentu\n");
        printf("5. Hapus mahasiswa/mahasiswi dari lingkaran\n");
        printf("6. Tampilkan lingkaran mahasiswa\n");
        printf("7. Tampilkan lingkaran mahasiswi\n");
        printf("8. Tampilkan lingkaran gabungan (mahasiswa dan mahasiswi)\n");
        printf("9. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            case 2:
            case 3:
                printf("Masukkan nama: ");
                scanf("%s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);

                if (jenis_kelamin == 'L') {
                    if (strcmp(nama, "Irsyad") == 0 || strcmp(nama, "Arsyad") == 0) {
                        addToCircle(&headMahasiswa, &jumlahMahasiswa, "Irsyad", 'L', MAX_MAHASISWA);
                        addToCircle(&headMahasiswa, &jumlahMahasiswa, "Arsyad", 'L', MAX_MAHASISWA);
                        printf("Irsyad dan Arsyad telah ditambahkan ke lingkaran mahasiswa.\n");
                    } else if (jumlahMahasiswa < MAX_MAHASISWA) {
                        if (pilihan == 1) {
                            addToCircle(&headMahasiswa, &jumlahMahasiswa, nama, jenis_kelamin, MAX_MAHASISWA);
                        } else if (pilihan == 2) {
                            addToCircle(&headMahasiswa, &jumlahMahasiswa, nama, jenis_kelamin, MAX_MAHASISWA);
                        } else if (pilihan == 3) {
                            addToCircleFront(&headMahasiswa, &jumlahMahasiswa, nama, jenis_kelamin, MAX_MAHASISWA);
                        }
                    }
                } else if (jenis_kelamin == 'P') {
                    if (strcmp(nama, "Cindy") == 0) {
                        if (jumlahMahasiswi == 0) {
                            printf("Cindy tidak mau bergabung karena tidak ada mahasiswi lain.\n");
                        } else {
                            if (pilihan == 1) {
                                addToCircle(&headMahasiswi, &jumlahMahasiswi, nama, jenis_kelamin, MAX_MAHASISWI);
                            } else if (pilihan == 2) {
                                addToCircle(&headMahasiswi, &jumlahMahasiswi, nama, jenis_kelamin, MAX_MAHASISWI);
                            } else if (pilihan == 3) {
                                addToCircleFront(&headMahasiswi, &jumlahMahasiswi, nama, jenis_kelamin, MAX_MAHASISWI);
                            }
                        }
                    } else {
                        if (pilihan == 1) {
                            addToCircle(&headMahasiswi, &jumlahMahasiswi, nama, jenis_kelamin, MAX_MAHASISWI);
                        } else if (pilihan == 2) {
                            addToCircle(&headMahasiswi, &jumlahMahasiswi, nama, jenis_kelamin, MAX_MAHASISWI);
                        } else if (pilihan == 3) {
                            addToCircleFront(&headMahasiswi, &jumlahMahasiswi, nama, jenis_kelamin, MAX_MAHASISWI);
                        }
                    }
                } else {
                    printf("Jenis kelamin tidak valid.\n");
                }
                break;

            case 4:
                printf("Masukkan nama yang ingin disisipkan setelah: ");
                char targetName[50];
                scanf("%s", targetName);
                printf("Masukkan nama: ");
                scanf("%s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);

                if (jenis_kelamin == 'L') {
                    addToCircle(&headMahasiswa, &jumlahMahasiswa, nama, jenis_kelamin, MAX_MAHASISWA);
                } else if (jenis_kelamin == 'P') {
                    addToCircle(&headMahasiswi, &jumlahMahasiswi, nama, jenis_kelamin, MAX_MAHASISWI);
                } else {
                    printf("Jenis kelamin tidak valid.\n");
                }
                break;

            case 5:
                printf("Masukkan nama yang ingin dihapus: ");
                scanf("%s", nama);
                removeFromCircle(&headMahasiswa, &jumlahMahasiswa, nama);
                removeFromCircle(&headMahasiswi, &jumlahMahasiswi, nama);
                break;

            case 6:
                printf("Lingkaran Mahasiswa:\n");
                printCircle(headMahasiswa);
                break;

            case 7:
                printf("Lingkaran Mahasiswi:\n");
                printCircle(headMahasiswi);
                break;

            case 8:
                printGabungan(headMahasiswa, headMahasiswi);
                break;

            case 9:
                printf("Keluar dari program.\n");
                return 0;

            default:
                printf("Pilihan tidak valid.\n");
        }
    }
}
