//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_DATA_HPP
#define SOLID_MONITOR_DATA_HPP

#include <string>
#include <vector>
#include <memory>

class Data {
public:
    class graphData {
    public:
        graphData(float actual = 0, float min = 0, float max = 0);
        graphData(const graphData &other);
        graphData &operator=(const graphData &other);
        float getMin() const;
        void setMin(float min);
        float getMax() const;
        void setMax(float max);
        float getActual() const;
        void setActual(float actual);

    private:
        float min;
        float max;
        float actual;
    };
    Data() = default;
    Data(const Data &data);
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getGeneralInfo() const;

    void setGeneralInfo(const std::string &generalInfo);

    const std::shared_ptr<graphData> &getGlobalRange() const;

    void setGlobalRange(const std::shared_ptr<graphData> &globalRange);

    const std::vector<float> &getHistory() const;

    void setHistory(const std::vector<float> &history);

    const std::vector<Data> &getSubModule() const;

    void setSubModule(const std::vector<Data> &subModule);

private:
    std::string name;
    std::string generalInfo;
    std::shared_ptr<graphData> globalRange;
    std::vector<float> history;
    std::vector<Data> subModule;
};

#endif //SOLID_MONITOR_DATA_HPP
