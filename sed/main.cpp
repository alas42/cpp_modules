#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage: ./replace [filename] [string1]" << std::endl;
		return (1);
	}

	std::stringstream buffer;
	std::ofstream ofs;
	std::ifstream ifs;
	std::string content;
	std::string content1;
	std::string s1("Template");
	std::string s2(argv[2]);
	std::string filename(argv[1]);

	if (s2.empty() || filename.empty() || !s1.compare(s2))
	{
		std::cout << "Error: [filename], [string1] and should not be empty" << std::endl;
		return (1);
	}
	std::string	outfile1 = filename + ".cpp";
	std::string outfile2 = filename + ".hpp";
	ifs.open("Template.cpp");
	if (!ifs.is_open())
	{
		std::cout << "the infile could not be opened: be sure to enter a valid filename" << std::endl;
		return (1);
	}

	ofs.open(outfile1.c_str(), std::ios::trunc);
	if (!ofs.is_open())
	{
		std::cout << "The outfile could not be opened/created, be sure to enter a valid filename" << std::endl;
		return (1);
	}

	buffer << ifs.rdbuf();
	content = buffer.str();

	size_t	pos = 0;
	size_t	len_s1 = s1.length();
	pos = content.find(s1);

	while (pos != (size_t) -1)
	{
		content.erase(pos, len_s1);
		content.insert(pos, s2);
		pos = content.find(s1);
	}

	ofs << content;
	ifs.close();
	ofs.close();
	buffer.clear();
	content.clear();


	std::stringstream buffer1;
	std::ofstream ofs1;
	std::ifstream ifs1;
	ifs1.open("Template.hpp");
	if (!ifs1.is_open())
	{
		std::cout << "the infile could not be opened: be sure to enter a valid filename" << std::endl;
		return (1);
	}

	ofs1.open(outfile2.c_str(), std::ios::trunc);
	if (!ofs1.is_open())
	{
		std::cout << "The outfile could not be opened/created, be sure to enter a valid filename" << std::endl;
		return (1);
	}

	buffer1 << ifs1.rdbuf();
	content1 = buffer1.str();

	size_t	pos1 = 0;
	size_t	len_s11 = s1.length();
	pos1 = content1.find(s1);

	while (pos1 != (size_t) -1)
	{
		content1.erase(pos1, len_s11);
		content1.insert(pos1, s2);
		pos1 = content1.find(s1);
	}

	ofs1 << content1;
	ifs1.close();
	ofs1.close();
	buffer1.clear();

	return (0);
}
