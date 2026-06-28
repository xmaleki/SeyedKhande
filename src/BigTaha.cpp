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



void BigTaha::SpecialAbility(SpecialAbilityContext& specialcontext)
{
    random_device rd;
    mt19937 generator(rd());

    if(!specialcontext.LivingEnemyHeroes.empty())
    {
        uniform_int_distribution<int> EnemyRand(0, specialcontext.LivingEnemyHeroes.size() - 1);

        int RandomEnemyIndex = EnemyRand(generator);

        specialcontext.LivingEnemyHeroes[RandomEnemyIndex]->BigTahaMarked = true;
        specialcontext.LivingEnemyHeroes[RandomEnemyIndex]->SetBigTahaMarked(2);
    }

    specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

    specialcontext.MyTeam->Energy -= 3;

    cout<<">>In yeki baraye dadash kochikam bod... Hala nobat to e.<<..."<<endl;
    cout<<"******** Entegham Baradar execute successfully ********"<<endl;

}




void BigTaha::ApplyEndOfRoundEffects(int roundcount, GameManager& Gamemanager, Team &enemy, Team& currentteam)
{
    if(roundcount >= EndHiddenRound && EndHiddenRound != 0)
    {
        EndHiddenRound = 0;
        SetUnHidden();
    }

    danighofliused = false;
}