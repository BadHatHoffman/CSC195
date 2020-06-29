// Misc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <bitset>

using namespace std;
using u8_t = unsigned char;
using u32_t = unsigned int;
#define BIT(bit_index) (1 << (bit_index - 1))

int main()
{
    //aserts
    int i = 5;
    assert(i == 5);

    int* ptr{ nullptr };
    ptr = &i;
    assert(ptr);

    const int n = 6;
    static_assert(sizeof(int*) == 4, "invalid value");

    //pointer arithmetic
    int int_array[4] = { 34,65,78,12 };
    cout << int_array << endl;
    int* int_ptr = int_array;
    cout << *int_ptr << endl;
    int_ptr++;
    int_ptr++;
    int_ptr--;
    cout << *int_ptr << endl;
    int_ptr = int_array + 2;
    int_ptr = int_ptr - 1;
    cout << *int_ptr << endl;
    int* int_ptr2 = int_ptr;
    if (int_ptr == int_ptr2) cout << "same\n";

    //bitwise
    /*bool b1;
    bool b2;
    bool b3;*/

    const u8_t player = BIT(1);
    const u8_t invisible = BIT(2);
    const u8_t flight = BIT(3);

    u8_t character_stats{ player | flight }; // [0][0][0][0][0][1][1][1]
    character_stats = character_stats | invisible; //turn on bit
    cout << bitset<8>{character_stats} << endl;
    character_stats = character_stats & ~flight; //turn off bit
    cout << bitset<8>{character_stats} << endl;
    character_stats = character_stats ^ player; //toggle bit
    cout << bitset<8>{character_stats} << endl;
    
    u32_t color{ 134 << 8 | 255 }; // a8 r8 g8 b8 (0,0,255,255)
    color = (color >> 8) & 0xff;

    cout << bitset<32>{color} << endl;

    if ((character_stats & player) && (character_stats & invisible))// 0 = false, != true
    {
        cout << "invisible player\n";
    }


    cout << "Hello World!\n";
}


