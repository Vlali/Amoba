#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

enum bool{False,True};
void jatek_kezdese(){
    printf("AMOBA jatek");
    printf("\n\n\n\nA jatek kezdesehez nyomjon meg barmilyen gombot...");
    getch();
    system("cls");
    sleep(1);
}
void jatek_tabla_kiiratasa(char jatek_tabla[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c ",jatek_tabla[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void jatekos_udvozlese(char nev[30]){
    printf("\nUdvozollek %s!\n",nev);
}

char elso_jatekos_alakzata(char elso_jatekos_neve[30]){
    char alakzat_valasztas;
    char valaszthato_alakzatok[]={'x','o'};
    while(True){
        printf("%s valaszd ki, hogy melyik alakzattal szeretnel jatszani(%c,%c): ",
               elso_jatekos_neve,valaszthato_alakzatok[0],valaszthato_alakzatok[1]);
        scanf(" %c",&alakzat_valasztas);
        if(alakzat_valasztas=='x' || alakzat_valasztas=='o'){
            break;
        }
        printf("\nHibas erteket adtal meg!\n\n");
    }
    return alakzat_valasztas;
}
char masodik_jatekos_alakzata(char masodik_jatekos_neve[30],char elso_jatekos_alakzata){
    char alakzat_valasztas;
    char valaszthato_alakzatok[]={'x','o'};
    for (int i = 0; i < 2; i++) {
        if(elso_jatekos_alakzata!=valaszthato_alakzatok[i]) {
            alakzat_valasztas = valaszthato_alakzatok[i];
        }
    }
    printf("%s a %c karakterrel fogsz jatszani\n",masodik_jatekos_neve,alakzat_valasztas);
    return alakzat_valasztas;
}
int elso_jatekos_szinv(char elso_jatekos_neve[30]){
    int valasztott_szin;
    printf("Valaszthato szinek:\n\t\t1-kek\n\t\t2-lila\n\t\t3-sarga\n\n");
    while(True){
        printf("%s valaszd ki, hogy milyen szinu legyen a szoveg: ",elso_jatekos_neve);
        scanf("%d",&valasztott_szin);
        if(valasztott_szin<1 || valasztott_szin>3){
            printf("\nHibas erteket adtal meg!\n\n");
            continue;
        }
        break;
    }
    return valasztott_szin;
}
int masodik_jatekos_szinv(char masodik_jatekos_neve[30],int elso_jatekos_szin){
    int valasztott_szin;
    char szinek[3][10]={"kek","lila","sarga"};
    printf("Valaszthato szinek:\n\t\t1-kek\n\t\t2-lila\n\t\t3-sarga\n\n");
    while(True){
        printf("%s valaszd ki, hogy milyen szinu legyen a szoveg: ",masodik_jatekos_neve);
        scanf("%d",&valasztott_szin);
        if(valasztott_szin<1 || valasztott_szin>3){
            printf("\nHibas erteket adtal meg!\n\n");
            continue;
        }
        if(valasztott_szin==elso_jatekos_szin){
            printf("\nA %s szint az elso jatekos mar lefoglalta!\n\n",szinek[elso_jatekos_szin-1]);
            continue;
        }
        break;
    }
    return valasztott_szin;
}
void szin_atallitasa(int szinkod){
    switch(szinkod){
        case 1:
            system("COLOR 01");
            break;
        case 2:
            system("COLOR 05");
            break;
        case 3:
            system("COLOR 06");
            break;
        case 4:
            system("COLOR 02");
            break;
        case 5:
            system("COLOR 04");
            break;
        case 6:
            system("COLOR 07");
            break;
        default:
            break;
    }
}
int sor_valasztasa(char nev[30],char alakzat){
    int sor_valasztas;
    while (True){
        printf("%s valaszd ki melyik sorban szeretned a %c-t elhelyezni(1-3): ",nev,alakzat);
        scanf("%d",&sor_valasztas);
        if(sor_valasztas<1 || sor_valasztas>3){
            printf("\nA sor erteket 1-3 kozott kell megadnod.\n\n");
            continue;
        }
        break;
    }
    return sor_valasztas;
}
int oszlop_valasztas(char nev[30]){
    int oszlop_valasztas;
    while (True){
        printf("\n%s valaszd ki melyik oszlopban szeretned az alakzatodat elhelyezni(1-3): ",nev);
        scanf("%d",&oszlop_valasztas);
        if(oszlop_valasztas<1 || oszlop_valasztas>3){
            printf("\nAz oszlop erteket 1-3 kozott kell megadnod.\n");
            continue;
        }
        break;
    }
    return oszlop_valasztas;
}
int szabad_hely_ellenorzese(int sor,int oszlop,char jatek_tabla[3][3]){
    if(jatek_tabla[sor-1][oszlop-1]!='_'){
        printf("\nA [%d,%d] kordinata foglalt.",sor,oszlop);
        return False;
    }
    return True;
}
int dontetlen_vizsgalata(char jatek_tabla[3][3]) {
    int mas_alakzatok_szama = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jatek_tabla[i][j] != '_') {
                mas_alakzatok_szama++;
            }
        }
    }
    if(mas_alakzatok_szama==9){
        return True;
    }
    return False;
}
void dontetlen_kiiratasa(){
    system("cls");
    system("COLOR 07");
    printf("A jatek dontetlennel fejezodott be.\n\n");
    printf("A jatek tabla ujra toltese");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    system("cls");
}
int nyertes_vizsgalata(char alakzat,char jatek_tabla[3][3]){
    int drb;
    for(int i=0;i<3;i++){
        drb=0;
        for(int j=0;j<3;j++){
            if(jatek_tabla[i][j]==alakzat){
                drb++;
            }else{
                break;
            }
        }
        if(drb==3){
            return True;
        }
    }
    for(int i=0;i<3;i++){
        drb=0;
        for(int j=0;j<3;j++){
            if(jatek_tabla[j][i]==alakzat){
                drb++;
            }else{
                break;
            }
        }
        if(drb==3){
            return True;
        }
    }
    if(jatek_tabla[0][0]==alakzat && jatek_tabla[1][1]==alakzat && jatek_tabla[2][2]==alakzat){
        return True;
    }
    if(jatek_tabla[0][2]==alakzat && jatek_tabla[1][1]==alakzat && jatek_tabla[2][0]==alakzat){
        return True;
    }
    return False;
}
void nyertes_kiiratasa(char nyertes[]){
    system("cls");
    system("COLOR 02");
    printf("%s nyert\n\n",nyertes);
}
void vesztes_kiiratasa(char vesztes[]){
    system("cls");
    system("COLOR 04");
    printf("%s vesztett\n\n",vesztes);
}
void jatek_befejezese(){
    system("cls");
    system("COLOR 07");
    printf("A jatekbol valo kilepeshez nyomjon meg barmilyen gombot...");
    getch();
}


