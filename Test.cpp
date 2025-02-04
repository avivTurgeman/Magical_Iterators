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
        container.addElement(-1);
        container.addElement(4);
        container.addElement(2);
        container.addElement(-3);
        container.addElement(0);
        container.addElement(10);
        container.addElement(-10);

        std::vector<int> expected{-10, -3, -1, 0, 2, 3, 4, 10};

        int i = 0;
        for(auto itr = ascIter.begin(); itr != ascIter.end(); ++itr, ++i){
            if(i == 3){
                container.addElement(-9);
            }
            CHECK_EQ(*itr, expected[i]);
        }

        CHECK_EQ(container.size(), 5);

        container.removeElement(0);
        container.removeElement(4);
        container.removeElement(4);
       
        CHECK_EQ(container.size(), 6);
    }

    MagicalContainer::AscendingIterator ascIter1(container);
    MagicalContainer::AscendingIterator ascIter2(container);
    TEST_CASE("operators ==, !=, <, >"){
        CHECK(ascIter1 == ascIter2);
        CHECK_FALSE(ascIter1 != ascIter2);

        ++ascIter1;
        CHECK_FALSE(ascIter1 == ascIter2);
        CHECK(ascIter1 != ascIter2);

        CHECK(ascIter1 > ascIter2);
        CHECK(ascIter2 < ascIter1);

        ++ascIter2;
        CHECK(ascIter1 == ascIter2);
        CHECK_FALSE(ascIter1 != ascIter2);

        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK_FALSE(ascIter2 < ascIter1);
    }
}

TEST_SUITE("SideCrossIterator"){

    MagicalContainer container;
    MagicalContainer::SideCrossIterator crossIter(container);
    TEST_CASE("side crossed"){
        container.addElement(0);
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);

        CHECK_EQ(*crossIter, 0);
        ++crossIter;
        CHECK_EQ(*crossIter, 4);
        ++crossIter;
        CHECK_EQ(*crossIter, 1);
        ++crossIter;
        CHECK_EQ(*crossIter, 2);
        container.addElement(5);
        ++crossIter;
        CHECK_EQ(*crossIter, 2);
        ++crossIter;
        CHECK_EQ(*crossIter, 3);


        CHECK_EQ(container.size(), 6);

        container.removeElement(0);
        container.removeElement(3);
       
        CHECK_EQ(container.size(), 4);
    }

    MagicalContainer::SideCrossIterator crossIter1(container);
    MagicalContainer::SideCrossIterator crossIter2(container);
    TEST_CASE("operators ==, !=, <, >"){
        CHECK(crossIter1 == crossIter2);
        CHECK_FALSE(crossIter1 != crossIter2);

        ++crossIter1;
        CHECK_FALSE(crossIter1 == crossIter2);
        CHECK(crossIter1 != crossIter2);

        CHECK(crossIter1 > crossIter2);
        CHECK(crossIter2 < crossIter1);

        ++crossIter2;
        CHECK(crossIter1 == crossIter2);
        CHECK_FALSE(crossIter1 != crossIter2);

        CHECK_FALSE(crossIter1 > crossIter2);
        CHECK_FALSE(crossIter2 < crossIter1);
    }
}

TEST_SUITE("PrimeIterator")
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator primeIter(container);
    TEST_CASE("primes only"){
        container.addElement(0);
        container.addElement(2);
        container.addElement(1);
        container.addElement(7);
        container.addElement(3);
        container.addElement(5);

        CHECK_EQ(*primeIter, 2);
        ++primeIter;
        CHECK_EQ(*primeIter, 7);
        ++primeIter;
        CHECK_EQ(*primeIter, 3);
        container.addElement(11);
        ++primeIter;
        CHECK_EQ(*primeIter, 5);
        ++primeIter;
        CHECK_EQ(*primeIter, 11);

        CHECK_EQ(container.size(), 5);

        container.removeElement(2);
    
        CHECK_EQ(container.size(), 4);
    }

    MagicalContainer::PrimeIterator primeIter1(container);
    MagicalContainer::PrimeIterator primeIter2(container);
    TEST_CASE("operators ==, !=, <, >"){
        CHECK(primeIter1 == primeIter2);
        CHECK_FALSE(primeIter1 != primeIter2);

        ++primeIter1;
        CHECK_FALSE(primeIter1 == primeIter2);
        CHECK(primeIter1 != primeIter2);

        CHECK(primeIter1 > primeIter2);
        CHECK(primeIter2 < primeIter1);

        ++primeIter2;
        CHECK(primeIter1 == primeIter2);
        CHECK_FALSE(primeIter1 != primeIter2);

        CHECK_FALSE(primeIter1 > primeIter2);
        CHECK_FALSE(primeIter2 < primeIter1);
    }
}