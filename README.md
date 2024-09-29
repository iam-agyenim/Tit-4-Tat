
# Tit for Tat Strategy Program

## Overview
This C++ project implements the **Tit for Tat** strategy, commonly used in game theory and the **Prisoner's Dilemma**. The Tit for Tat strategy involves copying the opponent's previous action. If the opponent cooperated in the last round, the player will cooperate; if the opponent defected, the player will defect.

In addition to the Tit for Tat strategy, the program also simulates:
- **Evil Strategy**: Always defects.
- **Cooperate Strategy**: Always cooperates.
- **Random Strategy**: Randomly decides between cooperating or defecting.

## Features
- **Tit for Tat Strategy**: Mimics the opponent's previous action.
- **Evil Strategy**: Always defects, representing a non-cooperative approach.
- **Cooperate Strategy**: Always cooperates.
- **Random Strategy**: Randomly chooses to cooperate or defect.

## Program Structure
The program utilizes a class-based design, primarily using the `STRATEGY` class to manage and simulate the different decision-making strategies.

### `STRATEGY` Class

#### Attributes:
- `int stratecode`: Stores the code for the current strategy.

#### Methods:
- `int getstratecode()`: Returns the current strategy code.
- `void setstratecode(int strategycode)`: Sets a new strategy code.
- `int evilStrategy()`: Always defects (returns 1).
- `int cooperateStrategy()`: Always cooperates (returns 0).
- `int titfortatStrategy(int code)`: Copies the opponent's last move (if opponent defected, returns 1; if cooperated, returns 0).
- `int randomStrategy()`: Randomly returns 0 or 1 (cooperate or defect).

### Strategy Codes:
1. **1 - Evil Strategy**: Always defect.
2. **2 - Cooperate Strategy**: Always cooperate.
3. **3 - Tit for Tat Strategy**: Mimic the opponent's last move.
4. **4 - Random Strategy**: Randomly choose to cooperate or defect.

## How to Use

### 1. Compile the Program:
Ensure you have a C++ compiler installed. Use the following command to compile the program:

```bash
g++ -o titfortat main1.cpp
```

### 2. Run the Program:
After compiling, run the program with:

```bash
./titfortat
```

### 3. Setting the Strategy:
Within the program, you can set the strategy by calling the `setstratecode()` method. The program will then simulate interactions based on the selected strategy.

### 4. Example Usage:
Here’s an example of setting the strategy to Tit for Tat and simulating a round of play:

```cpp
STRATEGY strategy;

// Set strategy to Tit for Tat (code 3)
strategy.setstratecode(3);

// Opponent's last move: Defected (1)
int opponent_last_move = 1;

// Tit for Tat response: Defects (returns 1)
int next_move = strategy.titfortatStrategy(opponent_last_move);
```

## Requirements
- C++ compiler (e.g., `g++`, `clang++`)
- Standard C++ libraries

## Future Improvements
- Allow user input to select strategies at runtime.
- Add a graphical user interface (GUI) for better interaction and visualization.
- Expand to include adaptive strategies where the program learns from past interactions.


