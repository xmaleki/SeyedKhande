#include <string>
#include <iostream>
#include "Hero.h"
#include "GameManager.h"
#include <random>
#include <limits>


int Hero::GetHP() const
{
    return CurrentHP;
}


void Hero::GetNameOfAbility() const
{
    cout<<"Normal Ability: "<<NameOfNormalAbility1<<"\t"<<NameOfNormalAbility2<<endl;
    cout<<"Special Ability: "<<NameOfSpecialAbility<<endl;
}



bool Hero::CanUseAbility(int currentEnergy, int round, Team& currentteam) const
{
    if((EnergyOfNormalAbility1 < currentEnergy) || (EnergyOfNormalAbility2 < currentEnergy))
        return true;
    if(GetIsSpecialAbilityUsable(round, currentteam) && UseEnergyOfSpecialAbility < currentEnergy)
        return true;
    
    return false;
}

