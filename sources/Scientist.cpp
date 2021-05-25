#include "Scientist.hpp"
using namespace std;

namespace pandemic{

    Player& Scientist::discover_cure(Color color){
        bool cures = this -> board.exists_cure(color);
        bool st = this -> board.has_st(this -> curr_city);
        int count = 0;

        for (City c : this -> pcards){
            if (this -> board.get_color(c) == color){
                count++;    
            } 
        }

        if(!st){
            throw invalid_argument{"Scientist got no reaserch station"};
        }

        if (count < this -> discover_ability){
            throw invalid_argument {"Scientist: not enough cards"};
        }

        if (!cures){
            //copt to temp set
            set<City> temp;
            for(City c : this -> pcards){
                temp.insert(c);
            }

            int counter = 0;
            //earase n cards to heal city
            for(City c : this -> pcards){
                if(this -> board.get_color(c) == color){
                    temp.erase(c);
                    if(counter == this -> discover_ability -1) {
                        break;
                    }
                    counter ++;
                }
            }
            this -> pcards.clear();
            for(City c : temp){
                this -> pcards.insert(c);           
                 }
            this -> board.new_cure_dis(color);

        }
      return *this;
    }
   
}