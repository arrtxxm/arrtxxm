// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct pipe {
	int id;
	int diameter;
	double length;
	bool repair_status;
};
struct compressor {
	int id;
	string Name;
	int number_workshops;
	int number_workshops_inwork;
	double efficiency;
};

bool check_value(int x) {
	return x > 0 ? true : false;
}
bool check_value(double x) {
	return x > 0 ? true : false;
}
pipe create_pipe() {
	pipe new_pipe;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
	cout << "Enter diameter" << endl;
	cin >> new_pipe.diameter;
} while (!check_value(new_pipe.diameter) || cin.fail());
do {
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "Enter length" << endl;
	cin >> new_pipe.length;
} while (!check_value(new_pipe.length) || cin.fail());
	new_pipe.repair_status = false;
	new_pipe.id = -1;
	return new_pipe;
}
compressor create_compressor() {
	compressor new_compressor;
	cout << "Enter name" << endl;
	cin >> new_compressor.Name;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
	cout << "Enter number of workshops" << endl;
	cin >> new_compressor.number_workshops;
	} while (!check_value(new_compressor.number_workshops) || cin.fail());
	do {
		cin.clear();
		cin.ignore(10000, '\n');
	cout << "Enter number of working workshops" << endl;
	cin >> new_compressor.number_workshops_inwork;	
	} while (!(check_value(new_compressor.number_workshops_inwork) && (new_compressor.number_workshops_inwork <= new_compressor.number_workshops)) || cin.fail());

	do {
		cin.clear();
		cin.ignore(10000, '\n');
	cout << "Enter efficiency" << endl;
	cin >> new_compressor.efficiency;
	} while (!check_value(new_compressor.efficiency) || cin.fail());
	new_compressor.id = -1;
	return new_compressor;
}
void write_pipe_info(pipe p) {
	cout << "Diameter " << p.diameter << endl;
	cout << "Length " << p.length << endl;
	cout << "id " << p.id << endl;
	cout << (p.repair_status ? "Under repair" : "Not in repair") << endl;
}
void write_compressor_info(compressor comp) {
	cout << "Name: " << comp.Name << endl;
	cout << "Number of workshops: " << comp.number_workshops << endl;
	cout << "Number of working workshops: " << comp.number_workshops_inwork << endl;
	cout << "Efficiency: " << comp.efficiency << endl;
}
void change_status(bool& status) {
	status = !status;
}
void save_to_fileP	(pipe p) {
	ofstream fout;
	fout.open("p.txt", ios::out);
	if (fout.is_open()) {
		fout << p.id << endl << p.diameter << endl << p.length << endl << p.repair_status;
		fout.close();
	}

}

void save_to_fileC(compressor c) {
	ofstream fout;
	fout.open("c.txt", ios::out);
	if (fout.is_open()) {
		fout << c.id << endl << c.Name << endl << c.number_workshops << endl << c.number_workshops_inwork << endl << c.efficiency;
		fout.close();
	}
}

pipe load_from_fileP() {
	ifstream fin;
	fin.open("p.txt", ios::in);
	pipe p;
	if (fin.is_open()) {
		fin >> p.id;
		fin >> p.diameter;
		fin >> p.length;
		fin >> p.repair_status;
		fin.close();
		return p;
	}
}

compressor load_from_fileC() {
	ifstream fin;
	fin.open("C.txt", ios::in);
	compressor c;
	if (fin.is_open()) {
		fin >> c.id;
		fin >> c.Name;
		fin >> c.number_workshops;
		fin >> c.number_workshops_inwork;
		fin >> c.efficiency;
		return c;
		fin.close();
	}
}

void stop_work(compressor& comp) {
	comp.number_workshops_inwork--;
}
void continue_work(compressor& comp) {
	comp.number_workshops_inwork++;
}

void PrintMenu() {
	cout << "1. Load  from file" << endl;
	cout << "2. Create pipe" << endl;
	cout << "3. Create compressor" << endl;
	cout << "4. Change pipe status" << endl;
	cout << "5. Print info" << endl;
	cout << "6. Save  to file" << endl;
	cout << "7. Update compressor" << endl;
	cout << "0. Exit" << endl;
}


int main()
{
	compressor comp;
	pipe p;
	int i;
	while (1) {
		cout << "Select action:" << endl;
		PrintMenu();
		cin >> i;
		switch (i)
		{
		case 1:
			p = load_from_fileP();
			comp = load_from_fileC();
			break;
		case 2:
			p = create_pipe();
			break;
		case 3:
			comp = create_compressor();
			break;
		case 4:
			change_status(p.repair_status);
			break;
		case 5:
			write_pipe_info(p);
			write_compressor_info(comp);
			break;
		case 6:
			save_to_fileP(p);
			save_to_fileC(comp);
			break;
		case 7:
			cout << "\t Select action:" << endl;
			cout << "\t 1. Start work" << endl;
			cout << "\t 2. Stop work" << endl;
			cout << "\t 0. Back" << endl;
			cin >> i;
			switch (i)
			{
			case 1:
				continue_work(comp);
				break;
			case 2:
				stop_work(comp);
				break;
			case 0:
				break;
			default:
				cout << "Select valid action " << endl;
				break;
			}
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Select valid action: " << endl;
			break;
		}

	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
