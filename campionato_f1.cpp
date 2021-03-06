//https://www.cplusplus.com/reference/cstring/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;
unsigned int sleep(unsigned int seconds);

const int sizenome=30; //nome di tutto: scuderia, gara e piloti(nome e cognome)
const int SIZEpiloti=20;
const int SIZEscuderie=10;

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
	Pilota* vincitore;
	Pilota* secondo;
	Pilota* terzo;
	int giri;
}Gara;
////////////funzioni generali
void coppa()
{

	system("color 0E");
	cout <<"                ************\n";
	cout <<"            ********************\n";
	cout <<"        ****    ************    ****\n";
	cout <<"    ****        ************        ****\n";
	cout <<"        ****    ************    ****\n";
	cout <<"            ********************\n";
	cout <<"                ************\n";
	cout <<"                    ****\n";
	cout <<"                    ****\n";
	cout <<"                ************\n";
	cout <<"            ********************";
	sleep(2);
	system("color 07");

}

void menupiloti(Pilota temp[])
{
	cout <<"- PILOTI -\n";
	for(int j=0;j<20;j++)
	{
		cout<<j<<"- "<<temp[j].nome<<" "<<temp[j].cognome <<"\n";
	}		
}

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
		cout<<"\n COGNOME = ";
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
		v[i].punti=0;
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
	menuscuderie(k);
	for(int j=0;j<20;j++)
	{
		
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
			menuscuderie(k);
	}
}
///////input gare

void inseriscinomegare(char a[],Gara gare[],int pos)
{
	char temp[500];
	
	cout <<"Inserisci il nome della gara : ";
	cin >>temp;
	while(lunghezza(temp)>=sizenome)
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
		 	while(lunghezza(temp)>=sizenome)
			{
				cout <<"Nome gara non valido; reinserisci il nome della gara: ";
				cin >>temp;
			}
			passaggio(temp, a);
		}
	}
}

void ridimensioneArrayGare(Gara* &vecchio, int &cap,int &nArr)
{
	if(nArr==cap)
	{
		Gara *nuovo=(Gara*) malloc(cap*2*sizeof(Gara));
		for(int j=0;j<nArr;j++)
		{
			nuovo[j]=vecchio[j];	
		}
		cap=cap*2;
		free(vecchio);
		vecchio=nuovo;
	}
	nArr++;		
}

void insvincitori(Pilota arrayp[], Gara &race)
{
	int j=1;
	int x=sorteggiaNumero(0,19);
	int y=sorteggiaNumero(0,19);
	int z=sorteggiaNumero(0,19);
	while(y==x)
	{
		y=sorteggiaNumero(0,19);	
	}
	while(z==x||z==y)
	{
		z=sorteggiaNumero(0,19);	
	}
	arrayp[x].punti +=15;
	arrayp[x].squadra->puntiTOT +=15;
	race.vincitore = &arrayp[x];
	arrayp[y].punti +=10;
	arrayp[y].squadra->puntiTOT +=10;
	race.secondo = &arrayp[y];
	arrayp[z].punti +=5;
	arrayp[z].squadra->puntiTOT +=5;
	race.terzo = &arrayp[z];
}

int insgiri()
{
	int j;
	
	cout <<"Inserisci il numero di giri da fare: ";
	cin >>j;
	
	while(j<=0)
	{
		cout <<"ERRORE! Reinserisci il numero di giri da fare: ";
		cin >>j;
	}
	return j;
}

void outvincitori(Gara s)
{
	cout <<"I tre piloti nella zona punti sono:\n1 - "<< s.vincitore->nome <<" "<< s.vincitore->cognome<<"\n2 - "<< s.secondo->nome <<" "<< s.secondo->cognome<<"\n3 - "<< s.terzo->nome <<" "<< s.terzo->cognome<<"\n";
	sleep(4);
}

void inputgare(Gara gare[], Pilota a[])
{
	int i=0,x,cap=1,nArr=0,j=1;
	
 	do{
 		system("cls");
 		cout <<"----- Inserimento Gare ----\n";
		cout <<"Gara numero "<<j<<"\n";
		ridimensioneArrayGare(gare,cap,nArr);
		inseriscinomegare(gare[i].nome,gare,i);
		gare[i].giri = insgiri();
		insvincitori(a, gare[i]);
		outvincitori(gare[i]);
		i++;	
		j++;
		cout<<"Vuoi inserire un'altra gara? \n0 o piu' per inserirla': ";
		cin>>x;
	}while(x>=0);
}

/////funzioni del menu output

void bubbleSortp(Pilota* A[])
{
	bool scambiato= true;
	
	for(int j = 0; j < SIZEpiloti-1 && scambiato; j++)
	{
		scambiato = false;
		for(int i = SIZEpiloti-1; i>j; i--)
		{
			if(A[i]->punti > A[i-1]->punti)
			{				
				Pilota* t = A[i];
				A[i] = A[i-1];
				A[i-1] = t;
				scambiato = true;
			}
		}
	}
	
	
}

void bubbleSorts(Scuderia* A[])
{
	bool scambiato= true;
	
	for(int j = 0; j < SIZEscuderie-1 && scambiato; j++)
	{
		scambiato = false;
		for(int i = SIZEscuderie-1; i>j; i--)
		{
			if(A[i]->puntiTOT > A[i-1]->puntiTOT)
			{				
				Scuderia* t = A[i];
				A[i] = A[i-1];
				A[i-1] = t;
				scambiato = true;
			}
		}
	}
}

void menu()
{
	cout<<"\n ======================MENU====================";
	cout<<"\n\n  0. Inserisci 0 per finire il programma. ";
	cout<<"\n  1. Vincitore dei piloti ";	
	cout<<"\n  2. Classifica dei piloti ";	
	cout<<"\n  3. Vincitori dei costruttori ";
	cout<<"\n  4. Classifica dei costruttori ";

}

void classificapiloti(Pilota v[], Pilota *PuntArray[])
{
   Pilota *temp;
   
   for(int i=0;i<SIZEpiloti;i++) 
   {
   		PuntArray[i] = &v[i];
   }
	
	bubbleSortp(PuntArray);

}

void classificascuderie(Scuderia v[], Scuderia *PuntArray[])
{
   Pilota *temp;
   
   for(int i=0;i<SIZEscuderie;i++) 
   {
   		PuntArray[i] = &v[i];
   }
	
	bubbleSorts(PuntArray);
}

int controlloX(int x)
{
	while(x<0||x>4)
	{
    cout<<"\n ERRORE! reinserisci un numero del menu : ";
	cin>>x;	
	}
	return x;
}

void menuinterattivo(Pilota v[], Scuderia s[])
{
	int x,j;
	
	Pilota* classificapil[SIZEpiloti];
	classificapiloti(v, classificapil);
	Scuderia* classificascu[SIZEscuderie];
	classificascuderie(s, classificascu);
	do{
	
	menu();
	cout<<"\n inserisci un numero del menu : ";
	cin>>x;
	x=controlloX(x);
	switch(x)
	{
		case 0: 
		cout <<"- FINE PROGRAMMA -";
			break;
		case 1:
			system("cls");
		cout <<"Il pilota vincitore della stagione e' "<< classificapil[0]->nome <<" "<<classificapil[0]->cognome <<" con "<<classificapil[0]->punti <<" punti.\n";
		coppa();
			break;
		case 2:
			j=1;
			system("cls");
				cout <<"-  CLASSIFICA PILOTI -\n";
		for(int i=0;i<SIZEpiloti;i++)
		{
		
			cout <<j <<"-"<< classificapil[i]->nome <<" "<<classificapil[i]->cognome <<" con "<<classificapil[i]->punti <<" punti.\n";
			j++;
		}
			break;
		case 3:
		system("cls");
		cout <<"La scuderia vincitrice della stagione e' "<< classificascu[0]->nome <<" con "<<classificascu[0]->puntiTOT <<" punti.\n";
		coppa();
			break;
		case 4:
		j=1;
		system("cls");
			cout <<"-  CLASSIFICA SCUDERIE -\n";
		for(int i=0;i<SIZEscuderie;i++)
		{
		
			cout <<j <<"-"<< classificascu[i]->nome <<" con "<<classificascu[i]->puntiTOT <<" punti.\n";
			j++;
		}
			break;				
	}
	}while(x!=0);

}
/////////////////////////////////////////////////main

int main()
{
	int i;
	Scuderia squadre[10];
	Pilota pilota[20];
	Gara *gare= (Gara*) malloc(sizeof(Gara));
	
	preparaGeneratore();
	//input scuderia
	inputscuderia(squadre);
	system("cls");
	//input pilota
  inputpilota(pilota);
	system("cls");
	//destinare il pilota alla scuderia
	inputscuderia(pilota, squadre);
	system("cls");
	//array dinamico delle gare, assegnazione punti casuali
	inputgare(gare, pilota);
	////////////////////////////////// TODO stampa tutti i piloti
	system("cls");
	//una volta finite le gare si chiede cosa si vuole vedere
	menuinterattivo(pilota, squadre);
}
