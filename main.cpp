#include <iostream>
#include "pigPlayer.h"

using namespace std;

bool continueRolling();
string playerInput(pigPlayer player, pigPlayer computer);
void playerLoop(pigPlayer &player, pigPlayer computer);
void computerLoop(pigPlayer &computer);

int main() {
    pigPlayer player;
    pigPlayer computer;

    while (true) {
        playerLoop(player, computer);
        if (player.getTotal() >= 100) {
            cout << "Player Wins with " << player.getTotal() << " points" <<  endl;
            break;
        }

        computerLoop(computer);
        if (computer.getTotal() >= 100) {
            cout << "Computer Wins with " << computer.getTotal() << " points" << endl;
            break;
        }
    }
    return 0;
}

bool continueRolling() {
    if (rand() % 3 + 1 == 1) {
        return false;
    }
    return true;
}

void computerLoop(pigPlayer &computer) {
    while (true) {
        computer.roll();
        cout << "Computer rolled: " << computer.getDieValue() << endl;

        if (computer.getDieValue() == 1) {
            computer.resetTurnTotal();
            computer.stop();
            cout << "\n";
            break;
        }

        if (continueRolling()) {
            computer.stop();
            cout << "\n";
            break;
        }
    }
}

void playerLoop(pigPlayer &player, pigPlayer computer) {
    while (true) {
        string plrInp = playerInput(player, computer);

        if (plrInp == "R" or plrInp == "r") {
            player.roll();
            cout << "You rolled a " << player.getDieValue() << "\n\n";
            if (player.getDieValue() == 1) {
                player.resetTurnTotal();
                player.stop();
                cout << "\n";
                break;
            }
        }
        else {
            player.stop();
            cout << "\n";
            break;
        }
    }
}

string playerInput(pigPlayer player, pigPlayer computer) {
    cout << "Turn Total: " << player.getTurnTotal() << "\nGame Total: " << player.getTotal() << "\tComputer Game Total: " << computer.getTotal() << "\n(R)oll or (S)top: ";
    string input;
    cin >> input;
    return input;
}