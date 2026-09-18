# Seyed Khande
<p align="center">
  <a href="https://isocpp.org/"><img src="https://img.shields.io/badge/c++-%2300599C.svg?style=flat&logo=c%2B%2B&logoColor=white"></img></a>
  <a href="http://opensource.org/licenses/MIT"><img src="https://img.shields.io/github/license/arthursonzogni/FTXUI?color=black"></img></a>
  <a href="#"><img src="https://img.shields.io/github/repo-size/xmaleki/SeyedKhande"></img></a>
  <a href="#"><img src="https://img.shields.io/badge/Platform-Desktop-lightgrey.svg"></img></a>
</p>

Seyed Khande is a university Advanced Programming project built around a two-team tactical combat system. Each team selects three unique heroes, manages a shared Energy pool, and uses normal and special abilities to defeat the opposing team.
The project was designed to practice Object-Oriented Programming, inheritance, polymorphism, abstraction, smart pointers, game-state management, and modular C++ development.

# Features
| Feature | Description |
|--|--|
| Heroes | 7 heroes with different roles, HP, and abilities. |
| Team Battles | Two teams, each with 3 heroes, fight against each other. |
| Unique Abilities | Each hero has 2 Normal Abilities and 1 Special Ability. |
| Energy System | Energy is used to activate abilities during the battle. |
| Special Abilities | Powerful abilities with cooldowns and special effects. |
| Turn-Based Combat | Players take turns choosing heroes and using abilities. |
| Status Effects | Abilities can apply effects such as shields, stealth, and damage over time. |
| Hero Revival | Some abilities can bring defeated heroes back into the battle. |
| Console-Based | The game is played entirely through the terminal. |

# Creator
| Name | Student Number |
|--|--|
| Abolfazl Maleki | *40412358052* |

# Project Structure
```text
├── CMakeLists.txt
├── README.md
├── LICENSE
├── main.cpp
│
├── Document/
│ └── Document.pdf
│
├── include/
│ ├── AghaShahriar.h
│ ├── AminEmeni.h
│ ├── BigTaha.h
│ ├── DaniGolang.h
│ ├── GameManager.h
│ ├── GameTypes.h
│ ├── Hero.h
│ ├── PouyaKazhDam.h
│ ├── SmallTaha.h
│ └── WhiteDoctor.h
│ 
└── src/
  ├── AghaShahriar.cpp
  ├── AminEmeni.cpp
  ├── BigTaha.cpp
  ├── DaniGolang.cpp
  ├── GameManager.cpp
  ├── Hero.cpp
  ├── PouyaKazhDam.cpp
  ├── SmallTaha.cpp
  └── WhiteDoctor.cpp
```

# Requirements and Installation
 - GCC
 - CMake 3.10 or newer 
 - Git

# Build And Run
    cd build
    cmake
    make
## Run
    ./app

# How to Play
The goal is to defeat all three heroes of the opposing team. The first team to eliminate all enemy heroes wins the game.

## Game Setup
 1. Two players select their heroes.
 2. Each player chooses 3 different heroes.
 3. The starting player is selected randomly.
 4. The battle begins.
## During a Turn
 1. The current player selects one of their available heroes.
 2. Choose one of the hero's abilities.
 3. Select the target if required.
 4. The ability is executed if the team has enough Energy.
 5. The game updates HP, effects, and other active states.
 6. The player can continue taking actions as long as they have enough Energy.
 7. When the player can no longer perform an action, the turn passes to the other team.
## Rounds
 1. Each round consists of turns for both teams.
 2. Team Energy is updated according to the current round.
 3. Special Abilities can only be used again after their cooldown ends.

# Programming Concepts
|Concept| Usage |
|--|--|
| Object-Oriented Programming | Used to structure the game around heroes, teams, abilities, and game management. |
| Inheritance | Different hero classes inherit from the base `Hero` class. |
| Polymorphism | Each hero provides its own implementation of abilities. |
| Encapsulation | Game data and behavior are organized within classes. |
| Abstraction | Common hero behavior is defined through the abstract `Hero` class. |
| Smart Pointers | `std::unique_ptr` is used for managing hero objects. |
| STL Containers | `std::vector` is used to store and manage heroes. |
| References & Pointers | Used for passing and accessing game objects and contexts. |

# Author
Abolfazl Maleki

Computer Engineering Student at Bu-Ali Sina University

# Contributing
Contributions, suggestions, and improvements are welcome. You can open an Issue or submit a Pull Request.

---
If you enjoyed the project, consider giving it a Star!
