#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
class car {
	float HorsePower;
	float TankVolume;
	float MaxSpeed;
	string CarBody;
public:
	car();
	car(float, float, float, string);
	car(const car&);
	~car();

	float getHorsePower() { return HorsePower; }
	void setHorsePower(float hp) { HorsePower = hp; }

	float getTankVolume() { return TankVolume; }
	void setTankVolume(float TV) { TankVolume = TV; }

	float getMaxSpeed() { return MaxSpeed; }
	void setMaxSpeed(float MS) { MaxSpeed = MS; }

	string getCarBody() { return CarBody; }
	void setCarBody(string CB) { CarBody = CB; }

	car& operator=(car&);
	friend std::ostream& operator<<(std::ostream&, car&);
	friend std::istream& operator>>(std::istream&, car&);
	car& operator%=(int);
	float operator>>(int);


	void Start();
	void Drive(int);
	void Refuel();
	void KickWheel();
};
bool operator==(car, car);

car::car()
{
	HorsePower = 100;
	TankVolume = 70;
	MaxSpeed = 60;
	CarBody = "mcqueen";
	cout << "Сработал конструктор без параметров для машины " << endl;
}

car::car(float HP, float TV, float MS, string CB)
{
	HorsePower = HP;
	TankVolume = TV;
	MaxSpeed = MS;
	CarBody = CB;
	cout << "Сработал конструктор с параметрами для машины " << endl;
}

car::car(const car& other)
{
	HorsePower = other.HorsePower;
	TankVolume = other.TankVolume;
	MaxSpeed = other.MaxSpeed;
	CarBody = other.CarBody;
	cout << "Сработал конструктор копирования для машины " << endl;
}

car::~car()
{
	cout << "Машина сломалась :(" << endl;
}


car& car::operator=(car& other)
{
	HorsePower = other.HorsePower;
	TankVolume = other.TankVolume;
	MaxSpeed = other.MaxSpeed;
	CarBody = other.CarBody;

	cout << "Сработал оператор присваивания для машины " << endl;

	return *this;
}



std::ostream& operator<<(std::ostream& os, car& obj)
{
	return os <<
		"Лошадиных сил: " << obj.HorsePower << endl <<
		"Объем бака: " << obj.TankVolume << " литров" << endl <<
		"Максимальная скорость: " << obj.MaxSpeed << " км/ч" << endl <<
		"Тип кузова: " << obj.CarBody << endl;

}

std::istream& operator>>(std::istream& is, car& obj)
{
	is >> obj.HorsePower
		>> obj.TankVolume
		>> obj.MaxSpeed
		>> obj.CarBody;

	return is;
}

bool operator==(car a, car b)
{
	if (
		(a.getCarBody() == b.getCarBody()) &&
		(a.getHorsePower() == b.getHorsePower()) &&
		(a.getMaxSpeed() == b.getMaxSpeed()) &&
		(a.getTankVolume() == b.getTankVolume())
		)
		return true;
	else
		return false;
}

car& car::operator%=(int procent)
{
	TankVolume += TankVolume * procent / 100.0;

	cout << "Сработал оператор %= для машины " << endl;

	return *this;
}

float car::operator>>(int k)
{
	cout << "Сработал оператор >> (промчаться вперед, кчау) для машины " << endl;
	return k * HorsePower;
}

void car::Start()
{
	cout << "Оу да, маквин готов!" << endl;
}

void car::Drive(int s)
{
	cout << "Врум, врум, врум, машина проехала "<<s<<" километров" << endl;
}

void car::Refuel()
{
	cout << "Машину заправили" << endl;
}

void car::KickWheel()
{
	if (rand() % 3 == 0)
		cout << "Виу, виу, виу, сработала сигнализация" << endl;
	else
		cout << "Машина терпит данное унижение" << endl;
}

void workCar(car& C) {
    int choice;
    float value;
    bool exit = true;

    do {
        system("cls");
        cout << "Выберите пункт меню:" << endl;
        cout << "1 - Задать параметры машины" << endl;
        cout << "2 - Завести машину (Start)" << endl;
        cout << "3 - Поехать (Drive)" << endl;
        cout << "4 - Заправить машину (Refuel)" << endl;
        cout << "5 - Пнуть колесо (KickWheel)" << endl;
        cout << "6 - Вывести параметры машины" << endl;
        cout << "7 - Увеличить бак (operator%=)" << endl;
        cout << "8 - Промчаться вперед (operator>>)" << endl;
        cout << "9 - Присвоить значения другой машины (operator=)" << endl;
        cout << "0 - Выход" << endl;
        cin >> choice;
switch (choice) {
        case 1:
            cout << "Введите (Лошадиные силы Объем бака Макс скорость Кузов): ";
            cin >> C;
            system("pause");
            break;

        case 2:
            system("cls");
            C.Start();
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Введите расстояние (км): ";
            cin >> value;
            C.Drive(value);
            system("pause");
            break;

        case 4:
            system("cls");
            C.Refuel();
            system("pause");
            break;

        case 5:
            system("cls");
            C.KickWheel();
            system("pause");
            break;

        case 6:
            system("cls");
            cout << C;
            system("pause");
            break;

        case 7:
            system("cls");
            cout << "Введите процент увеличения бака: ";
            cin >> value;
            C %= (int)value;
            system("pause");
            break;

        case 8:
            system("cls");
            cout << "Введите коэффициент: ";
            cin >> value;
            cout << "Результат: " << (C >> (int)value) << endl;
            system("pause");
            break;

        case 9: {
            car temp;
            cout << "Введите параметры временной машины: ";
            cin >> temp;
            C = temp;
            system("pause");
            break;
        }

        case 0:
            exit = false;
            break;

        default:
            cout << "Неверный выбор!" << endl;
            system("pause");
        }
    } while (exit);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    car A;
    car B;
    int choice;
    bool exit = true;

    do {
        system("cls");
        cout << "Выберите пункт меню:" << endl;
        cout << "1 - Работать с машиной A" << endl;
        cout << "2 - Работать с машиной B" << endl;
        cout << "3 - Сравнить машины (operator==)" << endl;
        cout << "0 - Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            workCar(A);
            break;

        case 2:
            workCar(B);
            break;

        case 3:
            system("cls");
            if (A == B)
                cout << "Машины одинаковы" << endl;
            else
                cout << "Машины разные" << endl;
            system("pause");
            break;

        case 0:
            exit = false;
            break;

        default:
            cout << "Неверный выбор!" << endl;
            system("pause");
        }
    } while (exit);

    return 0;
}