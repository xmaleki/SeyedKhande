#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>
#include "WhiteDoctor.h"



void WhiteDoctor::NormalAbility1(AbilityContext& context)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> Rand(0, context.LivingTeamHeroes.size() - 1);
    int RandomHeroIndex = Rand(generator);    
  
    vector<string> enenmyheroes;
    int counter = 1;

    cout<<"Live enemy heroes: ";
    for(const auto liveheroes : context.LivingEnemyHeroes)
    {
        if(liveheroes->IsHiddenFunc())
            continue;

        cout<<counter<<") "<<liveheroes->Name<<"\t";
        enenmyheroes.push_back(liveheroes->Name);
        counter++;
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
        if(enemy != nullptr && enemy->Name == enenmyheroes[target - 1])
        {
            ChosenEnemy = enemy;
            break;
        }
    }

    if(context.LivingTeamHeroes[RandomHeroIndex] != nullptr && ChosenEnemy != nullptr)
    {
        context.LivingTeamHeroes[RandomHeroIndex]->Hill(40, *context.GameObj);
        ChosenEnemy->TakeDamage(40, IsDamageMultiplierEnabled,DamageType::Single , *context.GameObj);
        if(ChosenEnemy->GetCurrentHP() <= 0)
        {
            ChosenEnemy->SetDead();
        }
        context.MyTeam->Energy -= 3;
    }

    cout<<"******** Aspirin execute successfully ********"<<endl;

}