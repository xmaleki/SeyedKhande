#include <GameManager.h>
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include <limits>
#include "AghaShahriar.h"
#include "AminEmeni.h"
#include "BigTaha.h"
#include "DaniGolang.h"
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
                teams[i].heroes.push_back(make_unique<DaniGolang>());
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

bool GameManager::CanTeamMakeAnyMove(int teamIndex)
{
    int currentEnergy = teams[teamIndex].Energy;

    for(const auto& heroPtr : teams[teamIndex].heroes)
    {
        if(heroPtr->CanUseAbility(currentEnergy, RoundCounter, teams[teamIndex]))
            return true;
    }
    return false;
}


int GameManager::GetRoundCounter() const
{
    return RoundCounter;
}


void GameManager::Run()
{
        cout<<"===================== Welcome To The Seyed Khande ====================="<<endl;
        cout<<"In this game, two teams will compete. Each team must select three heroes. Please proceed with your hero selection."<<endl<<endl;
        printHeroes();
        initializeHeroes();

        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> RandGen(0,1);
    
        CurrentTeamIndex = RandGen(generator);
        StartingTeamIndex = CurrentTeamIndex;

        GameLoop();



}



void GameManager::GameLoop()
{
    while(!isGameOver())
    {
        cout<<"============================= Round "<<RoundCounter + 1<<" ============================="<<endl;

        SetRoundEnergy();

        Player(CurrentTeamIndex);

        teams[CurrentTeamIndex].turnCount++;

        DeleteDeadHeroes(teams[CurrentTeamIndex].heroes);

        CurrentTeamIndex = 1 - CurrentTeamIndex;

        SetRoundEnergy();
        
        Player(CurrentTeamIndex);

        teams[CurrentTeamIndex].turnCount++;

        DeleteDeadHeroes(teams[CurrentTeamIndex].heroes);

        ApplyEndOfRoundEffects();

        CurrentTeamIndex = 1 - CurrentTeamIndex;

        RoundCounter++;

        SpecifyWinner();
    }
}




void GameManager::ApplyEndOfRoundEffects()
{
    for(int i = 0; i < teams.size(); i++)
    {
        Team& currentTeam = teams[i];
        Team& enemyTeam = teams[1 - i];

        for(const auto &heroptr : currentTeam.heroes)
        {
            if(heroptr->IsDead()) continue;
            heroptr->ApplyEndOfRoundEffects(RoundCounter, *this, enemyTeam, currentTeam);

            if(heroptr->IsDamageMultiplierEnabled && RoundCounter >= heroptr->GetDamageMultiplierExpire())
            {
                heroptr->IsDamageMultiplierEnabled = false;
            }
            
        }

        
    }

   

    
}



bool GameManager::isGameOver() const
{
    if(teams[0].turnCount >= 15 || teams[1].turnCount >= 15)
        return true;

    if(teams[0].heroes.empty() || teams[1].heroes.empty())
        return true;


   return false;
}



void GameManager::SpecifyWinner() const
{
    int Team1Alive = 0;
    int Team2Alive = 0;

    for(auto const &hero : teams[0].heroes)
    {
        if(!hero->IsDead())
            Team1Alive++;    
    }

    for(auto const &hero : teams[1].heroes)
    {
        if(!hero->IsDead())
            Team2Alive++;
    }

    // equal: last hero of teams delete at same time.
    if(Team1Alive == 0 && Team2Alive == 0)
    {
        cout<<"======================== GAME OVER ========================"<< endl;
        cout<<"Result: EQUAL! The last heroes of both teams fell simultaneously"<< endl;
        exit(0);
    }

    if(Team1Alive == 0)
    {
        cout<<"======================== GAME OVER ========================"<< endl;
        cout<<"Result: Team 2 WINS! All heroes of Team 1 have been killed."<< endl;
        exit(0);
    }

    if(Team2Alive == 0)
    {
        cout<<"======================== GAME OVER ========================"<< endl;
        cout<<"Result: Team 1 WINS! All heroes of Team 2 have been killed."<< endl;
        exit(0);
    }


    if(RoundCounter >= 15)
    {
        cout<<"======================== GAME OVER ========================"<< endl;
        cout<<"Game ended by reaching the round limit." <<endl;
        cout<<"Team 1 has "<< Team1Alive <<" heroes remaining." <<endl;
        cout<<"Team 2 has "<< Team2Alive <<" heroes remaining." <<endl;
        
        if(Team1Alive > Team2Alive)
        {
            cout<<"Result: Team 1 WINS by having more surviving heroes!"<<endl;
            exit(0);
        }
        else if(Team2Alive > Team1Alive)
        {
            cout<<"Result: Team 2 WINS by having more surviving heroes!"<<endl;
            exit(0);
        }
        else
        {
            cout<<"Result: EQUAL! Both teams have the same number of heroes." << endl;
            exit(0);
        }
    }
}


void GameManager::DeleteDeadHeroes(vector<unique_ptr<Hero>> &heroes)
{
    auto it = heroes.begin();

    while(it != heroes.end())
    {
        if((*it)->GetCurrentHP() == 0)
        {
            (*it)->SetDead();
        }

        it++;
    }


}


void GameManager::PrintHeroAndAbility(int teamid) const
{
    int i = 1;
    for(const auto &hero_ptr : teams[teamid].heroes)
    {
        if(!hero_ptr->IsDead())
        {
            cout<<endl<< i <<" - Name Of Hero: "<<hero_ptr->Name<<"\t"<<"HP Is: "<<hero_ptr->GetHP()<<endl;
            hero_ptr->GetNameOfAbility();
            i++;
        }
    }
}


Hero* GameManager::ChooseHero(Team& team)
{
    while(true)
    {
        cout<<"--------============= Choose Hero =============--------"<<endl;
        cout<<"-- Player number "<<CurrentTeamIndex + 1<<endl;
        cout<<"-- Your team energy is: "<<team.Energy<<endl;
        cout<<"----------------"<<endl;
        

        vector<Hero*> LiveHeroes;
        for(const auto &hero : team.heroes)
        {
            if(!hero->IsDead()  && hero->IsAbilityActivated)
            {
                LiveHeroes.push_back(hero.get());
            }
        }

        int counter = 1;
        
        for(const auto& hero : LiveHeroes)
        {
            cout<<counter<<") "<<hero->Name<<" HP: "<<hero->GetHP();
            if(hero->HaveShield)
            {
                cout<<"\t [Have Shiled]"<<endl;
            }
            else
                cout<<endl;

            counter++;
        }
        int Skip = counter;
        cout<<counter<<") Skip Turn"<<endl;
        counter++;
        int EndGame = counter;
        cout<<counter<<") End Game"<<endl;

        cout<<"Your choice: ";
        int choice;
        cin>>choice;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        if(choice == Skip)
        {
            return nullptr;
        }

        if(choice == EndGame)
            exit(0);


        if(cin.fail() || choice < 1 || choice > LiveHeroes.size() + 2)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout<<"Invalid number. Please enter number from a list."<<endl;
            continue;
        }

        if(choice == LiveHeroes.size() + 1)
            return nullptr;
        else
            return LiveHeroes[choice - 1];
    }
}





int GameManager::ChooseAbilityForMyHero(Hero* hero, Team& team)
{
    while(true)
    {
        cout<<"\n------------ Choose ability for "<< hero->Name<<" ------------"<<endl;
        
        cout<<"1) "<<hero->NameOfNormalAbility1 << " (Cost: "<<hero->GetEnergyOfNormalAbility1()<<")"<<endl;

        cout<<"2) "<<hero->NameOfNormalAbility2 << " (Cost: "<<hero->GetEnergyOfNormalAbility2()<<")"<<endl;

        cout<<"3) "<<hero->NameOfSpecialAbility << " (Cost: "<<hero->GetUseEnergyOfSpecialAbility()<<")";
    
        if(!hero->GetIsSpecialAbilityUsable(RoundCounter, team))
        {
            cout<<" [Unusable]";
        }
    
        cout<<endl;

        cout<<"4) Back to choose hero"<<endl;

        cout<<"Your choice: ";

        int choice;
        cin>>choice;

        if(cin.fail() || choice < 1 || choice > 4)
        {
            cin.clear();
            cin.ignore();
            cout<<"Invalid input. Please enter a number from 1 to 4."<<endl;
            continue;
        }

        cin.ignore();

        if(choice == 4)
        {
            return 0;
        }

        int AbilityEnergyCost = 0;

        switch (choice)
        {
            case 1:
                    AbilityEnergyCost = hero->GetEnergyOfNormalAbility1();
                break;
            case 2:
                    AbilityEnergyCost = hero->GetEnergyOfNormalAbility2();
                break;
            case 3:
                    if(!hero->GetIsSpecialAbilityUsable(RoundCounter, team))
                    {
                        cout << "######### This ability is on cooldown! #########" << endl;
                        continue;
                    }
                    AbilityEnergyCost = hero->GetUseEnergyOfSpecialAbility();
                break;
        }

        if(team.Energy < AbilityEnergyCost)
        {
            cout<<"Invalid move: Not enough energy. Costs "<<AbilityEnergyCost<<" , but you only have "<<team.Energy<<" ."<<endl;
            continue;
        }

        return choice;
    }
}



void GameManager::Player(int teamIndex)
{
    Team& CurrentTeam = teams[teamIndex];

    if(!CanTeamMakeAnyMove(teamIndex))
    {
        cout<<"Your team doesn't have enough energy for any hero to make an attack. Turn ends.";
        return;
    }

    for(const auto &heroptr : teams[teamIndex].heroes)
    {
        if(heroptr->IsDead())
            continue;

        if(heroptr->GetHillExpireRound() >= RoundCounter && heroptr->GetHillExpireRound() != 0)
        {
            heroptr->Hill(heroptr->GetHillRoundAmount(), *this);
        }

        if(heroptr->HaveShield && heroptr->GetRemainRoundShield() > 0)
        {
            heroptr->DecreaseRoundShield();

            if(heroptr->GetRemainRoundShield() == 0)
            {
                heroptr->SetAmountShield(0);
                heroptr->HaveShield = false;
            }
        }

        if(heroptr->BigTahaMarked)
        {
            heroptr->DecreaseBigTahaMarked();

            if(heroptr->GetBigTahaMarked() == 0)
            {
                if(BigTahaMark == nullptr)
                {
                    for(const auto &hero : teams[1 - teamIndex].heroes)
                    {
                        if(hero->Name == "Big Taha")
                        {
                            BigTahaMark = hero.get();
                        }
                    }
                }
                
                
                if(heroptr->GetHP() < 360)
                {
                    heroptr->SetDead();
                }
                else
                {
                    if(BigTahaMark != nullptr)
                    {
                        heroptr->TakeDamage(200, BigTahaMark->IsDamageMultiplierEnabled, DamageType::Single, *this);
                        if (heroptr->GetCurrentHP() <= 0)
                        {
                            heroptr->SetDead();
                        }
                    }
                }

                heroptr->BigTahaMarked = false;

            }
        }





        if(heroptr->IsAghrabExists)
        {
            if(kazhdam == nullptr)
            {
                for(const auto &hero : teams[1 - teamIndex].heroes)
                {
                    if(hero->Name == "Pouya Kazh Dam")
                    {
                        kazhdam = hero.get();
                    }
                }
            }

            if(kazhdam != nullptr)
            {
                if(heroptr->IsAghrabActivated)
                {
                    heroptr->TakeDamage(60, kazhdam->IsDamageMultiplierEnabled, DamageType::Single, *this);
                    if (heroptr->GetCurrentHP() <= 0)
                    {
                        heroptr->SetDead();
                    }
                }
                else
                {
                    heroptr->TakeDamage(20, kazhdam->IsDamageMultiplierEnabled, DamageType::Single, *this);
                    if (heroptr->GetCurrentHP() <= 0)
                    {
                    heroptr->SetDead();
                    }
                }
                
            }
            
        }
        

        if(heroptr->Name == "Pouya Kazh Dam")
        {
            heroptr->ApplyEndOfRoundEffects(RoundCounter, *this, teams[1 - teamIndex], teams[teamIndex]);
        }


        if(heroptr->Name == "Agha Shahriar")
        {
            if(IsWorldInverse)
            {
                if(WorldInversionRoundRemaining > 0)
                {
                    WorldInversionRoundRemaining--;

                    if(WorldInversionRoundRemaining == 0)
                    {
                        IsWorldInverse = false;
                    }
                }
            }
        }
            
        

}
    

    while(true)
    {
        SpecifyWinner();

        Hero* myhero = ChooseHero(CurrentTeam);

        if(myhero == nullptr)
        {
            cout<<"Ending turn for team "<<teamIndex + 1<<"."<<endl;
            break;
        }

        
        int AbilityIndex = ChooseAbilityForMyHero(myhero, CurrentTeam);

        if(AbilityIndex == 0)
        {
            continue;
        }

        vector<Hero *> LivingTeamHeroes;
        for(auto const& heroPtr: teams[teamIndex].heroes)
        {
            if(!heroPtr->IsDead())
            {
                LivingTeamHeroes.push_back(heroPtr.get());
            }
        }
        
        vector<Hero *> LivingEnemyHeroes;
        for(auto const &heroptr : teams[1 -teamIndex].heroes)
        {
            if(!heroptr->IsDead())
            {
                LivingEnemyHeroes.push_back(heroptr.get());
            }
        }

        AbilityContext context {this ,myhero , LivingTeamHeroes, LivingEnemyHeroes, &teams[teamIndex], RoundCounter};


        vector<Hero *> DeadTeammateHeroes;

        for(const auto &heroptr : teams[teamIndex].heroes)
        {
            if(heroptr->IsDead())
            {
                DeadTeammateHeroes.push_back(heroptr.get());
            }
        }

        SpecialAbilityContext specialcontext {this ,myhero, DeadTeammateHeroes, LivingTeamHeroes, LivingEnemyHeroes, &teams[teamIndex], RoundCounter};
     
        switch (AbilityIndex)
        {
        case 1:
                myhero->NormalAbility1(context);
            break;
        case 2:
                myhero->NormalAbility2(context);
            break;
        case 3:
                myhero->SpecialAbility(specialcontext);
            break;
        
        default:
            cout<<"invalid chosen!";
            continue;
        }


        cout<<"Remaining Energy: "<<CurrentTeam.Energy<<endl;

        DeleteDeadHeroes(teams[teamIndex].heroes);
        DeleteDeadHeroes(teams[1 - teamIndex].heroes);

        if(!CanTeamMakeAnyMove(teamIndex))
        {
            cout<<"Not enough energy for further moves. Ending turn automatically."<<endl;
            break;
        }

    }



}



void GameManager::SetRoundEnergy()
{
   Team& CurrentTeam = teams[CurrentTeamIndex];
   
   bool IsStartingPlayer = (CurrentTeamIndex == StartingTeamIndex);

   int TeamTurnNumber = CurrentTeam.turnCount + 1;

   int NewTeamEnergy = 0;

   if(IsStartingPlayer)
   {
        switch (TeamTurnNumber)
        {
            case 1:
                NewTeamEnergy = 5;
                break;
            case 2:
                NewTeamEnergy = 8;
                break;
            case 3:
                NewTeamEnergy = 9;
                break;
            default:
                NewTeamEnergy = 10;
                break;
        }
   }
   else
   {
        switch (TeamTurnNumber)
        {
            case 1: 
                NewTeamEnergy = 8;
                break;
            case 2:
                NewTeamEnergy = 9;
                break;
            default:
                NewTeamEnergy = 10;
                break;
        }
   }

   CurrentTeam.Energy = NewTeamEnergy;

}

