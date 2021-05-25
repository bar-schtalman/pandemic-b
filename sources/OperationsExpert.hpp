#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{
    class OperationsExpert : public Player{

        public: 

        OperationsExpert(Board& board, City city):Player(board,city){
            this -> role_ = "OperationsExpert";
        }
        

        void build()override;
    };
}