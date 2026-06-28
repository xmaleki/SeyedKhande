#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>
#include "PouyaKazhDam.h"


void PouyaKazhDam::NormalAbility1(AbilityContext& context)
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
            hero->TakeDamage(40, IsDamageMultiplierEnabled, DamageType::Single, *context.GameObj);
            if (hero->GetCurrentHP() <= 0)
            {
                hero->SetDead();
            }

            if(hero->IsAghrabExists)
            {
                hero->IsAghrabActivated = true;
            }
            break;
        }
    }

    context.MyTeam->Energy -= 2;

    cout<<"******** Khanjar execute successfully ********"<<endl;

}

