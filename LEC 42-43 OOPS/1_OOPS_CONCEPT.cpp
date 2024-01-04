//OOPS


#include<iostream>
#include<string.h>
using namespace std;

//class

class hero
{
    //properties/members
    public:
    char *name;
    int health;
    char level;

    //static keyword
    static int timetocomplete;

    void print()
    {
        cout<<health<<endl;
        cout<<level<<endl;
    }


    //getter

    int gethealth()
    {
        return health;
    }

    char getlevel()
    {
        return level;
    }


    //setter : can also be used to check any condition

    void sethealth(int h)
    {
        health=h;
    }

    void setlevel(char l)
    {
        level=l;
    }

    //constructor

    hero()
    {
        name = new char[100];
        cout<<"simple constructor called"<<endl;
    }

    //parametrised constructor

    hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    //default copy constructor--> shallow copy

    //custom copy constructor--> deep copy

    hero(hero& temp)
    {
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name = ch;

        this->health = temp.health;
        this->level = temp.level;

    }


    //destructor

    ~hero()
    {
        cout<<"destructor called"<<endl;
    }


    //static funcn

    static int random()
    {
        return timetocomplete;
    }

    

};


int hero::timetocomplete = 10;


int main()
{
    //object
    //static allocation

    hero h1;
    h1.health = 70;
    h1.level = 'A';

    cout<<"size : "<<sizeof(h1)<<endl;
    cout<<h1.health<<endl;
    cout<<h1.level<<endl;


    //using getter

    cout<<h1.gethealth()<<endl;
    cout<<h1.getlevel()<<endl;

    //using setter

    h1.sethealth(80);
    h1.setlevel('B');


    //dynamic allocation

    hero *h2 = new hero; 

    h2->sethealth(50);
    h2->setlevel('C'); 
    
    cout<<(*h2).gethealth()<<endl;
    cout<<(*h2).getlevel()<<endl;

    cout<<h2->gethealth()<<endl;
    cout<<h2->getlevel()<<endl;

    hero h3(h1);

    h1.print();
    h2->print();
    h3.print();

    // copy assignment operator

    h1 = h3;

    //dynamic ke liye manually destuctor

    delete h2;
    


}