//POP_2014_12_16_projekt_1_AIR
//Bloodshed Dev-C++ 4.9.9.2

//Test gita

#include <iostream>
#include <cctype>
using namespace std;

const int MAX_WIERSZY = 35;
const int MAX_KOLUMN = 35;

//w kazdym miejscu programu i- nr. wiersza, j- nr. kolumny, m- podana przez gracza ilosc wierszy, n- -||- kolumn,

//**********************************************************SPRWADZANIE WYGRANEJ
int skosA(int i, int j, int tab[][MAX_KOLUMN], int g, int s) {
    int znaleziono = 0;
    int p = 0;                                                  //gracz pierwszy
    int d = 0;                                                     //gracz drugi
    for (int k = 0; k < g; k++){
        if (tab[i][j] == 0){
            p = 0;
            d = 0;
        }
        else if (tab[i][j] == 1){
        p++;
        d = 0;
        }
        else if (tab[i][j] == 2){
        p = 0;
        d++;
        }
        j++;
        i--;
        if (znaleziono) break;
        if (p == s) return 1;
        else if (d == s) return 2;
    }
}

int skosB(int i, int j, int tab[][MAX_KOLUMN], int g, int s) {
    int znaleziono = 0;
    int p = 0;
    int d = 0;
    for (int k = 0; k < g; k++){
        if (tab[i][j] == 0){
            p = 0;
            d = 0;
        }
        else if (tab[i][j] == 1){
        p++;
        d = 0;
        }
        else if (tab[i][j] == 2){
        p = 0;
        d++;
        }
        j++;
        i++;
        if (znaleziono) break;
        if (p == s) return 1;
        else if (d == s) return 2;
    }
}

int wygrana (int m, int n, int tab[][MAX_KOLUMN], int s){
    int znaleziono = 0;

    //szukanie w pionie      (dla kazdej kolumny sprawdzam kazdy element w niej)
    for (int j = 0; j < n; j++){
        int p = 0;
        int d = 0;

        for (int i = m-1; i >= 0; i--){
            if (tab[i][j] == 0){
                p = 0;
                d = 0;
            }
            else if (tab[i][j] == 1){
                p++;
                d = 0;
            }
            else if (tab[i][j] == 2){
                p = 0;
                d++;
            }
            if (p == s) znaleziono = 1;
            else if (d == s) znaleziono = 2;
            if (znaleziono) break;
        }
    }
    //szukanie w poziomie           (dla kazdego wiersza spr kazdy jego element)
    if (znaleziono == 0){
    for (int i = m-1; i >= 0 ; i--){
        int p = 0;
        int d = 0;

        for ( int j = 0; j < n; j++){
            if (tab[i][j] == 0){
                p = 0;
                d = 0;
            }
            else if (tab[i][j] == 1){
                p++;
                d = 0;
            }
            else if (tab[i][j] == 2){
                p = 0;
                d++;
            }
            if (p==s) znaleziono = 1;
            else if (d==s) znaleziono = 2;
            if (znaleziono) break;
        }
    }
    }

    //szukanie po skosie
    //lewy gorny trojkat
    if (znaleziono == 0){
        int g;                       //ograniczenie sprawdzanej ilosci elementow
        if (m > n) g = n;
        else g = m;
        for (int i = m-1; i > 0; i--){
            int j =0;
            znaleziono = skosA(i, j, tab, g, s);
            if (znaleziono) break;
        }
    }

    //prawy dolny trojkat
    if (znaleziono == 0){
        int g;
        if (m > n) g = n;
        else g = m;
        for (int j = 0; j < n; j++){
            int i = m-1;
            znaleziono = skosA(i, j, tab, g, s);
            if (znaleziono) break;
        }
    }

    //lewy dolny trojkat
    if (znaleziono == 0){
        int g;
        if (m > n) g = n;
        else g = m;
        for (int i = 0; i < m-1; i++){
            int j =0;
            znaleziono = skosB(i, j, tab, g, s);
            if (znaleziono) break;
        }
    }

    //prawy gorny trojkat
    if (znaleziono == 0){
        int g;
        if (m > n) g = n;
        else g = m;
        for (int j = 0; j < n; j++){
            int i =0;
            znaleziono = skosB(i, j, tab, g, s);
            if (znaleziono) break;
        }
    }

    //sprawdzanie czy jest remis
    if (znaleziono == 0){
        for (int i = m-1; i >= 0; i--){
            for (int j = 0; j < n; j++){
                if (tab[i][j] != 0) znaleziono = 3;
                else {
                    znaleziono = 0;
                    break;
                }
            }
        }
    }

    if (znaleziono == 1) return 1;
    else if (znaleziono == 2) return 2;
    else if (znaleziono == 3) return 3;
    else return 0;
    }

//*************************************************************RYSOWANIE PLANSZY
void rysNazw(int n){                                                  //naglowek
    cout << " ";
    if (n > 9){
        for (int i = 0; i < 9; i++){
        cout << static_cast<char>(i+49);
        }
        for (int i = 0; i < n-9; i++){
        cout << static_cast<char>(i+97);
        }
    }
    else {
        for (int i = 0; i < n; i++){
        cout << static_cast<char>(i+49);
        }
    }
    cout << endl;
}

void rysLPozG(int n){                                     //gorna krawedz tabeli
    cout << static_cast<char>(0xC9);
    for (int i = 0; i < n; i++){
    cout <<  static_cast<char>(0xCD);
    }
    cout << static_cast<char>(0xBB);
    cout << endl;
}

void rysLPozD(int n){                                     //dolna krawedz tabeli
    cout << static_cast<char>(0xC8);
    for (int i = 0; i < n; i++){
    cout <<  static_cast<char>(0xCD);
    }
    cout << static_cast<char>(0xBC);
    cout << endl;
}

void rysWier(int m, int n, int tab[][MAX_KOLUMN]){ //zawartosc tabeli + boczne krawedzie
    for (int i = 0; i < m; i++){
        cout << static_cast<char>(0xBA);
        for (int j = 0; j < n; j++){
            if (tab[i][j] == 2) cout << "X";
            else if (tab[i][j] == 1) cout << "O";
            else cout << " ";
        }
        cout << static_cast<char>(0xBA) << endl;
    }
}

void rysTab(int m, int n, int tab[][MAX_KOLUMN]){
    rysNazw(n);
    rysLPozG(n);
    rysWier(m, n, tab);
    rysLPozD(n);
}
//*************************************************************************POMOC
void pomoc (){
    cout << endl << "Instrukcja gry." << endl
         << "Gra w kolko i krzyzyk przeznaczona jest dla 2 graczy. Gracze na zmiane wpisuja" << endl
         << "do wybranej KOLUMNY przypisane im elementy, ktorymi sa 'O' i 'X'. Elementy" << endl
         << "pojawiaja sie w pierwszym wolnym w danej kolumnie wierszu, liczac od dolu." << endl
         << "Gre wygrywa osoba ktora jako pierwsz umiesci pod rzad pionowo, poziomo, " << endl
         << "lub po skosie wymagana ilosc elementow. Gra konczy sie remisem gdy w tabeli " << endl
         << "zostana zapelnione wszystkie wolne miejsca." << endl
         << "Aby natychmiast opuscic gre, w dowolnym momencie nacisnij '0'." << endl << endl;
}
//*****************************************GLOWNA FUNKCJA OD WSTAWIANIA ELEMENTU
int wstaw(int m, int n, int tab[][MAX_KOLUMN], int licznik, int *pom){
    char s[80];
    int j = 0;
    int i = 0;
    int k = m-1;                       // do wpisywania elementu od dolu tablicy
    int q;                                   //wpisuje sie do tego numer kolumny
    bool blad = false;          //dotyczy nie istnienia kolumny o podanej nazwie
    char p;
    rysTab(m, n, tab);
    cout << endl;

    cout << "Kolejka gracza ";
    if (licznik%2 == 0) cout << "pierwszego.";
    else cout << "drugiego.";
    cout << endl;

    cin.sync();

    cout << "W ktora kolumne wstawic ";
    if (licznik%2 == 0) cout << "O?" << endl;
    else cout << "X?" << endl;

    cin.getline(s, 80);

    while (s[1] != 0){
        cin.sync();
        cout << endl <<"Podano wiecej niz jeden znak lub nie podano zadnego." << endl;
        cout << endl;
        rysTab(m, n, tab);

        cout << "Kolejka gracza ";
        if (licznik%2 == 0) cout << "pierwszego.";
        else cout << "drugiego.";
        cout << endl;

        cin.sync();

        cout << "W ktora kolumne wstawic ";
        if (licznik%2 == 0) cout << "O?" << endl;
        else cout << "X?" << endl;

        cin.getline(s, 80);
    }

    p = s[0];

    if ((q = (p-'?')) == 0) {                                    //spr czy pomoc
        pomoc();
        return 1;
    }
    else {
        if ((q = (p-'0')) == 0) {                              //spr czy wyjscie
            return 2;
        }
        else {
            if ((q = (p-'0')) < 10){
                if (q < n+1) j = q-1;                            //spr czy cyfra
                else {
                    cout << endl << "Kolumna o podanym adresie nie istnieje" << endl;
                    blad = true;
                }
            }
            else if ((q = (p-'a')) < (n-9)) j = q+9;            //spr czy litera
            else {
                cout << endl << "Kolumna o podanym adresie nie istnieje" << endl;
                blad = true;
            }

            if (!blad){
                if (pom[j] < m){
                    while (tab[k][j] != 0) k--;
                    i = k;
                    pom[j]++;
                    if (licznik%2 == 0) tab[i][j] = 1;
                    else tab[i][j] = 2;
                    cout << endl << endl;
                    return 0;
                }
                else {
                    cout << endl << "Brak miejsca w podanej kolumnie.\n";
                    return 1;
                }
            }
            else return 1;
        }
    }
}
//************************************************************GLOWNA FYNKCJA GRY
int gra (int m, int n, int tab[][MAX_KOLUMN], int s){

    int licznik = 0;
    bool gramydalej = true;
    int j, i, k, g;                         // do g wipsywana jest wartosc wstaw

    int *pom;
    pom = new int [n];               //pomaga zliczyc ilosc elementow w kolumnie
    for (int p = 0; p < n; p++){
        pom[p] = 0;
    }

    while (gramydalej){
        g = wstaw(m, n, tab, licznik, pom);
        if (g == 2){
            gramydalej = false;
            return 1;
        }
        else {
            if (g == 1) licznik--;

            licznik ++;
            k = m-1;

            int wyg = wygrana(m, n, tab, s);

            if (wyg == 1){
                gramydalej = false;
                cout << "WYGRAL GRACZ PIERWSZY! GRATULACJE!" << endl;
            }
            else if (wyg == 2){
                gramydalej = false;
                cout << "WYGRAL GRACZ DRUGI! GRATULACJE!" << endl;
            }
            else if (wyg == 3){
                gramydalej = false;
                cout << "REMIS. Tablica jest juz pelna." << endl;
            }
        cout << endl;
        }
    }
    if (g != 2) rysTab(m, n, tab);

    delete[] pom;
    pom = NULL;
}
//**************************************************************************MAIN
int main(){

    int tab[MAX_WIERSZY][MAX_KOLUMN];
    int m, n, s, wyjscie;

    cout << "Witam w grze w kolko i krzyzyk." << endl;
    cout << "Podaj wymiary tablicy:" << endl;

    cout << "wierszy: "; cin >> m;
    while ((m < 3) or (m > MAX_WIERSZY)){
        cout << "Ilosc wierszy nie moze byc mniejsza niz 3 i nie moze przekroczyc 35.\nPodaj prawidlowa liczbe wierszy: ";
        cin >> m;
    }

    cout << "kolumn: "; cin >> n;
    while ((n < 3) or (n > MAX_KOLUMN)){
        cout << "Ilosc kolumn nie moze byc mniejsza niz 3 i nie moze przekroczyc 35.\nPodaj prawidlowa liczbe kolumn: ";
        cin >> n;
    }

    cout << "Podaj ile elementow gwarantuje wygrana:" << endl;
    cin >> s;
    while ((s < 3) or (s > m) or (s > n)){
        cout << "Ilosc szukanych elementow nie moze byc mniejsza niz 3 i nie moze" << endl
        << "przekroczyc zadnego z wymiarow tablicy.\nPodaj prawidlowa liczbe szukanych elementow: ";
        cin >> s;
    }

    cout << "Aby wyswietlic pomoc w dowolnym momencie nacisnij '?',\na aby natychmiast wyjsc z gry '0' [zero]" << endl << endl;

    //neutralne wypelnianie tablicy zerami
    for (int i = 0; i < MAX_WIERSZY; i++){
        for (int j = 0; j < MAX_KOLUMN; j++){
            tab[i][j] = 0;
        }
    }

    wyjscie = gra(m, n, tab, s);

    //OPCJA NOWEJ GRY PO SKONCZENIU POPRZEDNIEJ
    if (wyjscie != 1){                   //gdy wychodzi sie zerem pomija pytanie
        cout << endl << "Chcesz zagrac jeszcze raz? (jesli tak nacisnij '1')" << endl;
        int t;
        cin >> t; cout << endl;
        if (t == 1) main();
    }

    return 0;
}
