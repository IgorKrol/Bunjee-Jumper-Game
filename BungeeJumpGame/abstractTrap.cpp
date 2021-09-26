#include "AbstractTrap.h"
#include "PendulumTrap.h"
#include "SpinningSawTrap.h"

AbstractTrap* AbstractTrap::Create(string trapType, Vector2f possition, int RotationDegree)
{
    if (trapType =="VT_SpinningSawTrap")
        return new SpinningSawTrap(possition, RotationDegree);
    else if (trapType == "VT_PendulumTrap")
        return new PendulumTrap(possition, RotationDegree);
    else return NULL;
}