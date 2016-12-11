#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

struct ObjInstance {
    std::string name_;
    std::string value_;
};
typedef std::vector<ObjInstance> ObjInfoContainer;
typedef std::map<std::string, ObjInfoContainer> NeObjContainer;

inline std::ostream& operator<<(std::ostream& lth, ObjInfoContainer& objInfo)
{
    ObjInfoContainer::iterator iter = objInfo.begin();
    for (; iter != objInfo.end(); ++iter) {
        lth << iter->name_ << " : " << iter->value_ << ",";
    }

    return lth;
}

inline std::ostream& operator<<(std::ostream& lth, NeObjContainer& neObjs)
{
    NeObjContainer::iterator iter = neObjs.begin();
    for (; iter != neObjs.end(); ++iter) {
        lth << iter->first << ", " << iter->second << "\n";
    }

    return lth;
}

void overloadoperator()
{
    ObjInfoContainer objIns;
    ObjInstance obj;

    obj.name_ = "c";
    obj.value_ = "N=1";
    objIns.push_back(obj);

    obj.name_ = "c++";
    obj.value_ = "N=2";
    objIns.push_back(obj);

    NeObjContainer neObjs;
    neObjs.insert(std::make_pair("Hello", objIns));
    neObjs.insert(std::make_pair("World", objIns));

    std::cout << neObjs;
}

struct BaseNum {
    int num_;
    
    void toAdd(int addnum)
    {
        num_ += addnum;
    }

    void toOut()
    {
        std::cout << num_ << ",";
    }

    int num()
    {
        return num_;
    }
};

typedef std::vector<BaseNum> BaseNumContainer;


void memfunref_int()
{
    BaseNumContainer nums;
    BaseNum onenum;
    onenum.num_ = 0;
    nums.push_back(onenum);

    onenum.num_ = 1;
    nums.push_back(onenum);

    onenum.num_ = 2;
    nums.push_back(onenum);

    onenum.num_ = 3;
    nums.push_back(onenum);

    std::for_each(nums.begin(), nums.end(), std::mem_fun_ref(&BaseNum::toOut));
    std::cout << "\n";
    std::for_each(nums.begin(), nums.end(), std::bind2nd(std::mem_fun_ref(&BaseNum::toAdd), 2));
    std::for_each(nums.begin(), nums.end(), std::mem_fun_ref(&BaseNum::toOut));
    std::cout << "\n";

    std::vector<int> numVec;
    std::transform(nums.begin(), nums.end(), std::back_inserter(numVec), std::mem_fun_ref(&BaseNum::num));
    std::copy(numVec.begin(), numVec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

struct BaseString {
    std::string str_;

    void toAppend(std::string suffix)
    {
        str_.append(suffix);
    }

    void toOut()
    {
        std::cout << str_ << ",";
    }
};

typedef std::vector<BaseString> StringContainer;

void memfunref_string()
{
    StringContainer strs;
    BaseString onestr;
    onestr.str_ = "c";
    strs.push_back(onestr);

    onestr.str_ = "c++";
    strs.push_back(onestr);

    onestr.str_ = "python";
    strs.push_back(onestr);

    std::for_each(strs.begin(), strs.end(), std::mem_fun_ref(&BaseString::toOut));
    std::cout << "\n";

    std::for_each(strs.begin(), strs.end(), std::bind2nd(std::mem_fun_ref(&BaseString::toAppend), " please"));
    std::for_each(strs.begin(), strs.end(), std::mem_fun_ref(&BaseString::toOut));
    std::cout << "\n";
}

int main(int argc, char* argv[])
{
    overloadoperator();

    memfunref_int();

    memfunref_string();

    return 0;
}


