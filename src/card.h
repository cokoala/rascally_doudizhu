#ifndef __CARD_H__
#define __CARD_H__

#include "base.h"

enum CardType{
	CardType_Check=0,//0
	CardType_Single=1,//1
	CardType_Pair=2,//11
	CardType_Three=3,//111
	CardType_Three_Attach_Single=4,//111,2
	CardType_Three_Attach_Pair=4,//111,22
	CardType_Four_Attach_Single=6,//1111,2,3
	CardType_Four_Attach_Pair=7,//1111,22,33
	CardType_Straight=8,//1,2,3,4,5
	CardType_Straight_Pair=9,//11,22,33
	CardType_Straight_Three=10,//111,222
	CardType_Straight_Three_Attach_Single=11,//111,222,3,4
	CardType_Straight_Three_Attach_Pair=12,//111,222,33,44
	CardType_Bomb_Fake=13,//111,@
	CardType_Bomb=14,//1111
	CardType_Bomb_Super=15,//@@@@
	CardType_TNT=16,
	CardType_Rocket=17,//NM
};

struct ComboAnalysis{
	struct Counter{
		byte val;
		int num;
	};
	struct ComboInfo{
		int single;
		int pair;
		int three;
		int four;
		bool straight;
		bool joker;
	};
	int count;
	int unequal;
	int equal_max;
	int equal_min;
	ComboInfo combo;
};

void sort(byte* arr, int len);
void shuffle(byte* const arr, int len);
byte get_value(byte card);
int get_type(byte* const arr, int len,const ComboAnalysis result);
bool contains_value(byte one,byte arr[],int len);
void analyse_combo(byte* const arr, int len, ComboAnalysis& analy);
bool is_straight(byte* const arr, int len);
#endif