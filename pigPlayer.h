//
// Created by thetr on 9/18/2024.
//

#ifndef PIGPLAYER_H
#define PIGPLAYER_H



class pigPlayer {
    public:
        void stop();
        void roll();
        void resetTurnTotal();
        int getDieValue();
        int getTurnTotal();
        int getTotal();

    private:
        int dieValue = 0;
        int turnTotal = 0;
        int gameTotal = 0;

};



#endif //PIGPLAYER_H
