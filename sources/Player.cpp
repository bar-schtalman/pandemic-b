#include "Player.hpp"
#include "City.hpp"
const int MaxCard = 5;

using namespace std;

namespace pandemic{

     

        Player& Player::drive(City city){
            
        if( this -> curr_city == city){
                throw invalid_argument {"error! can not fly to current city while you there"};
        }

        if (!(Board::is_ni(this -> curr_city, city))){
            throw invalid_argument {"error! cities not neighbors"} ;
        }

        this -> curr_city = city;
        return *this;
        }

        Player& Player::fly_direct(City city)
        {
            if( this -> curr_city == city || !has_card(city)){
                throw invalid_argument {"can not fly to current city while you there"};
            } 
            this -> pcards.erase(city);
            this -> curr_city = city;
            return *this;

        }

        Player& Player::fly_charter(City city)
        {
            if(this -> curr_city == city){
                throw invalid_argument{"can not fly to current city while you there"};
            }
            if (!has_card (this -> curr_city)){
                throw invalid_argument {"cant fly to city without the city card!"};
            }
            this -> pcards.erase(this -> curr_city);
            this -> curr_city = city;
            return *this;
        }

        Player& Player::fly_shuttle(City city)
        {
            if ( this -> curr_city == city){
                throw invalid_argument {"error, cant fly to city from itself"};
            }

            if(!(this -> board.has_st(this -> curr_city))){
                throw invalid_argument{"error, current city doesnt has station"};
            }
            if (!this -> board.has_st(city)){
                throw invalid_argument{"error, dest city doesnt has station "};
                
            }

            if( city == this -> curr_city){
                throw invalid_argument ("can not fly from one city to the same city");
            }
            this -> curr_city = city;
            return *this;

        }

        void Player::build()
        {
            if (!has_card(this -> curr_city)){
                throw invalid_argument ("cant build without apropriate card!");
            }
            if(!(this -> board.has_st(this -> curr_city))){
                    this -> pcards.erase(this->curr_city);
                    this -> board.build_st(this -> curr_city);
                }
            
        }
       
        

        Player& Player::discover_cure(Color color)
        {
            int count = 0;
            for(City c: this -> pcards){
                if (this -> board.get_color(c) == color){
                    count ++;
                }
            }
              if (count < MaxCard){
                  throw invalid_argument{"not enough cards"};
              }
            
            bool ans_st = this -> board.has_st(this ->curr_city);
            if(!ans_st){
                throw invalid_argument {"no research station"};
            }
            bool ans_cure = this-> board.exists_cure(color);
            if (!ans_cure){
                set<City> temp;
                for (City c : this ->pcards){
                    temp.insert(c);
                }
                int counter = 0;
                for (City c : this -> pcards){
                    if ( this -> board.get_color(c) == color){
                        temp.erase(c);
                        if (counter == MaxCard -1 ){
                            break;
                        }
                        counter++;
                    }
                }
                this -> pcards.clear();

                for (City c : temp){
                    this -> pcards.insert(c);
                }
                this -> board.new_cure_dis(color);
            }
            return *this;
        }

        Player& Player::treat(City city)
        {
            if (this -> board[this -> curr_city] == 0){
                throw invalid_argument("city has no disease");
            }
            if ( this -> board.exists_cure(this-> board.get_color(city))){
                this -> board [this ->curr_city] = 0;
            }
            else{
                this -> board [this -> curr_city] --;
            }
            return *this;
        }
        string Player::role(){
        
            return  role_;
        }
    
        Player& Player::take_card(City city){
            this -> pcards.insert(city);
            return *this;
    }
        bool Player::has_card(City c){
            for (const City t : this -> pcards){
                if ( t == c) {
                return true;
                }
            }
            return false;
        }
        // Color Player::rnd_color(){
        //     const int size = 4;
        //     Color list[size] = {Color::Black, Color::Yellow, Color::Blue , Color::Red};
        //     Color rnd = list[rand() & size];
        //     return rnd;
        // } 
        
}