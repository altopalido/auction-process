#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

enum Movement{impressionism,expressionism,naturalism};
enum Condition{bad,good,excellent};
enum Technique{oil,aquarelle,tempera};
enum Material{iron,stone,wood};

class artifact{
public:
	artifact(int index,string creator,int year);
	artifact(const artifact &a);
	artifact();
	~artifact();
	virtual void getInfo();
	void getIndex();
	virtual void evaluate(Movement mov,Condition con)=0;
private:
	int index;
	string creator;
	int year;
};

class masterpiece:public artifact{
public:
	masterpiece(int index,string creator,int year,Movement movement,Condition condition);
	masterpiece(const masterpiece &m);
	masterpiece();
	~masterpiece();
	Condition condition;
	void getInfo();
protected:
	Movement movement;
};

class paintings:public masterpiece{
public:
	paintings(int index,string creator,int year,Movement movement,Condition condition,float length,float width,Technique technique);
	paintings(const paintings &p);
	paintings();
	~paintings();
	void getInfo();
	void evaluate(Movement mov,Condition con=good);
private:
	float length;
	float width;
	Technique technique;
	float surface;
};

class sculptures:public masterpiece{
public:
	sculptures(int index,string creator,int year,Movement movement,Condition condition,float volume,Material material);
	sculptures(const sculptures &s);
	sculptures();
	~sculptures();
	void getInfo();
	void evaluate(Movement mov,Condition con=excellent);
private:
	float volume;
	Material material;
};

void auction(artifact* pin[],Movement mov,Condition con);
















