#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>
#include "DaniGolang.h"

void DaniGolang::NormalAbility1(AbilityContext& context)
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

    int choice;
    while(true)
    {
        cout<<"\nPlease enter your choice: ";
        cin>>choice;

        if(choice < 1 || choice > context.LivingEnemyHeroes.size())
        {
            cout<<"Invalid choice. enter again!";
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
        if(enemy != nullptr && enemy->Name == Enemy[choice - 1])
        {
            ChosenEnemy = enemy;
            enemy->danighofliused = true;
            break;
        }
    }

    if(ChosenEnemy != nullptr)
    {
        if(ChosenEnemy == LastGhofliTarget)
        {
            CurrentGhofliDamage *= 1.6;
        }
        else
        {
            CurrentGhofliDamage = 20.0;
        }

        ChosenEnemy->TakeDamage(static_cast<int>(CurrentGhofliDamage), IsDamageMultiplierEnabled,DamageType::Single, *context.GameObj);

        if(ChosenEnemy->GetCurrentHP() <= 0)
        {
            ChosenEnemy->SetDead();
        }

        ChosenEnemy->danighofliused = true;
        LastGhofliTarget = ChosenEnemy;
    }

    cout<<"******** Ghofli execute successfully ********"<<endl;
    context.MyTeam->Energy -= 2;

}

