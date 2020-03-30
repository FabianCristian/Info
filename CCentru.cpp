#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
ifstream f("Filme.txt");
ifstream g("clienti.txt");
class Centru
{
public:
    static int numar_filme;
};
int Centru::numar_filme=0;
class Film:protected Centru
{
    string nume_film;
    bool inchiriat;
public:
    Film()
    {
        getline(f,nume_film,';');
        f>>inchiriat;
        f.ignore();
        numar_filme++;
    }
    string get_nume_film()
    {
        return nume_film;
    }
    bool get_inchiriat()
    {
        return inchiriat;
    }
    void set_inchiriat(bool a)
    {
        inchiriat=a;
    }
}movies[6];
class Client:public Film
{
    string nume_client,parola;
public:
    void set_nume_client(string x)
    {
        nume_client=x;
    }
    void set_parola(string x)
    {
        parola=x;
    }
    string get_parola()
    {
        return parola;
    }
    string get_nume_client()
    {
        return nume_client;
    }
    void inchiriere_film(string );
    void returnare_film(string );
    void afisare_filme();
    void cautare_film(string );
};
void Client::inchiriere_film(string x)
{
    for(int i=0;i<numar_filme;i++)
    {
        if(movies[i].get_nume_film()==x)
            if(movies[i].get_inchiriat()==false)
            {
                movies[i].set_inchiriat(true);
                cout<<"Tocmai ati inchiriat filmul: "<<x<<endl;
                return;
            }
            else
            {
                cout<<"Filmul "<<x<<" a fost inchiriat deja!"<<endl;
                return;
            }
    }
    cout<<"Filmul nu exista!"<<endl;
}
void Client::returnare_film(string x)    {
    for(int i=0;i<numar_filme-2;i++)
    {
        if(movies[i].get_nume_film()==x)
            if(movies[i].get_inchiriat()==true)
            {
                movies[i].set_inchiriat(false);
                cout<<"Tocmai ati returnat filmul: "<<x<<endl;
                return;
            }
            else
            {
                cout<<"Filmul "<<x<<" a fost returnat deja!"<<endl;
                return;
            }
    }
    cout<<"Filmul nu exista!"<<endl;
}
void Client::afisare_filme()
{
    for(int i=0;i<numar_filme-5;i++)
    {
        cout<<i+1<<". "<<movies[i].get_nume_film()<<" ";
        if(movies[i].get_inchiriat()==true)
                cout<<"-Inchiriat"<<endl;
            else
                cout<<"-Disponibil"<<endl;
    }
}
void Client::cautare_film(string x)
{
    for(int i=0;i<numar_filme-2;i++)
    {
        if(movies[i].get_nume_film()==x)
        {
            cout<<x;
            if(movies[i].get_inchiriat()==true)
                cout<<"-Inchiriat"<<endl;
            else
                cout<<"-Disponibil"<<endl;
            return;
        }
    }
    cout<<"Nu avem filmul cautat!"<<endl;
}
int main()
{
    string str,parola(""),cont(""),username,x,y,z;
    bool ok=0;
    Client Persoana[5];
    for(int i=0;i<5;i++)
    {
        getline(g,str,';');
        Persoana[i].set_nume_client(str);
        getline(g,str);
        Persoana[i].set_parola(str);
    }
    cout<<"              ------------------------------------------------------------------------              ";
    cout<<"                |        Bine ati venit la Centrul de inchiriere filme VISION !        |"<<endl;
    cout<<"              ";
    cout<<"------------------------------------------------------------------------"<<endl<<endl;
    logare:cout<<"      Introduceti username pentru a va identifica: ";
    getline(cin,username);
    int i;
     for(i=0;i<5;i++)
        if(Persoana[i].get_nume_client()==username)
        {
            cont=Persoana[i].get_nume_client();
            cout<<"      Introduceti parola de identificare: ";
            getline(cin,parola);
                if(Persoana[i].get_parola()==parola)
                {
                    cont=Persoana[i].get_nume_client();
                    ok=1;
                    goto bine;
                }
        }
        if(ok==0)
        {
            cout<<"Nu exista asemenea cont. Doriti sa incercati din nou? (d/n) "<<endl;
            dn1:switch(getch())
            {
                case 'd':goto logare;
                case 'n':
                    cout<<endl<<"              ----------------------------------              \n              |          La revedere!          |\n              ----------------------------------              ";exit(0);
                default:cout<<"Introduceti d pentru Da si n pentru Nu"<<endl;
                goto dn1;
            }
        }
    bine:cout<<"Bine ati venit "<<cont<<" !"<<endl;
    act:cout<<endl;
    cout<<"      Apasati cifra corespunzatoare actiunii pe care doriti sa o efectuati:"<<endl;
    cout<<"      1 - Afiseaza lista cu filme."<<endl;
    cout<<"      2 - Inchiriaza un film. "<<endl;
    cout<<"      3 - Returneaza un film. "<<endl;
    cout<<"      4 - Cauta un film. "<<endl;
   switch(getch())
   {
      case '1': Persoana[i].afisare_filme();
      d2:cout<<"Doriti sa faceti si alta actiune? (d/n)";
      switch(getch())
            {
                case 'd':goto act;
                case 'n':cout<<endl<<"              ----------------------------------              \n              |          La revedere!          |\n              ----------------------------------              ";
                exit(0);
                default:cout<<"Introduceti d pentru Da si n pentru Nu"<<endl;
                goto d2;
            }
      case '2' :
      cout<<"Introduceti filmul dorit pentru inchiriere: ";
      getline(cin,x);
      Persoana[i].inchiriere_film(x);
      goto d2;
      case '3' :
      cout<<"Introduceti filmul dorit pentru returnare: ";
      getline(cin,y);
      Persoana[i].returnare_film(y);
      goto d2;
      case '4' :
      cout<<"Introduceti filmul dorit pentru cautare: ";
      getline(cin,z);
      Persoana[i].cautare_film(z);
      cout<<endl;
      goto d2;
      default: cout<<"Introduceti alta cifra!!";
      goto d2;
   }
    return 0;
}
