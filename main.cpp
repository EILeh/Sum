/* Sum
 *
 * Description
 *
 * Program asks the user to input integers that are separated by spaces and then
 * counts the sum of all the integers using recursion.
 *
 * Writer of the program
 *
 * Name: EILeh
 */

#include <iostream>
#include <string>
#include <vector>

#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif


std::vector<std::string> split(const std::string& s, const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        // Finds from every fileline a separator and stores its' location to a
        // variable new_part.
        std::string new_part = tmp.substr(0, tmp.find(delimiter));

        // Variable tmp starts splitting after the separator.
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());

        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

//
int sum_recursive(std::vector<int>& v)
{

    RECURSIVE_FUNC

    // If vector's v size is 1 then the sum of the integer is the integer at
    // index 0.
    if ( v.size() == 1 )
    {
        return v.at(0);
    }

    else
    {
        // Initializes a variable last_member and stores the information of the
        // member that is the last one in the vector.
        int last_member = v.back();

        // Removes the last member from the vector.
        v.pop_back();

        // Initializes a variable that stores the information of the sum.
        int sum = 0;

        // Function calls itself and adds the last member to the variable sum.
        sum = sum_recursive(v) + last_member;

        return sum;

    }
}


#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter integers separated by spaces: ";

    std::string line;
    getline(std::cin, line);

    std::vector<std::string> strings = split(line, ' ', true);

    std::vector<int> integers;

    for(const auto& s : strings)
    {
        integers.push_back(stoi(s));
    }

    std::cout << "Sum: " << sum_recursive(integers) << std::endl;
}
#endif
