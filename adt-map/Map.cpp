#include "Map.h"
#include "MapIterator.h"


Map::Map() {
    this->length = 0;
    this->capacity = 5;
    this->elements = new TElem[this->capacity];
}


Map::~Map() {
	delete[] this->elements;
}

/*
 * best case: θ()
 * average case: θ()
 * worst case: θ()
 */
TValue Map::add(TKey c, TValue v){
	for (int index = 0; index < this->length; ++index) {
        if (c == this->elements[index].first) {
            TValue oldValue = this->elements[index].second;
            this->elements[index].second = v;
            return oldValue;
        }
    }

    if (this->length == this->capacity) {
        this->resizeUp();
    }


    this->elements[this->length++] = TElem(c, v);


	return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
	for (int index = 0; index < this->length; ++index) {
        if (this->elements[index].first == c) {
            return this->elements[index].second;
        }
    }
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
    for (int index = 0; index < this->length; ++index) {
        if (this->elements[index].first == c) {
            TValue deletedElement = this->elements[index].second;
            for (int iterator = index; iterator < this->length - 1; ++iterator) {
                this->elements[iterator] = this->elements[iterator + 1];
            }

            this->length--;

            if (this->length < this->capacity / 4) {
                this->resizeDown();
            }

            return deletedElement;
        }
    }
	return NULL_TVALUE;
}


int Map::size() const {
	return this->length;
}

bool Map::isEmpty() const{
	return this->length == 0;
}

void Map::resizeUp() {
    this->capacity = 2 * this->capacity;
    TElem *newElements = new TElem[this->capacity];

    for (int index = 0; index < this->length; ++index) {
        newElements[index] = this->elements[index];
    }

    delete[] this->elements;
    this->elements = newElements;
}

void Map::resizeDown() {
    this->capacity /= 2;
    TElem *newElements = new TElem[this->capacity];

    for (int position = 0; position < this->length; ++position) {
        newElements[position] = this->elements[position];
    }

    delete[] this->elements;
    this->elements = newElements;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}
