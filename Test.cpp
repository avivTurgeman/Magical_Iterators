#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

TEST_SUITE("MagicalContainer"){
    MagicalContainer container1;
    MagicalContainer container2;

    TEST_CASE("addElement()"){
        //size = 0 when initialize
        CHECK_EQ(container1.size(), 0);
        
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(3);
        container1.addElement(4);
        container1.addElement(5);
        int num = 6;
        container1.addElement(num);

        //adding the same element wont throw
        CHECK_NOTHROW(container1.addElement(num));
        CHECK_EQ(container1.size(), 7);
    }

    TEST_CASE("removeElement()"){
        //container2 is empty
        CHECK_THROWS_AS(container2.removeElement(1), runtime_error);
        
        CHECK_NOTHROW(container1.removeElement(5));
        
        //6 added twice so wont throw
        CHECK_NOTHROW(container1.removeElement(6));
        CHECK_NOTHROW(container1.removeElement(6));
        CHECK_EQ(container1.size(), 4);
        
        //removing non-existing element
        CHECK_THROWS_AS(container1.removeElement(12), invalid_argument);
    }
}

TEST_SUITE("AscendingIterator"){
    MagicalContainer container;
    MagicalContainer::AscendingIterator ascIter(container);

    TEST_CASE("sorted after adding"){
        container.addElement(3);
        container.addElement(1);
        container.addElement(4);
        container.addElement(2);
        container.addElement(0);

        int i = 0;
        for(auto itr = ascIter.begin(); itr != ascIter.end(); ++ascIter, ++i){
            CHECK_EQ(*ascIter, i);
        }

        CHECK_EQ(container.size(), 5);
        CHECK_EQ(ascIter.begin(), 0);
        CHECK_EQ(ascIter.end(), 4);

        container.removeElement(0);
        container.removeElement(4);
       
        CHECK_EQ(container.size(), 3);
        CHECK_EQ(ascIter.begin(), 1);
        CHECK_EQ(ascIter.end(), 3);
    }
}

TEST_SUITE("SideCrossIterator"){
    MagicalContainer container;
    MagicalContainer::AscendingIterator ascIter(container);

    TEST_CASE("side crossed"){
        container.addElement(0);
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);

        CHECK_EQ(*ascIter, 0);
        ++ascIter;
        CHECK_EQ(*ascIter, 4);
        ++ascIter;
        CHECK_EQ(*ascIter, 1);
        ++ascIter;
        CHECK_EQ(*ascIter, 2);
        ++ascIter;
        CHECK_EQ(*ascIter, 3);


        CHECK_EQ(container.size(), 5);
        CHECK_EQ(ascIter.begin(), 0);
        CHECK_EQ(ascIter.end(), 3);

        container.removeElement(0);
        container.removeElement(3);
       
        CHECK_EQ(container.size(), 3);
        CHECK_EQ(ascIter.begin(), 4);
        CHECK_EQ(ascIter.end(), 2);
    }
}

TEST_SUITE("SideCrossIterator"){
    MagicalContainer container;
    MagicalContainer::AscendingIterator ascIter(container);

    TEST_CASE("side crossed"){
        container.addElement(0);
        container.addElement(2);
        container.addElement(1);
        container.addElement(7);
        container.addElement(3);
        container.addElement(5);

        CHECK_EQ(*ascIter, 2);
        ++ascIter;
        CHECK_EQ(*ascIter, 7);
        ++ascIter;
        CHECK_EQ(*ascIter, 3);
        ++ascIter;
        CHECK_EQ(*ascIter, 5);

        CHECK_EQ(container.size(), 4);
        CHECK_EQ(ascIter.begin(), 2);
        CHECK_EQ(ascIter.end(), 5);

        container.removeElement(2);
        container.removeElement(5);
       
        CHECK_EQ(container.size(), 2);
        CHECK_EQ(ascIter.begin(), 7);
        CHECK_EQ(ascIter.end(), 3);
    }
}