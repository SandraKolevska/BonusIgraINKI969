//Sandra Kolevska INKI969 igra - X 0
#include <iostream>
using namespace std;
const int golemina=3; // deklariranje na konstantna golemina na tablicata
void pecatiTablica(char tablica[][golemina]) // se pecati tablica so 2 for ciklusi
{
	int i,j;
	for(i=0;i<golemina;i++){ cout<<"\n";
	for(j=0;j<golemina;j++)
	cout<<tablica[i][j]<<" ";}
	cout<<"\n";
}
bool pobednik(char tablica[][golemina], char igrach) // funkcija za pobednik
{
	int i,j;
	for(i=0;i<golemina;i++)
	if(tablica[i][0]==igrach && tablica[i][1]==igrach && tablica[i][2]==igrach) //igracot shto kje popolni edna od trite redici, kje pobedi
	return true;
	for(j=0;j<golemina;j++)
	if(tablica[0][j]==igrach && tablica[1][j]==igrach && tablica[2][j]==igrach) //igracot shto kje popolni edna od trite koloni, kje pobedi
	return true;
	if(tablica[0][0]==igrach && tablica[1][1]==igrach && tablica[2][2]==igrach) //dokolku igracot gi popolni polinjata shto se naogjaat na glavna dijagolana, kje pobedi
	return true;
	if(tablica[0][2]==igrach && tablica[1][1]==igrach && tablica[2][0]==igrach) //dokolku igracot gi popolni polinjata shto se naogjaat na sporedna dijagolana, kje pobedi
	return true;
	//vo sprotivno, ne pobeduva
	return false;
}
bool neresheno(char tablica[][golemina]) //metoda kooja se koristi dokolku e neresheno
{
	int i,j;
	for(i=0;i<golemina;i++)
	for(j=0;j<golemina;j++)
	if(tablica[i][j]=='-') //ako ima ushte prostor za popolnuvanje
	return false; //togas igrata nema da zavrshi
	
	return true; //ako ne se ispolnat uslovite za pobeda, togash krajniot rezultat kje e neresheno
}
int main() 
{
	char tablica[golemina][golemina]; //deklariranje na tablicata vo forma na matrica
	char igrach='X'; // deklariranje na igrach
	bool zavrshenaIgra=false; //deklariranje na zavrshena igra
	int i,j;
	for(i=0;i<golemina;i++)
	for(j=0;j<golemina;j++)
	tablica[i][j]='-';
	cout<<"X O \n";
	pecatiTablica(tablica); //povik na funkcijata za pecatenje na tablicata
	while(!zavrshenaIgra) 
	{
		int red,kolona;
		cout<<"Igrach "<<igrach<<" da vnese red : "; //igrachot da vnese redica
		cin>>red;
		cout<<"Igrach "<<igrach<<" da vnese kolona : "; //igrachot da vnese kolona
		cin>>kolona;
		if(red<1 || red>golemina || kolona<1 || kolona>golemina || tablica[red-1][kolona-1]!='-') //ako igrachot vnesi redica ili kolona pogolema od 3 ili pomala od 1
		{ //ili dokolku igrachot vnesi vrednost kade sto poleto e popolnato, togas igrachot napravil nepravilen poteg i prodolzuva ponataka
			cout<<"Nevaliden poteg. Probaj pak.\n"; continue;
		}
		tablica[red-1][kolona-1]=igrach; //ovozmozuvanje na igrachot da pravi poteg
		pecatiTablica(tablica); //povik na funkcija za pecatenje na tablicata
		if(pobednik(tablica,igrach)){ //dokolku igrachot gi ispolni kriteriumite za pobeda, togas igrachot pobeduva i igrata se zavrshuva
			cout<<"Igrachot "<<igrach<<" pobede.\n";
			zavrshenaIgra=true;
		}else if(neresheno(tablica)){ //dokolku nema pobednici vo igrata, togash rezultatot e neresheno i igrata se zavrshuva
			cout<<"Neresheno."; 
			zavrshenaIgra=true;
		}
		//dokolku igrachot e X, se promenuva vo O, a dokolku e O, se promenuva vo X, odnosno se menuvaat igrachite
		if(igrach=='X')
		igrach='O';
		else
		igrach='X';
	} //kraj na while ciklusot
		return 0;
}
