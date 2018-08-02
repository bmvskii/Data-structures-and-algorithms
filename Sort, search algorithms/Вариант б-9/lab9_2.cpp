#include <iostream>

struct ProductItem
{
	const char * m_productName;
	double m_price;
	double m_quantity;
};

void selectionSort(ProductItem* _pData, const int _N);
int getTotalCost(ProductItem _p);

int main()
{
	ProductItem items[9] = { 
	{"Potato",2,3},
	{"Orange",15,5},
	{"Banana",10,6},
	{"Cauliflower",5,5},
	{"Milk",2,10},
	{"Rose",50,7},
	{"Tulip",25,10},
	{"Onion",5.5, 50},
	{"Garlic",2,30}
	};

	selectionSort(items, 9);
	for (int i = 0; i < 9; i++)
		std::cout << items[i].m_productName << " " << items[i].m_price << " " << items[i].m_quantity << std::endl;
 
	return 0;
}

void selectionSort(ProductItem* _pData, const int _N)
{
	for (int i = 0; i < _N - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _N; j++)
			if (getTotalCost(_pData[j]) > getTotalCost(_pData[lowIndex]))
				lowIndex = j;

		std::swap(_pData[lowIndex], _pData[i]);
	}
}

int getTotalCost(ProductItem _p)
{
	return _p.m_price * _p.m_quantity;
}