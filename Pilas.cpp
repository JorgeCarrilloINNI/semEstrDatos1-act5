#include<iostream>

using namespace std;

const int TAM = 100;

//***************************Definicion de la clase Empleado*************************
//**********************************************************************************

class Empleado{
	private:
		int ClaveEmpleado;
		string Nombre;
		string Domicilio;
		float Sueldo;
		string ReportaA;
	public:
		Empleado(){};
		Empleado(int C, string N, string D, float S, string R): ClaveEmpleado(C), Nombre(N), Domicilio(D), Sueldo(S), ReportaA(R){}

    friend istream& operator >>(istream& input, Empleado& e){
	    cout << "\nIngrese la clave del empleado: ";
	    input >> e.ClaveEmpleado;
	    cout << "\nIngrese el nombre del empleado: ";
	    input >> e.Nombre;
	    cout << "\nIngrese el domicilio del empleado: ";
	    input >> e.Domicilio;
	    cout << "\nIngrese el sueldo del empleado: ";
	    input >> e.Sueldo;
	    cout << "\nIngrese a quien reporta el empleado: ";
	    input >> e.ReportaA;
	    return input;
	}

    friend ostream& operator <<(ostream& out, Empleado& e){
        out<<"Clave: "<<e.ClaveEmpleado<<"\n";
        out<<"Nombre: "<<e.Nombre<<"\n";
        out<<"Domicilio: "<<e.Domicilio<<"\n";
        out<<"Sueldo: "<<e.Sueldo<<"\n";
        out<<"Reporta a: "<<e.ReportaA<<"\n";
        return out;
    }
};

//***************************************************************************************



//****************************Definicion de la clase Pila****************************
//***********************************************************************************
class Pila{
	private:
		Empleado datos[TAM];
		int ult;
		bool elimina(int pos){
        if(Vacia() || pos<0 || pos>ult){
            std::cout<<"\n error de eliminacion";
            return true;
        }
        int i=pos;
        while(i<ult){
            datos[i]=datos[i+1];
            i++;
        }
        ult--;
        return false;
    	}
     	int inserta(Empleado& elem, int pos){
        	if(Llena()|| pos<0 || pos>ult+1){
            	cout<<"\n Error de insercion";
            	return 0;
        	}
        	int i=ult+1;
        	while(i>pos){
	            datos[i]=datos[i-1];
            	i--;
        	}
        	datos[pos]=elem;
        	ult++;
        	return 1;
    	}
		int ultimo()const{
			return ult;
		}
		friend ostream& operator<<(ostream & o, Pila& L){
			int i=0;
        	cout<<"\n";
        	while(i<=L.ultimo()){;
            	o<<L.datos[i];
            	i++;
        	}
        	return o;
		}
	public:
		Pila(): ult(-1){};
		
		int Vacia()const{
			if(ult==-1)
				return true;
			return false;
		}
		
		int Llena()const{
			if(ult==TAM-1)
				return true;
			return false;
		}	
		
		int Push(Empleado& T){
			if(Llena())
				return 400;
			inserta(T, ultimo()+1);
			return 201;
		}
		
		int Pop(){
			if(Vacia())
				return 400;
			ult--;
			return 200;
		}
		
		int Top(){
			if(Vacia())
				return 400;
			cout<<"***************"<<endl;
			cout<<datos[ult];
			cout<<"***************"<<endl;
			return 1;
		}
};

int main(){
	Pila P;
	Empleado T;
	int opcion = 0, status;
	
	while(opcion != 4){
		cout<<"*****Pilas Estaticas*****"<<endl;
		cout<<"1- Push"<<endl;
		cout<<"2- Pop"<<endl;
		cout<<"3- Top"<<endl;
		cout<<"4- Salir"<<endl;
		cout<<"Tu opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Apila Empleado"<<endl;
				cin>>T;
				if(P.Push(T) == 400)
					cout<<"La Pila esta llena"<<endl;
//				P.Push(T);
				break;
			case 2:
				cout<<"Desapilando Empleado..."<<endl;
//				P.Pop();
				if(P.Pop() == 400)
					cout<<"Error, La Pila esta vacia"<<endl;
				break;
			case 3:
				cout<<"Top de la Pila:"<<endl;
//				P.Top();
				if(P.Top() == 400)
					cout<<"La Pila esta vacia"<<endl;
				break;;
			case 4:
				cout<<"Saliendo...";
				break;
			default:
				cout<<"Escoja una opcion valida"<<endl;
		}
	}
	return 0;
}