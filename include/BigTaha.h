#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"
#include "Hero.h"

using namespace std;

class BigTaha : public Hero
{
    private:
        int EndHiddenRound = 0;

    public:
        BigTaha(string InName = "Big Taha", string InRole = "Attacker", 
        string InNameOfNormalAbility1 = "Ragbar", int InEnergyOfNormalAbility1 = 3, string InNameOfNormalAbility2 = "Xray",
        int InEnergyOfNormalAbility2 = 4, string InNameOfSpecialAbility = "Entegham Baradar",
        int InUseEnergyOfSpecialAbility = 3, int InLimitOfSpecialAbility = 4, int InMaxHP = 500, int InCurrentHP = 500)
        :
        Hero(InName, InRole, InNameOfNormalAbility1,
        InEnergyOfNormalAbility1, InNameOfNormalAbility2, InEnergyOfNormalAbility2, InNameOfSpecialAbility,
        InUseEnergyOfSpecialAbility, InLimitOfSpecialAbility, InMaxHP, InCurrentHP){} 

        void SpecialAbility(SpecialAbilityContext& ) override;

        void NormalAbility1(AbilityContext& ) override;

        void NormalAbility2(AbilityContext& ) override;
        
        void ApplyEndOfRoundEffects(int , GameManager&, Team &, Team&) override;

        ~BigTaha() override = default;
};
