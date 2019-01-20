//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_DATATYPES_HPP
#define SOLID_MONITOR_DATATYPES_HPP

#include <string>

class DataTypes {
public:
    explicit DataTypes(const std::string &name,
        bool generic = false,
        bool graph = false,
        bool histograph = false);
    DataTypes(const DataTypes &other);
    DataTypes &operator=(const DataTypes &other);
    const std::string &getName() const;
    bool isGeneric() const;
    bool isGraph() const;
    bool isHistoGraph() const;

private:
    std::string _name;
    bool _hasGeneric;
    bool _hasGraph;
    bool _hasHistoGraph;
    size_t refreshTime;
};

#endif //SOLID_MONITOR_DATATYPES_HPP
