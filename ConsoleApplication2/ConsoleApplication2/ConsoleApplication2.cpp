// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct pipe {
	int id;
	double length;
	int diameter;
	bool repair_status;
};
struct compressor {
	int id;
	string Name;
	int number_workshops;
	int number_inwork;
	double efficiency;
};
pipe create_pipe() {
	pipe new_pipe;
	cout << "Enter diameter" << endl;
	cin >> new_pipe.diameter;
	cout << "Enter length" << endl;
	cin >> new_pipe.length;
	new_pipe.repair_status = false;
	new_pipe.id = -1;
	return new_pipe;
}
compressor create_compressor() {
	compressor new_compressor;
	cout << "Enter name" << endl;
	cin >> new_compressor.Name;
	cout << "Enter number of workshops" << endl;
	cin >> new_compressor.number_workshops;
	cout << "Enter number of working workshops" << endl;
	cin >> new_compressor.number_inwork;
	cout << "Enter efficiency" << endl;
	cin >> new_compressor.efficiency;
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
	cout << "Number of working workshops: " << comp.number_inwork << endl;
	cout << "Efficiency: " << comp.efficiency << endl;
}
void change_status(bool& status) {
	status = !status;
}

void save_to_file(pipe p) {
	ofstream fout;
	fout.open("f.txt", ios::out);
	if (fout.is_open()) {
		fout << p.id << endl << p.diameter << endl << p.length << endl << p.repair_status;
		fout.close();
	}
}

pipe load_from_file() {
	ifstream fin;
	fin.open("f.txt", ios::in);
	pipe p;
	if (fin.is_open()) {
		fin >> p.id;
		fin >> p.diameter;
		fin >> p.length;
		fin >> p.repair_status;
		return p;
	}
}

int main()
{
    std::cout << "Hello World!\n";
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
