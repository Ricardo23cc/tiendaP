#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

const int num=5;
struct infoProducto{
	string caducidad;
	char tamano[20];
	int cantidad;
};

struct producto{
	int clave;
	char nombre[15];
	struct infoProducto datosProducto;
	double precio;
	double totalVendido;
}productos[num];

void menu();
void agregarProducto();
void bodega();
int buscarLugarVacio();
void venderProducto(int);
int buscarClave(int);

int main()
{
	int opcion;
	int clave;
	do{
		menu();
		cin>>opcion;
		
		switch(opcion)
		{
			case 1:
				agregarProducto();
				break;
			case 2:
				bodega();
				break;
			case 3:
				bodega();
				cout<<"\n Introduce la clave del producto = "; cin>>clave;
				venderProducto(clave);
				break;
			case 4:
				cout<<"\n bye."<<endl;
				break;
			default:
				cout<<"Opcion incorrecta";
				break;
		}
		getch();
		system("cls");
			
	}while(opcion != 4);
	return 0;
}

void menu(){
	cout<<"Bienvenido "<<endl;
	cout<<"1.Agregar productos"<<endl;
	cout<<"2.Ver productos disponibles"<<endl;
	cout<<"3.Vender producto"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Que desea relizar: ";
}

void bodega()
{
	cout << endl;
    cout << setw(6) << "clave"
            << setw(35) << "Nombre"
            << setw(25) << "Tamaño"
            << setw(15) << "Fecha de caducidad"
            << setw(25) << "Cuantos desea comprar"
            << setw(7) << "el presio es " << endl;
    for (int i = 0; i < num; i++) {
        if (productos[i].clave != 0) {
            cout << setw(6) << productos[i].clave
                    << setw(35) << productos[i].nombre
                    << setw(25) << productos[i].datosProducto.tamano
                    << setw(15) << productos[i].datosProducto.caducidad
                    << setw(25) << productos[i].datosProducto.cantidad
                    << setw(7) << productos[i].precio<<"$"<<endl;
        }
    }
    cout<<"\n Dinero en caja: "<<productos[0].totalVendido<<"$"<<endl;
}

void agregarProducto(){
	int lugarVacio;
	lugarVacio=buscarLugarVacio();
	if(lugarVacio==-1){
		cout<<"\n No hay lugares disponibles. "<<endl;
		return;
	}
	fflush(stdin);
	cout<<"\n Cual es la clave del producto: "; cin>>productos[lugarVacio].clave;
	fflush(stdin);
	cout<<"\n Cual es el nombre del producto: "; cin.getline(productos[lugarVacio].nombre,15,'\n');
	cout<<"\n Cual es el precio del producto: "; cin>>productos[lugarVacio].precio;
	fflush(stdin);
	cout<<"\nIngresar cantidad del producto: "; cin>>productos[lugarVacio].datosProducto.cantidad;
	fflush(stdin);
	cout<<"\n Cual es el tamaño del producto: "; cin.getline(productos[lugarVacio].datosProducto.tamano,20,'\n');
	cout<<"\n Cual es el caducidad del producto: "; getline(cin,productos[lugarVacio].datosProducto.caducidad);
	cout<<"\n";
	
}

int buscarLugarVacio(){
	
	for(int i=0; i<num; i++)
	{
		if(productos[i].clave == 0)
		{
			return i;
		}
	}
	return -1;
	
}

void venderProducto(int clavex){
	int cantidadx;
	int claveR=buscarClave(clavex);
	double total;
	
	if(claveR !=-1&&productos[claveR].datosProducto.cantidad !=0)
	{
		cout<<"Ingresar cuantos productos desea vender: "; cin>>cantidadx;
		
		productos[claveR].datosProducto.cantidad=productos[claveR].datosProducto.cantidad-cantidadx;
		total=productos[claveR].precio*cantidadx;
		productos[0].totalVendido=productos[0].totalVendido+total;
		cout<<"\n LISTO!!!!! Venta realizada \n"<<endl;
		bodega();
		return;
	}else if(productos[claveR].datosProducto.cantidad==0){
		cout<<"ya no hay vaya a la miselanea cruzando la calle"<<endl;
		return;
	}
	
}

int buscarClave(int clavex){
	for(int i=0; i<num; i++)
	{
		if(clavex==productos[i].clave){
			return i;
		}
	}
	cout<<"Clave incorrecta "<<endl;
	return -1;
}
