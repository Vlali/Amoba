void jatek_kezdese();
void jatek_tabla_kiiratasa(char jatek_tabla[3][3]);
void jatekos_udvozlese(char nev[30]);
char elso_jatekos_alakzata(char elso_jatekos_neve[30]);
char masodik_jatekos_alakzata(char masodik_jatekos_neve[30],char elso_jatekos_alakzata);
int elso_jatekos_szinv(char elso_jatekos_neve[30]);
int masodik_jatekos_szinv(char masodik_jatekos_neve[30],int elso_jatekos_szin);
void szin_atallitasa(int szinkod);
int sor_valasztasa(char nev[30],char alakzat);
int oszlop_valasztas(char nev[30]);
int szabad_hely_ellenorzese(int sor,int oszlop,char jatek_tabla[3][3]);
int dontetlen_vizsgalata(char jatek_tabla[3][3]);
void dontetlen_kiiratasa();
int nyertes_vizsgalata(char alakzat,char jatek_tabla[3][3]);
void nyertes_kiiratasa(char nyertes[]);
void vesztes_kiiratasa(char vesztes[]);
void jatek_befejezese();