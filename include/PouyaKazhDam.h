#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"
#include "Hero.h"

using namespace std;

class PouyaKazhDam : public Hero
{
    private:
        int EndHiddenEffectRound = 0;

    public:
        PouyaKazhDam(string InName = "Pouya Kazh Dam", string InRole = "Attacker",  
        string InNameOfNormalAbility1 = "Khanjar", int InEnergyOfNormalAbility1 = 2, string InNameOfNormalAbility2 = "Aghrab",
        int InEnergyOfNormalAbility2 = 4, string InNameOfSpecialAbility = "Dam Kazh Dam",
        int InUseEnergyOfSpecialAbility = 5, int InLimitOfSpecialAbility = 4, int InMaxHP = 550, int InCurrentHP = 550)
        :
        Hero(InName, InRole, InNameOfNormalAbility1,
        InEnergyOfNormalAbility1, InNameOfNormalAbility2, InEnergyOfNormalAbility2, InNameOfSpecialAbility,
        InUseEnergyOfSpecialAbility, InLimitOfSpecialAbility, InMaxHP, InCurrentHP){} 

        void SpecialAbility(SpecialAbilityContext& ) override;

        void NormalAbility1(AbilityContext& ) override;

        void NormalAbility2(AbilityContext& ) override;

        void ApplyEndOfRoundEffects(int , GameManager&, Team &, Team&) override;
        
        ~PouyaKazhDam() override = default;
};