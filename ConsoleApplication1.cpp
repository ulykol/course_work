#include <iostream>
#include <clocale>
#include<fstream>
#include<string>

using namespace std;
void zero_matrix(int** matrix, int n);
void zero_matrix(int** matrix, int n)
{
	int zero = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0) zero++;
		}
	}

	if (zero == n * n)
	{
		printf("\nРебра отсутствуют!\n");
		exit(1);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, tmp, k;
	int** array;
	bool* choosen;
	int edgeNum = 0;
	string s;
	

	cout << "    Алгоритм Прима\n\n";
	cout << "    В какой файл вы хотите занести результат?\n";
	cout << " Имя файла: ";
	cin >> s;

	cout << "    Каким образом вы хотите создать матрицу смежности?\n";
	cout << "   1. Ручной ввод\n" << "   2. Рандомная генерация\n";
	cout << " Ваш выбор: ";
	cin >> k; 

	if ((k < 1) || (k > 2))
	{
		do
		{
			cout << "\nВведите один из 2 вариантов \n";
			cin >> k;
			if ((k < 1) || (k > 2))
			{
			 cout<< "Невозможно считать данные! Попробуйте заново!\n";
			}
		} while ((k < 1) || (k > 2));

	}
	if (k == 1) {

		cout << "   Введите размер графа\n";
		cout << " Ваш выбор:  ";
		cin >> n;

		if (n < 2) {
			do
			{
				cout << "\nВведите число больше 1\n";
				cin >> n;
				if (n < 2)
				{
					cout << "Невозможно считать данные! Попробуйте заново!\n";
				}
			} while (n < 2);
		}
		cout << "   Введите матрицу смежности\n";

		//инициализирует вершину для отслеживания
		choosen = new bool[n];				//ребро, которое соединяет две вершины
		for (int i = 1; i < n; i++)
			choosen[i] = false;
		choosen[0] = true; // выбирает 1 вершину 
		int x, y; // номера строк и столбцов

		// создаем массив
		array = new int* [n];
		for (int i = 0; i < n; i++)
			array[i] = new int[n];

		// вводим значения
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> tmp;
				array[i][j] = tmp;
				if (tmp < 0) {
					do
					{
						cout << "\nВведите положительные числа \n";
						cin >> tmp;
						if (tmp < 0)
						{
							cout << "Невозможно считать данные! Попробуйте заново!\n";
						}
					} while (tmp < 0);

				}
				{
					ofstream fout;
					fout.open(s, ofstream::app);
					if (!fout.is_open()) {
						cout << "   Ошибка открытия файла!" << endl;
					}
					else
					{
						fout << array[i][j] << " \n ";
					}

					fout<<"\n";
				}
			
			}
		
		cout << "Введите вершину, с которой хотите начать обход";
		cout << "   Результат\n";
		while (edgeNum < n - 1) {  //edgeNum - выбираем вершину    
			x = 0; //вершина 1
			y = 0; // веришны 2
			int min = INT_MAX; // установим наибольшее число для того, чтобы сравнить с наименьшим весом ребра

			//определяются веса между выбранной вершиной edgeNum и остальными невыбранными вершинами
			for (int i = 0; i < n; i++) {
				if (choosen[i]) { 
					for (int j = 0; j < n; j++)
					{
						if (!choosen[j] && array[i][j]) {
							if (min > array[i][j]) { // выбираем выршину с наименьшим весом
								//фиксируем выбранные ребра и вес
								x = i;
								y = j;
								//устанавливаем минимальный вес
								min = array[i][j];
							}
						}
					}
				}
			}
			cout << '(' << x + 1 << " -> " << y + 1 << ") " << array[x][y] << " | "; // выводим веришны на экран и вес ребра между этими вершинами
			choosen[y] = true; // выбранную вершину исключаем из перечня
			++edgeNum; // число выбранных вершин увеличиваем на 1
			ofstream fout;
			fout.open(s, ofstream::app);
			if (!fout.is_open()) {
				cout << "   Ошибка открытия файла!" << endl;
			}
			else
			{ 
				fout << '(' << x + 1 << " -> " << y + 1 << ") " << array[x][y] << " | ";
			}
			fout.close();
		}

		0;
		
	}
if (k == 2) {
	
	cout << "   Введите размер графа\n";
	cout << " Ваш выбор:  ";
	cin >> n;
	if (n < 2) {
		do
		{
			cout << "\nВведите число больше 1\n";
			cin >> n;
			if (n < 2)
			{
				cout << "Невозможно считать данные! Попробуйте заново!\n";
			}
		} while (n < 2);
	}
	int** matrix = new int* [n];						// Генерируем матрицу M1
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];
	}

	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[n];
	}

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 30;
			if (i == j)
			{
				matrix[i][j] = 0;
			}
			if (matrix[i][j] >= 0 && matrix[i][j] < 5)
			{
				matrix[i][j] = 0;
			}
			
		}
		
	}

	zero_matrix(matrix,n);

	cout << "   Матрица смежности: \n";
	
	
	ofstream fout;
	fout.open(s, ofstream::app);

		if (!fout.is_open()) {
			cout << "   Ошибка открытия файла!" << endl;
		}
		
		fout << "   Матрица смежности: \n";
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			matrix[i][j] = matrix[j][i];
			printf(" %2d\t", matrix[j][i]);		// Выводим элементы матрицы M1
			

	
				fout << matrix[i][j] << "  ";
				
			
		}
		fout << " \n ";
		cout << endl;
		
	}
	
	choosen = new bool[n];
	for (int i = 1; i < n; i++)
		choosen[i] = false;
	choosen[0] = true; 
	int x, y;
	cout << "   Результат\n";
	while (edgeNum < n - 1) {
		x = 0;
		y = 0;
		int min = INT_MAX; 

		for (int i = 0; i < n; i++) {
			if (choosen[i]) {
				for (int j = 0; j < n; j++)
				{
					if (!choosen[j] && matrix[i][j]) {
						if (min > matrix[i][j]) {
							x = i;
							y = j;
							min = matrix[i][j];
						}
					}
				}
			}
		}
		cout << '(' << x + 1 << " -> " << y + 1 << ") " << matrix[x][y] << " | ";
		choosen[y] = true;
		++edgeNum;
		ofstream fout;
		fout.open(s, ofstream::app);
		if (!fout.is_open()) {
			cout << "   Ошибка открытия файла!" << endl;
		}
		else
		{
			fout << '(' << x + 1 << " -> " << y + 1 << ") " << matrix[x][y] << " | ";
		}
		fout.close();
	}
	
}

}