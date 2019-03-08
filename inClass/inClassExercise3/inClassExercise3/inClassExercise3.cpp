#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class weapon
{
public:
	virtual void reload()
	{
		cout << "Reload this!\n";
	}
	virtual void fire() = 0;
};

class instantWeapon : public weapon
{
public:
	virtual void reload() override
	{
		cout << "Reload this!\n";
	}
	virtual void fire()
	{
		cout << "Fire Pistol\n";
	}
};

class projectileWeapon : public weapon
{
public:
	virtual void reload() override
	{
		cout << "Reload Rocket\n";
	}
	virtual void fire()
	{
		cout << "Fire Rocket\n";
	}
};

int main()
{
	projectileWeapon rocketLauncher;
	instantWeapon pistol;

	cout << "Fire weapons\n\n";
	rocketLauncher.fire();
	rocketLauncher.reload();

	cout << "\n";

	pistol.fire();
	pistol.reload();

	return 0;
}