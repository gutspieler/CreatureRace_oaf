//
//  creature.cpp
//  oaf
//
//  Created by spieler on 31/10/14.
//  Copyright (c) 2014 spieler. All rights reserved.
//

#include "creature.h"
#include <string.h>
#include <iostream>

//Buggy methods
void Buggy::Sunny()
{
	
   
        water=water-1;
        moved=moved+3;
    
    
}

void Buggy::Cloudy()
{
    moved=moved+1;
}

void Buggy::Rainy()
{
    
        if(water+3<8) {water=water+3;}
        else {water=8;}
    
    
}
//Sponge methods
void Sponge::Sunny()
{
    water=water-4;
    
}

void Sponge::Cloudy()
{
    
        water=water-1;
        moved=moved+1;
    
   
}

void Sponge::Rainy()
{
        if (water+6<20){water=water+6;}
        else {water=20;}
        moved=moved+3;
    
    
    
}
//Walker methods
void Walker::Sunny()
{
   
        water=water-2;
        moved=moved+1;
    
    
}

void Walker::Cloudy()
{
    
        water=water-1;
        moved=moved+2;
    
   
    
}

void Walker::Rainy()
{
    
        if(water+3<12){water=water+3;}
        else {water=12;}
        moved=moved+1;
    
    
    
}
