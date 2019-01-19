//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "Data.hpp"

const std::string &Data::getName() const
{
    return name;
}

void Data::setName(const std::string &name)
{
    Data::name = name;
}

const std::string &Data::getGeneralInfo() const
{
    return generalInfo;
}

void Data::setGeneralInfo(const std::string &generalInfo)
{
    Data::generalInfo = generalInfo;
}

const std::shared_ptr<Data::graphData> &Data::getGlobalRange() const
{
    return globalRange;
}

void Data::setGlobalRange(const std::shared_ptr<graphData> &globalRange)
{
    Data::globalRange = globalRange;
}

const std::vector<float> &Data::getHistory() const
{
    return history;
}

void Data::setHistory(const std::vector<float> &history)
{
    Data::history = history;
}

const std::vector<Data> &Data::getSubModule() const
{
    return subModule;
}

void Data::setSubModule(const std::vector<Data> &subModule)
{
    Data::subModule = subModule;
}

Data::Data(const Data &data)
{
    name = data.name;
    generalInfo = data.generalInfo;
    globalRange = data.globalRange;
    subModule = data.subModule;

}

float Data::graphData::getMin() const
{
    return min;
}

void Data::graphData::setMin(float min)
{
    graphData::min = min;
}

float Data::graphData::getMax() const
{
    return max;
}

void Data::graphData::setMax(float max)
{
    graphData::max = max;
}

float Data::graphData::getActual() const
{
    return actual;
}

void Data::graphData::setActual(float actual)
{
    graphData::actual = actual;
}

Data::graphData::graphData(float actual, float min, float max):
actual(actual),
max(max),
min(min)
{
}

Data::graphData::graphData(const Data::graphData &other)
{
    min = other.min;
    max = other.max;
    actual = other.actual;
}

Data::graphData &Data::graphData::operator=(const Data::graphData &other) = default;
