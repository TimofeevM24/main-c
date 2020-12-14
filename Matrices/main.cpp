#include "Matrix.hpp"
#include <fstream>
#include <vector>



int main()
{
	std::string in_path, out_path;
	std::cout << "Enter input file: ";
	std::cin >> in_path;
	std::cout << "Enter output file: ";
	std::cin >> out_path;

	std::ifstream fin(in_path);
	std::ofstream fout(out_path);

	Matrix lm;
	Matrix rm;

	while (fin >> lm && fin >> rm)
	{
		fout << lm * rm;
	}

	return 0;
}