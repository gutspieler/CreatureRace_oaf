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





//Buggy's methods
void Buggy::Sunny()
{
	Modify(8,-1,3);   
    
    
    
}

void Buggy::Cloudy()
{
    Modify(8,0,1);
}

void Buggy::Rainy()
{
    
        Modify(8,3,0);
    
    
}
//Sponge's methods
void Sponge::Sunny()
{
   Modify(20,-4,0);
    
}

void Sponge::Cloudy()
{
    
       Modify(20,-1,+1);
    
   
}

void Sponge::Rainy()
{
        Modify(20,6,3);
    
    
    
}
//Walker's methods
void Walker::Sunny()
{
   
     Modify(12,-2,1);
    
}

void Walker::Cloudy()
{
    
        Modify(12,-1,2);
    
   
    
}

void Walker::Rainy()
{
    
       Modify(12,3,1);
    
    
    
}
