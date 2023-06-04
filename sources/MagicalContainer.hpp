#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>

namespace ariel {
    class MagicalContainer {
        protected:
            std::vector<int> container_;

        public:
            //Constructor
            MagicalContainer();
            
            void addElement(int);
            void removeElement(int);
            size_t size() const;
    
        class AscendingIterator {
            private:
                MagicalContainer& container_;
                size_t index_;

            public:
                //Constructors
                AscendingIterator(MagicalContainer&);
                AscendingIterator(const AscendingIterator&);

                //Deconstructor
                ~AscendingIterator() = default;

                //Move Constructor, Assignment for tidy
                AscendingIterator(AscendingIterator&&) noexcept;
                AscendingIterator& operator=(AscendingIterator&&) noexcept;

                //Operators
                AscendingIterator& operator=(const AscendingIterator&);
                AscendingIterator& operator++();
                int& operator*() const;
                bool operator==(const AscendingIterator&) const;
                bool operator!=(const AscendingIterator&) const;
                bool operator>(const AscendingIterator&) const;
                bool operator<(const AscendingIterator&) const;


                AscendingIterator begin() const;
                AscendingIterator end() const;
        };

        class SideCrossIterator {
            private:
                MagicalContainer& container_;
                size_t index_;

            public:
                //Constructors
                SideCrossIterator(MagicalContainer&);
                SideCrossIterator(const SideCrossIterator&);

                //Deconstructor
                ~SideCrossIterator() = default;

                //Move Constructor, Assignment for tidy
                SideCrossIterator(SideCrossIterator&&) noexcept;
                SideCrossIterator& operator=(SideCrossIterator&&) noexcept;

                //Operators
                SideCrossIterator& operator=(const SideCrossIterator&);
                SideCrossIterator& operator++();
                int& operator*() const;
                bool operator==(const SideCrossIterator&) const;
                bool operator!=(const SideCrossIterator&) const;
                bool operator>(const SideCrossIterator&) const;
                bool operator<(const SideCrossIterator&) const;


                SideCrossIterator begin() const;
                SideCrossIterator end() const;
        };

        class PrimeIterator {
            private:
                MagicalContainer& container_;
                size_t index_;

            public:
                //Constructors
                PrimeIterator(MagicalContainer&);
                PrimeIterator(const PrimeIterator&);

                //Deconstructor
                ~PrimeIterator() = default;

                //Move Constructor, Assignment for tidy
                PrimeIterator(PrimeIterator&&) noexcept;
                PrimeIterator& operator=(PrimeIterator&&) noexcept;

                //Operators
                PrimeIterator& operator=(const PrimeIterator&);
                PrimeIterator& operator++();
                int& operator*() const;
                bool operator==(const PrimeIterator&) const;
                bool operator!=(const PrimeIterator&) const;
                bool operator>(const PrimeIterator&) const;
                bool operator<(const PrimeIterator&) const;


                PrimeIterator begin() const;
                PrimeIterator end() const;
        };
    };

}

#endif