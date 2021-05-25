#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{
    class Medic : public Player {

        public:
            Medic(Board& board, City city):Player(board,city){
                this-> role_ = "Medic";
            }

            Player& treat(City city)override;
            Player& drive(City city)override;
            Player& fly_direct(City city)override;
            Player& fly_charter(City city)override;
            Player& fly_shuttle(City city)override;

    };
}