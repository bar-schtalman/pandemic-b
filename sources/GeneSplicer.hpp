#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{

    class GeneSplicer : public Player {

        public:
            GeneSplicer(Board& board, City city):Player(board,city){
                this -> role_ = "GeneSplicer";
            }

            Player& discover_cure(Color color);
    };
}