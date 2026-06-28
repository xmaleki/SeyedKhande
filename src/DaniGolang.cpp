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


void DaniGolang::NormalAbility2(AbilityContext& context)
{
    Hero* MaxHpHero = context.LivingEnemyHeroes[0];
    
    int MaximumHp = context.LivingEnemyHeroes[0]->GetHP();

    for(int i = 1; i < context.LivingEnemyHeroes.size() ; i++)
    {
        if(context.LivingEnemyHeroes[i]->GetHP() > MaximumHp)
        {
            MaximumHp = context.LivingEnemyHeroes[i]->GetHP();
            MaxHpHero = context.LivingEnemyHeroes[i];
        }
    }

    MaxHpHero->TakeDamage(50, IsDamageMultiplierEnabled,DamageType::Single, *context.GameObj);
    if (MaxHpHero->GetCurrentHP() <= 0)
    {
        MaxHpHero->SetDead();
    }


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
        cout<<endl<<"Please enter your target: ";
        cin>>target;

        if(target < 1 || target > context.LivingEnemyHeroes.size())
        {
            cout<<"Invalid choice. enter again!";
            continue;
        }
        else
            break;
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(const auto &enemy : context.LivingEnemyHeroes)
    {
        if(enemy != nullptr && enemy->Name == Enemy[target - 1])
        {
            enemy->TakeDamage(50, IsDamageMultiplierEnabled, DamageType::Single, *context.GameObj);
            if(enemy->GetCurrentHP() <= 0)
            {
                enemy->SetDead();
            }
            break;
        }
    }

    
    context.MyTeam->Energy -= 4;

    cout<<"******** Fil Kosh execute successfully ********"<<endl;
}



void DaniGolang::SpecialAbility(SpecialAbilityContext& specialcontext)
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

        outminhero->HaveShield = true;
        outminhero->RemainRoundShield = 2;
        
        specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

        specialcontext.MyTeam->Energy -= 4;
    }

    cout<<">>Hich kas az in khat rad nemishe<<!"<<endl;
    cout<<"******** Sangar Khanevade execute successfully ********"<<endl;
}







void DaniGolang::ApplyEndOfRoundEffects(int roundcount, GameManager& Gamemanager, Team &enemy, Team& currentteam)
{
    LastGhofliTarget = nullptr;
    CurrentGhofliDamage = 20.0;

    danighofliused = false;
}
