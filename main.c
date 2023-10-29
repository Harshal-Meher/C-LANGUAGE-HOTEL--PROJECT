#include <stdio.h>
#include <stdlib.h>

int w = 1, totbill = 0;

int userplats(int mi) {
    int plats = 0;
    printf("ok..........good choice\n");
    if (mi == 4 || mi == 5 || mi == 6) {
        printf("How many cups= ");
    } else {
        printf("HOW MANY PLATES= ");
    }
    scanf("%d", &plats);
    return plats;
}

int totalbill(int rate, int mi) {
    int plats = 0;
    plats = userplats(mi);
    totbill = totbill + (plats * rate);
    return plats;
}

void printnote(int amt) {
    int temp, i;
    int a[9] = {2000, 500, 100, 50, 20, 10, 5, 2, 1};
    printf("Enter Your Cash amount= ");
    scanf("%d", &amt);
    temp = amt;
    for (i = 0; i < 9; i++) {
        printf("\n%d Note is=%d", a[i], temp / a[i]);
        temp = temp % a[i];
    }
}

void printbill() {
    int cash = 0;
    printf("your bill=%d\n", totbill);
h:
    printf("your cash= ");
    scanf("%d", &cash);
    if (cash > totbill) {
        printf("\n----------------------------------------------------------------------\n");
        printf("Return Money\n");
        printf("\n----------------------------------------------------------------------\n");
    }
    if (cash < totbill) {
        printf("\n--------------------------------------------------------------------\n");
        printf("please pay %d/- more money\n", totbill - cash);
        totbill = totbill - cash;
        goto h;
        printf("\n--------------------------------------------------------------------\n");
    }
}

void order(int ch) {
    switch (ch) {
        case 1:
            printf("SAMOSA\n");
            totalbill(20, ch);
            break;
        case 2:
            printf("DHOKLA\n");
            totalbill(50, ch);
            break;
        case 3:
            printf("DOSA\n");
            totalbill(70, ch);
            break;
        case 4:
            printf("coffee\n");
            totalbill(40, ch);
            break;
        case 5:
            printf("ice-cream\n");
            totalbill(60, ch);
            break;
        case 6:
            printf("TEA\n");
            totalbill(15, ch);
            break;
        case 0:
            w = 0;
            printbill();
            printf("\n--------------------Thank you----------------------------\n");
            printf("------------------Visit Again---------------------------------\n");
            break;
        default:
            printf("WRONG INPUT SORRY !!!!! PLEASE CLICK YOUR RIGHT NUMBER\n");
    }
}

int menu() {
    int ch = 0;
    printf("       ::menu::        \n");
    printf("1.SAMOSA            20/-\n");
    printf("2.DHOKLA            50/-\n");
    printf("3.DOSA              70/-\n");
    printf("4.coffee            40/-\n");
    printf("5.ice-cream        60/-\n");
    printf("6.TEA               15/-\n");
    printf("0.exit                  \n");
    printf("Select your Choice= ");
    scanf("%d", &ch);
    return ch;
}

int main() {
    while (w) {
        int ch;
        printf("WELCOME TO MY HOTEL MEHER\n");
        ch = menu();
        order(ch);
    }

    return 0;
}
