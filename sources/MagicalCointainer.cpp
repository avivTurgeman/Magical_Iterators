#include "MagicalContainer.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer():container_(){}

void MagicalContainer::addElement(int element){
    container_.push_back(element);
}

void MagicalContainer::removeElement(int element){
    for (auto it = container_.begin(); it != container_.end(); ++it) {
        if (*it == element) {
            container_.erase(it);
            break;
        }
    }
}

size_t MagicalContainer::size() const{
    return container_.size();
}

//---------AscendingIterator-------------
MagicalContainer::AscendingIterator
::AscendingIterator(MagicalContainer& container, size_t index)
:container_(container), index_(index){}

MagicalContainer::AscendingIterator
::AscendingIterator(const AscendingIterator& other)
:container_(other.container_){}

MagicalContainer::AscendingIterator& MagicalContainer
::AscendingIterator::operator=(const AscendingIterator& other){return *this;}

int& MagicalContainer::AscendingIterator::operator*() const{
    return container_.container_.at(index_);
}

MagicalContainer::AscendingIterator& MagicalContainer
::AscendingIterator::operator++(){
    index_++;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{return index_ == other.index_;}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{return !(*this == other);}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{return index_ > other.index_;}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{return index_ < other.index_;}

MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: begin () const {
    return AscendingIterator(container_, 0);
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end () const {
    return AscendingIterator(container_, container_.size());
}

//---------SideCrossIterator-------------
MagicalContainer::SideCrossIterator
::SideCrossIterator(MagicalContainer& container, size_t index)
:container_(container), index_(index){}

MagicalContainer::SideCrossIterator
::SideCrossIterator(const SideCrossIterator& other)
:container_(other.container_){}

MagicalContainer::SideCrossIterator& MagicalContainer
::SideCrossIterator::operator=(const SideCrossIterator& other){return *this;}

int& MagicalContainer::SideCrossIterator::operator*() const{
    return container_.container_.at(index_);
}

MagicalContainer::SideCrossIterator& MagicalContainer
::SideCrossIterator::operator++(){
    index_++;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{return index_ == other.index_;}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{return !(*this == other);}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{return index_ > other.index_;}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{return index_ < other.index_;}

MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () const {
    return SideCrossIterator(container_, 0);
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end () const {
    return SideCrossIterator(container_, container_.size());
}

//---------PrimeIterator-------------
MagicalContainer::PrimeIterator
::PrimeIterator(MagicalContainer& container, size_t index)
:container_(container), index_(index){}

MagicalContainer::PrimeIterator
::PrimeIterator(const PrimeIterator& other)
:container_(other.container_){}

MagicalContainer::PrimeIterator& MagicalContainer
::PrimeIterator::operator=(const PrimeIterator& other){return *this;}

int& MagicalContainer::PrimeIterator::operator*() const{
    return container_.container_.at(index_);
}

MagicalContainer::PrimeIterator& MagicalContainer
::PrimeIterator::operator++(){
    index_++;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{return index_ == other.index_;}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{return !(*this == other);}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{return index_ > other.index_;}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{return index_ < other.index_;}

MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: begin () const {
    return PrimeIterator(container_, 0);
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end () const {
    return PrimeIterator(container_, container_.size());
}