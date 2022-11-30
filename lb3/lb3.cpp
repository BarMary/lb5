
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
	if (b < a) // ��������, �� ������ ����� ����� �� ��������� 
	{
		throw "The value of [a] must be less than the value of [b]!";// �.�. � - ��������� �������� �������, � b - ������, �� � �� ���� ����� b
	}
	else if (h > (b - a)) // ��������, �� ���� � ������ �� ���� �������
	{
		throw "Step [h] is too large for this expression!";
	}
	else if (n < 2) // �������� �������� n
	{
		throw "n < 2 - Error!";
	}
}

//-----------------------------------------------

double calculate(double a, double b, double h, int n, bool write_to_file)
{
	ofstream fout("results.txt"); // ���������� �����

	if (write_to_file == 1)
	{
		fout << "a = " << a << ", b = " << b << ", h = " << h << ", n = " << n << endl; // ����� ��������� � ����
		fout << "-----------------------------" << endl;
	}

	for (a; a <= b; a += h) // ����
	{
		double y = 0.0;

		if (a < 0) // ����� ��� a < 0
		{
			for (int i = 1; i <= n - 1; i++) // ����� ����, i
			{
				double s = 0.0;

				for (int j = 1; j <= n; j++) // ����� ����, j
				{
					s += a - i + j;
				}
				y += s; // ��������� ����������
			}

			cout << "x = " << a << ", y = " << y << endl; // ���� ���������� � ������

			if (write_to_file == 1)
			{
				fout << "x = " << a << ", y = " << y << endl; // ���� ���������� � ����
			}
		}
		else  // ���� a>=0
		{
			for (int i = 1; i <= n - 1; i++) // ����
			{
				y += a / i; // ��������� ����������
			}

			cout << "x = " << a << ", y = " << y << endl; // ���� ���������� � ������

			if (write_to_file == 1)
			{
				fout << "x = " << a << ", y = " << y << endl; // ���� ���������� � ����
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
		cout << "Enter a (double): "; // ������� ��������
		cin >> a;
		checkValidInput();

		cout << "Enter b (double): "; // ʳ���� ��������
		cin >> b;
		checkValidInput();

		cout << "Enter h (double): "; // ����
		cin >> h;
		checkValidInput();

		cout << "Enter n (integer): "; // n
		cin >> n;
		checkValidInput();

		cout << "you want to save the result of each step to a file? (Yes - 1 ; No - 0): "; // �� ���� ���������� �������� ���������� �� �����
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