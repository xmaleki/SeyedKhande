#pragma once
#include <vector>
#include <array>
#include <memory>
#include "Hero.h"
#include "GameTypes.h"



using namespace std;

class GameManager
{

    private:
        
        int CurrentTeamIndex;
        int StartingTeamIndex;
        int RoundCounter = 0;
    
        // Agha Shahriar
        bool IsWorldInverse = false;
        int WorldInversionRoundRemaining = 0;

    public:
        void Run();
        void initializeHeroes();
        void printHeroes() const;
        void SetRoundEnergy();
        void printTeamStatus() const;
        void GameLoop();
        bool isGameOver() const;
        void Player(int);
        void PrintHeroAndAbility(int ) const;
        bool CanTeamMakeAnyMove(int ) ;
        Hero* FindHeroByName(const string &, int);
        Hero* ChooseHero(Team& team);
        int ChooseAbilityForMyHero(Hero* , Team& );
        int GetRoundCounter() const;
        void ApplyEndOfRoundEffects();
        
        void DeleteDeadHeroes(vector<unique_ptr<Hero>> & );

        // Agha Shahriar
        void ActivateWorldInversion(int);
        void DeActivateWorldInversion();
        bool IsWorldInversed() const;  
        
        void SpecifyWinner() const;

        array<Team, 2> teams;

        Hero* kazhdam = nullptr;
        Hero* BigTahaMark = nullptr;

};
