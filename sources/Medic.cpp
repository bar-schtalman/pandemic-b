#include "Medic.hpp"
using namespace std;

namespace pandemic{

    Player& Medic::treat(City city){
        if (curr_city != city) {
            throw invalid_argument {"cant treat city by remote control"};
        }
        if ( this -> board[city] == 0){
            throw invalid_argument{"Medic: City has no disease"};

        }
        this -> board[city] = 0;
        return *this;
        
    }

    Player& Medic::drive(City city){
        
        if ( this -> curr_city == city){
           
            throw invalid_argument{"Medic player already on dest city"
            };
        }

        if(!  Board::is_ni(curr_city,city)){
            throw invalid_argument {"Medic: cities not neighbors"};
        }

        if(this->board.exists_cure(this->board.get_color(city))){
            this ->board[city] = 0;
        }
        this -> curr_city = city;
        return *this;

    }

    Player& Medic::fly_direct(City city){
        if (city == this -> curr_city){
            throw invalid_argument{"Medic player already in dest city, cant fly!"};
        }
        if(!has_card(city)){
            throw invalid_argument{"Medic player does not have the city card"};
        }
            if( this-> board.exists_cure(this -> board.get_color(city))){
                this -> board[city] = 0;
                
            }
            this -> pcards.erase(city);
            this -> curr_city = city;
        
        return *this;
    }


    Player& Medic::fly_charter(City city){
        if (this -> curr_city == city){
            throw invalid_argument{"Medic player already in dest city, cant fly"};
        }
        if (has_card(this-> curr_city)){
            this -> pcards.erase(this -> curr_city);
            this -> curr_city = city;
            if(this -> board.exists_cure(this->board.get_color(city))){
                this ->board[city] = 0;
            }
        }
        return *this;
    }

    Player& Medic::fly_shuttle(City city){
        if (this -> curr_city == city){
            throw invalid_argument{"Medic player already in dest city, cant fly"};
        }
        if(!this-> board.has_st(this -> curr_city) && !this -> board.has_st(city)){
            throw invalid_argument{"Medic  no stations in one of the cities"};
        }

        this -> curr_city = city;
        if( this -> board.exists_cure(this -> board.get_color(city))){
            this -> board [city] = 0;
        }
        return *this;

    }
}