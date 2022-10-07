#include <iostream>
using namespace std;

class Transport
{
	string type;
	string color;
	int speed;
	int fuelcons;
	int passenger;
public:
	Transport()
	{
		type = color = "";
		speed = fuelcons = passenger = 0;
	}
	Transport(string t, string c, int s, int f, int p)
	{
		type = t;
		color = c;
		speed = s;
		fuelcons = f;
		passenger = p;
	}
	virtual void Show()
	{
		cout << "Transport: " << type << endl;
		cout << "Color: " << color << endl;
		cout << "Speed: " << speed << " km\\h\n";
		cout << "Fuel consumption: " << fuelcons << " L\\100 km\n";
		cout << "Passengers: " << passenger << endl;
	}
	virtual void Init()
	{
		cout << "Transport: ";
		cin >> type;
		cout << "Color: ";
		cin >> color;
		cout << "Speed: ";
		cin >> speed;
		cout << "Fuel consumption: ";
		cin >> fuelcons;
		cout << "Passengers: ";
		cin >> passenger;
	}
	virtual int GetFuel()
	{
		return fuelcons;
	}
};

class Plane :public Transport
{
	string company;
public:
	Plane()
	{
		company = "";
	}
	Plane(string t, string c, int s, int f, int p, string co) :Transport(t, c, s, f, p)
	{
		company = co;
	}
	void Show()
	{
		Transport::Show();
		cout << "Company: " << company << endl;
	}
	void Init()
	{
		Transport::Init();
		cout << "Company: ";
		cin >> company;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Cycle :public Transport
{
	double tire_size;
public:
	Cycle()
	{
		tire_size = 0;
	}
	Cycle(string t, string c, int s, int f, int p, double ti) :Transport(t, c, s, 0, p)
	{
		tire_size = ti;
	}
	void Show()
	{
		Transport::Show();
		cout << "Tire Diameter: " << tire_size << " sm\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Tire size: ";
		cin >> tire_size;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Jeep :public Transport
{
	bool offroad;
public:
	Jeep()
	{
		offroad = false;
	}
	Jeep(string t, string c, int s, int f, int p, bool off) :Transport(t, c, s, f, p)
	{
		offroad = f;
	}
	void Show()
	{
		Transport::Show();
		if (offroad)
			cout << "Can drive on offroad\n";
		else
			cout << "Cant drive on offroad\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "For offroad?\t1.Yes\t0.No\n";
		cin >> offroad;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Ship :public Transport
{
	double carr_cap;
public:
	Ship()
	{
		carr_cap = 0;
	}
	Ship(string t, string c, int s, int f, int p, double cc) :Transport(t, c, s, f, p)
	{
		carr_cap = cc;
	}
	void Show()
	{
		Transport::Show();
		cout << "Carrying capacity: " << carr_cap << " tones\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Carrying capacity: ";
		cin >> carr_cap;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

class Truck :public Transport
{
	int HP;
public:
	Truck()
	{
		HP = 0;
	}
	Truck(string t, string c, int s, int f, int p, int hp) :Transport(t, c, s, f, p)
	{
		HP = hp;
	}
	void Show()
	{
		Transport::Show();
		cout << "Horse power: " << HP << "\n";
	}
	void Init()
	{
		Transport::Init();
		cout << "Horse power: ";
		cin >> HP;
	}
	int GetFuel()
	{
		return Transport::GetFuel();
	}
};

int menu1()
{
	int choose;
	cout << "1.Plane\n2.Cycle\n3.Jeep\n4.Ship\n5.Truck\n";
	cin >> choose;
	return choose;
}

int menu2()
{
	int choose;
	cout << "1.Show\n2.Show fuel consumption per 100km\n";
	cin >> choose;
	return choose;
}

int main()
{
	int choose_1 = menu1();
	Transport* Tptr = nullptr;
	switch (choose_1)
	{
	case 1:
		Tptr = new Plane();
		Tptr->Init();
		break;
	case 2:
		Tptr = new Cycle();
		Tptr->Init();
		break;
	case 3:
		Tptr = new Jeep();
		Tptr->Init();
		break;
	case 4:
		Tptr = new Ship();
		Tptr->Init();
		break;
	case 5:
		Tptr = new Truck();
		Tptr->Init();
		break;
	default:
		break;
	}
	system("cls");
	int choose_2 = menu2();
	switch (choose_2)
	{
	case 1:
		Tptr->Show();
		break;
	case 2:
		cout << Tptr->GetFuel();
		break;
	default:
		break;
	}
	delete Tptr;
}