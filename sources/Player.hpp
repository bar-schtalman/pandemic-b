#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{
    class Player{

        protected:
        Board& board;
        City curr_city;
        std::string role_;
        std::set<City> pcards;

        Color rnd_color();

        public:
        Player(Board& board,City city): board(board), curr_city(city){
            this -> pcards = {};
        }
            // this -> board = board;
            // this -> city = city;
        

        bool has_card(City c);
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual void build();
        virtual Player& discover_cure(Color color);
        virtual Player& treat(City city);


        //nothing to do down here
        std::string role();
        Player& take_card(City city);

    };

}