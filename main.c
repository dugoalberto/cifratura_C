#include <stdio.h>
void cifratura(char s[], int lunghezza, int k);
void decifratura(char s[], int lunghezza, int k);
int calcolaSalti(int totale, int salti){
    if (totale == 10 && salti >= 10) return salti % 10;
    if (totale == 25 && salti >= 10) return salti % 25;
    else {
        return salti;
    }
}
void printMenu(){
    printf("-----------------\n\n");
    printf("Benvenuto in criptApp");
    printf("\n\n-----------------\n");
    printf(" Scegliere una delle seguenti opzioni:\n"
           "\n"
           "   \n"
           "\n"
           "   1) specificare la chiave di cifratura\n"
           "\n"
           "   2) codifica un messaggio\n"
           "\n"
           "   3) decodifica un messaggio\n"
           "\n"
           "   4) esci"
           "\n\n"
           "numero : ");
}
void gestisciMenu(int* scelta){
    printMenu();
    scanf("%d", scelta);
}

int main() {
    //char s[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    //char s[] = {"abcdefghijklmnopqrstuvwxyz"};
    //char s[] = {"0123456789"};
    char s[] = {"C14O,, a 7utt1!!!"};
    int lunghezza = sizeof s / sizeof s[0] - 1 ; //lunghezza array
    int k = 0; //chiave di cifratura
    int scelta = 0;
    while (scelta <= 0 || scelta >= 5) {
        printMenu();
        scanf("\n%d", &scelta);
        printf("\n la tua scelta = %d \n", scelta);
        if (scelta == 1) {
            while (k <= 0) {
                printf("\ninserisci una chiava maggiore di 0 ---> ");
                scanf("%d", &k);
            }
            printf("\n");
            gestisciMenu(&scelta);
        }
        //TODO GESTIRE CHE PRIMA DI CIFRARE DEVE ESSERE STATA SCELTA UNA CHIAVE
        if (scelta == 2) {
            cifratura(s, lunghezza, k);
            for (int i = 0; i < lunghezza; ++i) {
                printf(" %c ", s[i]);
            }
            printf("\n");
            gestisciMenu(&scelta);
        }
        if (scelta == 3) {
            decifratura(s, lunghezza, k);
            for (int i = 0; i < lunghezza; ++i) {
                printf(" %c ", s[i]);
            }
            printf("\n");
            gestisciMenu(&scelta);
        }
        if (scelta == 4) {
            printf(" sei uscito dal menù, se vuoi ritornare, re-run");
            return 0;
        }
        printf("SCEGLI UN NUMERO TRA 1 E 4!!\n");
    }
    return 0;
}
void cifratura(char s[], int lunghezza, int k){
    int salti;
    for (int i = 0; i < lunghezza; ++i) {
        unsigned char x = s[i];
        int z = x;
        if(48 <= z  && z <= 57) {
            salti = calcolaSalti(10, k);
            if(z+salti > 57 && z <= 57) {
                x = 47 + ((z+salti) % 57);
                s[i] = x;
            } else if(48 <= z  && z <= 57){
                x = z + salti;
                s[i] = x;
            }
        }
        if(65 <= z && z<=90) {
            salti = calcolaSalti(25, k);
            if (z + salti > 90 && z <= 90) {
                x = 64 + ((z + salti) % 90);
                s[i] = x;
            }else if (65 <= z && z<=90){
                x = z + salti;
                s[i] = x;
            }
        }
        if((97 <= z && z <= 122)){
            salti = calcolaSalti(25, k);
            if(z+ salti> 122 && z <= 122) {
                x = 96 + z + salti - 122;
                s[i] = x;
            }else if((97 <= z && z <= 122)){
                x = z + salti;
                s[i] = x;
            }
        }
    }
}
void decifratura(char s[], int lunghezza, int k){
    int salti;
    for (int i = 0; i < lunghezza; ++i) {
        unsigned char x = s[i];
        int z = x;
        if(48 <= z  && z <= 57) {
            salti = calcolaSalti(10, k);
            if(z - salti < 48 && z <= 57) {
                x = 58 - (48 - (z - salti));
                s[i] = x;
            } else if(48 <= z  && z <= 57){
                x = z- salti;
                s[i] = x;
            }
        }
        if(65 <= z && z <= 90) {
            salti = calcolaSalti(25, k);
            if (z-salti < 65 && z <= 90) {
                x = 91 - (65 - (z - salti));
                s[i] = x;
            }else if (65 <= z && z<=90){
                x = z - salti;
                s[i] = x;
            }
        }
        if((97 <= z && z <= 122)){
            salti = calcolaSalti(25, k);
            if(z-salti < 97 && z <= 122) {
                x = 123 - (97 - (z - salti));
                s[i] = x;
            }else if((97 <= z && z <= 122)){
                x = z - salti;
                s[i] = x;
            }
        }
    }
    printf("\ndopo : ");
}

