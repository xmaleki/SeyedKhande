#pragma once

#include <vector>
#include <memory>
#include <string>

class Hero;
class GameManager;

struct Team
{
    std::vector<std::unique_ptr<Hero>> heroes;
    int Energy;
    int turnCount = 0;
    int LastRoundUsedSpecial = -1;
};

struct AbilityContext
{
    GameManager* GameObj;
    Hero* MyHero;
    std::vector<Hero*> &LivingTeamHeroes;
    std::vector<Hero*> &LivingEnemyHeroes;
    Team* MyTeam;
    int RoundCount;
};

struct SpecialAbilityContext
{
    GameManager* GameObj;
    Hero* MyHero;
    std::vector<Hero*> &DeadTeammateHeroes;
    std::vector<Hero*> &LivingTeamHeroes;
    std::vector<Hero*> &LivingEnemyHeroes;
    Team* MyTeam;
    int RoundCount;
};
