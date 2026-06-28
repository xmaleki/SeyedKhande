#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"
#include "Hero.h"

using namespace std;

class AghaShahriar : public Hero
{
    public:
        AghaShahriar(string InName = "Agha Shahriar", string InRole = "Joker",  
        string InNameOfNormalAbility1 = "Maskhare", int InEnergyOfNormalAbility1 = 2, string InNameOfNormalAbility2 = "Lajbaz",
        int InEnergyOfNormalAbility2 = 4, string InNameOfSpecialAbility = "Makos Sazi Jahan (Ba Tashdid)",
        int InUseEnergyOfSpecialAbility = 8, int InLimitOfSpecialAbility = 4, int InMaxHP = 500, int InCurrentHP = 500)
        :
        Hero(InName, InRole, InNameOfNormalAbility1,
        InEnergyOfNormalAbility1, InNameOfNormalAbility2, InEnergyOfNormalAbility2, InNameOfSpecialAbility,
        InUseEnergyOfSpecialAbility, InLimitOfSpecialAbility, InMaxHP, InCurrentHP){} 

        void SpecialAbility(SpecialAbilityContext& ) override;

        void NormalAbility1(AbilityContext& ) override;

        void NormalAbility2(AbilityContext& ) override;

        void ApplyEndOfRoundEffects(int , GameManager&, Team &, Team&) override;
        
        ~AghaShahriar() override = default;
};
