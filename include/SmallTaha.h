#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"
#include "Hero.h"

using namespace std;

class SmallTaha : public Hero
{
    public:
        SmallTaha(string InName = "Small Taha", string InRole = "Healer",  
        string InNameOfNormalAbility1 = "Tigh Tiz", int InEnergyOfNormalAbility1 = 2, string InNameOfNormalAbility2 = "Serom Khon",
        int InEnergyOfNormalAbility2 = 4, string InNameOfSpecialAbility = "Gharantine Kamel",
        int InUseEnergyOfSpecialAbility = 4, int InLimitOfSpecialAbility = 3, int InMaxHP = 500, int InCurrentHP = 500)
        :
        Hero(InName, InRole, InNameOfNormalAbility1,
        InEnergyOfNormalAbility1, InNameOfNormalAbility2, InEnergyOfNormalAbility2, InNameOfSpecialAbility,
        InUseEnergyOfSpecialAbility, InLimitOfSpecialAbility, InMaxHP, InCurrentHP){} 

        void SpecialAbility(SpecialAbilityContext& ) override;

        void NormalAbility1(AbilityContext& ) override;

        void NormalAbility2(AbilityContext& ) override;

        void ApplyEndOfRoundEffects(int , GameManager&, Team &, Team&) override;
        
        ~SmallTaha() override = default;


};