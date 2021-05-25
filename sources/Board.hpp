#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <unordered_set>


namespace pandemic{

    class Board{

        private:
            static std::map<City, std::set<City>> neighbors;
            std::map<City,int> deases_level;
            std::map<City,Color> city_color;

            std::set<City> stations;
            std::unordered_set<Color> cures;

            


        public:

            Board();

            ~Board(){}
            

            bool is_clean();

            int& operator[](City city);

            friend std::ostream& operator<<(std::ostream& output, const Board& board);

            void remove_cures();

            void remove_stations();

            static bool is_ni(City a, City b);

            bool has_st(City c);

            void build_st(City c);

            // void readToArray();

            bool exists_cure(Color color);

            void new_cure_dis(Color color);

            Color get_color(City city);

            




    };
};