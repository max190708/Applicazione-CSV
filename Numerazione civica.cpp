#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct NumerazioneCivica{
string 	classeTopinimo;
string descrizioneToponimo;
string numero;
string subalterno;
int cap;
int sezioneistat;
double lat;
double lon;
string location;
};	

struct location{
double x;
double y;
};

/*Crea un programma in c++ che permetta di gestire i dati presenti nel file allegato.

Il programma dovrà essere strutturato con un menù che permetta di selezionare le seguenti funzionalità:
caricare i primi 1000 record presenti nel file,  in una struttura in memoria;
visualizzare i dati presenti nella struttura in memoria.
*/

void CaricaDati(NumerazioneCivica a[] , string file)
{
	 ifstream fileInput("testo.txt"); 
    string linea;

    if (fileInput.is_open()) {
        while (fileInput>>linea){ 
            cout << linea << '\n';
        }
        fileInput.close(); 
    } else {
        cout << "Impossibile aprire il file";
    }
}
	
void visualizzazione(NumerazioneCivica a[] , string file)
{
	
}
void cercaVia(NumerazioneCivica a[] , string file)
{
	
}		
int main(){
NumerazioneCivica dati[1500];

int opzione;
		bool a;
		do{
		cout<<endl<<"MENU :"<<endl;
		cout<<"1 --- Carica i dati"<<endl;
		cout<<"2 --- Visualizzazione"<<endl;
		cout<<"0 --- Esci"<<endl;
		cout<<"Scegli l'opzione :"<<endl;
		cin>>opzione;
		switch(opzione)
		{
		case 1:
				
		break;	
		
		case 2:
	
		break;	
	
		case 0:
		cout<<"Uscita dal programma.";
		return 0;
		
		default:
		cout<<"Opzione non valida."<<endl;
			}
		}while(opzione!=0);
	
	
	
	
	return 0;
}
