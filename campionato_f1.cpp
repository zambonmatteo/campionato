//https://www.cplusplus.com/reference/cstring/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct{
	char nome[20];
	int puntiTOT;
	int annofondazione;
}Scuderia;

typedef struct{
	char nome[20];
	char cognome[20];
	int punti;
	Scuderia* squadra;
}Pilota;

typedef struct{
	char nome[60];
	Pilota* primo;
	Pilota* secondo;
	Pilota* terzo;
}Gara;
////////////funzioni generali
int lunghezza(char a[])
{
	int i=0;
	do{
		i++;
	}while(a[i]!='\0');
	
	return i;	
}

void passaggio(char a[], char b[])
{
	int i=0;
	
	do{
		b[i] = a[i];
		i++;
	}while(a[i]!='\0');
	b[i] = '\0';
}

int confronta(char a[], char b[])
{
     return strcmp(a,b);
}
////////////funzioni solo per scuderia
void inseriscinomescuderia(char a[],Scuderia tutti[],int pos)
{
	char temp[500];
	
	cout <<"Inserisci il nome della scuderia: ";
	cin >>temp;
	while(lunghezza(temp)>=60)
	{
		cout <<"Nome scuderia non valido; reinserisci il nome della scuderia: ";
		cin >>temp;
	}
	passaggio(temp, a);
	for(int j=0;j<20;j++)
	{			
		while(confronta(a,tutti[j].nome)==0&&pos!=j)
		{
		 	cout <<"Nome scuderia inserito gia' presente, reinseriscilo: ";
		 	cin >>temp;
		 	while(lunghezza(temp)>=60)
			{
				cout <<"Nome scuderia non valido; reinserisci il nome della scuderia: ";
				cin >>temp;
			}
			passaggio(temp, a);
		}
	}
}

int inseriscianno()
{
	int j;
	cout <<"Inserisci l'anno di formazione della scuderia: ";
	cin >>j;
	while(j<1900||j>2021)
	{
		cout <<"Anno nascita scuderia non valido; reinscerisci l'anno di creazione della scuderia: ";
		cin >>j;
	}
	return j;
}

void inputscuderia(Scuderia v[])
{
	int i=0;
	cout <<"- Inserimento dati scuderie -\n";
	for(int j=1;i<10;i++,j++)
	{
		cout <<"Scuderia numero "<<j<<"\n";
		inseriscinomescuderia(v[i].nome,v,i);
		v[i].annofondazione = inseriscianno();	
		v[i].puntiTOT=0;
	}
}
/////////////funzioni solo pilota
void inputpilota(Pilota v[]) 
{
	char temp[1000];
	int contatore=1,scelta;
	for(int i=0;i<20;i++)
	{
		cout<<" \n Insersci il pilota "<<contatore<<" :\n NOME = ";
		cin>>temp;
		while(lunghezza(temp)>20)
		{
			cout<<"\n hai inserito un nome troppo lungo, reinserisci  :";
			cin>>temp;
		}
		passaggio(temp,v[i].nome);
		bool uguale=true;
		for(int j=0;j<20;j++)
		{			
			 while(confronta(v[i].nome,v[j].nome)==0&&i!=j&&uguale)
			 {
			 	cout <<"Nome inserito gia' presente, vuoi cambiarlo? Inserire 0 o meno per cambiarlo: ";
			 	cin >>scelta;
			 	if(scelta <=0)
			 	{
			 		cout <<"Inserisci il nome del pilota: ";
			 		cin>>temp;
					while(lunghezza(temp)>20)
					{
						cout<<"\n hai inserito un nome troppo lungo, reinserisci  :";
						cin>>temp;
					}
					passaggio(temp,v[i].nome);
				}else{
					uguale = false;
				}
			 }
		}
		cout<<"\n COGNOME =";
		cin>>temp;
		while(lunghezza(temp)>20)
		{
			cout<<"\n hai inserito un cognome troppo lungo, reinserisci  :";
			cin>>temp;
		}
		passaggio(temp,v[i].cognome);
		uguale=true;
		for(int j=0;j<20;j++)
		{			
			 while(confronta(v[i].cognome,v[j].cognome)==0&&i!=j&&uguale)
			 {
			 	cout <<"Cognome inserito gia' presente, vuoi cambiarlo? Inserire 0 o meno per cambiarlo: ";
			 	cin >>scelta;
			 	if(scelta <=0)
			 	{
			 		cout <<"Inserisci il cognome del pilota: ";
			 		cin>>temp;
					while(lunghezza(temp)>20)
					{
						cout<<"\n hai inserito un cognome troppo lungo, reinserisci:";
						cin>>temp;
					}
					passaggio(temp,v[i].cognome);
				}else{
					uguale = false;
				}
			 }
		}
		contatore++;
	}	
}	

void menuscuderie(Scuderia squadra[])
{
	cout <<"- MENU' SCUDERIE -";
	for(int j=0;j<10;j++)
	{
		cout<<j<<"- "<<squadra[j].nome<<"\n";
	}		
}

void inputscuderia(Pilota v[], Scuderia k[])
{
	int x;
	
	cout<<"----- ASSEGNAZIONE SCUDERIA ------ \n";
	for(int j=0;j<20;j++)
	{
		menuscuderie(k);
		cout<<" \n Nome pilota = "<<v[j].nome<<" "<<v[j].cognome;
		cout<<" \n in che scuderia corre? :  ";
	    cin>>x;
	    while(x<0||x>9)
	    {
	    	cout<<"Scuderia insesistente, reinserisci scuderia: ";
		}
	    switch(x)
	    {
	     	case 0:
	     		break;
	     	case 1:
	     		break;
	     	case 2:
	     		break;
	     	case 3:
	     		break;
	    	case 4:
	     		break;
	     	case 5:
	     		break;
	     	case 6:
	     		break;
	     	case 7:
	     		break;
	     	case 8:
	     		break;
	     	case 9:
	     		break;
		}
		system("cls");
	}
}

int main()
{
	int i;
	Scuderia squadre[10];
	Pilota pilota[20];
	//input scuderia
	inputscuderia(squadre);
	system("cls");
	//input pilota
	inputpilota(pilota);
	system("cls");
	//destinare il pilota alla scuderia
	inputscuderia(pilota, squadre);
	//array dinamico delle gare
	
	//una volta finite le gare si chiede cosa si vuole vedere
}
