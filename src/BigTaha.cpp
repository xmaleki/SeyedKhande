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