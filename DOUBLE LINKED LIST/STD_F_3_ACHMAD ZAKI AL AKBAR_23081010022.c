#include <stdio.h>
#include <stdlib.h>

// Double linked list node
struct node {
    int data;
    struct node *next; // pointer single linked list (maju)
    struct node *prev; // pointer double linked list (mundur)
};

typedef struct node node;

// function declarations
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void jumlahData(node *head);
void tranverse(node *head, int reverse);

int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Hitung jumlah data\n");
        printf("9. Hitung perjumlahan total dari semua data\n");
        printf("0. Cetak isi list\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        switch(pilih) {
            case '1': tambahAwal(&head); break;
            case '2': tambahData(&head); break;
            case '3': tambahAkhir(&head); break;
            case '4': hapusAwal(&head); break;
            case '5': hapusData(&head); break;
            case '6': hapusAkhir(&head); break;
            case '7': cariData(head); break;
            case '8': hitungData(head); break;
            case '9': jumlahData(head); break;
            case '0': tranverse(head, 0); getch(); break; // Forward traversal
        }
    } while (pilih != 'q');

    return 0;
}

// tambah awal list
void tambahAwal(node **head) {
    int bil;
    node *pNew = (node *)malloc(sizeof(node));

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
        pNew->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = pNew;
        }
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

// tambah tengah list
void tambahData(node **head) {
    int pos, bil;
    node *pNew = (node *)malloc(sizeof(node));
    node *pCur = *head;

    system("cls");
    tranverse(*head, 0);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        free(pNew);
        getch();
        return;
    }

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = pCur->next;
        pNew->prev = pCur;

        if (pCur->next != NULL) {
            pCur->next->prev = pNew;
        }
        pCur->next = pNew;
    } else {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

// tambah akhir list
void tambahAkhir(node **head) {
    int bil;
    node *pNew = (node *)malloc(sizeof(node));
    node *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            pNew->prev = NULL;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->prev = pCur;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

// hapus data awal
void hapusAwal(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang dihapus.");
        getch();
        return;
    }

    node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

// hapus data tengah
void hapusData(node **head) {
    int bil;
    node *pCur = *head, *pPrev = NULL;

    system("cls");
    tranverse(*head, 0);
    printf("\nMasukkan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    while (pCur != NULL && pCur->data != bil) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan.");
        getch();
        return;
    }

    if (pPrev == NULL) {
        *head = pCur->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        pPrev->next = pCur->next;
        if (pCur->next != NULL) {
            pCur->next->prev = pPrev;
        }
    }

    free(pCur);
}

// hapus akhir list
void hapusAkhir(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang dihapus.");
        getch();
        return;
    }

    node *pCur = *head;

    while (pCur->next != NULL) {
        pCur = pCur->next;
    }

    if (pCur->prev == NULL) {
        *head = NULL;
    } else {
        pCur->prev->next = NULL;
    }

    free(pCur);
}

// mencari data
void cariData(node *head) {
    int bil;
    node *pCur = head;

    system("cls");
    tranverse(head, 0);
    printf("\nMasukkan data yang dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan.\n", bil);
            getch();
            return;
        }
        pCur = pCur->next;
    }
    printf("Data tidak ditemukan.\n");
    getch();
}

// hitung jumlah data
void hitungData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data dalam list: %d\n", count);
    getch();
}

// jumlah penjumlahan data
void jumlahData(node *head) {
    int sum = 0;
    node *pCur = head;

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Perjumlah total dari semua data: %d\n", sum);
    getch();
}

// traverse (cetak isi list)
void tranverse(node *head, int reverse) {
    node *pWalker = head;

    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    if (reverse == 0) {
        printf("NULL <- ");
        while (pWalker != NULL) {
            printf("%d", pWalker->data);
            if (pWalker->next != NULL) {
                printf(" <-> ");
            }
            pWalker = pWalker->next;
        }
        printf(" -> NULL\n");

    }
}
