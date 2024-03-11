#include "../Includes.hpp"

void (*Update)(void *);

uintptr_t _moneyLp;
uintptr_t _moneyCrsytal;
uintptr_t _moneyTicket;

void new_Update(GameManager *ins) {
    Update(ins);

    SetObscuredFloatValue((uintptr_t) ins + _moneyLp, FLT_MAX);
    SetObscuredFloatValue((uintptr_t) ins + _moneyCrsytal, FLT_MAX);
    SetObscuredFloatValue((uintptr_t) ins + _moneyTicket, FLT_MAX);
}

void GameManager::Initialize() {
    setPointer(Update, "Update", 0);
    setFieldOffset(_moneyLp, "_moneyLp");
    setFieldOffset(_moneyCrsytal, "_moneyCrsytal");
    setFieldOffset(_moneyTicket, "_moneyTicket");
}

void GameManager::Hook() {
    setHook(Update, "Update");
}

const char *GameManager::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *GameManager::getNamespace() {
    return "";
}

const char *GameManager::getClass() {
    return "GameManager";
}