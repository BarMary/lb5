
#include <iostream> 
#include <fstream> 

using namespace std;

void checkValidInput()
{
	if (cin.fail())
	{
		throw "Incorrect input";
	}
}

//-----------------------------------------------

void checkValidParams(double a, double b, double h, int n, bool write_to_file)
{
	if (b < a) // Перевірка, чи кінцева точка більша за початкову 
	{
		throw "The value of [a] must be less than the value of [b]!";// Т.я. а - початкове значення діапзону, а b - кінцеве, то а має бути більше b
	}
	else if (h > (b - a)) // Перевірка, чи крок є більшим за весь діапазон
	{
		throw "Step [h] is too large for this expression!";
	}
	else if (n < 2) // Перевірка значення n
	{
		throw "n < 2 - Error!";
	}
}

//-----------------------------------------------

double calculate(double a, double b, double h, int n, bool write_to_file)
{
	ofstream fout("results.txt"); // Оголошення файлу

	if (write_to_file == 1)
	{
		fout << "a = " << a << ", b = " << b << ", h = " << h << ", n = " << n << endl; // Запис заголовка у файл
		fout << "-----------------------------" << endl;
	}

	for (a; a <= b; a += h) // Цикл
	{
		double y = 0.0;

		if (a < 0) // Умова для a < 0
		{
			for (int i = 1; i <= n - 1; i++) // Перша сума, i
			{
				double s = 0.0;

				for (int j = 1; j <= n; j++) // Друга сума, j
				{
					s += a - i + j;
				}
				y += s; // Отримання результату
			}

			cout << "x = " << a << ", y = " << y << endl; // Друк результату в консолі

			if (write_to_file == 1)
			{
				fout << "x = " << a << ", y = " << y << endl; // Друк результату у файл
			}
		}
		else  // Якщо a>=0
		{
			for (int i = 1; i <= n - 1; i++) // Сума
			{
				y += a / i; // Отримання результату
			}

			cout << "x = " << a << ", y = " << y << endl; // Друк результату в консолі

			if (write_to_file == 1)
			{
				fout << "x = " << a << ", y = " << y << endl; // Друк результату у файл
			}
		}
	}
	return true;
}

//-----------------------------------------------

int main()
{
	double a, b, h;
	int n;
	bool write_to_file;

	try
	{
		cout << "Enter a (double): "; // Початок діапазону
		cin >> a;
		checkValidInput();

		cout << "Enter b (double): "; // Кінець діапазону
		cin >> b;
		checkValidInput();

		cout << "Enter h (double): "; // Крок
		cin >> h;
		checkValidInput();

		cout << "Enter n (integer): "; // n
		cin >> n;
		checkValidInput();

		cout << "you want to save the result of each step to a file? (Yes - 1 ; No - 0): "; // Чи хоче користувач записати результати до файлу
		cin >> write_to_file;
		checkValidInput();

		checkValidParams(a, b, h, n, write_to_file);

		calculate(a, b, h, n, write_to_file);
	}
	catch (const char* ex)
	{
		cout << ex << endl;
		return -1;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
		return -2;
	}

	return 0; 
}