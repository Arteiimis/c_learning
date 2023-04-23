#include <iostream>
#include <string>

std::string intToIPAddress(unsigned int n)
{
    std::string result = "";
    unsigned char bytes[4];
    unsigned char *p = (unsigned char *)&n;
    if (*(p + 3) == 0)
    {
        bytes[0] = *(p + 0);
        bytes[1] = *(p + 1);
        bytes[2] = *(p + 2);
        bytes[3] = *(p + 3);
    }
    else
    {
        bytes[0] = *(p + 3);
        bytes[1] = *(p + 2);
        bytes[2] = *(p + 1);
        bytes[3] = *(p + 0);
    }
    for (int i = 0; i < 4; i++)
    {
        if (i > 0)
        {
            result += ".";
        }
        result += std::to_string((int)bytes[i]);
    }
    return result;
}

unsigned int ipAddressToInt(std::string ipAddress)
{
    unsigned int result = 0;
    unsigned char bytes[4];
    int i = 0;
    int j = 0;
    while (i < ipAddress.length())
    {
        int k = i;
        for (; k < ipAddress.length() && ipAddress[k] != '.'; k++);
        std::string s = ipAddress.substr(i, k - i);
        bytes[j] = (unsigned char)std::stoi(s);
        i = k + 1;
        j++;
    }
    unsigned char *p = (unsigned char *)&result;
    *(p + 0) = bytes[3];
    *(p + 1) = bytes[2];
    *(p + 2) = bytes[1];
    *(p + 3) = bytes[0];
    return result;
}

int main()
{
    unsigned int n = 2148205343;
    std::string ipAddress = intToIPAddress(n);
    std::cout << ipAddress << std::endl;
    std::cout << ipAddressToInt(ipAddress) << std::endl;

    return 0;
}