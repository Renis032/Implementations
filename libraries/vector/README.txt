Overview:

rsm::vector<T> is a C++ template class that implements a dynamic array (similar to std::vector) capable of storing elements of type T. It provides functionalities for dynamically resizing, accessing elements, and performing various operations commonly associated with vectors.

Member Functions:

-Constructors and Destructors
vector(): Constructs an empty vector.
~vector(): Destroys the vector and deallocates memory.

-Capacity
size(): Returns the number of elements in the vector.
capacity(): Returns the total number of elements that the vector can hold without resizing.
empty(): Returns true if the vector is empty, false otherwise.

-Element Access
operator[]: Accesses the element at the specified index.
at(int index): Accesses the element at the specified index with bounds checking.
front(): Returns a reference to the first element.
back(): Returns a reference to the last element.

-Modifiers
push_back(T elementToPush): Adds an element to the end of the vector.
pop_back(): Removes the last element from the vector.
resize(int indexToResizeTo): Changes the size of the vector.
reserve(int capacityToReserve): Requests that the vector capacity be at least enough to contain a certain number of elements.
clear(): Removes all elements from the vector.

-Comparison Operators
operator==: Checks if two vectors are equal.
operator!=: Checks if two vectors are not equal.

Notes
This vector implementation does not provide iterators or support for initializer lists.
Care should be taken to ensure proper memory management when using this vector, especially when passing it across functions or dealing with dynamic resizing.
