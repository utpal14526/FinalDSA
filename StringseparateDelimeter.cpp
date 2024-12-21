#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
    std::string input = "12,34,56,78";
    std::vector<int> numbers; // Vector to store the separated numbers
    std::stringstream ss(input);
    std::string token;

    // Split the input string by comma and convert to integers
    while (std::getline(ss, token, ','))
    {
        numbers.push_back(std::stoi(token));
    }

    // Output the separated numbers
    std::cout << "Separated numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
