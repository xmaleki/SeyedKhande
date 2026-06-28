#include <GameManager.h>
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include <limits>
#include "AghaShahriar.h"
#include "AminEmeni.h"
#include "BigTaha.h"
#include "danigolang.h"
#include "PouyaKazhDam.h"
#include "SmallTaha.h"
#include "WhiteDoctor.h"

using namespace std;



void GameManager::initializeHeroes()
{
    for(int i = 0; i < 2; i++)
    {
        cout<<"Player "<< CurrentTeamIndex + 1 <<", Choose your heroes :"<<endl;
        cout<<"1. White Doctor \n2. Small Taha \n3. dani golang \n4. Amin Emeni \n5. Big Taha\n6. Pouya Kazh Dam\n7. Agha Shahriar\n";
        
        vector<int> chosenHeroes;

        for(int j = 0; j < 3; j++)
        {
            int choose;
            while(true)
            {
                cout<<"Choose hero number "<< j + 1 <<" : ";
                cin>>choose;

                if(find(chosenHeroes.begin(), chosenHeroes.end(), choose) != chosenHeroes.end())
                {
                    cout<<"This hero has already been selected for your team. Please choose another one."<< endl;
                    continue;
                }

                if(choose < 1 || choose > 7)
                {
                    cout<<"Invalid choice. Please enter a number between 1 and 5."<< endl;
                    continue;
                }

                break;
            }

            chosenHeroes.push_back(choose);
            
            switch (choose)
            {
            case 1:
                teams[i].heroes.push_back(make_unique<WhiteDoctor>());
                break;
            case 2:
                teams[i].heroes.push_back(make_unique<SmallTaha>());
                break;
            case 3:
                teams[i].heroes.push_back(make_unique<danigolang>());
                break;
            case 4:
                teams[i].heroes.push_back(make_unique<AminEmeni>());
                break;
            case 5:
                teams[i].heroes.push_back(make_unique<BigTaha>());
                break;   
            case 6:
                teams[i].heroes.push_back(make_unique<PouyaKazhDam>());
                break; 
            case 7:
                teams[i].heroes.push_back(make_unique<AghaShahriar>());
                break;              

            default:
                cout<<"Invalid choice. Please try again."<<endl;
                break;
            }
        }
    }

    cin.ignore();
}
