//
//  creature.h
//  oaf
//
//  Created by spieler on 31/10/14.
//  Copyright (c) 2014 spieler. All rights reserved.
//

#ifndef oaf_creature_h
#define oaf_creature_h

#include <string>

class Creature{
    
public:
    
    
//query methods:
    bool Alive()const{return water>0;}
    std::string Name()const{return name;}
    int Headway()const{return moved;}
    int Water()const{return water;}

    
//abstrac methods:
    virtual void Sunny(){}
    virtual void Cloudy(){}
    virtual void Rainy(){}
    virtual ~Creature(){}
    
    
    
protected:
    Creature(std::string &a, int &b):name(a), water(b), moved(0){}
    std::string name;
    int water;
    int moved;
    
};

class Buggy:public Creature
{
public:
    Buggy(std::string &a, int &b):Creature(a, b){}
    void Sunny();
    void Cloudy();
    void Rainy();
};

class Sponge:public Creature
{
public:
    Sponge(std::string &a, int &b):Creature(a, b){}
    void Sunny();
    void Cloudy();
    void Rainy();
};

class Walker:public Creature
{
public:
    Walker(std::string &a, int &b):Creature(a, b){}
    void Sunny();
    void Cloudy();
    void Rainy();
};




#endif
