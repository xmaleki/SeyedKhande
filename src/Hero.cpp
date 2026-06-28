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

int Hero::GetLimitOfSpecialAbility() const
{
    return LimitOfSpecialAbility;
}


int Hero::GetEnergyOfNormalAbility1() const
{
    return EnergyOfNormalAbility1;
}

int Hero::GetEnergyOfNormalAbility2() const
{
    return EnergyOfNormalAbility2;
}

int Hero::GetUseEnergyOfSpecialAbility() const
{
    return UseEnergyOfSpecialAbility;
}


int Hero::GetDamageMultiplierExpire() const
{
    return DamageMultiplierExpire;
}

void Hero::SetBigTahaMarked(int amount)
{
    BigTahaMarkedRemain = amount;
}


int Hero::GetBigTahaMarked()
{
    return BigTahaMarkedRemain;   
}

void Hero::DecreaseBigTahaMarked()
{
    BigTahaMarkedRemain--;

    if(BigTahaMarkedRemain <= 0)
        BigTahaMarkedRemain = 0;
}

void Hero::SetDead()
{
    CurrentHP = 0;
    Dead = true;
}

void Hero::SetLive(int hp)
{
    CurrentHP = hp;
    Dead = false;
}


int Hero::GetHillRoundAmount()
{
    return HillRoundAmount;
}

int Hero::GetHillExpireRound()
{
    return HillExpireRound;
}

void Hero::TakeDamage(int damage, bool InIsDamageMultiplierEnabled,DamageType type ,GameManager& GameObj)
{
    if(this->IsHiddenFunc() && type != DamageType::Group)
    {
        cout<<"Target is hidden and Damage isn't group!";
        return;
    }

    int FinalDamage = damage;
    int InversedFinalDamage = damage;

    if(InIsDamageMultiplierEnabled)
    {
        FinalDamage = static_cast<int> (damage * 1.2);
        InversedFinalDamage = static_cast<int> (damage * 0.8);
    }

    if(HaveShield)
    {
        if(GameObj.IsWorldInversed())
        {
            // Dar in halat hich tafavoti ba halati ke separ faal nabashe nadare.
            CurrentHP += InversedFinalDamage;
            if(CurrentHP > MaxHP)
                CurrentHP = MaxHP;
        }
        else
        {
            int DamageAbsorbedByShield;

            DamageAbsorbedByShield = FinalDamage < AmountShield ? FinalDamage : AmountShield;

            AmountShield -= DamageAbsorbedByShield;

            FinalDamage -= DamageAbsorbedByShield;

            CurrentHP -= FinalDamage;
            if(CurrentHP < 0)
                CurrentHP = 0;
        }
    }
    else
    {
        if(GameObj.IsWorldInversed())
        {
            CurrentHP += InversedFinalDamage;
            if(CurrentHP > MaxHP)
                CurrentHP = MaxHP;
        }
        else
        {
            CurrentHP -= FinalDamage;
            if(CurrentHP < 0)
                CurrentHP = 0;
        }
    }
}



void Hero::Hill(int hill, GameManager& GameObj)
{
    if(GameObj.IsWorldInversed())
    {

        if(HaveShield)
        {
            int DamageAbsorbedByShield;

            DamageAbsorbedByShield = hill < AmountShield ? hill : AmountShield;

            AmountShield -= DamageAbsorbedByShield;

            hill -= DamageAbsorbedByShield;

            CurrentHP -= hill;
            if(CurrentHP < 0)
                CurrentHP = 0;
        }
        else
        {
            CurrentHP -= hill;
            if(CurrentHP < 0)
            CurrentHP = 0;
        }
    }
    else
    {
        CurrentHP += hill;
        if(CurrentHP > MaxHP)
            CurrentHP = MaxHP;
    }
}


int Hero::GetCurrentHP()
{
    return CurrentHP;
}

void Hero::SetCurrentHP(int hp)
{
    CurrentHP = hp;
}
