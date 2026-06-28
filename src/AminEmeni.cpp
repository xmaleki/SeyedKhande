#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>
#include "AminEmeni.h"

void AminEmeni::NormalAbility1(AbilityContext& context)
{
    vector<string> Enemy;
    int counter = 1;

    cout<<"Live enemy heroes: "<<endl;
    for(const auto &hero : context.LivingEnemyHeroes)
    {
        if(hero->IsHiddenFunc())
            continue;

        if(hero != nullptr)
        {
            cout<<counter<<") "<<hero->Name<<"\t";
            Enemy.push_back(hero->Name);
            counter++;
        }
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
        if(hero != nullptr && hero->Name == Enemy[target - 1])
        {
            hero->TakeDamage(AkharinFeshang, IsDamageMultiplierEnabled,DamageType::Single, *context.GameObj);
            if (hero->GetCurrentHP() <= 0)
            {
                hero->SetDead();
            }
            if(hero->IsDead())
            {
                AkharinFeshang *= 2;
            }

            break;
        }
    }

    context.MyTeam->Energy -= 3;

    cout<<"******** Akharin Feshang execute successfully ********"<<endl;
}

