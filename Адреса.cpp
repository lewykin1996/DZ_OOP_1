// Калькулятор двух числе.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

class Address {
private:
	std::string city;
	std::string street;
	int house;
	int apartment;

public:
	Address(std::string c, std::string s, int h, int a)
	{
		city = c;
		street = s;
		house = h;
		apartment = a;
	}

	std::string get_output_address() const {
		return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");

	if (!fin.is_open() || !fout.is_open())
	{
		std::cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	int N;
	fin >> N;
	fin.ignore();

	Address** addresses = new Address*[N];


	for (int i = 0; i < N; i++)
	{
		std::string city, street;
		int house, apartment;

		std::getline(fin, city);
		std::getline(fin, street);
		fin >> house;
		fin >> apartment;
		fin.ignore();

		addresses[i] = new Address(city, street, house, apartment);
	}

	fout << N << std::endl;

	for (int i = N - 1; i >= 0; i--)
	{
		fout << addresses[i]->get_output_address() << std::endl;
	}

	for (int i = 0; i < N; i++)
	{
		delete addresses[i];
	}
	delete[] addresses;

	fin.close();
	fout.close();

	return 0;
}

