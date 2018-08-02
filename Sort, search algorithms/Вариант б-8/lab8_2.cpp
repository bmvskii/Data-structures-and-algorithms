#include <iostream>

int main()
{
	unsigned int hotel = (1 << 20);
	int cmd, room;

	while (true)
	{
		std::cin >> cmd;
		switch (cmd)
		{
		case 1:
			std::cin >> room; 
			if (room < 1 || room > 20) {
				std::cout << "Tolko 20 komnat" << std::endl;
				break;
			}
			if (hotel & (1 << (room - 1)))
				std::cout << "Zanyato" << std::endl;
			else
				std::cout << "Svobodno" << std::endl;
			break;
		case 2:
			std::cin >> room; 
			if (room < 1 || room > 20) {
				std::cout << "Tolko 20 komnat" << std::endl;
				break;
			}
			if (hotel & (1 << (room - 1)))
				std::cout << "Komnata uzhe zanyata" << std::endl;
			else
				hotel |= (1 << (room - 1));
			break;
		case 3:
			std::cin >> room; 
			if (room < 1 || room > 20) {
				std::cout << "Tolko 20 komnat" << std::endl;
				break;
			}
			if (!(hotel & (1 << (room - 1))))
				std::cout << "Komnata i tak svobodna" << std::endl;
			else
				hotel &= ~(1 << (room - 1));
			
			break;
		case 4:
			return 0;
		default:
			std::cout << "Error" << std::endl;
			break;
		}
	}
}