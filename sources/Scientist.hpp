#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic {
    
    class Scientist : public Player{
        private:
            int discover_ability; 

        public:

            Scientist(Board& board, City city,const int cards ):Player(board,city){
                this -> role_ = "Scientist";
                this -> discover_ability = cards;
            }
            ~Scientist(){};

            Player& discover_cure(Color color) override;
    };
}