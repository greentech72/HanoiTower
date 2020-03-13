#include "hanoi_towers.h"

using namespace std;

vector<string> generate_moves(int amount){
    vector<string> moves;

    stack<int> pin1;
    stack<int> pin2;
    stack<int> pin3;

    for(int i = 0; i < amount; i++){
        pin1.push(amount - i);
    }

    while(pin2.size() != amount || pin3.size() != amount){

        // 1 - 2
        // 1 - 3
        // 2 - 3
        if( pin1.size() == 0 && pin2.size() == 0 )
            break;
        if( pin1.size() == 0 && pin3.size() == 0 )
            break;

        // 1 - 2
        if( pin1.size() == 0 ){
            pin1.push(pin2.top());
            pin2.pop();
            moves.push_back("2 => 1");
        } else if(pin2.size() == 0){
            pin2.push(pin1.top());
            pin1.pop();
            moves.push_back("1 => 2");
        } else if(pin1.top() < pin2.top()){
            pin2.push(pin1.top());
            pin1.pop();
            moves.push_back("1 => 2");
        } else{
            pin1.push(pin2.top());
            pin2.pop();
            moves.push_back("2 => 1");
        }

        if(pin2.size() == amount || pin3.size() == amount)
            break;

        // 1 - 3
        if( pin1.size() == 0 ){
            pin1.push(pin3.top());
            pin3.pop();
            moves.push_back("3 => 1");
        } else if(pin3.size() == 0){
            pin3.push(pin1.top());
            pin1.pop();
            moves.push_back("1 => 3");
        } else if(pin1.top() < pin3.top()){
            pin3.push(pin1.top());
            pin1.pop();
            moves.push_back("1 => 3");
        } else{
            pin1.push(pin3.top());
            pin3.pop();
            moves.push_back("3 => 1");
        }

        if(pin2.size() == amount || pin3.size() == amount)
            break;

        // 2 - 3
        if( pin2.size() == 0 ){
            pin2.push(pin3.top());
            pin3.pop();
            moves.push_back("3 => 2");
        } else if(pin3.size() == 0){
            pin3.push(pin2.top());
            pin2.pop();
            moves.push_back("2 => 3");
        } else if(pin2.top() < pin3.top()){
            pin3.push(pin2.top());
            pin2.pop();
            moves.push_back("2 => 3");
        } else{
            pin2.push(pin3.top());
            pin3.pop();
            moves.push_back("3 => 2");
        }
    }
    return moves;
}



void do_move(vector<stack<int>>* pins, string move){
    int from = (int)(move[0]) - 49;
    int to = (int)(move[5]) - 49;
    (*pins)[to].push( (*pins)[from].top() );
    (*pins)[from].pop();
}



vector<stack<int>> generate_pins(int amount){
    vector<stack<int>> pins;
    pins.resize(3);
    for(int i = 0; i < amount; i++){
        pins[0].push(amount - i);
    }
    return pins;
}

