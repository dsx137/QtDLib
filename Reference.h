#pragma once

enum RETURNCODE {
    SUCCESS = 0,
    FAILURE = -1
};

template<typename T1, typename T2>
class DoubleMap {
public:
    std::map<T1, T2>* abMap;
    std::map<T2, T1>* baMap;
    DoubleMap() {
        abMap = new std::map<T1, T2>;
        baMap = new std::map<T2, T1>;
    }
    ~DoubleMap() {
        delete abMap;
        delete baMap;
    }
    void insert(T1 a, T2 b) {
        abMap->insert(std::pair<T1, T2>(a, b));
        baMap->insert(std::pair<T2, T1>(b, a));
    }
    typename std::map<T1, T2>::iterator findByA(T1 a) {
        typename std::map<T1, T2>::iterator it = abMap->find(a);
        return it;
    }
    typename std::map<T1, T2>::iterator findByB(T2 b) {
        typename std::map<T2, T1>::iterator it = baMap->find(b);
        return abMap->find(it->second);
    }
    void erase(typename std::map<T1, T2>::iterator it) {
        baMap->erase(it->second);
        abMap->erase(it);
    }
    void erase(typename std::map<T2, T1>::iterator it) {
        abMap->erase(it->second);
        baMap->erase(it);
    }
    void eraseByA(T1 a) {
        typename std::map<T1, T2>::iterator it = abMap->find(a);
        if (it != abMap->end()) erase(it);
    }
    void eraseByB(T2 b) {
        typename std::map<T2, T1>::iterator it = baMap->find(b);
        if (it != baMap->end()) erase(it);
    }
    void clear() {
        abMap->clear();
        baMap->clear();
    }
    //begin
    typename std::map<T1, T2>::iterator begin() {
        return abMap->begin();
    }
    //end
    typename std::map<T1, T2>::iterator end() {
        return abMap->end();
    }
};