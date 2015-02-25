#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctime>
#include <cstring>
using namespace std;
void swap(char*,char*);
void swapN(int*,int*);

int main(int argc, char const *argv[]){
	srand(time(0));
	int a,b;
	int r,t=1,t1=0,ra,rb;
	int ran;
	int d=0;
	int c=0,acum=0;
	int correcto=0;
	cout<<"Columna A: ";
	cin>>a;
	cout<<"Columna B: ";
	cin>>b;
	char** col_a=new char*[a];
	char** col_b=new char*[b];
	
	char cadena[100];
	char temp1[100];
	char temp2[100];
	
	int n_a[a];
	int n_b[b];
	cout<<"\nPalabras C.A."<<endl;
	for (int i = 0; i < a; i++){
		cout<<i+1<<": ";
		cin>>cadena;
		col_a[i]=new char[strlen(cadena)+1];
		strcpy(col_a[i],cadena);
		n_a[i]=i+1;
	}

	cout<<"Palabra C.B."<<endl;
	for (int i = 0; i < b; i++){
		cout<<i+1<<": ";
		cin>>cadena;
		col_b[i]=new char[strlen(cadena)+1];
		strcpy(col_b[i],cadena);
		n_b[i]=(i+1);
	}

	//la pauta
	cout<<"\nKey"<<endl;	
	
	int** resp=new int*[2];
	do{
		cout<<"col A: ";
		cin>>ra;
		cout<<"col B: ";
		cin>>rb;
		resp[acum]=new int[2];
		resp[acum][0]=ra;
		cout<<resp[acum][0]<<endl;
		cout<<"wtf"<<endl;
		resp[acum][1]=rb;
		cout<<resp[acum][1]<<endl;
		acum++;
		t1++;
		cout<<"Continuar? [1-Si/2-No]";
		cin>>t;
		if (t==1){
			continue;
		}else{
			break;
		}
	}while(true);
	resp[acum]=NULL;
	d=100/t1;

	//shuffle los arrays
	for (int i = a-1; i >0; i--){
		ran=rand()%(i+1);//busca un numero random de 0 - i
		swap(col_a[i],col_a[ran]);//intercambia valor en i con valor en random
		swapN(&n_a[i],&n_a[ran]);
	}
	for (int i = b-1; i >0; i--){
		ran=rand()%(i+1);
		swap(col_b[i],col_b[ran]);
		swapN(&n_b[i],&n_b[ran]);
	}
	cout<<"\nRandom"<<endl
		<<"Col. A"<<endl;
	for (int i = 0; i < a; i++){
		cout<<i+1<<". "<<col_a[i]<<endl;
	}
	cout<<"Col. B"<<endl;
	for (int i = 0; i < b; i++){
		cout<<i+1<<". "<<col_b[i]<<endl;
	}

	//preguntar por las respuestas
	cout<<"\nRespuestas"<<endl;
	do{
		cout<<"Col. A: ";
		cin>>ra;
		cout<<"Col. B: ";
		cin>>rb;
		for (int i = 0; i < t1; i++){
			if (resp[i][0]==n_a[ra-1]&&resp[i][1]==n_b[rb-1]){
				correcto++;
			}
		}
		cout<<"Continuar? [1-Si/2-No]";
		cin>>t;
		if (t==1){
			continue;
		}else{
			break;
		}
	}while(true);
	cout<<"Promedio: "<<d*correcto<<"\n"<<endl;
	
	//liberar memoria
	for (int i = 0; i < a; i++){
		delete[] col_a[i];
	}
	for (int i = 0; i < b; i++){
		delete[] col_b[i];
	}
	for (int i = 0; i < t1+1; ++i){
		delete[] resp[i];
	}
	
	return 0;
}

void swap(char* a,char* b){
	char temp[100];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

void swapN(int *a,int *b){
	int temp= *a;
	*a=*b;
	*b=temp;
}