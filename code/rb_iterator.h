#ifndef RB_ITERATOR_H
#define RB_ITERATOR_H
#include "rb_node.h"


template< typename T >
class rb_iterator
{
protected:
		T * Iterator ;	
public:	

// Constructors:
	explicit rb_iterator( void ): Iterator(NULL) { } ;
	rb_iterator( T * ptr ): Iterator( ptr ) { }
	rb_iterator( const rb_iterator & that ): Iterator( that.Iterator ) { }

//Operators
	rb_iterator operator++( void ) {
		Iterator = Iterator->successor() ;
		return *this ;
	}
	rb_iterator operator++( int ) {
		T * temp = Iterator ;
		operator++();
		return rb_iterator( temp ) ;
	}

	rb_iterator operator--( void ) {
		Iterator = Iterator->predecessor() ;
		return ( *this ) ;
	}

	rb_iterator operator--( int ) {
		T * temp = Iterator ;
		operator--();
		return rb_iterator( temp ) ;
	}

	rb_iterator operator=(const T * that ) {
		Iterator->value = that ;
		return *this;
	}

	bool operator==( const rb_iterator & that ) const	{	return ( Iterator == that.Iterator ) ;	}
	bool operator!=( const rb_iterator & that ) const	{	return ( Iterator != that.Iterator ) ;	}
	operator T&()				{	return *Iterator ;	}
	operator const T&() const	{	return *Iterator ;	}
	T operator* ( void )	{	return Iterator->value ;		}
	T * operator->( void )		{	return Iterator ;	}
} ;
#endif
