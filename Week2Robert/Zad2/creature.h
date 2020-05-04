#pragma once
#include <iostream>
#include <string>
using namespace std;

class player
{
private:
	string name;
	double gender;
protected:
	player(): gender(0.0) {}
	player(const player& obj) : name(obj.name), gender(obj.gender) {}
	player(const string& _name, double _gender) : name(_name), gender(_gender) {}
	virtual ~player() 
	{
		cout << "player deleted" << endl << endl; 
	}
	virtual void _print() const 
	{ 
		cout << "name: " << name << ", gender: " << gender; 
	}
public:
	void print() const
	{
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")" << endl;
	}
	double get_gender() const
	{
		return gender;
	}
};

class mob: public player
{
private:
	double health;
public:
	mob() : player(), health(0.0) {}
	mob(const mob& obj) : player(obj), health(obj.health) {}
	mob(const string& _name, double _gender, double _health) : player(_name, _gender), health(_health) {}
	double get_health() const
	{
		return health;
	}
	~mob() 
	{ 
		cout << "mob deleted" << endl; 
	}
protected:
	void _print() const
	{
		player::_print();
		cout << ", health: " << health;
	}
};

class hostile_mob : public mob
{
private:
	double range;
public:
	hostile_mob() : mob(), range(0.0) {}
	hostile_mob(const hostile_mob& obj) : mob(obj), range(obj.range) {}
	hostile_mob(const string& _name, double _gender, double _health, double _range) : mob(_name, _gender, _health), range(_range) {}
	double get_range() const
	{
		return range;
	}
	~hostile_mob()
	{
		cout << "hostile_mob deleted" << endl;
	}
protected:
	void _print() const
	{
		mob::_print();
		cout << ", range: " << range;
	}
};

class friendly_mob : public mob
{
private:
	double loot;
public:
	friendly_mob() : mob(), loot(0.0) {}
	friendly_mob(const friendly_mob& obj) : mob(obj), loot(obj.loot) {}
	friendly_mob(const string& _name, double _gender, double _health, double _loot) : mob(_name, _gender, _health), loot(_loot) {}
	double get_loot() const
	{
		return loot;
	}
	~friendly_mob()
	{
		cout << "friendly_mob deleted" << endl;
	}
protected:
	void _print() const
	{
		mob::_print();
		cout << ", loot: " << loot;
	}
};

class animal : public friendly_mob
{
private:
	double taming;
public:
	animal() : friendly_mob(), taming(0.0) {}
	animal(const animal& obj) : friendly_mob(obj), taming(obj.taming) {}
	animal(const string& _name, double _gender, double _health, double _loot, double _taming) : friendly_mob(_name, _gender, _health, _loot), taming(_taming) {}
	double get_taming() const
	{
		return taming;
	}
	~animal()
	{
		cout << "animal deleted" << endl;
	}
protected:
	void _print() const
	{
		mob::_print();
		cout << ", taming: " << taming;
	}
};

class villager : public virtual mob
{
private:
	double interactions;
public:
	villager() : mob(), interactions(0.0) {}
	villager(const villager& obj) : mob(obj), interactions(obj.interactions) {}
	villager(const string& _name, double _gender, double _health, double _interactions) : mob(_name, _gender, _health), interactions(_interactions) {}
	double get_interactions() const
	{
		return interactions;
	}
	~villager()
	{
		cout << "villager deleted" << endl;
	}
	virtual bool interaction_possibility(const mob& obj)
	{
		return obj.get_health() > get_health();
	}
protected:
	void _print() const
	{
		mob::_print();
		cout << ", interactions: " << interactions;
	}
};

