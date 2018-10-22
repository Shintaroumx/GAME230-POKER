#pragma once

struct Cards
{
	int value;
	char showValue;
	char suit;
};

class PokerCards
{
public:
	PokerCards();
	~PokerCards();

	void Initial(Cards array[]);
	void Shuffle(Cards array[], int length);

private:
};



