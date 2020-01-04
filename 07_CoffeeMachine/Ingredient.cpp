#include "Ingredient.h"

Ingredient::Ingredient(Coffee::SPtr coffee)
{
	if (coffee == nullptr)
	{
		throw std::string("Nullpointer in CTor of Ingredient");
	}
	else
	{
		mComponent = coffee;
	}
}
