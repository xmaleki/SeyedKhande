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




void PouyaKazhDam::NormalAbility2(AbilityContext& context)
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
            hero->IsAghrabExists = true;
            break;
        }
    }

    context.MyTeam->Energy -= 4;
    cout<<"******** Aghrab execute successfully ********"<<endl;

}



void PouyaKazhDam::SpecialAbility(SpecialAbilityContext& specialcontext)
{
    specialcontext.MyHero->SetHidden();
    specialcontext.MyHero->IsAbilityActivated = false;

    // in tabe do bar dar har round farakhani mishe, pas bayad 8 bashe
    EndHiddenEffectRound = 8;

    specialcontext.MyTeam->Energy -= 5;
    
    specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

    cout<<">>Nisham ro didi? Na? Khob... Dige hich vaght nemibini<<..."<<endl;
    cout<<"******** Dam Kazh Dam execute successfully ********"<<endl;


}




void PouyaKazhDam::ApplyEndOfRoundEffects(int roundcount, GameManager& Gamemanager, Team &enemy, Team& currentteam)
{
    if(EndHiddenEffectRound > 0)
    {
        EndHiddenEffectRound--;

        if(EndHiddenEffectRound == 0)
        {
            if(enemy.heroes.empty())
            {
                cout<<"Enemy empty.";
            }
            else
            {
                IsAbilityActivated = true;
                SetUnHidden();
                EndHiddenEffectRound = 0;

                random_device rd;
                mt19937 generator(rd());
                uniform_int_distribution<> randeng(0, enemy.heroes.size() - 1);

                int randomenemyindex = randeng(generator);

                enemy.heroes[randomenemyindex]->TakeDamage(450, IsDamageMultiplierEnabled, DamageType::Single, Gamemanager);
                if (enemy.heroes[randomenemyindex]->GetCurrentHP() <= 0)
                {
                    enemy.heroes[randomenemyindex]->SetDead();
                }
            }
        }  
    }


    danighofliused = false;
}
