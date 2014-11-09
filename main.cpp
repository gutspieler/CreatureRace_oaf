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
char ch;
	do{
        std::string fname;
        if(argc>1)fname = argv[1];
        else{
            std::cout << "File name: ";
            std::cin >> fname;
        }
    
    
    std::ifstream f(fname.c_str());
    if (f.fail()) {
        std::cout<<"Wrong input file!"<<std::endl;
        break;
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

    //Write the result
    Race(creatures, days);   
    
    
    	
	 
    std::cout<<"Rerun? (Y/N) "; std::cin>>ch;
}while(ch!='n' && ch!='N');
    return 0;
}

    //Race function:
    //this function simulate the contest of the creatures according to days
    //inside the function call the Winner() function
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
    Winner(creatures);
    //destruct the elements of the "creatures" vector 
        for(int i=0; i<creatures.size(); ++i){
        delete creatures[i];
    }
}

//Winner function:
//ascertain winner(s), and print the result 
void Winner(std::vector<Creature*> &creatures)
{
    bool l=false; //check survivors
    int max=0;
    for (int i=0;  i<creatures.size(); i++) {
        if (max<=creatures[i]->Headway() && creatures[i]->Alive()) {
            max=creatures[i]->Headway();
            l=true;
        }
    }
    if(!l)std::cout<<"no survivors!"<<std::endl; 
    else std::cout<<"Winner(s):"<<std::endl;
    for(int i=0; l && i<creatures.size(); i++)
    {
    	if(creatures[i]->Headway()==max && creatures[i]->Alive())
    	{
    		std::cout<<creatures[i]->Name()<<std::endl;
    	}
    }

    
}
    






