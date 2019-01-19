//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "DataTypes.hpp"

const std::string &DataTypes::getName() const
{
    return _name;
}

bool DataTypes::isGeneric() const
{
    return _hasGeneric;
}

bool DataTypes::isGraph() const
{
    return _hasGraph;
}

bool DataTypes::isHistoGraph() const
{
    return _hasHistoGraph;
}

DataTypes::DataTypes(const std::string &name, bool generic, bool graph,
    bool histograph):
    _name(name), _hasGeneric(generic),
    _hasGraph(graph), _hasHistoGraph(histograph)
{
}

DataTypes::DataTypes(const DataTypes &other)
{
    if (&other != this) {
        _name = other._name;
        _hasGeneric = other._hasGeneric;
        _hasGraph = other._hasGraph;
        _hasHistoGraph = other._hasHistoGraph;
    }
}

DataTypes &DataTypes::operator=(const DataTypes &other)
{
    if (&other != this) {
        _name = other._name;
        _hasGeneric = other._hasGeneric;
        _hasGraph = other._hasGraph;
        _hasHistoGraph = other._hasHistoGraph;
    }
}
