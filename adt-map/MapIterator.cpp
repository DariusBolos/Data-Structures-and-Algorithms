#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	this->index = 0;
}


void MapIterator::first() {
	 this->index = 0;
}


void MapIterator::next() {
    if (this->valid()) {
        this->index++;
        return ;
    }

    throw exception();
}


TElem MapIterator::getCurrent(){
    if (this->valid()) {
        return this->map.elements[this->index];
    }

    throw exception();
}


bool MapIterator::valid() const {
	return this->index < this->map.length;
}



