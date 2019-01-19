/*
** EPITECH PROJECT, 2018
** babel
** File description:
** DLLoader.hpp
*/

#ifndef BABEL_DLLOADER_HPP
#define BABEL_DLLOADER_HPP

#include <dlfcn.h>
#include <string>
#include <stdexcept>
#include <memory>

template<typename T>
class DLLoader {
public:
    explicit DLLoader(const std::string &path) : _object(nullptr),
        _libHandler(nullptr), _libPath(path)
    {
        createInstance(path);
    }

    ~DLLoader()
    {
        deleteInstance();
    }

    void createInstance(const std::string &path)
    {
        T *(*entryPoint)();

        deleteInstance();
        _libHandler = dlopen(path.c_str(), RTLD_LAZY);
        if (!_libHandler) {
            perror(dlerror());
            throw std::invalid_argument("Can't open lib");
        }
        entryPoint = (T *(*)())dlsym(_libHandler, "entryPoint");
        if (!entryPoint)
            throw std::invalid_argument("No entryPoint");
        _object.reset(entryPoint());
        _libPath = path;
    }

    void deleteInstance()
    {
        if (_libHandler) {
            dlclose(_libHandler);
        }
        _libPath.clear();
    }

    T &getObject()
    {
        return *_object;
    }

    std::shared_ptr<T> getSharedObject()
    {
        return _object;
    }


    const std::string &getLibPath() const
    {
        return _libPath;
    }

private:
    std::shared_ptr<T> _object;
    void *_libHandler;
    std::string _libPath;
};

#endif //BABEL_DLLOADER_HPP
