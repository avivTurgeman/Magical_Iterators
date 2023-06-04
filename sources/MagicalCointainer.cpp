#include "MagicalContainer.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

void MagicalContainer::addElement(int element){}

void MagicalContainer::removeElement(int element){}

size_t MagicalContainer::size() const{
    return container_.size();
}

//---------AscendingIterator-------------
MagicalContainer::AscendingIterator
::AscendingIterator(MagicalContainer& container)
:container_(container){}

MagicalContainer::AscendingIterator
::AscendingIterator(const AscendingIterator& other)
:container_(other.container_){}

MagicalContainer::AscendingIterator& MagicalContainer
::AscendingIterator::operator=(const AscendingIterator& other){}

int& MagicalContainer::AscendingIterator::operator*() const{
    return container_.container_.at(index_);
}

MagicalContainer::AscendingIterator& MagicalContainer
::AscendingIterator::operator++(){
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{return true;}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{return true;}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{return true;}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{return true;}

MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: begin () const {
    return AscendingIterator(container_);
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end () const {
    return AscendingIterator(container_);
}

//---------SideCrossIterator-------------
MagicalContainer::SideCrossIterator
::SideCrossIterator(MagicalContainer& container)
:container_(container){}

MagicalContainer::SideCrossIterator
::SideCrossIterator(const SideCrossIterator& other)
:container_(other.container_){}

MagicalContainer::SideCrossIterator& MagicalContainer
::SideCrossIterator::operator=(const SideCrossIterator& other){}

int& MagicalContainer::SideCrossIterator::operator*() const{
    return container_.container_.at(index_);
}

MagicalContainer::SideCrossIterator& MagicalContainer
::SideCrossIterator::operator++(){
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{return true;}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{return true;}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{return true;}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{return true;}

MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () const {
    return SideCrossIterator(container_);
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end () const {
    return SideCrossIterator(container_);
}

//---------PrimeIterator-------------
MagicalContainer::PrimeIterator
::PrimeIterator(MagicalContainer& container)
:container_(container){}

MagicalContainer::PrimeIterator
::PrimeIterator(const PrimeIterator& other)
:container_(other.container_){}

MagicalContainer::PrimeIterator& MagicalContainer
::PrimeIterator::operator=(const PrimeIterator& other){}

int& MagicalContainer::PrimeIterator::operator*() const{
    return container_.container_.at(index_);
}

MagicalContainer::PrimeIterator& MagicalContainer
::PrimeIterator::operator++(){
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{return true;}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{return true;}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{return true;}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{return true;}

MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: begin () const {
    return PrimeIterator(container_);
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end () const {
    return PrimeIterator(container_);
}