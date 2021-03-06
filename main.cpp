#include<iostream>
#include <algorithm>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include "Textable.h"


//ESTUDIANTE: JONATHAN DAVID LOPEZ GARCIA LG221728
using namespace std;

bool checkForItemInt(vector<int> arr, int data);
bool checkForItemInt(vector<string> arr, string data);
void printTable(vector<int> taxis, vector<string> drivers, vector<string> plates, vector<string> models, vector<int> carYears, vector<string> categories);

int main(){
	char response='\0';
	int option;
	int id;
	char confirmation;
	int idToReinsert;
	string driverName;
	string plateNumber;
	string motorNumber;
	string modelo;
	string category;
	string startPlace;
	string endPlace;
	float price;
	string selectedCategory;
	string confirmacion;
	int categoryPosition;
	int carYear;
	cout<<"Taxi sistema \t\n";
	vector<int> taxis;
	vector<string> drivers;
	vector<string> plates;
	vector<string> models;
	vector<string> categories;
    vector<int> carYears;
	vector<int> nAtaxis;
	vector<string> nAdrivers;
	vector<string> nAplates;
	vector<string> nAmodels;
	vector<string> nAcategories;	
	vector<int> nAcarYears;
	do{
		system("cls");
		cout<<"Opciones menu principal:\n\n"<<endl;
		cout<<"\t\t1. Agregar nuevo taxi"<<endl;
		cout<<"\t\t2. Revisar datos "<<endl;
		cout<<"\t\t3. Enviar taxi a cliente"<<endl;
		cout<<"\t\t4. Ver taxis en ruta"<<endl;
		cout<<"\t\t5. Poner taxi como disponible "<<endl;
		cout<<"\t\t6. Salir del programa"<<endl<<endl;
		cout<<"Por favor seleccione una opcion valida: ";
		cin>>option;
		switch(option){
			case 1:
					cout<<"anio del taxi: ";
						cin.ignore();
					cin>>carYear;	
					if(carYear<2010){
						cout<<"Lo sentimos, el vehiculo debe ser del anio 2010 como minimo."<<endl;
					}else{
							carYears.push_back(carYear);
							if(carYear>=2015){
								categories.push_back("Ejecutivo");
								
							}else{
								categories.push_back("Tradicional");
							}
				do{
					cout<<"Escriba el ID del taxi (NUMERO): ";
						cin.ignore();
					cin>>id;
				}while(checkForItemInt(taxis, id));
				taxis.push_back(id);
				
				do{
					cout<<"Nombre del conductor: ";
					cin.ignore();
					getline(cin,driverName);
				}while(checkForItemInt(drivers, driverName));
				drivers.push_back(driverName);
				do{
					cout<<"Numero de placa: ";
					cin.ignore();
					getline(cin,plateNumber);
				}while(checkForItemInt(plates, plateNumber));
				plates.push_back(plateNumber);
	            cout<<"modelo del taxi: ";
					cin.ignore();
					getline(cin,modelo);			
				models.push_back(modelo);
					}		
				cout<<"El taxi ha sido guardado con exito \n";
			break;
			case 2:		
				printTable(taxis, drivers, plates,models, carYears, categories);
			break;
		    case 3:
			
						cout<<"Escriba E para seleccionar taxi ejecutivo o cualquier otra para tradicional (E/T): \n";
						cin.ignore();
				    getline(cin,selectedCategory);
					if(selectedCategory=="E" || selectedCategory=="e"){
						// using the find function to search the element proving all the parameters
auto res = std::find (categories.begin(), categories.end(), "Ejecutivo");
//checking if the variable 'res' has index 
if (res != categories.end())
{

categoryPosition= res - categories.begin(); //+ 1 ;

	cout<<"escriba la tarifa para el viaje (numeros) \n";
						cin.ignore();
						cin>>price;
cout<<"Escriba el punto de partida \n";
						cin.ignore();
				    getline(cin,startPlace);
				    cout<<"Escriba el destino del viaje \n";
						cin.ignore();
				    getline(cin,endPlace);
//cout<<"Ese dato ya esta registrado en la posicion ["<<categoryPosition<<"].\nPor favor ingrese uno diferente.\n";
	//agregamos el taxi a no disponible
					nAtaxis.push_back(taxis.at(categoryPosition));
					nAdrivers.push_back(drivers.at(categoryPosition));
					nAplates.push_back(plates.at(categoryPosition));					
					nAmodels.push_back(models.at(categoryPosition));
					nAcarYears.push_back(carYears.at(categoryPosition));
					nAcategories.push_back(categories.at(categoryPosition));
					//borramos el taxi en los regitros disponibles
					taxis.erase(taxis.begin() + categoryPosition);
					drivers.erase(drivers.begin() + categoryPosition);
					plates.erase(plates.begin() + categoryPosition);
					carYears.erase(carYears.begin() + categoryPosition);
					models.erase(models.begin() + categoryPosition);
					categories.erase(categories.begin() + categoryPosition);
					cout<<"El taxi ha sido enviado exitosamente, puede revisarlo en la lista de taxis en ruta \n";
}
else{
cout<<"Lo sentimos, no hay taxis disponibles de la categoria seleccionada ";	
}

}else{
		// using the find function to search the element proving all the parameters
auto res = std::find (categories.begin(), categories.end(), "Tradicional");
//checking if the variable 'res' has index 
if (res != categories.end())
{

categoryPosition= res - categories.begin(); //+ 1 ;
		//agregamos el taxi a no disponible
					nAtaxis.push_back(taxis.at(categoryPosition));
					nAdrivers.push_back(drivers.at(categoryPosition));
					nAplates.push_back(plates.at(categoryPosition));					
					nAmodels.push_back(models.at(categoryPosition));
					nAcarYears.push_back(carYears.at(categoryPosition));
					nAcategories.push_back(categories.at(categoryPosition));
						//borramos el taxi en los regitros disponibles
					taxis.erase(taxis.begin() + categoryPosition);
					drivers.erase(drivers.begin() + categoryPosition);
					plates.erase(plates.begin() + categoryPosition);
					carYears.erase(carYears.begin() + categoryPosition);
					models.erase(models.begin() + categoryPosition);
					categories.erase(categories.begin() + categoryPosition);
					cout<<"El taxi ha sido enviado exitosamente, puede revisarlo en la lista de taxis en ruta \n";
}
else{
cout<<"Lo sentimos, no hay taxis disponibles de la categoria seleccionada ";	
}
}
					
					
					/*
					nAtaxis.push_back(taxis.at(0));
					nAdrivers.push_back(drivers.at(0));
					nAplates.push_back(plates.at(0));					
					nAmodels.push_back(models.at(0));
					nAcarYears.push_back(carYears.at(0));
					nAcategories.push_back(categories.at(0));
					//Deleting items from avaialable arrays
					taxis.erase(taxis.begin());
					drivers.erase(drivers.begin());
					plates.erase(plates.begin());
					carYears.erase(carYears.begin());
					models.erase(models.begin());
					categories.erase(categories.begin());*/
					
				
				//printTable(taxis, drivers, plates,models, carYears, categories);
			break;
			case 4:
				cout<<"Taxis en ruta: "<<endl;
				printTable(nAtaxis, nAdrivers, nAplates, nAmodels, nAcarYears, nAcategories);
			break;
			case 5:
				cout<<"Cual taxi desea poner como disponible? "<<endl;
				printTable(nAtaxis, nAdrivers, nAplates, nAmodels, nAcarYears, nAcategories);
				cout<<"\nPor favor ingrese el numero de orden del taxi: ";
				cin>>idToReinsert;
				taxis.push_back(nAtaxis.at(idToReinsert));
				drivers.push_back(nAdrivers.at(idToReinsert));
				plates.push_back(nAplates.at(idToReinsert));
				models.push_back(nAmodels.at(idToReinsert));
				categories.push_back(nAcategories.at(idToReinsert));
				carYears.push_back(nAcarYears.at(idToReinsert));
				nAtaxis.erase(nAtaxis.begin()+idToReinsert);
				nAdrivers.erase(nAdrivers.begin()+idToReinsert);
				nAplates.erase(nAplates.begin()+idToReinsert);
				nAmodels.erase(nAmodels.begin()+idToReinsert);
				nAcategories.erase(nAcategories.begin()+idToReinsert);
				cout<<"El taxi ya se encuentra como disponible"<<endl;
			break;
			case 6:
				cout<<"Ha finalidado la ejecucion del programa...";
				system("pause");
				system("exit");
			break;
			default:
				cout<<"Selecciona una opcion disponible."<<endl;
			break;
		}
  	cout<<"Desea continuar? (Y/N)?: ";
  	response=getch();
	}while(response=='Y' || response=='y');	
}

bool checkForItemInt(vector<int> arr, int data){
	for(int i=0;i<arr.size();i++)
	{
		if(arr.at(i)==data)
		{
			cout<<"Ese dato ya esta registrado en la posicion ["<<i<<"].\nPor favor ingrese uno diferente.\n";
			return true;
		}
		else
		{
			return false;
		}
	}		
}

bool checkForItemInt(vector<string> arr, string data){
	for(int i=0;i<arr.size();i++)
	{
	if(arr.at(i)==data)
		{
			cout<<"Ese dato ya esta registrado en la posicion  ["<<i<<"].\nPor favor ingrese uno diferente.	\n";
			return true;
		}
		else
		{
			return false;
		}
	}		
}

void printTable(vector<int> taxis, vector<string> drivers, vector<string> plates, vector<string> models, vector<int> carYears, vector<string> categories)
{
	TextTable t( '-', '|', '+' );
	t.add("Order");
	t.add("ID");
	t.add("Driver Name");
	t.add("Plate Number");
	t.add("Year");
	t.add("Model");
	t.add("Category");
     t.endOfRow();
		
	for(int i=0; i<taxis.size();i++)
	{
		t.add(to_string(i));
		t.add(to_string(taxis.at(i)));
		t.add(drivers.at(i));
		t.add(plates.at(i));	
		t.add(to_string(carYears.at(i)));
		t.add(models.at(i));
		t.add(categories.at(i));		
		t.endOfRow();	
	}
	t.setAlignment( 2, TextTable::Alignment::RIGHT );
	cout<<t;
}
