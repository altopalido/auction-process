#include "classes.h"
#include <time.h>
#include <cstdlib>
#include <sstream>


int main(int argc,char *argv[]){
	srand(time(NULL));
	int i,move,num,cond,creator;
	stringstream ss;
	string movement=argv[2];
	string condition=argv[3];

	if(argc!=4){
		cout<<"Lathos plhthos parametrwn"<<endl;
		exit(2);
	}

	if(movement=="impressionism")
		move=0;
	else if(movement=="expressionism")
		move=1;
	else if(movement=="naturalism")
		move=2;
	else{
		cout<<"There is no such movement.Try again!"<<endl;
		exit(0);
	}

	if(condition=="bad")
		cond=0;
	else if(condition=="good")
		cond=1;
	else if(condition=="excellent")
		cond=2;
	else{
		cout<<"There is no such condition.Try again!"<<endl;
		exit(0);
	}

	num=atoi(argv[1]);

	// *****  pinakes gia apothikeush twn tuxewn arxikopoihsewn twn antikeimenwn  *****
	int year_array[num];
	float length_array[num];
	float width_array[num];
	float volume_array[num];
	Movement movement_array[num];
	Condition condition_array[num];
	Material material_array[num];
	Technique technique_array[num];
	string creator_array[num];
	// *****  *****  *****

	for(i=0;i<num;i++){
		ss<<(1+(rand()%100));
		string str=ss.str();
		year_array[i]=1800+(rand()%(2017-1800+1));//random year from 1800-2017
		length_array[i]=2+static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(100-2)));//rand length 2-100cm
		width_array[i]=2+static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(100-2)));//rand width 2-100cm
		volume_array[i]=2+static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(100-2)));//rand volume 2-100cm^3
		movement_array[i]=static_cast<Movement>(rand()%3);
		condition_array[i]=static_cast<Condition>(rand()%3);
		material_array[i]=static_cast<Material>(rand()%3);
		technique_array[i]=static_cast<Technique>(rand()%3);
		creator_array[i]="Creator " + str;
		ss.str("");//katharisma 
	}
	
	sculptures objects[num];//pinakas antikeimenwn sculptures sta opoia tha deixnoun oi deiktes tou pinaka object_array
	paintings object[num];//pinakas antikeimenwn paintings sta opoia tha deixnoun oi deiktes tou pinaka object_array 
	artifact* object_array[num+1];//pinakas deiktwn se artifacts pou mpainei orisma sthn auction
	artifact *ptr;
	for(i=0;i<num/2;i++){
		paintings paint(i+1,creator_array[i],year_array[i],movement_array[i],condition_array[i],length_array[i],width_array[i],technique_array[i]);
		object[i]=paint;
		ptr=&object[i];
		object_array[i]=ptr;
	}

	for(i=num/2;i<=num;i++){
		if(i==num){
			object_array[i]=NULL;
		}
		else{
			sculptures sculpt(i+1,creator_array[i],year_array[i],movement_array[i],condition_array[i],volume_array[i],material_array[i]);
			objects[i]=sculpt;
			ptr=&objects[i];
			object_array[i]=ptr;
		}
	}
	cout<<endl;
	auction(object_array,static_cast<Movement>(move),static_cast<Condition>(cond));	
}

