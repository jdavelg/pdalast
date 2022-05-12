#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include "Textable.h"

using namespace std;

bool checkForItemInt(vector<int> arr, int data);
bool checkForItemInt(vector<string> arr, string data);
void printTable(vector<int> taxis, vector<string> drivers, vector<string> plates, vector<string> models, vector<int> carYears);

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
					cin>>carYear;	
					if(carYear<2010){
						cout<<"Lo sentimos, el vehiculo debe ser del anio 2010 como minimo."<<endl;
					}else{
							carYears.push_back(carYear);
				do{
					cout<<"Taxi ID: ";
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
			
			break;
			case 2:		
				printTable(taxis, drivers, plates,models, carYears);
			break;
		    case 3:
				cout<<"Really wanna send first avialable taxi? (Y/N): ";
				confirmation=getch();
				cout<<"\n";
				if(confirmation=='Y' || confirmation=='y')
				{
					//Adding Items to non avaialable vectors
					nAtaxis.push_back(taxis.at(0));
					nAdrivers.push_back(drivers.at(0));
					nAplates.push_back(plates.at(0));					
					nAmodels.push_back(models.at(0));
					nAcarYears.push_back(carYears.at(0));
					//Deleting items from avaialable arrays
					taxis.erase(taxis.begin());
					drivers.erase(drivers.begin());
					plates.erase(plates.begin());
					carYears.erase(carYears.begin());
					models.erase(models.begin());
					
				}
				printTable(taxis, drivers, plates,models, carYears);
			break;
			case 4:
				cout<<"Taxis in route: "<<endl;
				printTable(nAtaxis, nAdrivers, nAplates, nAmodels, nAcarYears);
			break;
			case 5:
				cout<<"Which taxi would you like to reinsert? "<<endl;
				printTable(nAtaxis, nAdrivers, nAplates, nAmodels, nAcarYears);
				cout<<"\nPlease, input order below: ";
				cin>>idToReinsert;
				taxis.push_back(nAtaxis.at(idToReinsert));
				drivers.push_back(nAdrivers.at(idToReinsert));
				plates.push_back(nAplates.at(idToReinsert));
				models.push_back(nAmodels.at(idToReinsert));
				carYears.push_back(nAcarYears.at(idToReinsert));
				nAtaxis.erase(nAtaxis.begin()+idToReinsert);
				nAdrivers.erase(nAdrivers.begin()+idToReinsert);
				nAplates.erase(nAplates.begin()+idToReinsert);
				nAmodels.erase(nAmodels.begin()+idToReinsert);
				
				cout<<"Taxi has been already inserted to avialable queue"<<endl;
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
			cout<<"Data is already registered at position ["<<i<<"].\nPlease Enter Data again.\n";
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
			cout<<"Data is already registered at position ["<<i<<"].\nPlease Enter Data again.\n";
			return true;
		}
		else
		{
			return false;
		}
	}		
}

void printTable(vector<int> taxis, vector<string> drivers, vector<string> plates, vector<string> models, vector<int> carYears)
{
	TextTable t( '-', '|', '+' );
	t.add("Order");
	t.add("ID");
	t.add("Driver Name");
	t.add("Plate Number");
	t.add("Year");
	t.add("Model");
     t.endOfRow();
		
	for(int i=0; i<taxis.size();i++)
	{
		t.add(to_string(i));
		t.add(to_string(taxis.at(i)));
		t.add(drivers.at(i));
		t.add(plates.at(i));	
		t.add(to_string(carYears.at(i)));
		t.add(models.at(i));
		t.endOfRow();	
	}
	t.setAlignment( 2, TextTable::Alignment::RIGHT );
	cout<<t;
}