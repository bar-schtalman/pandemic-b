#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic{
    
    class Researcher : public Player{
        public:

        Researcher(Board& board, City city):Player(board,city){
            this -> role_ = "Researcher";
        }
        ~Researcher(){}

        Player& discover_cure(Color color)override;

    };
}