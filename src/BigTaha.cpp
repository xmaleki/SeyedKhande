#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>
#include "BigTaha.h"


void BigTaha::NormalAbility1(AbilityContext& context)
{
    for(const auto &hero : context.LivingEnemyHeroes)
    {
        hero->TakeDamage(30, IsDamageMultiplierEnabled, DamageType::Group, *context.GameObj);
        if (hero->GetCurrentHP() <= 0)
        {
            hero->SetDead();
        }
    }

    context.MyTeam->Energy -= 3;
    
    cout<<"******** Ragbar execute successfully ********"<<endl;

}




void BigTaha::NormalAbility2(AbilityContext& context)
{
    vector<string> Enemy;
    int counter = 1;

    cout<<"Live enemy heroes: "<<endl;
    for(const auto &hero : context.LivingEnemyHeroes)
    {
        if(hero->IsHiddenFunc())
            continue;

        cout<<counter<<") "<<hero->Name<<"\t";
        Enemy.push_back(hero->Name);
        counter++;
    }

    int target;
    while(true)
    {
        cout<<"\nPlease enter your choice: ";
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

    for(const auto &hero : context.LivingEnemyHeroes)
    {
        if(hero->Name == Enemy[target - 1])
        {
            hero->TakeDamage(90, IsDamageMultiplierEnabled, DamageType::Single, *context.GameObj);
            if (hero->GetCurrentHP() <= 0)
            {
                hero->SetDead();
            }

            SetHidden();
            EndHiddenRound = context.RoundCount + 1;

            break;
        }
    }

    context.MyTeam->Energy -= 4;

    cout<<"******** Xray execute successfully ********"<<endl;

}

