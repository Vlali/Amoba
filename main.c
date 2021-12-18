#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fuggvenyek.h"

enum bool{False,True};

int main() {
    char elso_jatekos_neve[30],elso_jatekos_alakz;
    int elso_jatekos_szin;
    char masodik_jatekos_neve[30],masodik_jatekos_alakz;
    int masodik_jatekos_szin;
    int feher=6,sor,oszlop,nyertes=False;
    char jatek_tabla[3][3]={
            {'_','_','_'},
            {'_','_','_'},
            {'_','_','_'}
    };
    jatek_kezdese();
    printf("Kerem az elso jatekos nevet: ");
    scanf("%s",&elso_jatekos_neve);
    sleep(0.20);
    jatekos_udvozlese(elso_jatekos_neve);
    sleep(2);
    system("cls");
    printf("Kerem a masodik jatekos nevet: ");
    scanf("%s",&masodik_jatekos_neve);
    sleep(0.20);
    jatekos_udvozlese(masodik_jatekos_neve);
    sleep(2);
    system("cls");
    elso_jatekos_alakz=elso_jatekos_alakzata(elso_jatekos_neve);
    sleep(2);
    system("cls");
    masodik_jatekos_alakz=masodik_jatekos_alakzata(masodik_jatekos_neve,elso_jatekos_alakz);
    sleep(2);
    system("cls");
    elso_jatekos_szin=elso_jatekos_szinv(elso_jatekos_neve);
    szin_atallitasa(elso_jatekos_szin);
    sleep(2);
    system("cls");
    szin_atallitasa(feher);
    masodik_jatekos_szin=masodik_jatekos_szinv(masodik_jatekos_neve,elso_jatekos_szin);
    szin_atallitasa(masodik_jatekos_szin);
    sleep(2);
    while(True){
        while(True){
            system("cls");
            szin_atallitasa(elso_jatekos_szin);
            jatek_tabla_kiiratasa(jatek_tabla);
            sor=sor_valasztasa(elso_jatekos_neve,elso_jatekos_alakz);
            oszlop=oszlop_valasztas(elso_jatekos_neve);
            if(szabad_hely_ellenorzese(sor,oszlop,jatek_tabla)){
                jatek_tabla[sor-1][oszlop-1]=elso_jatekos_alakz;
                sleep(0.5);
                printf("\n");
                jatek_tabla_kiiratasa(jatek_tabla);
            }else{
                sleep(2);
                continue;
            }
            if(nyertes_vizsgalata(elso_jatekos_alakz,jatek_tabla)){
                nyertes=True;
            }
            sleep(2);
            break;
        }
        if(nyertes){
            nyertes_kiiratasa(elso_jatekos_neve);
            jatek_tabla_kiiratasa(jatek_tabla);
            sleep(2);
            vesztes_kiiratasa(masodik_jatekos_neve);
            jatek_tabla_kiiratasa(jatek_tabla);
            sleep(2);
            break;
        }
        if(dontetlen_vizsgalata(jatek_tabla)){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    jatek_tabla[i][j]='_';
                }
            }
            dontetlen_kiiratasa();
            continue;
        }
        while(True){
            system("cls");
            szin_atallitasa(masodik_jatekos_szin);
            jatek_tabla_kiiratasa(jatek_tabla);
            sor=sor_valasztasa(masodik_jatekos_neve,masodik_jatekos_alakz);
            oszlop=oszlop_valasztas(masodik_jatekos_neve);
            if(szabad_hely_ellenorzese(sor,oszlop,jatek_tabla)){
                jatek_tabla[sor-1][oszlop-1]=masodik_jatekos_alakz;
                sleep(0.5);
                printf("\n");
                jatek_tabla_kiiratasa(jatek_tabla);
            }else{
                sleep(2);
                continue;
            }
            if(nyertes_vizsgalata(masodik_jatekos_alakz,jatek_tabla)){
                nyertes=True;
            }
            sleep(2);
            break;

        }
        if(nyertes){
            nyertes_kiiratasa(masodik_jatekos_neve);
            jatek_tabla_kiiratasa(jatek_tabla);
            sleep(2);
            vesztes_kiiratasa(elso_jatekos_neve);
            jatek_tabla_kiiratasa(jatek_tabla);
            sleep(2);
            break;
        }
        if(dontetlen_vizsgalata(jatek_tabla)){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    jatek_tabla[i][j]='_';
                }
            }
            dontetlen_kiiratasa();
            continue;
        }
    }
    jatek_befejezese();
}