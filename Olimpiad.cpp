#include<iostream>
#include<cmath>

using namespace std;

void VinniPuh();
void Mushrooms();
void Fool();
void Menu();
double dist(int x1, int x2, int y1, int y2);
void Check(char** p, int num);


int main()
{
	setlocale(LC_ALL, "Russian");

	Menu();

	system("pause");
	return 0;
}

void VinniPuh()
{
	system("cls");
	int v = 0, n = 0, k = 0, res = 0, kRes = 0;
	bool check = 0;

	cout << "Введи V (кол-во горстей для полного горшка меда)\n";
	cin >> v;
	cout << "Введи N (кол-во дней до зимы)\n";
	cin >> n;
	cout << "Введи K (кол-во горстей сьедаемых каждый день)\n";
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		if (v >= kRes)
		{
			res += (v - kRes);
		}
		kRes += k;
	}

	if (v > kRes)
	{
		cout << "Горшек не пустой\n";
	}
	else
		cout << "Горшек пустой\n";

	cout << "На зиму заготовленно " << res << " горстей меда\n";

	system("pause");
}

void mushrooms()
{
	int n = 0;
	double minDist = 0, t = 0, currentDist = 0;

	do
	{
		cout << "Введи кол-во грибов(1-10): ";
		cin >> n;
	} while (n < 1 || n>10);

	int *x = new int[n];
	int *y = new int[n];
	int *r = new int[n];

	do
	{
		cout << "Введи длительность дождя(1-100): ";
		cin >> t;
	} while (t > 100 || t < 1);

	for (int i = 0; i < n; i++)
	{
		do 
		{
			cout << "Введи координаты гриба #" << i << " (x,y) (0-100)\n";
			cin >> x[i];
			cin >> y[i];
		} while ((x[i] < 0 || x[i]>100) && (y[i] < 0 || y[i]>100));

		do
		{
			cout << "Введи радиус шляпы гриба #" << i << "(1-10)\n";
			cin >> r[i];
		} while (r[i] > 10 || r[i] < 1);
	}

	minDist = dist(x[0], x[1], y[0], y[1]) - (r[0] - r[1]);

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			currentDist = dist(x[i], x[j], y[i], y[j]) - (r[i] - r[j]);
			if (minDist > currentDist)
			{
				minDist = currentDist;
			}
		}
	}

	if (minDist < 0)
	{
		minDist = 0;
	}
	if (t > minDist / 2)
	{
		t = minDist / 2;
	}

	cout << "Грибы увеличились на " << t << "\n";

	system("pause");
}

void Fool()
{

	int n = 0, m = 0;
	char r;
	do
	{
		cout << "Введите кол-во карт n (которыми отбивать) (1-35шт) \n";
		cin >> n;
	} while (n<1 || n>35);
	do
	{
		cout << "Введите кол-во карт m  (которыe отбивать) (1-4шт, m<=n)\n";
		cin >> m;
	} while ((m<1 || m>4) && m <= n);

	bool* mCheck = new bool[m];
	for (int q = 0; q < m; q++)
		mCheck[q] = 0;

	char** pM = new char*[m];
	char** pN = new char*[n];

	cout << "Введите " << n << " карт, которыми будем биться (6S - AH)\n";
	for (int w = 0; w < n; w++)
		cin >> pN[w];

	cout << "Введите " << m << " карт, которые будем бить\n";
	for (int e = 0; e < m; e++)
		cin >> pM[e];

	for (int t = 0; t < n; t++)
	{
		for (int y = 0; y < m; y++)
		{
			Check(pM, m);
			Check(pN, n);
			if (pM[y][0]<pN[t][0] && pM[y][1] == pN[t][1])
			{
				mCheck[y] = 1;
				pM[y] = "";
			}
		}
	}
	int k = 0;

	for (int i = 0; i < m; i++)
	{
		if (mCheck[i] == 1)
		{
			k++;
		}
		if (k == i)
		{
			cout << "Все карты отбиты\n";
		}
		else
			cout << "Карты не отбиты\n";
	}
	delete[] * pM;
	delete[] * pN;
	system("pause");
}

void menu()
{
	char Chose = '0';
	do
	{
		system("cls");
		cout << "1 - Винни Пух\n2 - Грибы\n3 - Дурак\n";
		cin >> Chose;

		if ((int)Chose != (char)Chose)
		{
			Chose = '322';
		}

		switch (Chose)
		{
		case '1':
			VinniPuh();
			break;
		case '2':
			Mushrooms();
			break;
		case '3':
			Fool();
			break;
		case '322':
			break;
		default:
			break;
		}
	} while (Chose != '3' || Chose != '2' || Chose != '1' || Chose != '322');
}

double Dist(int x1, int x2, int y1, int y2)
{
	return sqrt((x1 - x2) *(x1 - x2) + (y1 - y2) * (y1 - y2));
}

void Check(char** p, int num)
{
	for (int y = 0; y < num; y++)
	{
		if (p[y][0] == 'T')
			p[y][0] = 10;
		if (p[y][0] == 'J')
			p[y][0] = 11;
		if (p[y][0] == 'Q')
			p[y][0] = 12;
		if (p[y][0] == 'K')
			p[y][0] = 13;
		if (p[y][0] == 'A')
			p[y][0] = 14;
	}
}