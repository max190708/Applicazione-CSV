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

void CaricaDati(NumerazioneCivica a[] , string file, int& n)
{
	ifstream fileInput(file); 
	string linea;
	string tempCap, tempSez, tempLat, tempLon;

	if (fileInput.is_open()) {
		// Salta la prima riga di intestazione
		getline(fileInput, linea); 
		n = 0;
		
		// Legge i campi separati da virgola fino a 1000 record
		while (n < 1000 && getline(fileInput, a[n].classeTopinimo, ',')){ 
			getline(fileInput, a[n].descrizioneToponimo, ',');
			getline(fileInput, a[n].numero, ',');
			getline(fileInput, a[n].subalterno, ',');
			getline(fileInput, tempCap, ',');
			getline(fileInput, tempSez, ',');
			getline(fileInput, tempLat, ',');
			getline(fileInput, tempLon, ',');
			getline(fileInput, a[n].location, '\n');

			// Converte le stringhe in numeri (se il campo non è vuoto)
			if (tempCap != "") a[n].cap = stoi(tempCap); else a[n].cap = 0;
			if (tempSez != "") a[n].sezioneistat = stoi(tempSez); else a[n].sezioneistat = 0;
			if (tempLat != "") a[n].lat = stod(tempLat); else a[n].lat = 0.0;
			if (tempLon != "") a[n].lon = stod(tempLon); else a[n].lon = 0.0;
			
			n++;
		}
		cout << "Caricati " << n << " record con successo.\n";
		fileInput.close(); 
	} else {
		cout << "Impossibile aprire il file";
	}
}
	
void visualizzazione(NumerazioneCivica a[] , int n)
{
	if(n == 0){
		cout << "Nessun dato presente in memoria.\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i].classeTopinimo << " " << a[i].descrizioneToponimo << " " << a[i].numero << " ";
		cout << a[i].subalterno << " - CAP: " << a[i].cap << " - Sez: " << a[i].sezioneistat << " ";
		cout << "- Lat: " << a[i].lat << " Lon: " << a[i].lon << "\n";
	}
}

void cercaVia(NumerazioneCivica a[] , int n)
{
	
}		

int main(){
NumerazioneCivica dati[1000];
int n = 0; // Contatore dei record effettivamente caricati

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
			CaricaDati(dati, "Comune_Bergamo_-_Numerazione_civica.csv", n);
		break;	
		
		case 2:
			visualizzazione(dati, n);
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
