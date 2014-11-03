//
//  main.cpp
//  oaf
//
//  Created by spieler on 31/10/14.
//  Copyright (c) 2014 spieler. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "creature.h"

void Winner(std::vector<Creature*> &creatures);
void Race(std::vector<Creature*> &creatures, std::vector<char> &days);

int main(int argc, const char * argv[]) {

	

    std::ifstream f("input.txt");
    if (f.fail()) {
        std::cout<<"Wrong input file!"<<std::endl;
    }
    
    int n;
    f >> n;
    std::vector<Creature*> creatures(n);
    
    for(int i=0; i<n; i++)
    {
        std::string a;  //name
        char b;         //type
        int c;          //water
        f >> a;
        f>>b;
        f>>c;
        switch(b)
        {
            case 'h' : creatures[i] = new Buggy(a, c); break;
            case 's' : creatures[i] = new Sponge(a, c); break;
            case 'l' : creatures[i] = new Walker(a, c); break;
        }
        
    }
        char c;
        std::vector<char> days;   
        f>>c; 
    while (!f.eof()) {        
        days.push_back(c);  
        f>>c;      
    }
    //std::cout<<days.size()<<std::endl;
    //std::cout<<creatures.size()<<std::endl;
   // for(int i=0; i<days.size(); i++)
    //{
    //	std::cout<<days[i];
    //}
    Race(creatures, days);
    //for (int i=0; i<creatures.size(); i++) {
      //std::cout<<creatures[i]->Name()<<" "<<creatures[i]->Alive()<<" "<<creatures[i]->Headway()<<" "<<creatures[i]->Water()<<std::endl;
    //}
//        for(int i=0; i<n; i++)
//        {
//            std::cout<<creatures[i]->Name()<<" "<<creatures[i]->Water()<<std::endl;
//    
//        }
//    for(int i=0; i<days.size(); i++)
//    {
//        std::cout<<days[i];
//    
//    }
    
    	Winner(creatures);
    
    	
	 
    for(int i=0; i<n; ++i){
        delete creatures[i];
    }
    return 0;
}


void Race(std::vector<Creature*> &creatures, std::vector<char> &days)
{
	for (int j=0; j<creatures.size(); j++)
     {
         for (int i=0; i<days.size(); i++){
         	
         	if(creatures[j]->Alive())
         	{
         		 switch(days[i])
            {
                case 'n': creatures[j]->Sunny();break;
                case 'f' : creatures[j]->Cloudy();break;
                case 'e' : creatures[j]->Rainy();break;

            }
         	}
           else {break;}
           
           
            
        }
    }
}

void Winner(std::vector<Creature*> &creatures)
{
    bool l=false;
    int max=0;
    for (int i=0;  i<creatures.size(); i++) {
        if (max<creatures[i]->Headway() && creatures[i]->Alive()) {
            max=creatures[i]->Headway();
            l=true;
        }
    }
    if(!l)std::cout<<"no survivors!"<<std::endl;
    else std::cout<<"Winner(s):"<<std::endl;
    for(int i=0; l && i<creatures.size(); i++)
    {
    	if(creatures[i]->Headway()==max)
    	{
    		std::cout<<creatures[i]->Name()<<std::endl;
    	}
    }

    
}
    






