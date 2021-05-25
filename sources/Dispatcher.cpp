#include "Dispatcher.hpp"

using namespace pandemic;
    
        Player& pandemic::Dispatcher::fly_direct(City city){
            if (this -> curr_city == city){
                throw std::invalid_argument{"cant not fly from city to same city"};
            }
            if(this -> board.has_st(this -> curr_city)){
                this -> curr_city = city;
            } 
            else{
                if(!has_card(city)){
                    throw std::invalid_argument{"no card"};
                }
                this -> curr_city = city;
            }   
            return *this;
        }

           
    

