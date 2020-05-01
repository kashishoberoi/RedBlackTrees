#ifndef RB_NODE_H
#define RB_NODE_H
#include <iostream>

enum {	RED, BLACK	} ;

template< typename T >
struct rb_node
{

	typedef T value_type ;
	T value ;
	rb_node * parent ;
	rb_node * left ;
	rb_node * right ;
	bool color ;
		
	rb_node( value_type _value, rb_node * _parent, bool _color ): value( _value ), parent( _parent ), color( _color ), left( NULL ), right( NULL )	{ }

	rb_node( value_type _value, rb_node * _parent ): value( _value ), parent( _parent ), color( RED), left( NULL ), right( NULL )	{ }

	explicit rb_node( const value_type & _value ): value( _value ), color( RED ), parent( NULL ), left( NULL ), right( NULL ) { }

	rb_node( void ): color( BLACK ), parent( NULL ), left( NULL ), right( NULL ) { }

	rb_node( rb_node const & other)	{	( * this ) = other;	}

	

	value_type & operator=( const value_type & _value )	{	value = _value ;	}
	bool operator==( const value_type & _value ) const	{	return value == _value ;	}
	bool operator!=( const value_type & _value ) const	{	return value != _value ;	}
	bool operator>( const value_type & _value )	const	{	return value > _value ;	}
	bool operator<( const value_type & _value )	const	{	return value < _value ;	}
	bool operator>=( const value_type & _value ) const	{	return value >= _value ;	}
	bool operator<=( const value_type & _value ) const	{	return value <= _value ;	}
	bool operator==( const rb_node & other ) const	{	return ( value == other.value ) && ( parent == other.parent ) ;	}
	bool operator!=( const rb_node & other) const	{	return ( value != other.value ) || ( parent != other.parent ) ;	}
	bool operator>( const rb_node & other)	const	{	return value > other.value ;	}
	bool operator<( const rb_node & other)	const	{	return value < other.value ;	}
	bool operator>=( const rb_node & other) const	{	return value >= other.value ;	}
	bool operator<=( const rb_node & other) const	{	return value <= other.value ;	}
	const bool is_a_left_son( void ) const	{	return ( parent != NULL ) && ( parent->left == this ) ;		}
	const bool is_a_right_son( void ) const	{	return ( parent != NULL ) && ( parent->right == this ) ;	}
	
	//Returns maximum value in subtree
	rb_node * max( void )	{	return ( right == NULL ) ? this : right->max() ;	}
	
	//Returns minimum value in subtree
	rb_node * min( void )	{	return ( left == NULL ) ? this : left->min() ;	}
	
	//Returns successor 
	rb_node * successor( void ) {
		if(this!=NULL)
		{

		if ( right != NULL )
			return right->min() ;

		// check if this node is a left son:
		if ( is_a_left_son() )
			return parent ;
		
		// node does NOT have a right subtree and is NOT a left son.
		// search for the next ancestor which is a left son:
		rb_node * succ = this ;
		do { 
			succ = succ->parent ; 
		}while ( ( succ != NULL ) && succ->is_a_right_son() ) ;
		if ( succ != NULL )
			return succ->parent ;
		else
			return NULL ;
		}
		return NULL;
	}

	//sibling node
	rb_node * sibling( void )	
	{	
		if(this!=NULL)
		{
		if(parent==NULL)
			return NULL;
		return ( is_a_left_son() ) ? parent->right : parent->left ;
		}
		return NULL;
	}
	// get the previous node in the tree. 
	rb_node * predecessor( void ) {
		//check if the node has a left subtree
	if(this!=NULL)
	{
		if(left!=NULL)
			return left->max();
		//check if node is a right son
		if(is_a_right_son())
			return parent;
		//if node does NOT have a left subtree and is NOT a right son
		rb_node *pred= this;
		do{
			pred=pred->parent;
		}while(pred!=NULL && pred->is_a_left_son());
		
		if(pred!=NULL)
			return pred->parent;
		else
			return NULL;
	}
	return NULL;
	}


	void print()
	{
		std::cout<<std::endl<<"(Node value:"<<value<<" Color:"<<color;
		if(parent!=NULL)
			std::cout<<" Parent:"<<parent->value;
		if(left!=NULL)
			std::cout<<" Left:"<<left->value;
		if(right!=NULL)
			std::cout<<" Right:"<<right->value;
		std::cout<<")"<<std::endl;
	}

} ;

#endif
