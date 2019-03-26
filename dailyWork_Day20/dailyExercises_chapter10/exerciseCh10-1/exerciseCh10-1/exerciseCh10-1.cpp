#include "pch.h"
#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy();
	void Attack() const;

protected:
	int m_Damage;
};

Enemy::Enemy() :
	m_Damage(10)
{}

void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	Boss();
	int SpecialAttack() const;

private:
	int m_DamageMultiplier;
};

Boss::Boss() :
	m_DamageMultiplier(3)
{}

int Boss::SpecialAttack() const
{
	int dmg = (m_DamageMultiplier * m_Damage);
	cout << "Special Attack inflicts " << dmg;
	cout << " damage points!\n";
	return dmg;
}

class FinalBoss : public Boss
{
public:
	void MegaAttack() const;
private:
	const int m_DamageMultiplier = 10;

};

void FinalBoss::MegaAttack() const
{
	cout << "Mega Attack inflicts " << (m_DamageMultiplier * SpecialAttack());
	cout << " damage points!\n";
}

int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();

	cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();

	cout << "\nCreating a Final Boss.\n";
	FinalBoss fBoss1;
	fBoss1.Attack();
	fBoss1.MegaAttack();
	
	return 0;
}
