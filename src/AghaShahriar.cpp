#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>
#include "AghaShahriar.h"


void AghaShahriar::NormalAbility1(AbilityContext& context)
{
    random_device rd;
    mt19937 generator(rd());

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

    uniform_int_distribution<int> RandZeroTo100(1, 100);
    int RandNumber = RandZeroTo100(generator);

    for(const auto &hero : context.LivingEnemyHeroes)
    {
        if(hero->Name == Enemy[target - 1])
        {
            if(RandNumber <= 20)
            {
                cout<<"\n######### Miss #########";
                break;
            }
            else
            {
                hero->TakeDamage(60, IsDamageMultiplierEnabled, DamageType::Single, *context.GameObj);
                if (hero->GetCurrentHP() <= 0)
                {
                    hero->SetDead();
                }
                break;
            }
        }
    }

    context.MyTeam->Energy -= 2;

    cout<<"******** Maskhare execute successfully ********"<<endl;
}


void AghaShahriar::NormalAbility2(AbilityContext& context)
{
    random_device rd;
    mt19937 generator(rd());

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

    vector<Hero*> ChooseEnemies;

    for(const auto &hero : context.LivingEnemyHeroes)
    {
        if(hero->Name != Enemy[target - 1])
        {
            ChooseEnemies.push_back(hero);
        }
    }

    if(ChooseEnemies.empty())
    {
        cout<<"There is no enemy.";
        return;
    }

    uniform_int_distribution<int> RandIndex(0, ChooseEnemies.size() - 1);
    int randomIndex = RandIndex(generator);

    ChooseEnemies[randomIndex]->TakeDamage(100, IsDamageMultiplierEnabled, DamageType::Single, *context.GameObj);
    if (ChooseEnemies[randomIndex]->GetCurrentHP() <= 0)
    {
        ChooseEnemies[randomIndex]->SetDead();
    }


    context.MyTeam->Energy -= 4;

    cout<<"******** Lajbaz execute successfully ********"<<endl;
}



void AghaShahriar::SpecialAbility(SpecialAbilityContext& specialcontext)
{
    specialcontext.GameObj->ActivateWorldInversion(2);



    specialcontext.MyTeam->Energy -= 8;
    
    specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

    cout<<"******** Makos Sazi Jahan (Ba Tashdid) execute successfully ********"<<endl;

}






void AghaShahriar::ApplyEndOfRoundEffects(int roundcount, GameManager& Gamemanager, Team &enemy, Team& currentteam)
{
    
    danighofliused = false;
}