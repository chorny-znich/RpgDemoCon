#include "ini_parser.h"
#include <iostream>
#include <format>
#include <fstream>

namespace dr
{
  /**
   * @brief Read from the ini file and create the object contains all ini file's sections
   * @param path to the ini file 
   * @return The object of the Document class
   */
  IniDocument dr::load(const std::string& filename)
  {
		IniDocument doc;
		Section* section = nullptr;
		std::ifstream ifs(filename);
		if (ifs) {
			std::string str;
			while (std::getline(ifs, str)) {
				if (!str.empty()) {
					if (str[0] == '[') {
						std::string sectionName(str.substr(1, str.size() - 2));
						section = &doc.addSection(sectionName);
					}
					else {
						size_t pos = str.find("=");
						section->insert({ str.substr(0, pos), str.substr(pos + 1) });
					}
				}
			}
		}
		else {
			std::cout << std::format("File not found at: {}\n", filename);
		}
		return doc;
  }
}