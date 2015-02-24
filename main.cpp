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
	int r,t=1,t1,ra,rb;
	int ran;
	int d=0;
	int c=0;
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
	char* tok1;
	char* tok2;
	
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
	if (a>b){
		t=a;
		t1=a;
	}else{
		t=b;
		t1=b;
	}	
	
	int resp[t1][t1];
	for (int i = 0; i < t1; i++){
		c=0;
		cout<<"Cantidad de terminos que puede emparejar: "<<t<<endl;
		t--;
		cout<<"col A: ";
		cin>>ra;
		cout<<"col B: ";
		cin>>rb;
		resp[i][c]=ra;
		c++;
		resp[i][c]=rb;
	}
	if (a>b){
		t=a;
	}else{
		t=b;
	}	
	d=100/t;

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
	
	for (int x = 0; x < t1; x++){
		cout<<"Oportunidades: "<<t<<endl;
		t--;
		cout<<"Col. A: ";
		cin>>ra;
		cout<<"Col. B: ";
		cin>>rb;
		for (int i = 0; i < t1; i++){
			c=0;
			if (resp[i][c]==n_a[ra-1]&&resp[i][c+1]==n_b[rb-1]){
				correcto++;
			}
		}
	}	
	cout<<"Promedio: "<<d*correcto<<"\n"<<endl;
	
	//liberar memoria
	for (int i = 0; i < a; i++){
		delete[] col_a[i];
	}

	for (int i = 0; i < b; i++){
		delete[] col_b[i];
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