# Game Station | C

## Duration: May 2022 - June 2022

## Overview
Game Station is a multi-game platform developed in C, featuring classic games like Hangman, Math Quiz, and Tic Tac Toe. This project showcases efficient use of algorithms and core programming concepts such as loops and conditionals, delivering an immersive and interactive gaming experience.

---

## Features
- **Multiple Game Choices**: Includes Hangman, Math Quiz, and Tic Tac Toe, each meticulously implemented for an engaging user experience.
- **Efficient Algorithms**: Optimized loops and conditionals power the games, ensuring smooth gameplay and responsive interactions.
- **Dual-Interface System**: Separates user and admin functionalities for versatile platform management:
  - **User Functionalities**: Play games, track scores, and manage profiles.
  - **Admin Functionalities**: Manage user scores and profiles, with additional controls for password changes and security.

---

## How It Works
### Game Selection
- Players choose from the available games at the main menu.
- Each game offers a unique set of rules and gameplay mechanics.

### Gameplay Logic
- **Hangman**: Guess the word within a limited number of attempts.
- **Math Quiz**: Solve randomly generated math problems under time constraints.
- **Tic Tac Toe**: Play against an opponent with a classic 3x3 grid logic.

### User Interaction
- Users can:
  - Track and view their scores.
  - Manage their profiles (e.g., update usernames).

### Admin Privileges
- Admins can:
  - View and reset user scores.
  - Manage profiles, including password updates.

---

## Requirements
- A C compiler (e.g., GCC)
- Console interface for interaction

---

## How to Compile and Run
1. Clone the repository or download the source files.
2. Compile the program:
   ```bash
   gcc -o game_station game_station.c
