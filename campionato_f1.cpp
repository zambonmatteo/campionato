//https://www.cplusplus.com/reference/cstring/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

const int sizenome=30; //nome di tutto: scuderia, gara e piloti(nome e cognome)

typedef struct{
	char nome[sizenome];
	int puntiTOT;
	int annofondazione;
	int numeropiloti;
}Scuderia;

typedef struct{
	char nome[sizenome];
	char cognome[sizenome];
	int punti;
	Scuderia* squadra;
}Pilota;

typedef struct{
	char nome[sizenome];
	Pilota* primo;
	Pilota* secondo;
	Pilota* terzo;
}Gara;
////////////funzioni generali
void preparaGeneratore()
{
	srand(time(0));
}

int sorteggiaNumero(int min, int max)
{
	int width = max;
	int ris = rand() % width;	
	ris += min;
	return ris;
}

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
	while(lunghezza(temp)>=sizenome)
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
		 	while(lunghezza(temp)>=sizenome)
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
		v[i].numeropiloti=0;
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
		while(lunghezza(temp)>sizenome)
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
					while(lunghezza(temp)>sizenome)
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
		while(lunghezza(temp)>sizenome)
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
					while(lunghezza(temp)>sizenome)
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
	cout <<"- MENU' SCUDERIE -\n";
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
	    	cin >>x;
		}
	    if(k[x].numeropiloti<2)
	    {
	    	k[x].numeropiloti++;
	     	v[j].squadra=k+x;
	     	system("cls");
		}else{
			cout<<"Scuderia con gia' due piloti;\n";
			j--;
		}
	}
}
///////input gare

void inseriscinomegare(char a[],Gara gare[],int pos)
{
		char temp[500];
	
	cout <<"Inserisci il nome della gara : ";
	cin >>temp;
	while(lunghezza(temp)>=60)
	{
		cout <<"Nome gara non valido; reinserisci il nome della gara: ";
		cin >>temp;
	}
	passaggio(temp, a);
	for(int j=0;j<20;j++)
	{			
		while(confronta(a,gare[j].nome)==0&&pos!=j)
		{
		 	cout <<"Nome gara inserito gia' presente, reinseriscilo: ";
		 	cin >>temp;
		 	while(lunghezza(temp)>=60)
			{
				cout <<"Nome gara non valido; reinserisci il nome della gara: ";
				cin >>temp;
			}
			passaggio(temp, a);
		}
	}
}
void ridimensioneArrayGare(Gara gare[],int &cap,int &nArr)
{

if(nArr==cap)
			{
				Gara *temp=(Gara*) malloc(cap*2*sizeof(Gara));
				
				for(int j=0;j<nArr;j++)
				{
				temp[j]=gare[j];
					
				}
				
				cap=cap*2;
				//printf(" \n cap = %d",cap);
			free(gare);
			gare=temp;
			
			}
		nArr++;		
}
void inputgare(Gara gare[])
{

		int i=0,x,cap=1,nArr=0,j=0;
	cout <<"----- Inserimento Gare ----\n";
 do{
 
		cout <<"\n Gara numero "<<j<<"\n";
		inseriscinomegare(gare[i].nome,gare,i);
		
	
	ridimensioneArrayGare(gare,cap,nArr);
	i++;
	j++;
	cout<<"\n per uscire inserisci 0 :";
	cin>>x;
	}while(x!=0);
	
}

///////////////////////////////////////////////////main
int main()
{
	int i,cap;
	Scuderia squadre[10];
	Pilota pilota[20];
	Gara *gare= (Gara*) malloc(cap*sizeof(Gara));
	//input scuderia
	//inputscuderia(squadre);
	system("cls");
	//input pilota
    //inputpilota(pilota);
	system("cls");
	//destinare il pilota alla scuderia
	//inputscuderia(pilota, squadre);
	//array dinamico delle gare, assegnazione punti casuali
	inputgare(gare);	
	//una volta finite le gare si chiede cosa si vuole vedere
}
