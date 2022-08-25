#pragma once

namespace ft
{
	enum tree_color {red, black};
	
	template <typename Key, typename T>
    class map{
    public:
		typedef Key key_type;
		typedef T mapped_type;
		//iterator
	/***************constructor***************/
        map();
        ~map();
        map& operator=(map<T> a);
        get_allocator();
        /*Element access*/
        
        /*Iterators*/
        /*Capacity*/
        /*Modifiers*/
        /*Lookup*/
        /*Observers*/
	

    private:
		key_type key;
		mapped_type value;
		map *left;
		map *right;
		map *parent;
		tree_color color;

    protected:

    };
} // namespace name
