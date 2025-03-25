#include "BestioleDecorator.h"

BestioleDecorator::BestioleDecorator(Bestiole* b) : bestiole(b) { }

BestioleDecorator::~BestioleDecorator() {
    delete bestiole;
}
