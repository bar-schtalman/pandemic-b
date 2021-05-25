#include "Virologist.hpp"
using namespace std;

namespace pandemic{
    
        Player& Virologist::treat(City city){
        if( this -> board[city] == 0){
            throw invalid_argument{"Virologist: city has no disease"};
        }

        if(!has_card(city) && city != this -> curr_city){
            throw invalid_argument{"Virologist: no card!"};
        }
        if(this -> board.exists_cure(this->board.get_color(city))){
            this -> board [city] = 0;
        }
        else{
            this -> board [city] = (this->board[city])  -1;
        }
        this -> pcards.erase(city);
        return *this;
    }
}