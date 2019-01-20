//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "Data.hpp"

const std::string &Data::getName() const
{
    return _name;
}

void Data::setName(const std::string &name)
{
    Data::_name = name;
}

const std::string &Data::getGeneralInfo() const
{
    return _generalInfo;
}

void Data::setGeneralInfo(const std::string &generalInfo)
{
    Data::_generalInfo = generalInfo;
}

const std::shared_ptr<Data::graphData> &Data::getGlobalRange() const
{
    return _globalRange;
}

void Data::setGlobalRange(const std::shared_ptr<graphData> &globalRange)
{
    Data::_globalRange = globalRange;
}

const std::vector<float> &Data::getHistory() const
{
    return _history;
}

void Data::setHistory(const std::vector<float> &history)
{
    Data::_history = history;
}

const std::vector<Data> &Data::getSubModule() const
{
    return _subModule;
}

void Data::setSubModule(const std::vector<Data> &subModule)
{
    Data::_subModule = subModule;
}

Data::Data(const Data &data)
{
    _name = data._name;
    _generalInfo = data._generalInfo;
    _globalRange = data._globalRange;
    _subModule = data._subModule;

}

Data::Data(const std::string &name): _name(name)
{
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
