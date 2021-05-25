#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{

    class Virologist : public Player{
        public: 
            Virologist(Board& board, City city):Player(board,city){
                this -> role_ = "Virologist";
            }
            ~Virologist(){}
            Player& treat(City city)override;
    };
}