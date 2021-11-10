#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace [filename] [string1] [string2]" << std::endl;
		return (1);
	}

	std::stringstream buffer;
	std::ofstream ofs;
	std::ifstream ifs;
	std::string content;
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::string filename(argv[1]);
	std::string	outfile = filename;

	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cout << "Error: [filename], [string1] and [string2] should not be empty" << std::endl;
		return (1);
	}

	outfile.append(".replace");

	ifs.open(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "the infile could not be opened: be sure to enter a valid filename" << std::endl;
		return (1);
	}

	ofs.open(outfile.c_str(), std::ios::trunc);
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
	return (0);
}
