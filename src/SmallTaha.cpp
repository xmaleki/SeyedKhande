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
