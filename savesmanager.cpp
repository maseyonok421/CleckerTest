#include "savesmanager.h"

extern long long VERSION;
extern long long cps, clickDmg, balance;
extern long long curClickUpgrades[];
extern long long   curCpsUpgrades[];

SavesManager::SavesManager() {}

void SavesManager::save(){

    std::ofstream fout("save.txt");
    fout << VERSION << ' ' << cps << ' ' << clickDmg << ' ' << balance << ' ';
    for ( int i = 0; i < 3; i ++ ) fout << curClickUpgrades[i] << ' ';
    for ( int i = 0; i < 3; i ++ ) fout <<   curCpsUpgrades[i] << ' ';
    fout.close();

};

void SavesManager::load(){

    std::ifstream fin("save.txt");
    if (fin.is_open()){
        fin >> VERSION;
        if (VERSION == 0){
            fin >> cps >> clickDmg >> balance;
            for ( int i = 0; i < 3; i ++ ) fin >> curClickUpgrades[i];
            for ( int i = 0; i < 3; i ++ ) fin >>   curCpsUpgrades[i];
        }
        fin.close();
    }

};
