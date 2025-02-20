//
// Created by Daniel Skalski on 26/12/2024.
//

#include <string>
#include "Board.h"

Board::Board(const std::string &original, const std::string &solved) {
     for (int i = 0; i < 9; ++i) {
         for (int j = 0; j < 9; ++j) {
             initialState[i][j] = original[9 * i + j];
             solvedState[i][j] = solved[9 * i + j];
             currentState[i][j] = original[9 * i + j];
         }
     }
}

void Board::resetBoard() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
        Board::currentState[i][j] = Board::initialState[i][j];
        }
    }
}

void Board::updateCurrentState(const std::string &state) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            currentState[i][j] = state[9 * i + j];
        }
    }
}

Board& Board::operator=(const Board &other) {
    if (this == &other) {
        return *this;
    }

    std::memcpy(initialState, other.initialState, sizeof(initialState));
    std::memcpy(currentState, other.currentState, sizeof(currentState));
    std::memcpy(const_cast<char(*)[9]>(solvedState), other.solvedState, sizeof(solvedState));

    return *this;
}

bool Board::isInsertedByUser(const int &i, const int &j) {
    if (currentState[i][j] != initialState[i][j]) return true;
    return false;
}
