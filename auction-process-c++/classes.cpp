#include "classes.h"

artifact::artifact(int index,string creator,int year):index(index),creator(creator),year(year){
	cout<<"Creating an instance of artifact"<<endl;
}

artifact::artifact(const artifact &a){
	index=a.index;
	creator=a.creator;
	year=a.year;
}

artifact::artifact(){
	index=-1;
	creator="-";
	year=-1;
}

artifact::~artifact(){
	cout<<"Destroying an instance of artifact"<<endl;
}

void artifact::getInfo(){
	cout<<"The creator of the artifact is "<<creator<<endl;
	cout<<"The creation's year is "<<year<<endl;
}

void artifact::getIndex(){
	cout<<"Index: "<<index<<endl;
}

masterpiece::masterpiece(int index,string creator,int year,Movement movement,Condition condition):artifact(index,creator,year),movement(movement),condition(condition){
	cout<<"Creating an instance of masterpiece"<<endl;
	/*if(movement!=impressionism && movement!=expressionism && movement!=naturalism){
		cout<<"This movement does not exist"<<endl;
		exit(0);
	}
	if(condition!=bad && condition!=good && condition!=excellent){
		cout<<"This condition does not exist"<<endl;
		exit(0);
	}*/
}

masterpiece::masterpiece(const masterpiece &m):artifact(m){
	condition=m.condition;
	movement=m.movement;
}

masterpiece::masterpiece():artifact(){
	movement=impressionism;
	condition=bad;
}

masterpiece::~masterpiece(){
	cout<<"Destroying an instance of masterpiece"<<endl;
}

void masterpiece::getInfo(){
	artifact::getInfo();
	switch(movement){
		case 0:
			cout<<"Masterpiece's movement is impressionism"<<endl;
			break;
		case 1:
			cout<<"Masterpiece's movement is expressionism"<<endl;
			break;
		case 2:
			cout<<"Masterpiece's movement is naturalism"<<endl;
			break;
	}	

	switch(condition){
		case 0:
			cout<<"Masterpiece's condition is bad"<<endl;
			break;
		case 1:
			cout<<"Masterpiece's condition is good"<<endl;
			break;
		case 2:
			cout<<"Masterpiece's condition is excellent"<<endl;
			break;
	}	
}

paintings::paintings(int index,string creator,int year,Movement movement,Condition condition,float length,float width,Technique technique):masterpiece(index,creator,year,movement,condition),length(length),width(width),technique(technique){
	cout<<"Creating an instance of paintings"<<endl;
	/*if(technique!=oil && technique!=aquarelle && technique!=tempera){
		cout<<"This technique does not exist"<<endl;
		exit(0);
	}*/
}

paintings::paintings(const paintings &p):masterpiece(p){
	length=p.length;
	width=p.width;
	technique=p.technique;
}

paintings::paintings():masterpiece(){
	length=-1;
	width=-1;
	technique=oil;
}

paintings::~paintings(){
	cout<<"Destroying an instance of paintings"<<endl;
}

void paintings::getInfo(){
	masterpiece::getInfo();
	surface=length*width;
	switch(technique){
		case 0:
			cout<<"Painting's technique is oil"<<endl;
			break;
		case 1:
			cout<<"Painting's technique is aquarelle"<<endl;
			break;
		case 2:
			cout<<"Painting's technique is tempera"<<endl;
			break;
	}	

	cout<<"Painting's surface is: "<<surface<<" cm^2"<<endl;
}

void paintings::evaluate(Movement mov,Condition con){
	if((mov==movement && con==condition) || (mov==movement && con==excellent && condition==good))
		cout<<"acceptable painting"<<endl;
	
	else
		cout<<"not acceptable painting"<<endl;	
}

sculptures::sculptures(int index,string creator,int year,Movement movement,Condition condition,float volume,Material material):masterpiece(index,creator,year,movement,condition),volume(volume),material(material){
	cout<<"Creating an instance of sculptures"<<endl;
	/*if(material!=iron && material!=stone && material!=wood){
		cout<<"This material does not exist"<<endl;
		exit(0);
	}*/
}

sculptures::sculptures(const sculptures &s):masterpiece(s){
	volume=s.volume;
	material=s.material;
}

sculptures::sculptures():masterpiece(){
	volume=-1;
	material=iron;
}

sculptures::~sculptures(){
	cout<<"Destroying an instance of sculptures"<<endl;
}

void sculptures::getInfo(){
	masterpiece::getInfo();
	cout<<"Sculpture's volume is: "<<volume<<" cm^3"<<endl;
	switch(material){
		case 0:
			cout<<"Sculpture's material is iron"<<endl;
			break;
		case 1:
			cout<<"Sculpture's material is stone"<<endl;
			break;
		case 2:
			cout<<"Sculpture's material is wood"<<endl;
			break;
	}	
}

void sculptures::evaluate(Movement mov,Condition con){
	if(mov==movement && con==condition)
		cout<<"acceptable sculpture"<<endl;
	else
		cout<<"not acceptable sculpture"<<endl;
}

void auction(artifact* pin[],Movement mov,Condition con){
	int i=0;
	//for(i=0;i<((sizeof(pin))/(sizeof(pin[0])));i++){
	while(pin[i]!=NULL){
		cout<<"information about artifact "<<i+1<<endl;
		pin[i]->getIndex();
		pin[i]->getInfo();
		pin[i]->evaluate(mov,con);
		cout<<endl;
		i++;
	}
}











