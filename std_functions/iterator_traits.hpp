#pragma once

namespace ft
{
    template <class Iter>
	struct iterators_traits {
		/*typedef is to define a alias type: typedef type alias_name*/
		/*typename is to let compiler know that the following is not a static member of the class but a type*/
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::iterator_category iterator_category;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
	};

    /*hardcode when the input is pointer*/
	template <class T>
	struct iterators_traits<T*> {
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef random_access_iterator_tag iterator_category;
		typedef T* pointer;
		typedef T& reference;
	};
}
