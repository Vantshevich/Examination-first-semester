#include <fstream>
#include <iostream>
#include <string>
#include "List.h"
#include "Functions.h"

using namespace std;

//������ ������� �� 5 ������ �����������


int main(){
	setlocale(LC_ALL, "Russian");
	ifstream InputC("Client.txt");
	List<string> Client;
	if (InputC.is_open()) {
		string Input_Str;
		while (getline(InputC, Input_Str)) {
			Client.PushBack(Input_Str);
		}
	}
	InputC.close();

	Time* VremiaRazgovora = new Time[Client.getLength()];
	for (int i = 0; i < Client.getLength(); i++) {
		int timee;
		timee = atoi(FindFirstWordIf(Client.At(i).c_str(), Client.At(i).size(), IsDigit, true));
		VremiaRazgovora[i].tm = timee;
		VremiaRazgovora[i].Position = i;
	}
	sort(VremiaRazgovora, Client.getLength());

	ofstream SClient;
	SClient.open("SClient.txt");
	string* SortClientMass = new string[Client.getLength()];
	for (int i = 0; i < Client.getLength(); i++) {
		SortClientMass[i] = Client.At(VremiaRazgovora[i].Position);
		SClient << SortClientMass[i] << endl;
	}
	SClient.close();
	
	ifstream InputT("Tplan.txt");
	List<string> Tplan;
	if (InputT.is_open()) {
		string Input_Str;
		while (getline(InputT, Input_Str)) {
			Tplan.PushBack(Input_Str);
		}
	}
	InputT.close();
	string *TplanMass = new string[Tplan.getLength()];
	for (int i = 0; i < Tplan.getLength(); i++) {
		TplanMass[i] = Tplan.At(i);
	}

	string *ClietnsPlans = new string[Client.getLength()];
	for (int i = 0; i < Client.getLength(); i++) {
		ClietnsPlans[i] = FindFirstWordIf(SortClientMass[i].c_str(), SortClientMass[i].size(), NoProbel);
		double* c = new double;
		ClietnsPlans[i] += " ";
		string z = MinPlan(SortClientMass[i].c_str(), TplanMass, Tplan.getLength(), c);
		ClietnsPlans[i] += FindFirstWordIf(z.c_str(), z.size(), NoProbel);
		ClietnsPlans[i] += " ";
		ClietnsPlans[i] += to_string(*c);
	}

	ofstream PlanSort;
	PlanSort.open("PlanSort.txt");
	for (int i = 0; i < Client.getLength(); i++) {
		PlanSort << ClietnsPlans[i] << endl;
	}
	PlanSort.close();
	// � ���� PlanSort ���� �������� ������ ��� ����������



	system("pause");
	return 0;
}