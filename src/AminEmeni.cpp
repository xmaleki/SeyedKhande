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



void AminEmeni::NormalAbility2(AbilityContext& context)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> RandIndex(0 , context.LivingTeamHeroes.size() - 1);
        
    int RandomTeammateIndex = RandIndex(generator);

    context.LivingTeamHeroes[RandomTeammateIndex]->TakeDamage(25, IsDamageMultiplierEnabled,DamageType::Single, *context.GameObj);
    if (context.LivingTeamHeroes[RandomTeammateIndex]->GetCurrentHP() <= 0)
    {
        context.LivingTeamHeroes[RandomTeammateIndex]->SetDead();
    }

    context.MyHero->Hill(75, *context.GameObj);

    context.MyTeam->Energy -= 3;

    cout<<"******** Zarbe Be Khodi execute successfully ********"<<endl;
}



void AminEmeni::SpecialAbility(SpecialAbilityContext& specialcontext)
{
    random_device rd;
    mt19937 generator(rd());

    if(!specialcontext.LivingEnemyHeroes.empty())
    {
        uniform_int_distribution<int> EnemyRand(0, specialcontext.LivingEnemyHeroes.size() - 1);

        int RandomEnemyIndex = EnemyRand(generator);

        specialcontext.LivingEnemyHeroes[RandomEnemyIndex]->TakeDamage(250, IsDamageMultiplierEnabled, DamageType::Single, *specialcontext.GameObj);

        if (specialcontext.LivingEnemyHeroes[RandomEnemyIndex]->GetCurrentHP() <= 0)
        {
            specialcontext.LivingEnemyHeroes[RandomEnemyIndex]->SetDead();
        }
    }

    vector<Hero *> LivingTeamHeroesExceptHimSelf;

    for(const auto &hero : specialcontext.LivingTeamHeroes)
    {
        if(hero != nullptr && hero->Name != "Amin Emeni")
            LivingTeamHeroesExceptHimSelf.push_back(hero);
    }

    if(LivingTeamHeroesExceptHimSelf.size() >= 1)
    {
        LivingTeamHeroesExceptHimSelf[0]->TakeDamage(30, IsDamageMultiplierEnabled,DamageType::Single, *specialcontext.GameObj);  

        if (LivingTeamHeroesExceptHimSelf[0]->GetCurrentHP() <= 0)
        {
            LivingTeamHeroesExceptHimSelf[0]->SetDead();
        }  
    }
    
    if(LivingTeamHeroesExceptHimSelf.size() >= 2)
    {
        LivingTeamHeroesExceptHimSelf[1]->TakeDamage(30, IsDamageMultiplierEnabled,DamageType::Single, *specialcontext.GameObj);

        if (LivingTeamHeroesExceptHimSelf[1]->GetCurrentHP() <= 0)
        {
            LivingTeamHeroesExceptHimSelf[1]->SetDead();
        }
    }

    specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

    specialcontext.MyTeam->Energy -= 4;

    cout<<">>Yek... Do... Se... Boom... Che kasi mond? mohem nist!<<..."<<endl;
    cout<<"******** Faryad Na Amni execute successfully ********"<<endl;
} 


void AminEmeni::ApplyEndOfRoundEffects(int roundcount, GameManager& Gamemanager, Team &enemy, Team& currentteam)
{
    danighofliused = false;
}