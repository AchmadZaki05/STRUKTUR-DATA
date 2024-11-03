#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Deklarasi fungsi
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void jumlahData(node *head);
void tranverse(node *head);

//print f

int main() {
    node *head;
    char pilih;

    head = NULL;
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
            case '0': tranverse(head); getch(); break;
        }
    } while (pilih != 'q');

    return 0;
}

//void tambah awal

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;
        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//void tambah data tengah
void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//void tambah ahir

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//void hapus awal

void hapusAwal(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang dihapus.");
        getch();
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

//void hapus data tengah

void hapusData(node **head) {
    int bil;
    node *pCur = *head, *pPrev = NULL;

    system("cls");
    tranverse(*head);
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
    } else {
        pPrev->next = pCur->next;
    }

    free(pCur);
}

//void hapus ahir

void hapusAkhir(node **head) {
    if (*head == NULL) {
        printf("List kosong, tidak ada yang dihapus.");
        getch();
        return;
    }

    node *pCur = *head;
    node *pPrev = NULL;

    while (pCur->next != NULL) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pPrev == NULL) {
        *head = NULL;
    } else {
        pPrev->next = NULL;
    }

    free(pCur);
}

//void cari data

void cariData(node *head) {
    int bil;
    node *pCur = head;

    system("cls");
    tranverse(head);
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

//void hitung jumlah data

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

//void hitung hasil semua ditambah

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

// void cetak isi list

void tranverse(node *head) {
    node *pWalker;
    system("cls");
    pWalker = head;
    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }
    printf("NULL");
}
