#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct monitor{
    char *denumirea_firmei;
    int nr_de_culori_bit;
    float dimensiunea_inch;
    int rezolutie_x;
    int rezolutie_y;
};

void setValues(monitor *str, char *denumirea_firmei, int nr_de_culori_bit, float dimensiunea_inch, int rezolutie_x, int rezolutie_y)
{
    str->denumirea_firmei = new char[strlen(denumirea_firmei) +1];
    strcpy(str->denumirea_firmei,denumirea_firmei);
    str->nr_de_culori_bit = nr_de_culori_bit;
    str->dimensiunea_inch = dimensiunea_inch;
    str->rezolutie_x = rezolutie_x;
    str->rezolutie_y = rezolutie_y;
}
void sortStructByName(monitor *monitor1, monitor *monitor2)
{
    if(monitor1->denumirea_firmei < monitor2->denumirea_firmei)
    {
        monitor *temp = monitor1;
        monitor1 = monitor2;
        monitor2 = temp;
    }
}

void comparare(monitor * monitor1, monitor * monitor2)  //index_comp indexarea compararei
{
    int index_comp;
    cout << "1 || Compararea nr. de culori\n";
    cout << "2 || Compararea dimensiunea inch\n";
    cout << "3 || Compararea rezolutie\n";
    cout << "Alegeti compararea potrivita: ";
    cin >> index_comp;
    switch(index_comp)
    {
        case 1: // nr_de_culori
            if(monitor1->nr_de_culori_bit == monitor2->nr_de_culori_bit)
                cout << "Monitoarele au un numar de culori in bit egal";
            else
            if(monitor1->nr_de_culori_bit > monitor2->nr_de_culori_bit)
                cout << "Primul monitori are numarul de culori in bit mai mare";
            else
                cout << "Al doilea monitor are numarul de culori in bit mai mare";
            break;
        case 2: // dimensiunea_inch
            if(monitor1->dimensiunea_inch == monitor2->dimensiunea_inch)
                cout << "Monitoarele au dimensiunea in inch egala";
            else
            if(monitor1->dimensiunea_inch > monitor2->dimensiunea_inch)
                cout << "Primul monitori are dimensiunea in inch mai mare";
            else
                cout << "Al doilea monitor are dimensiunea in inch mai mare";
            break;
        case 3: // rezolutie
            if(monitor1->rezolutie_x == monitor2->rezolutie_x || monitor1->rezolutie_y == monitor2->rezolutie_y)
                cout << "Monitoarele au rezolutie egala";
            else
            if(monitor1->rezolutie_x > monitor2->rezolutie_x)
                cout << "Primul monitori are rezolutia mai mare";
            else
                cout << "Al doilea monitor are rezolutia mai mare";
            break;
    }
}
void afisare(monitor * catalog)
{
    cout << "Denumirea Firmei: || " << catalog->denumirea_firmei << " || Nr de culori bit || " << catalog->nr_de_culori_bit << " || Dimensiunea inch: || " << catalog->dimensiunea_inch << " || Rezolutie: || " << catalog->rezolutie_x << "x" << catalog->rezolutie_y << "\n";
}
void search_monitor(monitor * catalog)
{
    int index_searh, temp, temp_2;
    cout << "1 || Cautarea dupa numarul de culori\n";
    cout << "2 || Cautarea dupa dimensiunea inch\n";
    cout << "3 || Cautarea dupa rezolutie\n";
    cout << "Alegeti cautarea potrivita: ";
    cin >> index_searh;
    switch (index_searh)
    {
        case 1:
            cout << "Inserati numarul de culori: ";
            cin >> temp;
            for (int i = 0; catalog[i].nr_de_culori_bit > 0; i++)
                if ( temp == catalog[i].nr_de_culori_bit)
                    afisare(catalog + i);
            break;
        case 2:
            cout << "Inserati dimensiunea  (inch): ";
            cin >> temp;
            for (int i = 0; catalog[i].nr_de_culori_bit > 0; i++)
                if ( temp == catalog[i].dimensiunea_inch)
                    afisare(catalog + i);
            break;
        case 3:
            cout << "Dati rezolutia pentru x cit si y: ";
            cin >> temp;
            cin >> temp_2;
            for (int i = 0; catalog[i].nr_de_culori_bit > 0; i++)
                if ( temp == catalog[i].rezolutie_x || temp_2 == catalog[i].rezolutie_y)
                    afisare(catalog + i);
            break;
    }
}

void freeMem(monitor* sptr)
{
    if (sptr->denumirea_firmei) delete[] sptr->denumirea_firmei;
    sptr->denumirea_firmei = NULL;
    sptr->nr_de_culori_bit = 0;
    sptr->dimensiunea_inch = 0;
    sptr->rezolutie_x = 0;
    sptr->rezolutie_y = 0;
}

int main()
{
    int index_comp, cautare;
    monitor monitor1, monitor2, monitor3 , catalog;
    setValues(&monitor1, (char*)"Asus", 6, 26, 1600, 800);
    setValues(&monitor2, (char*)"Lenovo", 8, 28, 1420, 600);
    setValues(&monitor3, (char*)"HPOmen", 16, 27, 1920, 1080);
    monitor monitor[2];
    monitor[0] = monitor1;
    monitor[1] = monitor2;
    monitor[2] = monitor3;
    cout << "Monitoarele:\n";
    cout << "Monitor || 1 ||" << "Denumirea Firmei: || " << monitor[0].denumirea_firmei << " || Nr de culori bit || " << monitor[0].nr_de_culori_bit << " || Dimensiunea inch: || " << monitor[0].dimensiunea_inch << " || Rezolutie: || " << monitor[0].rezolutie_x << "x" << monitor[0].rezolutie_y << "\n";
    cout << "Monitor || 2 ||" << "Denumirea Firmei: || " << monitor[1].denumirea_firmei << " || Nr de culori bit || " << monitor[1].nr_de_culori_bit << " || Dimensiunea inch: || " << monitor[1].dimensiunea_inch << " || Rezolutie: || " << monitor[1].rezolutie_x << "x" << monitor[1].rezolutie_y << "\n";
    cout << "Monitor || 3 ||" << "Denumirea Firmei: || " << monitor[2].denumirea_firmei << " || Nr de culori bit || " << monitor[2].nr_de_culori_bit << " || Dimensiunea inch: || " << monitor[2].dimensiunea_inch << " || Rezolutie: || " << monitor[2].rezolutie_x << "x" << monitor[2].rezolutie_y << "\n";
    comparare(&monitor[0], &monitor[1]);
    cout << "\nEfectuarea cautari? || 1 : Da || 2 : Nu\n";
    cin >> cautare;
    if (cautare == 1)
        search_monitor(monitor);
    freeMem(&monitor1);
    freeMem(&monitor2);
}

