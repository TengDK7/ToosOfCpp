#include <iostream>
#include"JsonClass/Person.h"
#include<string>
#include<Windows.h>
#include<fstream>

const std::string JSON_FILE_NAME = "person.json";

std::string GetAppPath()
{
    char buffer[MAX_PATH] = { 0 };
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string appPath = buffer;
    appPath = appPath.substr(0, appPath.rfind("\\"));
    return appPath;
}

std::string ReadTextFile(std::string filepath)
{
    std::ifstream infile(filepath, std::ifstream::in);
    std::string data = "";
    if (infile.is_open())
    {
        std::string s;
        while (getline(infile, s))
        {
            data += s;
        }
        infile.close();
    }
    return data;
}

int main()
{
    std::string name = "xiaoming";
    std::string id = "25876688";
    std::string address = "ShangHai";
    std::string phoneNum = "18715688888";
    int age = 18;    
    JsonClass::Person xiaoming(name, id, address, phoneNum, age);
    std::string content = xiaoming.Serialize();
    std::cout << "Serialize persion  xiaoming:" << std::endl;
    std::cout << content << std::endl;

    auto appPath = GetAppPath();
    auto jsonFilePath = appPath + "\\" + JSON_FILE_NAME;
    auto jsonContent = ReadTextFile(jsonFilePath);
    if (jsonContent.empty())
    {
        std::cout << "json file is empty!" << std::endl;
    }
    else
    {
        JsonClass::Person xiaohong;
        if (xiaohong.Deserialize(jsonContent))
        {
            std::cout << "deserialize xiaohong success" << std::endl;
            std::cout << xiaohong.Serialize() << std::endl;
        }
        else
        {
            std::cout << "failed to deserialize xiaohong" << std::endl;
        }
    }

    char input;
    std::cin.read(&input, 1);
}


