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

void GameManager::printHeroes() const
{
    cout<<"----------================ Healer Category ================----------"<<endl;
    cout<<"================  White Doctor  ================"<<endl;
    cout<<"Role : "<<"Healer"<<endl;
    cout<<"Cooldown : "<<4<<endl;
    cout<<"HP = 550"<<endl;
    cout<<"---------- Normal Ability ----------"<<endl;
    cout<<"---- Aspirine : Heals a random teammate for 40 HP and deals 40 damage to a selected enemy."<<endl;
    cout<<"---- Usage Energy = 3"<<endl;
    cout<<"---- Doping : For two turns, a target teammate deals 20% more damage."<<endl;
    cout<<"---- Usage Energy = 4"<<endl;
    cout<<"---------- Special Ability ----------"<<endl;
    cout<<"---- Name: Amaliyat otagh amal"<<endl;
    cout<<"---- Effect: Revives a dead teammate (cannot be self) with 200 Health and cleanses all negative effects"<<endl;
    cout<<"---- Energy Cost: 4"<<endl;
    cout<<"---- Limitation: Can only be used once every 4 turns."<<endl;



    cout<<"================  Small Taha  ================"<<endl;
    cout<<"Role : "<<"Healer"<<endl;
    cout<<"Cooldown : "<<3<<endl;
    cout<<"HP = 500"<<endl;
    cout<<"---------- Normal Ability ----------"<<endl;
    cout<<"---- Tigh Tiz : Heals the lowest-health teammate for 20 HP and deals 30 damage to a selected enemy."<<endl;
    cout<<"---- Usage Energy = 2"<<endl;
    cout<<"---- Serom Khon : Heals a target teammate for 40 HP over 2 turns."<<endl;
    cout<<"---- Usage Energy = 4"<<endl;
    cout<<"---------- Special Ability ----------"<<endl;
    cout<<"---- Name: Gharantine Kamel"<<endl;
    cout<<"---- Effect: Heals the lowest-health teammate for 200 HP."<<endl;
    cout<<"---- Energy Cost: 4"<<endl;
    cout<<"---- Limitation: Can only be used once every 3 turns."<<endl;



    cout<<"----------================ Defender Category ================----------"<<endl;
    cout<<"================  dani golang  ================"<<endl;
    cout<<"Role : "<<"Defender"<<endl;
    cout<<"Cooldown : "<<4<<endl;
    cout<<"HP = 600"<<endl;
    cout<<"---------- Normal Ability ----------"<<endl;
    cout<<"---- Ghofli : Deals 20 damage to an enemy. If used on the same target consecutively, the damage is multiplied by 1.61."<<endl;
    cout<<"---- Usage Energy = 2"<<endl;
    cout<<"---- Fil Kosh : Deals 50 damage to the selected target and also to the enemy with the highest health."<<endl;
    cout<<"---- Usage Energy = 4"<<endl;
    cout<<"---------- Special Ability ----------"<<endl;
    cout<<"---- Name: Sangar Khanevade"<<endl;
    cout<<"---- Effect: Applies a shield with 250 health to the lowest-health teammate for 2 turns. The effect expires when the shield health is consumed or after 2 turns."<<endl;
    cout<<"---- Energy Cost: 4"<<endl;
    cout<<"---- Limitation: Can only be used once every 4 turns."<<endl;



    cout<<"----------================ Attacker Category ================----------"<<endl;
    cout<<"================  Amin Emeni  ================"<<endl;
    cout<<"Role : "<<"Attacker"<<endl;
    cout<<"Cooldown : "<<3<<endl;
    cout<<"HP = 500"<<endl;
    cout<<"---------- Normal Ability ----------"<<endl;
    cout<<"---- Akharin Feshang : Deals 55 damage to the target. If this ability delivers the killing blow, the damage is doubled."<<endl;
    cout<<"---- Usage Energy = 3"<<endl;
    cout<<"---- Zarbe Be Khodi : Sacrifices 25 HP from a teammate to heal himself for 75 HP."<<endl;
    cout<<"---- Usage Energy = 3"<<endl;
    cout<<"---------- Special Ability ----------"<<endl;
    cout<<"---- Name: Faryad Na Amni"<<endl;
    cout<<"---- Effect: Deals 250 damage to a random enemy. Deals 30 damage to two teammates."<<endl;
    cout<<"---- Energy Cost: 4"<<endl;
    cout<<"---- Limitation: Can only be used once every 3 turns."<<endl;



    cout<<"================  Big Taha  ================"<<endl;
    cout<<"Role : "<<"Attacker"<<endl;
    cout<<"Cooldown : "<<4<<endl;
    cout<<"HP = 500"<<endl;
    cout<<"---------- Normal Ability ----------"<<endl;
    cout<<"---- Ragbar : Deals 30 damage to all members of the enemy team."<<endl;
    cout<<"---- Usage Energy = 3"<<endl;
    cout<<"---- Xray : Deals 90 damage to the target and becomes hidden for one turn. (While hidden, can only be hurt by AoE damage)."<<endl;
    cout<<"---- Usage Energy = 4"<<endl;
    cout<<"---------- Special Ability ----------"<<endl;
    cout<<"---- Name: Entegham Baradar"<<endl;
    cout<<"---- Effect: A random enemy is marked. On the next turn, the mark triggers: if the target’s health is less than 360, he is instantly killed. If their health is higher, they take only 200 damage."<<endl;
    cout<<"---- Energy Cost: 3"<<endl;
    cout<<"---- Limitation: Can only be used once every 4 turns."<<endl;



    cout<<"================  Pouya Kazh Dam  ================"<<endl;
    cout<<"Role : "<<"Attacker"<<endl;
    cout<<"Cooldown : "<<3<<endl;
    cout<<"HP = 550"<<endl;
    cout<<"---------- Normal Ability ----------"<<endl;
    cout<<"---- Khanjar : Deals 40 damage to the target. If scorpions are exists, this ability also activates them."<<endl;
    cout<<"---- Usage Energy = 2"<<endl;
    cout<<"---- Aghrab : Locks a scorpion onto the target. This scorpion deals 20 damage per turn. However, if activated by the Khanjar ability, each scorpion will deal 60 damage instead."<<endl;
    cout<<"---- Usage Energy = 4"<<endl;
    cout<<"---------- Special Ability ----------"<<endl;
    cout<<"---- Name: Dam Kazh Dam"<<endl;
    cout<<"---- Effect: This ability is always available. Upon activation, the hero (“Pouya Kazhdom”) enters a stealth state (becomes invisible) and only vulnerable to group damage. While in this state, they cannot use any of their other abilities. This state persists for a minimum of 3 game rounds. After the 3-round duration, only this ability reactivates, dealing 450 damage to a random enemy, and the hero exits the stealth state, returning to their normal condition."<<endl;
    cout<<"---- Energy Cost: 5"<<endl;
    cout<<"---- Limitation: Can only be used once every 4 turns."<<endl;


    cout<<"----------================ Joker Category ================----------"<<endl;
    cout<<"================ Agha Shahriar ================"<<endl;
    cout<<"Role : "<<"Joker"<<endl;
    cout<<"Cooldown : "<<4<<endl;
    cout<<"HP = 500"<<endl;
    cout<<"---------- Normal Ability ----------"<<endl;
    cout<<"---- Maskhare : Deals 60 damage to its target, but its shot has a 20% chance to miss."<<endl;
    cout<<"---- Usage Energy = 2"<<endl;
    cout<<"---- Lajbaz : Deals 100 damage to a random enemy other than its target."<<endl;
    cout<<"---- Usage Energy = 4"<<endl;
    cout<<"---------- Special Ability ----------"<<endl;
    cout<<"---- Name: Makos Sazi Jahan (Ba Tashdid)"<<endl;
    cout<<"---- Effect: Any damage applied to an enemy heals it instead. Any healing applied to an teammate damages it instead."<<endl;
    cout<<"---- Energy Cost: 8"<<endl;
    cout<<"---- Limitation: Can only be used once every 4 turns.";



}

bool GameManager::IsWorldInversed() const
{
    return IsWorldInverse; 
}

void GameManager::ActivateWorldInversion(int round)
{
    WorldInversionRoundRemaining = round;
    IsWorldInverse = true;
}
