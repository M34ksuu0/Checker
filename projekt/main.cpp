#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class checker
{
public:
    void wczytajDoPliku(vector<string>& jeden, vector<string>& dwa)
    {
        fstream plik;
        string tekst;
        bool ktoryPlik=0;
        plik.open("a.txt", ios::in);
        while(getline(plik, tekst))
        {
            if(tekst=="drugi")
            {
                ktoryPlik=1;
                continue;
            }
            if(ktoryPlik==0)
            {
                jeden.push_back(tekst);
            }
            else
            {
                dwa.push_back(tekst);
            }
        }
        plik.close();
    }
    void check(vector<string>& jeden, vector<string>& dwa, vector<string>& wspolny, vector<string>& tylkoJeden, vector<string>& tylkoDwa)
    {
        fstream plik;
        bool znaleziony;
        for (int i=0; i<jeden.size(); i++)
        {
            znaleziony=false;
            for (int j=0; j<dwa.size(); j++)
            {
                if(jeden[i]==dwa[j])
                {
                    znaleziony=true;
                    break;
                }
            }
            if(znaleziony)
            {
                bool istnieje=false;
                for(int k=0; k<wspolny.size(); k++)
                {
                    if(wspolny[k] == jeden[i])
                    {
                        istnieje = true;
                        break;
                    }
                }
                if(!istnieje)
                {
                    wspolny.push_back(jeden[i]);
                }
            }
            else
            {
                tylkoJeden.push_back(jeden[i]);
            }
        }
        for(int i=0; i<dwa.size(); i++)
        {
            znaleziony=false;
            for(int j=0; j<jeden.size(); j++)
            {
                if (dwa[i]==jeden[j])
                {
                    znaleziony=true;
                    break;
                }
            }
            if(!znaleziony)
            {
                tylkoDwa.push_back(dwa[i]);
            }
        }
    }
    void wypisz(vector<string>& wspolny, vector<string>& tylkoJeden, vector<string>& tylkoDwa)
    {
        ofstream plik;
        plik.open("raport.txt", ios::out);
        plik<<"RAPORT\n";
        plik<<"Wspolne: \n";
        for(int i=0; i<wspolny.size(); i++)
        {
            plik<<wspolny[i]<<endl;
        }
        plik<<"Tylko w pierwszym: "<<endl;
        for(int i=0; i<tylkoJeden.size(); i++)
        {
            plik<<tylkoJeden[i]<<endl;
        }
        plik<<"Tylko w drugim: "<<endl;
        for(int i=0; i<tylkoDwa.size(); i++)
        {
            plik<<tylkoDwa[i]<<endl;
        }
        plik.close();
    }
};

int main()
{
    vector<string> jeden;
    vector<string> dwa;
    vector<string> wspolny;
    vector<string> tylkoJeden;
    vector<string> tylkoDwa;

    checker sprawdz;
    sprawdz.wczytajDoPliku(jeden, dwa);
    sprawdz.check(jeden, dwa, wspolny, tylkoJeden, tylkoDwa);
    sprawdz.wypisz(wspolny, tylkoJeden, tylkoDwa);

    return 0;
}
