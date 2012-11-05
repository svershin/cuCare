#include "PhysicianFilter.h"

PhysicianFilter::PhysicianFilter()
    : idMatch(false)
{
}

bool PhysicianFilter::idGetMatch() { return idMatch; }
void PhysicianFilter::idSetMatch(bool match) { idMatch = match; }
