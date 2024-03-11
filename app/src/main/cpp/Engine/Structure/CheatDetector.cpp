#include "../Includes.hpp"

void (*Start)(CheatDetector *);

uintptr_t mpCheatLimit;
uintptr_t lpCheatLimit;

void new_Start(CheatDetector *ins) {
    Start(ins);

    LOGI("Bypass limit");
    SetObscuredFloatValue((uintptr_t) ins + mpCheatLimit, -1);
    SetObscuredFloatValue((uintptr_t) ins + lpCheatLimit, -1);
}

void CheatDetector::Initialize() {
    setPointer(Start, "Start", 0);
    setFieldOffset(mpCheatLimit, "mpCheatLimit");
    setFieldOffset(lpCheatLimit, "lpCheatLimit");
}

void CheatDetector::Hook() {
    setHook(Start, "Start");
}

const char *CheatDetector::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *CheatDetector::getNamespace() {
    return "";
}

const char *CheatDetector::getClass() {
    return "CheatDetector";
}