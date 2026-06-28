#pragma once
#include <string>
#include <GameManager.h>
#include "GameTypes.h"

using namespace std;


enum class DamageType
{
    Single, Group
};


class Hero
{
    private:

        int EnergyOfNormalAbility1;

        int EnergyOfNormalAbility2;

        int UseEnergyOfSpecialAbility;
        
        int LimitOfSpecialAbility;

        int MaxHP;
        int CurrentHP;
        
        int DamageMultiplierExpire = 0;

        // dani sheild
        int ShieldEndRound = 0;
        int AmountShield = 250;

        // serom khon
        int HillRoundAmount = 0;
        int HillExpireRound = 0;

        //big taha, badan piyade sazi bshe
        bool IsHidden = false;
        int HiddenRound = 0;

        int BigTahaMarkedRemain = 0;

        //bool IsSpecialAbilityUsable = false;

        bool Dead = false;

    public:
        Hero(string InName, string InRole, 
        string InNameOfNormalAbility1, int InEnergyOfNormalAbility1, string InNameOfNormalAbility2,
        int InEnergyOfNormalAbility2, string InNameOfSpecialAbility, int InUseEnergyOfSpecialAbility,
        int InLimitOfSpecialAbility, int InMaxHP, int InCurrentHP
        ):Name(InName), Role(InRole),
        NameOfNormalAbility1(InNameOfNormalAbility1), EnergyOfNormalAbility1(InEnergyOfNormalAbility1),
        NameOfNormalAbility2(InNameOfNormalAbility2), EnergyOfNormalAbility2(InEnergyOfNormalAbility2),
        NameOfSpecialAbility(InNameOfSpecialAbility),UseEnergyOfSpecialAbility(InUseEnergyOfSpecialAbility),
        LimitOfSpecialAbility(InLimitOfSpecialAbility), MaxHP(InMaxHP), CurrentHP(InCurrentHP)
        {


        };

        string Name;
        string Role;
        string NameOfNormalAbility1;
        string NameOfNormalAbility2;
        string NameOfSpecialAbility;
        // dani ghofli
        bool danighofliused = false;
        void SetAmountShield(int);
        int GetAmountShield() const;

        // big taha
        void SetBigTahaMarked(int);
        int GetBigTahaMarked();
        void DecreaseBigTahaMarked();

        void SetRoundShield(int);
        int GetRemainRoundShield();
        void DecreaseRoundShield();

        int RemainRoundShield = 0;

        virtual void SpecialAbility(SpecialAbilityContext& ) = 0;
        virtual void NormalAbility1(AbilityContext& ) = 0;
        virtual void NormalAbility2(AbilityContext& ) = 0;
        virtual void ApplyEndOfRoundEffects(int , GameManager&, Team&, Team&) = 0;
        void GetNameOfAbility() const;


        bool CanUseAbility(int ,int , Team&) const;
        
        
        int GetHP() const;
        int GetEnergyOfNormalAbility1() const;
        int GetEnergyOfNormalAbility2() const;
        int GetUseEnergyOfSpecialAbility() const;

        int GetLimitOfSpecialAbility() const;

        int GetHillRoundAmount();
        int GetHillExpireRound();

        int GetDamageMultiplierExpire() const;
        
     
        // GameManager for Inverse world
        void TakeDamage(int, bool,DamageType ,GameManager&);
        void Hill(int, GameManager&);

        bool IsDead();

        // special ability limit bool
        
        bool GetIsSpecialAbilityUsable(int ,Team&) const;


        // white doctor
        void SetDamageMultiplier( int);
        // serom khon small taha
        void SetHillRound(int, int);

        // damage mulitplier
        bool IsDamageMultiplierEnabled = false;

        //big taha, badan piyade sazi bshe
        bool IsHiddenFunc() const;
        void SetHidden();
        void SetUnHidden();      

        //special shield danny
        bool HaveShield = false;
        void SetShieldEndRound(int );

        //big taha
        // Akhar har dor in bayad check beseh.
        bool BigTahaMarked = false;

        //Pouya KazhDam Aghrab
        // bayad Akhar har round hp ro kam konim
        bool IsAghrabActivated = false;
        bool IsAghrabExists = false;

        bool IsGroupDamage = false;


        bool IsAbilityActivated = true;
        
        int GetCurrentHP();
        void SetCurrentHP(int );
        void SetDead();
        void SetLive(int);

        virtual ~Hero() = default;
};