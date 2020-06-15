### Headers

```
#include <iostream>
#include <vector>
#include "IntCell.h" //Include a local header file
#include <algorithm> //algorithms
#include <set> //Set (auto sort nos)
#include <cmath> //Math functions
#include <map>  //Maps
#include <stdlib.h> // srand, rand

#include <bits/stdc++.h> //imp

```

### Class

##### Declaration

```
class IntCell{
    public:
        //Construct the IntCell. Initial value is 0.
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
```

### Objects

##### Creation

```
m = new IntCell( ); // OK
m = new IntCell{ }; // C++11
m = new IntCell; // Preferred in this text
```

##### Accessing objects of where an obj resides

If a pointer variable points at a class type, then a (visible) member of the object being pointed at can be accessed via the -> operator.

##### Return memory location

One important operator is the **address-of operator (&)**. This operator returns the memory location where an object resides and is useful for implementing an alias test

### Pointers

##### Definition

A pointer variable is a variable that stores the address where another object resides.

##### Declaration

```
IntCell *m;
m = new IntCell{ 0 };
m->write( 5 );
cout << "Cell contents: " << m->read( ) << endl;
delete m;
```

`Note`: When an object that is allocated by new is no longer referenced, the delete operation must be applied to the object (through a pointer). Otherwise, the memory that it consumes is lost (until the program terminates). This is known as a **memory leak.**


### Struct

A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type.

Structures in C++ can contain two types of members:
* Data Member: These members are normal C++ variables. We can create a structure with variables of different data types in C++
* Member Functions: These members are normal C++ functions. Along with variables, we can also include functions inside a structure declaration.

###### Declaration

```
// A variable declaration with structure declaration.
struct Point
{
   int x, y;
} p1;  // The variable p1 is declared with 'Point'


// A variable declaration like basic data types
struct Point
{
   int x, y;
};

int main()
{
   struct Point p1;  // The variable p1 is declared like a normal variable
}
```

##### Accessing

```
#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int main()
{
    struct Point p1 = { 0, 1 };

    // Accessing members of point p1
    p1.x = 20;
    cout << "x = " << p1.x << ", y = " << p1.y;

    return 0;
}
```

##### Structure Pointer

Like primitive types, we can have pointer to a structure. If we have a pointer to structure, members are accessed using arrow ( -> ) operator instead of the dot (.) operator.

```
struct Point {
    int x, y;
};

int main()
{
    struct Point p1 = { 1, 2 };

    // p2 is a pointer to structure p1
    struct Point* p2 = &p1;

    // Accessing structure members using
    // structure pointer
    cout << p2->x << " " << p2->y;
    return 0;
}
```

### Abstract Data Types (ADT)

##### Defintation

An abstract data type (ADT) is a set of objects together with a set of operations. Abstract data types are mathematical abstractions; nowhere in an ADT’s definition is there any mention of how the set of operations is implemented. Objects such as lists, sets, and graphs, along with their operations, can be viewed as ADTs, just as integers, reals, and booleans are data types. Integers, reals, and booleans have operations associated with them, and so do ADTs. For the set ADT, we might have such operations as add, remove, size, and contains.
Alternatively, we might only want the two operations union and find, which would define a different ADT on the set

### Vectors

##### Size declaration

```
vector<int> squares(100); //Declare a vector of size 100
```

##### Size Initialization

```
vector<int> squares = {1, 2,3,4,55}; //Initialize a vector of size 100
```

**OR**

```
vector<int> squares {1, 2,3,4,55}; //Shorthand property
```

##### Functions

1. `vector.size()` : Get the size
2. `vector.push_back()` : Append the value
3. `vector.back()` : Returns a reference to the last element in the vector.
4. `vector.front()` : Returns a reference to the first element in the vector.
5. `vector.end()` : Returns an iterator referring to the past-the-end element in the vector container.
6. `vector.begin()` : Returns an iterator pointing to the first element in the vector.
7. `vector.clear()` : removes all elements from the container
8. `empty()` : returns true if the container contains no elements, and false
otherwise
9. `int capacity( ) const` :  returns the internal capacity of the vector
10. `void reserve( int newCapacity )`: sets the new capacity. If a good estimate is available, it can be used to avoid expansion of the vector
11. `Object & at( int idx )`: returns the object at index idx in the vector, with boundschecking (an accessor that returns a constant reference is also provided)
12. `Object & operator[] ( int idx )`: returns the object at index idx in the vector, with no bounds-checking (an accessor that returns a constant reference is also provided).

### List (Linked List)

##### Functions

1. `int size( ) const`: returns the number of elements in the container.
2. `void clear( )`: removes all elements from the container.
3. `bool empty( ) const`: returns true if the container contains no elements, and false otherwise.
4. `void push_back( const Object & x )`: adds x to the end of the list.
5. `void pop_back( )`: removes the object at the end of the list.
6. `const Object & back( ) const`: returns the object at the end of the list (a mutator that returns a reference is also provided).
7. `const Object & front( ) const`: returns the object at the front of the list (a mutator that returns a reference is also provided).
8. `void push_front( const Object & x )`: adds x to the front of the list.
9. `void pop_front( )`: removes the object at the front of the list

### Iterators

##### Defination
It represents the position of an item

##### Functions
1. `iterator begin( )`: returns an appropriate iterator representing the first item in the container.
2. `iterator end( )`: returns an appropriate iterator representing the endmarker in the container (i.e., the position after the last item in the container).
3. `iterator insert( iterator pos, const Object & x )`: adds x into the list, prior to the position given by the iterator pos. This is a constant-time operation for list, but not for vector. The return value is an iterator representing the position of the inserted item.
4. `iterator erase( iterator pos )`: removes the object at the position given by the iterator. This is a constant-time operation for list, but not for vector. The return value is the position of the element that followed pos prior to the call. This operation invalidates pos, which is now stale, since the container item it was viewing has been removed.
5. `iterator erase( iterator start, iterator end )`: removes all items beginning at position start, up to, but not including end. Observe that the entire list can be erased by
the call c.erase( c.begin( ), c.end( ) ).


##### Methods

* itr++ and ++itr: advances the iterator itr to the next location. Both the prefix and postfix forms are allowable.
* *itr: returns a reference to the object stored at iterator itr’s location. The reference returned may or may not be modifiable (we discuss these details shortly).
* itr1==itr2: returns true if iterators itr1 and itr2 refer to the same location and false otherwise.
* itr1!=itr2: returns true if iterators itr1 and itr2 refer to a different location and false otherwise

##### Tricks

* For loop using an iterator
```
for( vector<int>::iterator itr = v.begin( ); itr != v.end( ); ++itr )
    cout << itr.??? << endl;
```
OR
```
vector<int>::iterator itr = v.begin( );
while( itr !=v.end( ) )
    cout << *itr++ << endl;
```

##### Notes

* The result of *itr is not just the value of the item that the iterator is viewing but also the item itself.
 ```
 while( itr != c.end( ) )
    *itr++ = newValue;
 ```

### Set

##### Declaration

```
set<int> S;
```

##### Insertion

```
S.insert(1);
S.insert(-11);

//Order; {-11, 1}
```

##### Check for existing element

```
auto it = S.find(-1);
if(it == S.end()){
    //not present
}
else{
    cout<<*it;
}

```

##### For a pair

```
set<pair <int, int> > S;

S.insert({2,3});
S.inserrt(make_pair(2,3))

//Print it using
for(auto const &x:S) {
    cout<<x.first<<"\n";
}

//Comparison b/w pairs

if(a < b) or (a == b and c < d){
    {a, b} is smaller than {c, d}
}

//Get the interval in which the element occurs

auto it = S.upper_bound({point, INT_MAX});
if(it == S.begin()){
    //doesnt lie
    return;
}
it--;
pair<int, int> current = *it;

if(current.first <= point && point <= current.second>){
    //yes <<current.first && current.second
}

```

##### Remove a no.

```
S.erase(1)
```

##### First no. greater than x or equal to x

```
auto it = S.lower_bound(x)
```

##### First no. strictly greater than x

```
auto it = S.upper_bound(x)
```

### Map

##### Defination
Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.

##### Declaration
```
map<int, int> gquiz1;

map<int, int> A;
map<char, int> cnts;

A[1] = 100;
A[12] = 200;
```

##### Insertion
```
// insert elements in random order
gquiz1.insert(pair<int, int>(1, 40));
gquiz1.insert(pair<int, int>(2, 30));
```

##### Printing
```
map<int, int>::iterator itr;
for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
    cout << '\t' << itr->first<< '\t' << itr->second << '\n';
    }
    cout << endl;
```

##### Copying
```
// assigning the elements from gquiz1 to gquiz2
map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
```

##### Removing
```
// remove all elements up to
// element with key=3 in gquiz2
gquiz2.erase(gquiz2.begin(), gquiz2.find(3));

// remove all elements with key = 4
gquiz2.erase(4);
```

##### Find a key

```
A.find(key);
```

##### Delete a key

```
A.delete(key);
```


##### Get the count of characters

```
string x = "hardik";

for(char y : x){
    cnt[x]++;
}

cout<<cnt['h'];
```

##### Functions available

* `begin()` – Returns an iterator to the first element in the map
* `end()` – Returns an iterator to the theoretical element that follows last element in the map
* `size()` – Returns the number of elements in the map
* `max_size()` – Returns the maximum number of elements that the map can hold
* `empty()` – Returns whether the map is empty
* `pair insert(keyvalue, mapvalue)` – Adds a new element to the map
* `erase(iterator position)` – Removes the element at the position pointed by the iterator
* `erase(const g)` – Removes the key value ‘g’ from the map
* `clear()` – Removes all the elements from the map

### Pair

##### Declartion

```
< pair<int,int> >

eg. {x, y}
```

### Class

### Loops

##### For loop (Print a vector)

```
for(int i=0;i<squares.size();i++){
    sum += squares[i];
}
```

##### For each loop (Range for loop) (Print a vector)

```
for(int i: squares) {
    sum += i;
}

// Auto can be used in place of int for automatically infering the type
```

##### Sort a vector

```
sort(v.begin(), v.end());
```

##### Reverse sort
```
sort(v.rbegin(),v.rend());
```

##### Sort a vector using a comparator

```
//Reverse sort
bool f(int x, int y){
    return x>y;
}

sort(v.begin(), v.end(), f);
```

##### Print a vector

```
vector<int>::iterator it;

for(it = A.begin(); it!=A.end(); it++){
    cout<<*it;
}

```

### Arrays

##### Declaration

```
int arr1[ 10 ];
//arr1 is actually a pointer to memory that is large enough to store 10 ints, rather than a first-class array type.
```

##### Get the size

```
sizeof(arr) / sizeof(*arr)
```

##### If size is unknown

```
int *arr2 = new int[ n ];
```

##### Delete an array

```
delete [ ] arr2;
//If we don't do this a memory leak will occur
```

### Strings

###### Functions

- `strcpy` : Copy string
- `strcmp` : Compare string
- `strlen` : Length of string
- `getline(cin, str)`: String input | If getline running initially (use `cin.ignore(256, '\n');` after cin)

### Constructor

##### Zero parameter constructor

```
IntCell{} { } or IntCell obj1 or IntCell obj4{ };
```

##### One parameter constructor

```
IntCell obj2{ 12 };
```

### Lvalues and Rvalues

##### Definition

An lvalue is an expression that identifies a non-temporary object. An rvalue is an expression that identifies a temporary object or is a value (such as a literal constant) not associated with any object.

###### References

`lvalue reference` is declared by placing an **&** after some type. An lvalue
reference then becomes a synonym (i.e., another name) for the object it references

eg.

```
string str = "hell";
string & rstr = str; // rstr is another name for str
rstr += ’o’; // changes str to "hello"
bool cond = (&str == &rstr); // true; str and rstr are same object
string & bad1 = "hello"; // illegal: "hello" is not a modifiable lvalue
string & bad2 = str + ""; // illegal: str+"" is not an lvalue
string & sub = str.substr( 0, 4 ); // illegal: str.substr( 0, 4 ) is not an lvalue
```

##### Use case

1. For a for each loop since the x is a copy so by using alias we are setting each value of the vector to x

```
for( auto & x : arr ) // works
    ++x;
```

2. Swapping when only the value is passed in the function i.e. `swap( x, y );` or (**call-by-value**)

```
void swap( double & a, double & b ); // swaps a and b; correct parameter types
```

or (**call-by-lvalue-reference**)

3. string randomItem( const vector<string> & arr ); // returns a random item in arr
   or (**call-by-constant reference.**)

`rvalue reference` is declared by placing **&&** after some type. An rvalue reference has the same characteristics as an lvalue reference except that, unlike an lvalue reference, an rvalue reference can also reference an rvalue (i.e., a temporary).

eg.

```
string str = "hell";
string && bad1 = "hello"; // Legal
string && bad2 = str + ""; // Legal
string && sub = str.substr( 0, 4 ); // Legal
```

`Note`:

1. Call-by-value is appropriate for small objects that should not be altered by the
   function.
2. Call-by-constant-reference is appropriate for large objects that should not be altered
   by the function and are expensive to copy.
3. Call-by-reference is appropriate for all objects that may be altered by the function.

##### More cases

- Pg. 47 obtain a random item in an array
-

##### Copy Constructor

```
IntCell B = C; // Copy construct if C is lvalue; Move construct if C is rvalue
IntCell B { C }; // Copy construct if C is lvalue; Move construct if C is rvalue
```

- For IntCell, the signatures of these operations are

```
~IntCell( ); // Destructor
IntCell( const IntCell & rhs ); // Copy constructor
IntCell( IntCell && rhs ); // Move constructor
IntCell & operator= ( const IntCell & rhs ); // Copy assignment
IntCell & operator= ( IntCell && rhs ); // Move assignment
```

### Dynamic Memory

* **Heap** : The free memory which resides in our computer
* **Stack**: Limited in size; Assigned by the OS; Cannot be increased dynamically; Stores our function calls
* **Static/ Global**: The variables which we decalare ore stored here
* **Code (Text)**: Code/ Text

##### Functions

* `new`: For assigning memory in heap (In C it is: `(int*)malloc(sizeof(int)`)
* `delete`: For freeing memory from heap (In C it is: `free(p)`)

eg.
```
    int *p;
    p = new int; //(In the heap assign a memory of size of int and returns the address)

    *p = 10; //Since p is an address so to store the value we need to use a pointer

    delete p; //Free memory of p (The address still remains)
```

##### Note
* Anything in dyanmic memory is accessed using pointers
  eg.
    `(*node).data = data;`
    //or
    `node->data = data`

### Random

##### Generate secret number between 1 and 10 (Inclusive)
```
rand() % 10 + 1;
```

### Stack

##### Declaration
```
stack <int> s;
```

##### Operations
Push O(1): `s.push(10)`
Pop  O(1): `s.pop()`
Empty O(1): `s.empty()`
Top O(1): `s.top()`
Size O(1): `s.size()`
Emplace O(1): `s.emplace()`
Swap: `stack1.swap(stack2)`

##### Difference between stack::emplace() and stack::push() function.
While push() function inserts a copy of the value or the parameter passed to the function into the container at the top, the emplace() function constructs a new element as the value of the parameter and then adds it to the top of the container.

### Templates

#### Function Templates

A function template is not an actual function, but instead is a pattern for what could become a function.

eg.

```
template <typename Comparable>
const Comparable & findMax( const vector<Comparable> & a ){
    int maxIndex = 0;
    for( int i = 1; i < a.size( ); ++i )
        if( a[ maxIndex ] < a[i] )
            maxIndex = i;
    return a[maxIndex];
}

//Call

vector<int> v1( 37 );
vector<double> v2( 40 );
cout << findMax( v1 ) << endl; // OK: Comparable = int
cout << findMax( v2 ) << endl; // OK: Comparable = double
```
eg.
```
#include <iostream>using namespace std;

template <class T>
T sum (T a, T b)
{
T result;
result = a + b;
return result;
}

int main () {
int i=5, j=6, k;
double f=2.0, g=0.5, h;
k=sum<int>(i,j);
h=sum<double>(f,g);
cout << k << '\n';
cout << h << '\n';
return 0;
}
```

#### Class template

In the simplest version, a class template works much like a function template.

eg.

```
template <typename Object>
class MemoryCell
{
    public:
        explicit MemoryCell(const Object & initialValue = Object{})
            : storedValue{initialValue} {}
        const Object & read() const
            { return storedValue; }
        void write(const Object & x)
            { storedValue = x; }
    private:
        Object storedValue;
};

//Call

int main(){
    MemoryCell<int> m1;             //actual classes
    MemoryCell<string> m2{"hello"}; //actual classes

    m1.write(37);
    m2.write(m2.read() + "world");
    cout<<m1.read()<<m2.read();
    return 0;
}
```

### Overloading

###### Operator overloading

Operator overloading allows us to define the meaning of a built-in operator.

### Hacks

##### Make I/O more efficient

```
ios::sync_with_stdio(0);
cin.tie(0);
```

##### Read whole lines

```
string s;
getline(cin, s);
```

##### When data is unknown

```
while (cin >> x) {
// code
}
```

##### Search using binary search

```
bool present = binary_search(v.begin(), v.end(), 3);
```

##### Get first occurence (logn)

`Sorting needed`

```
vector<int>::iterator it= lower_bound(A.begin(), A.end(), 3);

//OR

auto it= lower_bound(A.begin(), A.end(), 3);

//it is a pointer
```

##### Get last occurence (no. greater than last occurence)

```
vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 3);
```

##### Get total occurence of a number

```
it2 - it
```

##### Read the input file and write it in output one

```
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

##### For extra long int

32 bit - long int
64 bit - long long int
80 bit - long double int
128 bit - \_\_int128_t

##### Performing arithmatics on extra long numbers

```
(a+ b) mod m = (a mod m+ b mod m) mod m
(a− b) mod m = (a mod m− b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m
```

##### Print decimal places

```
printf("%.9f\n", x); // 9 decimal places
```

##### Compare floating numbers (as precision error can occur)

```
abs(a-b) < 1e-9
```

##### Sort a vector of pairs (by calculating their differences)

```
auto comp = [](vector<int> &a, vector<int> &b) {
    return (a[0] - a[1]) < (b[0] - b[1]);
};
```

##### Arithmatic Progression

(n numbers){a + ... + b} = (n( a + b ))/2

##### Geometric Progression

a + ak + ak^2 + .... + b = ( bk - a )/( k - 1)

: a - first number; b - last number; k - ratio

A special case of a sum of a geometric progression is the formula
1+2+4+8+...+2^(n−1) = 2^n - 1

##### Fibonacci numbers : (0,1,1,2,3,5,8,13,21,34,55,...)

Binets formula:

numerator1 = (1.0 + 5.0^0.5^)^n^
numerator2 = (1.0 - 5.0^0.5^)^n^
denominator = (2.0^n^) x (5.0^0.5^)

formula = (numerator1 - numerator2)/(denominator)
