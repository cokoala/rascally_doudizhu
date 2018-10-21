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
		bool equal(int _1, int _2, int _3, int _4) const{
			return single==_1 && pair==_2 && three==_3 && four==_4;
		}
		bool more(int _1, int _2, int _3, int _4) const{
			return (_1==0? single==_1:single>=_1)
				&& (_2==0? pair==_2:pair>=_2)
				&& (_3==0? three==_3:three>=_3)
				&& (_4==0? four==_4:four>=_4);
		}
		bool less(int _1, int _2, int _3, int _4) const{
			return single<=_1 && pair<=_2 && three<=_3 && four<=_4;
		}
		bool attach() const{
			return straight && (three==single || three==pair);
		}
		bool unattach() const{
			return straight && (single+pair)==0;
		}
	};
	int count;
	int unequal;
	int equal_max;
	int equal_min;
	ComboInfo combo;
};

void sort(byte* arr, int len);
void shuffle(byte* arr, int len);
byte get_value(byte card);
int get_type(const ComboAnalysis* result);
bool contains_value(byte one,byte arr[],int len);
void analyse_combo(const byte* arr, int len, ComboAnalysis& analy);
bool is_straight(const byte* arr, int len);
#endif