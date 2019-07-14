# Using the standard container classes
======================================

A container class is used to hold and organize objects of other classes, this allows us to apply generic algorithms to the containers do perform operations such as sorting. The containers are implemented as template classes which allows to be used with many different types. Containers are available in two designs:
 - COMPOSITION which store copies of the objects and will call the constructors and de-constructors of those objects.
 - AGGREGATIONS which means they store pointers or references to other objects and thus are not responsible for their creation and destruction. The containers can only hold one type of object unless you fill them with template class objects in which case each template class instance can have a different type. First lets look at the different containers.

SEQUENCE
Sequence containers are named so because their elements are accessed sequentially, they are:
 - vector,
 - list,
 - deque,
 - in C++11 array and forward_list were added.

ASSOCIATIVE
We also have associative containers which are designed to provide efficient access to elements by key,
as opposed to sequence containers which provide access to elements by position.
The associative container in the STL are:
 - set,
 - map,
 - multiset,
 - multimap.
Map and multimap use key value pairs and in set and multiset the value is the key, Map and set keys must be unique.
The associative containers are ordered and there are equivalent unordered containers:
 - unordered_set,
 - unordered_map,
 - unordered_multimap,
 - unordered_multiset.
So let's look as some use of these containers, we will create instances of vector, list, set, map and deque,
and then we will apply the following algorithms to each container and print out the answers.
Count, min_element, max_element, we will sort vector, list and deque,
but we won't sort map or set as these are store their element already sorted, reverse, partial_sort, intersection and accumulate.

MORE
There are many other algorithms you can use on container in the STL and you can also write your own,
and I recommend the reader spends some time further studying the use of these algorithms we haven't covered in this course.
