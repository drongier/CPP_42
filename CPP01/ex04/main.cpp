/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:20:02 by drongier          #+#    #+#             */
/*   Updated: 2025/03/06 12:20:03 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw std::runtime_error("Cannot open input file");
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename);
    if (!outFile.is_open()) {
        inFile.close();
        throw std::runtime_error("Cannot create output file");
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outFile << line;
        if (!inFile.eof()) {
            outFile << std::endl;
        }
    }

    inFile.close();
    outFile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    try {
        replaceInFile(argv[1], argv[2], argv[3]);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}