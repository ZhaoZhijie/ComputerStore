//
//  computers.hpp
//  c_computers
//
//  Created by Shuying Rao on 13/12/2020.
//

#ifndef computers_hpp
#define computers_hpp
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

class Component{
private:
    float _price;
public:
    Component(float price){
        _price = price;
    }
    
    float getPrice(){
        return _price;
    }
};



class Processor:public Component{
private:
    string _brand;
    string _model;
    float _price;
    string _type;
public:
    Processor(string brand,string model,string type, float price):Component(price){
        _brand = brand;
        _model = model;
        _type = type;
    }
    string getBrand(){
        return _brand;
    }
    
    string getModel(){
        return _model;
    }
    string  getType(){
        return _type;
    }
};

class Gpu:public Processor{

public:
    Gpu(string brand,string model, float price): Processor(brand,model,"GPU", price){}
};

class Cpu:public Processor{

public:
    Cpu(string brand,string model, float price): Processor(brand,model,"CPU", price){}
};

class Memory:public Component{
private:
    int _capacity;
  
public:
    Memory(int capacity, float price):Component(price){
        _capacity = capacity;
    }
    
    int getCapacity(){
        return _capacity;
    }
};

class Screen:public Component{
private:
    float _size;
public:
    Screen(float size, float price):Component(price){
        _size = size;
    }
    
    float getSize(){
        return _size;
    }
};


class Harddisk:public Component{
private:
    string _type;
    int _capacity; //amount in gb
public:
    Harddisk(string type,int capacity, float price):Component(price){
        _type = type;
        _capacity = capacity;
    }
    string getType(){
        return _type;
    }
    
    int getCapacity(){
        return _capacity;
    }
    
};

class Computer{
private:
    int _id;
    Cpu _cpu;
    int _cpuNum;
    Gpu _gpu;
    int _gpuNum;
    Memory _memory;
    Harddisk _hd;
    string _os;
    string _type;
public:
    Computer(int id,Cpu cpu, int cpuNum, Gpu gpu, int gpuNum, Memory memory,Harddisk hd,string os,string type):_cpu(cpu),_gpu(gpu),_hd(hd),_memory(memory){
         _id=id;
        _cpuNum = cpuNum;
        _gpuNum = gpuNum;
        _os=os;
        _type = type;
    }
    
    void checkCoresNum(int maxCpuNum, int maxGpuNum){
        if(_cpuNum > maxCpuNum){
            throw "cpu num exceed limited size";
        }
        if(_gpuNum > maxGpuNum){
            throw "gpu num exceed limited size";
        }
    }
    
    int getId(){
        return _id;
    }
    
    Cpu getCpu(){
        return _cpu;
    }
    Gpu getGpu(){
        return _gpu;
    }
    Memory getMemory(){
        return _memory;
    }
    Harddisk getHd(){
        return _hd;
    }
    string getOs(){
        return _os;
    }
    
    string getType(){
        return _type;
    }
    
    virtual stringstream getSaveStream(){
        stringstream ss;
        ss<<_type;
        ss<<" "<<_id;
        ss<<" "<<_cpu.getBrand();
        ss<<" "<<_cpu.getModel();
        ss<<" "<<_cpu.getPrice();
        ss<<" "<<_cpuNum;
        ss<<" "<<_gpu.getBrand();
        ss<<" "<<_gpu.getModel();
        ss<<" "<<_gpu.getPrice();
        ss<<" "<<_gpuNum;
        ss<<" "<<_memory.getCapacity();
        ss<<" "<<_memory.getPrice();
        ss<<" "<<_hd.getType();
        ss<<" "<<_hd.getCapacity();
        ss<<" "<<_hd.getPrice();
        ss<<" "<<_os;
        ss<<" "<<getPrice();
        cout<<"Computer getSaveStream"<<endl;
        return ss;
    }
    
    virtual void display(){
        cout<<"id:"<<_id<<endl;
        cout<<"type:"<<_type<<endl;
        cout<<"cpuBrand:"<<_cpu.getBrand()<<endl;
        cout<<"cpuModel:"<<_cpu.getModel()<<endl;
        cout<<"GCBrand:"<<_gpu.getBrand()<<endl;
        cout<<"GCModel:"<<_gpu.getModel()<<endl;
        cout<<"memory:"<<_memory.getCapacity()<<endl;
        cout<<"hardDiskType:"<<_hd.getType()<<endl;
        cout<<"hardDiskCapacity:"<<_hd.getCapacity()<<endl;
        cout<<"os:"<<_os<<endl;
        cout<<"price:"<<getPrice()<<endl;
    }
    
    virtual float getPrice(){
        return _cpu.getPrice()*_cpuNum + _gpu.getPrice()*_gpuNum + _hd.getPrice() + _memory.getPrice();
    }
};

class Laptop:public Computer{
private:
    string _mf;//manufacturer as mf.
    Screen _sc;
    const static int _maxCpuNum = 1;//Max number of  cpu
    const static int _maxGpuNum = 1;//Max number of GC
public:
    //    int id,Cpu cpu,Gpu gpu,Memory memory,Harddisk hd,string os,string type
    Laptop(int id,Cpu cpu, int cpuNum, Gpu gpu, int gpuNum, Memory memory,Harddisk hd,string os,string mf, Screen sc): Computer (id,cpu, cpuNum, gpu, gpuNum, memory,hd,os, "Laptop"), _sc(sc){
        checkCoresNum(Laptop::_maxCpuNum, Laptop::_maxGpuNum);
        _mf = mf;
    }
    string getMf(){
        return _mf;
    }
    Screen getSs(){
        return _sc;
    }
    
    stringstream getSaveStream(){
        stringstream ss = Computer::getSaveStream();
        ss<<" "<<_mf;
        ss<<" "<<_sc.getSize();
        cout<<"Laptop getSaveStream"<<endl;
        return ss;
    }
    
    void display(){
        Computer::display();
        cout<<"manufacturer:"<<_mf<<endl;
        cout<<"screebSize:"<<_sc.getSize()<<endl;
    }
    
    float getPrice(){
        return Computer::getPrice() + _sc.getPrice();
    }

};

class Desktop:public Computer{
private:
    const static int _maxCpuNum = 2;//Max number of  cpu
    const static int _maxGpuNum = 2;//Max number of GC
public:
    Desktop(int id,Cpu cpu, int cpuNum, Gpu gpu, int gpuNum, Memory memory,Harddisk hd,string os):Computer (id,cpu, cpuNum, gpu, gpuNum, memory,hd,os,"Desktop"){
        checkCoresNum(Desktop::_maxCpuNum, Desktop::_maxGpuNum);
    }
};


class Server:public Computer{
private:
    string _mf;//manufacturer as mf.
    const static int _maxCpuNum = 4;//Max number of  cpu
    const static int _maxGpuNum = 4;//Max number of GC
public:
    Server(int id,Cpu cpu, int cpuNum, Gpu gpu, int gpuNum, Memory memory,Harddisk hd,string os,string mf): Computer (id,cpu, cpuNum, gpu, gpuNum, memory,hd,os,"Server"){
        _mf = mf;
        checkCoresNum(Server::_maxCpuNum, Server::_maxGpuNum);
    }
    
    stringstream getSaveStream(){
        stringstream ss = Computer::getSaveStream();
        ss<<" "<<_mf;
        cout<<"Server getSaveStream"<<endl;
        return ss;
    }
    
    void display(){
        Computer::display();
        cout<<"manufacturer:"<<_mf<<endl;
    }

};

class ComputerStore{
private:
    vector<Computer*> _computers;
public:
    ComputerStore(){
    }
    
    void addComputer(Computer* cp){
        _computers.push_back(cp);
    }
    
    bool removeComputer(int id){
        for(vector<Computer*>::iterator iter = _computers.begin(); iter != _computers.end();iter++){
            if((*iter)->getId() == id){
                _computers.erase(iter);
                return true;
            }
        }
        return false;
    }
    
    void displayComputers(){
        unsigned long size = _computers.size();
        cout<<"--------All computers--------";
        for(unsigned int i=0;i<size;i++){
            _computers[i]->display();
            cout<<endl;
        }
    }
    
    Computer* searchById(int id){
        unsigned long size = _computers.size();
        for(unsigned int i=0;i<size;i++){
            if(_computers[i]->getId()==id)
                return _computers[i];
            }
        return NULL;
    }
    
    vector<Computer*>* searchByType(string type){
        vector<Computer*>* cps = new vector<Computer*>;
        unsigned long size = _computers.size();
        for(unsigned int i=0;i<size;i++){
            if(_computers[i]->getType()==type)
                cps->push_back(_computers[i]);
            }
        return cps;
    }
    
    vector<Computer*>* searchByPrice(float low, float high){
        vector<Computer*>* cps = new vector<Computer*>;
        unsigned long size = _computers.size();
        for(unsigned int i=0;i<size;i++){
            float price = _computers[i]->getPrice();
            if(price >= low && price <= high){
                cps->push_back(_computers[i]);
            }
        }
        return cps;
    }
    
    set<string>* searchSubtypes(string cpuBrand, string gpuBrand, float screenSize = 0){
        set<string>* subtypes = new set<string>;
        unsigned long size = _computers.size();
        for(unsigned int i=0;i<size;i++){
            Computer* cp = _computers[i];
            if(cp->getCpu().getBrand() == cpuBrand && cp->getGpu().getBrand()==gpuBrand &&
               ((cp->getType() == "Laptop" && ((Laptop*)cp)->getSs().getSize() == screenSize) || cp->getType() != "Laptop")){
                subtypes->insert(cp->getType());
            }
        }
        return subtypes;
    }

    void save(string path){
        unsigned long size = _computers.size();
        //id,cpuBrand,cpuModel,gpuBrand,gpuModel
        ofstream fout;
        fout.open(path);
        for(unsigned int i = 0; i < size; i++){
            stringstream ss = _computers[i]->getSaveStream();
            ss<<"\n";
            fout<<ss.rdbuf();
        }
        fout.close();
    }
    
    void load(string path){
        ifstream in;
        in.open(path);
        if(!in.is_open()){
            cout<<"store file is not existed!"<<endl;
            return;
        }

        string line;
        while(getline(in, line)){
            stringstream ss(line);
            string type;
            int id;
            string cpuBrand;
            string cpuModel;
            float cpuPrice;
            int cpuNum;
            string gpuBrand;
            string gpuModel;
            float gpuPrice;
            int gpuNum;
            int memoryCapacity;
            float memoryPrice;
            string hardType;
            int hardCapacity;
            float hardPrice;
            string os;
            ss>>type>>id>>cpuBrand>>cpuModel>>cpuPrice>>cpuNum>>gpuBrand>>gpuModel>>gpuPrice>>gpuNum>>memoryCapacity>>memoryPrice>>hardType>>hardCapacity>>hardPrice>>os;
            Cpu cpu(cpuBrand, cpuModel, cpuPrice);
            Gpu gpu(gpuBrand, gpuModel, gpuPrice);
            Harddisk hd(hardType, hardCapacity, hardPrice);
            Memory memory(memoryCapacity, memoryPrice);
            Computer* cp = NULL;
            if(type == "Laptop"){
                string mf;
                float screenSize;
                float screenPrice;
                ss>>mf>>screenSize>>screenPrice;
                Screen sc(screenSize, screenPrice);
                cp = new Laptop(id, cpu, cpuNum, gpu, gpuNum, memory, hd, os, mf, sc);
            } else if (type == "Desktop"){
                cp = new Desktop(id, cpu, cpuNum, gpu, gpuNum, memory, hd, os);
            } else if(type == "Server"){
                string mf;
                ss>>mf;
                cp = new Server(id, cpu, cpuNum, gpu, gpuNum, memory, hd, os, mf);
            }
            addComputer(cp);
        }
    }
};
#endif /* computers_hpp */
