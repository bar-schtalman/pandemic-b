#include "Board.hpp"
#include "City.hpp"
#include <fstream>
#include <vector>
#include <map>
#include "GeneSplicer.hpp"
#include "Researcher.hpp"

using namespace std;

namespace pandemic
{

    Board::Board()
    {
        //init cities
        deases_level = {{Algiers, 0}, {Atlanta, 0}, {Baghdad, 0}, {Bangkok, 0}, {Beijing, 0}, {Bogota, 0}, {BuenosAires, 0}, {Cairo, 0}, {Chennai, 0}, {Chicago, 0}, {Delhi, 0}, {Essen, 0}, {HoChiMinhCity, 0}, {HongKong, 0}, {Istanbul, 0}, {Jakarta, 0}, {Johannesburg, 0}, {Karachi, 0}, {Khartoum, 0}, {Kinshasa, 0}, {Kolkata, 0}, {Lagos, 0}, {Lima, 0}, {London, 0}, {LosAngeles, 0}, {Madrid, 0}, {Manila, 0}, {MexicoCity, 0}, {Miami, 0}, {Milan, 0}, {Montreal, 0}, {Moscow, 0}, {Mumbai, 0}, {NewYork, 0}, {Osaka, 0}, {Paris, 0}, {Riyadh, 0}, {SanFrancisco, 0}, {Santiago, 0}, {SaoPaulo, 0}, {Seoul, 0}, {Shanghai, 0}, {StPetersburg, 0}, {Sydney, 0}, {Taipei, 0}, {Tehran, 0}, {Tokyo, 0}, {Washington, 0}};

        city_color = {{Algiers, Black}, {Atlanta, Blue}, {Baghdad, Black}, {Bangkok, Red}, {Beijing, Red}, {Bogota, Yellow}, {BuenosAires, Yellow}, {Cairo, Black}, {Chennai, Black}, {Chicago, Blue}, {Delhi, Black}, {Essen, Blue}, {HoChiMinhCity, Red}, {HongKong, Red}, {Istanbul, Black}, {Jakarta, Red}, {Johannesburg, Yellow}, {Karachi, Black}, {Khartoum, Yellow}, {Kinshasa, Yellow}, {Kolkata, Black}, {Lagos, Yellow}, {Lima, Yellow}, {London, Blue}, {LosAngeles, Yellow}, {Madrid, Blue}, {Manila, Red}, {MexicoCity, Yellow}, {Miami, Yellow}, {Milan, Blue}, {Montreal, Blue}, {Moscow, Black}, {Mumbai, Black}, {NewYork, Blue}, {Osaka, Red}, {Paris, Blue}, {Riyadh, Black}, {SanFrancisco, Blue}, {Santiago, Yellow}, {SaoPaulo, Yellow}, {Seoul, Red}, {Shanghai, Red}, {StPetersburg, Blue}, {Sydney, Red}, {Taipei, Red}, {Tehran, Black}, {Tokyo, Red}, {Washington, Blue}};

      
        


        stations = {};
        cures = {};
    }
    std::map<City, std::set<City>> Board::neighbors  {
            {Algiers, {Madrid, Paris, Istanbul, Cairo}},
            {Atlanta, {Chicago, Miami, Washington}},
            {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
            {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
            {Beijing, {Shanghai, Seoul}},
            {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
            {BuenosAires, {Bogota, SaoPaulo}},
            {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
            {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
            {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
            {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
            {Essen, {London, Paris, Milan, StPetersburg}},
            {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
            {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
            {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
            {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
            {Johannesburg, {Kinshasa, Khartoum}},
            {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
            {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
            {Kinshasa, {Lagos, Khartoum, Johannesburg}},
            {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
            {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
            {Lima, {MexicoCity, Bogota, Santiago}},
            {London, {NewYork, Madrid, Essen, Paris}},
            {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
            {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
            {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
            {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
            {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
            {Milan, {Essen, Paris, Istanbul}},
            {Montreal, {Chicago, Washington, NewYork}},
            {Moscow, {StPetersburg, Istanbul, Tehran}},
            {Mumbai, {Karachi, Delhi, Chennai}},
            {NewYork, {Montreal, Washington, London, Madrid}},
            {Osaka, {Taipei, Tokyo}},
            {Paris, {Algiers, Essen, Madrid, Milan, London}},
            {Riyadh, {Baghdad, Cairo, Karachi}},
            {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
            {Santiago, {Lima}},
            {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
            {Seoul, {Beijing, Shanghai, Tokyo}},
            {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
            {StPetersburg, {Essen, Istanbul, Moscow}},
            {Sydney, {Jakarta, Manila, LosAngeles}},
            {Taipei, {Shanghai, HongKong, Osaka, Manila}},
            {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
            {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
            {Washington, {Atlanta, NewYork, Montreal, Miami}}};

    bool Board::is_clean()
    {
        for (const pair<City, int> pair : this->deases_level)
        {
            if (pair.second != 0)
            {
                return false;
            }
        }
        return true;
    }

    int &Board::operator[](City city)
    {
        return this->deases_level.at(city);
    }

    // ostream& operator<<(ostream& output, const Board& board){
    //     return (output << "hello " << endl);
    // }
    ostream &operator<<(ostream& output, const Board &board)
    {
        output << "--------------------------Board--------------------------" << endl
           << endl;
        output << "                 cities and deases level               " << endl
           << endl;

        for (const auto &level : board.deases_level)
        {
            output << city_by_string(level.first) << ": " << level.second << endl;
        }

        output << endl;
        output << "               discovered cures               " << endl
           << endl;
        for (const auto &cure : board.cures)
        {
            output << colors_by_string(cure) << endl;
        }

        output << endl;
        output << "               research stations               " << endl
           << endl;
        for (const auto &station : board.stations)
        {
            output << city_by_string(station) << endl;
        }

        return output;
    }
    void Board::remove_cures()
    {
        this->cures.clear();
    }
    void Board::remove_stations()
    {
        this->stations.clear();
    }

     bool Board::is_ni(City a, City b){
         return (neighbors.at(a).count(b) != 0);
     }

    bool Board::has_st(City c)
    {
        for (const City t : this->stations)
        {
            if (t == c)
            {
                return true;
            }
        }
        return false;
    }

    void Board::build_st(City c)
    {
        this->stations.insert(c);
    }

    bool Board::exists_cure(Color color)
    {
        for (const Color c : this->cures)
        {
            if (c == color){
                return true; }
        }
        return false;
    }
    void Board::new_cure_dis(Color color)
    {
        this->cures.insert(color);
    }

    Color Board::get_color(City city)
    {
        return this->city_color.at(city);
    }

};
// using namespace pandemic;

// int main(){
//   Board board;

//   board[City::Washington] = 2;
//   board[City::Santiago] = 3;
//   board[City::Lima] = 2;
//   board[City::SaoPaulo] = 2;
//   board[City::Shanghai] = 3;
//   board[City::Osaka] = 4;
//   board[City::Manila] = 5;
//   board[City::Karachi] = 1;

//    GeneSplicer player1{board, City::Shanghai};
//     player1.drive(City::Beijing);
// //    player1.take_card(City::Lima);
// //    player1.build();

// //    player1.take_card(City::Santiago);
// //    player1.take_card(City::Osaka);

// //    player1.drive(City::Santiago);
// //    player1.build();

// //    player1.fly_shuttle(City::Lima);

// //    player1.fly_direct(City::Osaka);
// //    //player1.build();
// //    player1.treat(City::Osaka);

// //   Researcher player2{board ,City::Shanghai};

// //   player2.take_card(City::Santiago);
// //   player2.take_card(City::Osaka);
// //   player2.take_card(City::Manila);
// //   player2.take_card(City::Seoul);
// //   player2.take_card(City::Taipei);
// //   player2.take_card(City::Shanghai);

// //   player2.discover_cure(Color::Red);
// //   player2.treat(City::Shanghai);

// //   player2.take_card(City::Manila);
// //   player2.take_card(City::Santiago);
// //   player2.take_card(City::Shanghai);

// //   player2.fly_charter(City::Manila);
// //   player2.build();
// //   player2.treat(City::Manila);

// //   player1.fly_shuttle(City::Santiago);
// //   player1.treat(City::Santiago);

// //   cout << "playr1: " << player1.role() << endl;
// //   cout << "playr2: " << player2.role() << endl;
//   cout << board << endl;

//   return 0;
// }