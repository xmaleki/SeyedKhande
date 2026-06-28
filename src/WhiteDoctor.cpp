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


void WhiteDoctor::NormalAbility2(AbilityContext& context)
{
    vector<string> TeamMate;
    int counter = 1;
    
    cout<<"Live teammate heroes: ";
    for(const auto liveheroes : context.LivingTeamHeroes)
    {
        if(liveheroes != nullptr)
        {
            cout<<counter<<") "<<liveheroes->Name<<"\t";
            TeamMate.push_back(liveheroes->Name);
            counter++;
        }
    }

    int choice;
    while(true)
    {
        cout<<"\nPlease enter your choice: ";
        cin>>choice;

        if(choice < 1 || choice > context.LivingTeamHeroes.size())
        {
            cout<<"Invalid choice. enter again!";
            continue;
        }
        else
            break;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Hero* ChosenHero = nullptr;

    for(Hero* teamMate : context.LivingTeamHeroes)
    {
        if(teamMate != nullptr && teamMate->Name == TeamMate[choice - 1])
        {
            ChosenHero = teamMate;
            break;
        }
    }

    if(ChosenHero != nullptr)
    {
        ChosenHero->SetDamageMultiplier(context.RoundCount + 2);
    }

    context.MyTeam->Energy -= 4;

    cout<<"******** Doping execute successfully ********"<<endl;

}


void WhiteDoctor::SpecialAbility(SpecialAbilityContext& specialcontext)
{

    Hero* TargetHero = nullptr;
    
    vector<string> DeadTeam;
    int counter = 1;

    if(!specialcontext.DeadTeammateHeroes.empty())
    {
        cout<<"Teammate dead heroes: "<<endl;       
        for(const auto &hero : specialcontext.DeadTeammateHeroes)
        {
            cout<<counter<<") "<<hero->Name<<"\t";
            DeadTeam.push_back(hero->Name);
            counter++;
        }

        int choice;
        while(true)
        {
            cout<<"\nPlease enter your choice: ";
            cin>>choice;

            if(choice < 1 || choice > specialcontext.DeadTeammateHeroes.size())
            {
                cout<<"Invalid choice. enter again!";
                continue;
            }
            else
                break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for(const auto &hero : specialcontext.DeadTeammateHeroes)
        {
            if(hero != nullptr && hero->Name == DeadTeam[choice - 1])
            {
                hero->SetLive(200);
                TargetHero = hero;
                break;
            }
        }
    }
    else
    {
        cout<<"There is'nt dead heroes."<<endl;
    }
    
    specialcontext.MyTeam->LastRoundUsedSpecial = specialcontext.RoundCount;

    // Delete all nagative effects
    TargetHero->danighofliused = false;
    TargetHero->BigTahaMarked = false;
    TargetHero->IsAghrabExists = false;
    TargetHero->IsAghrabActivated = false;

    specialcontext.MyTeam->Energy -= 4;

    cout<<">>Biyaridesh roye miz... Zende mimone age shans biyare<<."<<endl;
    cout<<"******** Amaliyat Otagh Amal execute successfully ********"<<endl;

}


void WhiteDoctor::ApplyEndOfRoundEffects(int roundcount, GameManager& Gamemanager, Team &enemy, Team& currentteam)
{
    danighofliused = false;
}