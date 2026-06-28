#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"
#include "Hero.h"

using namespace std;

class DaniGolang : public Hero
{
    private:
        Hero* LastGhofliTarget = nullptr;
        float CurrentGhofliDamage = 20.0;

    public:
        DaniGolang(string InName = "Dani Golang", string InRole = "Defender",  
        string InNameOfNormalAbility1 = "Ghofli", int InEnergyOfNormalAbility1 = 2, string InNameOfNormalAbility2 = "Fil Kesh",
        int InEnergyOfNormalAbility2 = 4, string InNameOfSpecialAbility = "Sangar Khanevade",
        int InUseEnergyOfSpecialAbility = 4, int InLimitOfSpecialAbility = 4, int InMaxHP = 600, int InCurrentHP = 600)
        :
        Hero(InName, InRole, InNameOfNormalAbility1,
        InEnergyOfNormalAbility1, InNameOfNormalAbility2, InEnergyOfNormalAbility2, InNameOfSpecialAbility,
        InUseEnergyOfSpecialAbility, InLimitOfSpecialAbility, InMaxHP, InCurrentHP){} 

        void SpecialAbility(SpecialAbilityContext& ) override;

        void NormalAbility1(AbilityContext& ) override;

        void NormalAbility2(AbilityContext& ) override;
        
        void ApplyEndOfRoundEffects(int , GameManager&, Team &, Team&) override;

        ~DaniGolang() override = default;

};
