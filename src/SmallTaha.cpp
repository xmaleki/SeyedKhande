#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>
#include "SmallTaha.h"

void SmallTaha::NormalAbility1(AbilityContext& context)
{   
    vector<string> Enemy;
    int counter = 1;

    cout<<"Live enemy heroes: ";

    for(const auto liveheroes : context.LivingEnemyHeroes)
    {
        if(liveheroes != nullptr)
        {
            if(liveheroes->IsHiddenFunc())
                continue;

            cout<<counter<<") "<<liveheroes->Name<<"\t";
            Enemy.push_back(liveheroes->Name);
            counter++;
        }
    }

    int target;
    while(true)
    {
        cout<<endl<<"Please enter your target: ";
        cin>>target;

        if(target < 1 || target > context.LivingEnemyHeroes.size())
        {
            cout<<"Invalid target. enter again!";
            continue;
        }
        else
            break;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Hero* ChosenEnemy = nullptr;

    for(Hero* enemy : context.LivingEnemyHeroes)
    {
        if(enemy != nullptr && enemy->Name == Enemy[target - 1])
        {
            ChosenEnemy = enemy;
            break;
        }
    }


    if(!context.LivingTeamHeroes.empty() && ChosenEnemy != nullptr)
    {
        Hero *outminhero = context.LivingTeamHeroes[0];
        int minhp = outminhero->GetHP();

        for(int i = 1; i < context.LivingTeamHeroes.size(); i++)
        {
            Hero* currenthero = context.LivingTeamHeroes[i];

            if(currenthero->GetHP() < minhp)
            {
                minhp = currenthero->GetHP();
                outminhero = currenthero;
            }
        }

        outminhero->Hill(20, *context.GameObj);

        ChosenEnemy->TakeDamage(30, IsDamageMultiplierEnabled,DamageType::Single, *context.GameObj);
        if(ChosenEnemy->GetCurrentHP() <= 0)
        {
            ChosenEnemy->SetDead();
        }
    
        context.MyTeam->Energy -= 2;
    }

    cout<<"******** Tigh Tiz execute successfully ********"<<endl;

}


void SmallTaha::NormalAbility2(AbilityContext& context)
{  
    vector<string> LiveTeammet;
    int counter = 1;

    cout<<"Live Heroes: ";
    for(const auto liveheroes : context.LivingTeamHeroes)
    {
        cout<<counter<<") "<<liveheroes->Name<<"\t";
        LiveTeammet.push_back(liveheroes->Name);
        counter++;
    }


    int choice;
    while(true)
    {
        cout<<"\nPlease enter your choice: ";
        cin>>choice;

        if(choice < 1 || choice > context.LivingTeamHeroes.size())
        {
            cout<<"Invalid choice. enter again!";
            continue;
        }
        else
            break;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Hero* ChosenHero = nullptr;

    for(Hero* teamMate : context.LivingTeamHeroes)
    {
        if(teamMate != nullptr && teamMate->Name == LiveTeammet[choice - 1])
        {
            ChosenHero = teamMate;
            break;
        }
    }

    if(ChosenHero != nullptr)
    {
        ChosenHero->SetHillRound(context.RoundCount + 2, 40);
    }

    context.MyTeam->Energy -= 4;

    cout<<"******** Serom Khon execute successfully ********"<<endl;

}


void SmallTaha::SpecialAbility(SpecialAbilityContext& specialcontext)
{  
    if(!specialcontext.LivingTeamHeroes.empty() && specialcontext.MyTeam != nullptr)
    {
        Hero *outminhero = specialcontext.LivingTeamHeroes[0];
        int minhp = outminhero->GetHP();

        for(int i = 1; i < specialcontext.LivingTeamHeroes.size(); i++)
        {
            Hero* currenthero = specialcontext.LivingTeamHeroes[i];

            if(currenthero->GetHP() < minhp)
            {
                minhp = currenthero->GetHP();
                outminhero = currenthero;
            }
        }

        outminhero->Hill(200, *specialcontext.GameObj);
        
        specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

        specialcontext.MyTeam->Energy -= 4;

    }

    specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

    cout<<">>Hame dar jaye khod! in mantaghe alode ast<<!"<<endl;
    cout<<"******** Gharantine Kamel execute successfully ********"<<endl;

}




void SmallTaha::ApplyEndOfRoundEffects(int roundcount, GameManager& Gamemanager, Team &enemy, Team& currentteam)
{
    danighofliused = false;
}