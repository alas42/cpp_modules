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
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string filename = argv[1];
	std::string	outfile = filename;
	outfile.append(".replace");

	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cout << "Error: [filename], [string1] and [string2] should not be empty" << std::endl;
		return (1);
	}

	std::ifstream ifs(filename.c_str());
	std::ofstream output_file(outfile.c_str());
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	
	std::string content = buffer.str();
	size_t	npos = -1;
	size_t	pos = 0;
	size_t	len_s1 = s1.length();
	pos = content.find(s1);
	while (pos != npos)
	{
		std::cout << "found one at " << pos << std::endl; 
		content.erase(pos, len_s1);
		content.insert(pos, s2);
		pos = content.find(s1);
	}
	output_file << content;
	ifs.close();
	output_file.close();
	return (0);
}
