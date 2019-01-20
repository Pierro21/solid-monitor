//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <ctime>
#include <chrono>
#include <Data.hpp>
#include <zconf.h>
#include "Module.hpp"

Module::Module()
{
    _types.emplace_back("user", true, false, false);
    _types.emplace_back("host", true, false, false);
    _types.emplace_back("user+host", true, false, false);
    _datas.emplace_back("user");
    _datas.emplace_back("host");
    _datas.emplace_back("user+host");
}

std::vector<Data> Module::getModuleData()
{
    std::string complete;
    char host[HOST_NAME_MAX];
    char login[LOGIN_NAME_MAX];
    gethostname(host, HOST_NAME_MAX);
    getlogin_r(login, LOGIN_NAME_MAX);
    complete = login;
    complete += "@";
    complete += host;
    _datas[0].setGeneralInfo(login);
    _datas[1].setGeneralInfo(host);
    _datas[2].setGeneralInfo(complete);
    return _datas;
}

std::vector<DataTypes> Module::getModuleTypes()
{
    return _types;
}

