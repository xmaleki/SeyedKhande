#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"
#include "Hero.h"

using namespace std;

class WhiteDoctor : public Hero
{
    public:
        WhiteDoctor(string InName = "White Doctor", string InRole = "Healer", 
        string InNameOfNormalAbility1 = "Aspirine", int InEnergyOfNormalAbility1 = 3, string InNameOfNormalAbility2 = "Doping",
        int InEnergyOfNormalAbility2 = 4, string InNameOfSpecialAbility = "OtaghAmal",
        int InUseEnergyOfSpecialAbility = 4, int InLimitOfSpecialAbility = 4, int InMaxHP = 550, int InCurrentHP = 550)
        :
        Hero(InName, InRole, InNameOfNormalAbility1,
        InEnergyOfNormalAbility1, InNameOfNormalAbility2, InEnergyOfNormalAbility2, InNameOfSpecialAbility,
        InUseEnergyOfSpecialAbility, InLimitOfSpecialAbility, InMaxHP, InCurrentHP){};
        
        void SetDamageMultiplier(float, int);
        void SpecialAbility(SpecialAbilityContext& ) override;

        void NormalAbility1(AbilityContext& ) override;

        void NormalAbility2(AbilityContext& ) override;

        void ApplyEndOfRoundEffects(int , GameManager&, Team &, Team&) override;

        ~WhiteDoctor() override = default;
};
