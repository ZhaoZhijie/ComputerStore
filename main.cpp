//
//  main.cpp
//  c_computers
//
//  Created by Shuying Rao on 13/12/2020.
//

#include <iostream>
#include  "computers.hpp"
#include <stdlib.h>
#include <fstream>
using namespace std;

Cpu createCpu(){
    string brands[5] = {"intelA", "intelB", "intelC", "intelD", "intelE"};
    string models[3] = {"mod1", "mod2", "mod3"};
    string cpuBrand = brands[rand()%5];
    string cpuModel = models[rand()%3];
    float cpuPrice = rand()%2000 + 2000;
    Cpu cpu(cpuBrand, cpuModel, cpuPrice);
    return cpu;
}

Gpu createGpu(){
    string brands[5] = {"intelA", "intelB", "intelC", "intelD", "intelE"};
    string models[3] = {"mod1", "mod2", "mod3"};
    string gpuBrand = brands[rand()%5];
    string gpuModel = models[rand()%3];
    float gpuPrice = rand()%2000 + 2000;
    Gpu gpu(gpuBrand, gpuModel, gpuPrice);
    return gpu;
}

Harddisk createHarddisk(){
    string hdtyes[3] = {"ssd", "hdd", "sshd"};
    int priceBase[3] = {40, 80, 120};
    int priceSteps[3] = {5, 10, 15};
    int sizes[5] = {60, 120, 240, 360, 500};
    int typeIndex = rand()%3;
    int sizeIndex = rand()%5;
    float price = priceBase[typeIndex] + priceSteps[typeIndex]*sizeIndex;
    Harddisk hd(hdtyes[typeIndex], sizes[sizeIndex], price);
    return hd;
}

Memory createMemory(){
    int sizes[5] = {1, 2, 4, 8, 16};
    float prices[5] = {40, 55, 70, 85, 100};
    int index = rand()%5;
    Memory memory(sizes[index], prices[index]);
    return memory;
}

Screen createScreen(){
    float screens[6][2] = {{11.1, 60}, {12, 70}, {13.3, 80}, {14, 90}, {15.6, 100}, {17.3, 110}};
    int index = rand()%6;
    Screen sc(screens[index][0], screens[index][1]);
    return sc;
}


Computer* createComputer(){
    string types[3] = {"Laptop", "Desktop", "Server"};
    string oses[3] = {"Win", "Linux", "Mac"};
    string mfs[3] = {"mf1", "mf2", "mf3"};
    string os = oses[rand()%3];
    int id = rand();
    string type = types[rand()%3];
    Computer* cp;
    Cpu cpu = createCpu();
    Gpu gpu = createGpu();
    Harddisk hd = createHarddisk();
    Memory memory = createMemory();
    int cpuNum = 1;
    int gpuNum = 1;
    if(type == "Laptop"){
        string mf = mfs[rand()%3];
        Screen sc = createScreen();
        cp = new Laptop(id,cpu,cpuNum,gpu,gpuNum,memory,hd,os,mf,sc);
    }else if(type == "Desktop"){
        cpuNum = rand()%3;
        gpuNum = rand()%3;
        cp = new Desktop(id,cpu,cpuNum,gpu,gpuNum,memory,hd,os);
    }else{
        cpuNum = rand()%5;
        gpuNum = rand()%5;
        string mf = mfs[rand()%3];
        cp = new Server(id,cpu,cpuNum,gpu,gpuNum,memory,hd,os,mf);
    }
    return cp;
}

void createVirtualComputers(string path, int num){
    ComputerStore cps ;
    for(int i = 0; i < num; i++){
        Computer* cp = createComputer();
        cps.addComputer(cp);
    }
    cps.displayComputers();
    cps.save(path);
}

int main(int argc, const char * argv[]) {
    string path = "/Users/shuying/Desktop/c++project_learing/c_computers/c_computers/output.txt";
//    createVirtualComputers(path, 100);
    ComputerStore cps ;
    cps.load(path);
    
    cps.displayComputers();
    cps.save(path);
    return 0;
}
