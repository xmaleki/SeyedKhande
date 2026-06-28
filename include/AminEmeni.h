#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"
#include "Hero.h"

using namespace std;

class AminEmeni : public Hero
{
    private:
        int AkharinFeshang = 55;

    public:
        AminEmeni(string InName = "Amin Emeni", string InRole = "Attacker", 
        string InNameOfNormalAbility1 = "Akharin Feshang", int InEnergyOfNormalAbility1 = 3, string InNameOfNormalAbility2 = "Zarbe Be Khodi",
        int InEnergyOfNormalAbility2 = 3, string InNameOfSpecialAbility = "Faryad Na Amni",
        int InUseEnergyOfSpecialAbility = 4, int InLimitOfSpecialAbility = 3, int InMaxHP = 500, int InCurrentHP = 500)
        :
        Hero(InName, InRole, InNameOfNormalAbility1,
        InEnergyOfNormalAbility1, InNameOfNormalAbility2, InEnergyOfNormalAbility2, InNameOfSpecialAbility,
        InUseEnergyOfSpecialAbility, InLimitOfSpecialAbility, InMaxHP, InCurrentHP){} 

        void SpecialAbility(SpecialAbilityContext& ) override;

        void NormalAbility1(AbilityContext& ) override;

        void NormalAbility2(AbilityContext& ) override;
        
        void ApplyEndOfRoundEffects(int , GameManager&, Team &, Team&) override;

        ~AminEmeni() override = default;
};