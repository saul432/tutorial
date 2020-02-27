#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "litzy.h"
using namespace std;

struct nodo{
	string Nombre;
	float Calf1,Calf2,Calf3,Promed;    
	
	nodo *siguiente;    
};


void agregar(nodo *&pila, string n, float c1, float c2, float c3, float p);
void eliminar(nodo *&pila, string &, float &, float &, float &, float &);

int main(){
	nodo *pila=NULL; 
	string Nombre;
	float Calf1,Calf2,Calf3,Promed;
	int opc;
	char res;
	do{
	system("cls");
	cout<<"1) Ingrese registro\n";
	cout<<"2) Eliminar registro\n";
	cout<<"3) Salir\n";
	cout<<endl<<"Seleccione la opcion deseada: ";
	cin>>opc;
	
	switch(opc){
		case 1:
			do{
			system("cls");
			
			cout<<"Nombre: "<<endl;
			cin>>Nombre;
			gotoxy(10,10); "Nombre:";
			gotoxy(30,0);  cout<<" Ingrese  calificacion 1"<<endl;
			gotoxy(35,1);  cin>>Calf1;
			gotoxy(50,0);  cout<<" Ingrese  calificacion 2"<<endl;
			gotoxy(55,0);  cin>>Calf2;
			gotoxy(70,0);  cout<<" Ingrese  calificacion 3"<<endl;
			gotoxy(75,1);  cin>>Calf3;
			Promed=(Calf1+Calf2+Calf3)/3;
			gotoxy(90,0); cout<<" El promedio es: "<<Promed;
		    agregar(pila,Nombre,Calf1,Calf2,Calf3,Promed);
			cout<<endl<<"Desea agregar otro elemento? s/n: "<<endl;
	        cin>>res;
	        }while(res!='n');
			break;
		case 2:
			cout<<"eliminar registro de la pila correctamente"<<endl;
	    	while(pila!=NULL){
	    	    eliminar(pila,Nombre,Calf1,Calf2,Calf3,Promed);
	    		if (pila!=NULL){
	    			cout<<Nombre<<" , "<<Calf1<<" , "<<Calf2<<" , "<<Calf3<<" == "<<Promed<<endl; 
				}
			    else{
			    	cout<<Nombre<<" , "<<Calf1<<" , "<<Calf2<<" , "<<Calf3<<" == "<<Promed<<"."<<endl; 
			    }
		    }   
			break;
		case 3:
			system("cls");
			return 0;
			break;
			
			
		
	}
	cout<<endl<<"Desea regresar al menu de opciones? s/n: "<<endl;
	        cin>>res;
	        }while(res!='n');
	getch();
}

void agregar(nodo *&pila, string N, float C1, float C2, float C3, float P){
	nodo *nvo_nodo=new nodo();
	
    nvo_nodo -> Nombre=N;
    nvo_nodo -> Calf1=C1;
    nvo_nodo -> Calf2=C2;
    nvo_nodo -> Calf3=C3;
    nvo_nodo -> Promed=P;
    nvo_nodo->siguiente=pila;
    pila = nvo_nodo;
    cout<<"\nLas calificaciones de "<<N<<" han sido registradas";
}

void eliminar(nodo *&pila, string &N, float &C1, float &C2, float &C3, float &P){
	nodo *aux = pila;
	N= aux ->Nombre;
	C1= aux ->Calf1;
	C2= aux ->Calf2;
	C3= aux ->Calf3;
	P= aux ->Promed;
	pila=aux->siguiente;
	delete aux;
}
