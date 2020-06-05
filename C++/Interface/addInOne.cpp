class IntCell{
    public:
        /**
        * Construct the IntCell.
        * Initial value is 0.
        */
        IntCell() {
            storedValue = 0;
        }

        IntCell(int initialValue) {
            storedValue = initialValue;
        }

        int read() {
            return storedValue;
        }

        void write(x) {
            storedValue = x;
        }
    
    private:
        int storedValue;
}

class IntCell {
    public:        
        explicit IntCell(int initialValue = 0):
            // if a data member is itself a class type that does not have a zero-parameter constructor, 
            // then it must be initialized in the initialization list.
            storedValue{ initialValue} {}
            
        int read() const {
            return storedValue;
        }
        void write( int x ){
            storedValue = x;
        }
    
    private:
        int storedValue;
}

IntCell obj; // obj is an IntCell