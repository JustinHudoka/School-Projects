// File: CCLinkedList.h
// Linked List class with List Iterator class

#ifndef _CLinkedList_
#define _CLinkedList_
#include <assert.h>
#include <iostream>

using namespace std;

// Need to prototype template classes if they are to be friends
template <typename eltType> class CLinkedList;
template <typename eltType> class CListItr;
/*
// and also the friend...note <> in header declaration of <<
template <typename eltType> 
		ostream& operator<<(ostream&,CLinkedList<eltType>);
*/

template <typename eltType> class node
{	private:
		node(eltType info= 0, node* link = NULL ) : 
						data(info), next(link) {};
		eltType data;
		node*	next;
	friend class CLinkedList<eltType>;
	friend class CListItr<eltType>;
};

template <typename eltType> class CLinkedList
{
	public:
		// Construct empty CLinkedList
		CLinkedList();
		// Construct deep copy of another CLinkedList
		CLinkedList(CLinkedList&);

		// destroy CLinkedList
		~CLinkedList();

		// Assign another CLinkedList to this CLinkedList; deep copy
		CLinkedList& operator=(const CLinkedList&);

		// Is the CLinkedList empty?
		bool empty();

		bool find(eltType);

		// Ordered insert/remove
		void orderedInsert(eltType);
		void remove(eltType);

	private:
		// linked list pointer
		node<eltType>*	head;
        node<eltType>*	tail;


		// Get a copy of a (deep) node
		node<eltType>*	copy(node<eltType> *);

		// Free nodes of a linked list
		void	destroy(node<eltType> *);

/*
	// Linked list to ostream
	friend ostream& operator<< <>(ostream&, CLinkedList<eltType>);
*/

	// Needed to use a list iterator
	friend class CListItr<eltType>;
};

template <typename eltType>
	ostream& operator<<(ostream &os,const CLinkedList<eltType> &l);

// Set up an iterator; 
//	an object that provides a pointer to a linked list (in this case)
template <typename eltType> class CListItr
{
	public:
		// Construc a List Iterator
		CListItr(const CLinkedList<eltType> &l);

		// Set curr to point at the first node of itr
		void begin();
		// Is curr null?
		bool more();
		// Go to curr->next
		void next();
		// Get the value out of curr's node
		eltType	value();

        eltType operator*(int);
        eltType& operator*() const;
	private:
		const CLinkedList<eltType> &itr;
		node<eltType> *curr;
};
/////////////////////////////////////////////////////////////////////////////////////////////

// Construct empty CLinkedList
template <typename eltType> CLinkedList<eltType>::CLinkedList() : head(NULL)
{}
// Copy constructor. copy() does the deep copy
template <typename eltType> 
	CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl)
{head = copy( cl.head );}

// Free all nodes
template <typename eltType> CLinkedList<eltType>::~CLinkedList()
{
    if (tail != NULL)
    {
        destroy(tail);
        head = NULL;
        tail = NULL;
    }
    
	
}

// Assignment operator: copy() does the deep copy
template <typename eltType> CLinkedList<eltType> 
	&CLinkedList<eltType>::operator =(const CLinkedList<eltType>& cl)
{	if (this != &cl)
	{	destroy(head);
		head = copy(cl.head);
	}
	return *this;
}

// Place x into the list in order
template <typename eltType> 
		void CLinkedList<eltType>::orderedInsert(eltType x)
{	
	if (empty())
    {
        head = new node<eltType>(x,head);
		tail = head;
		tail->next = head;
    }

	else
	{
		if (x < head->data)
    	{
        	head = new node<eltType>(x,head);
			tail->next = head;
    	}
		
		else   // start at 2nd node...already checked first node
		{	node<eltType>*	p	= head -> next; // head;
			node<eltType>*	trailp	= head;         // NULL;
			while (p != head && x > p->data)
			{	trailp = p;
				p = p->next;
			}
			trailp->next = new node<eltType>(x,p);
			if(p == head)
			{
				tail = trailp->next;
			}
		}
	}
}

// Is this element in the linked list?
template <typename eltType> 
		bool CLinkedList<eltType>::find(eltType x)
{	node<eltType> *p = head;
	while (p != NULL && p->data != x)
		p = p->next;
	return (p != NULL && p->data == x);
}

// Inline: Look into this.
template <typename eltType> inline bool CLinkedList<eltType>::empty()
{return (head == NULL);}

// Remove a node in an ordered list
// Pre: Node will be found
template <typename eltType> void CLinkedList<eltType>::remove(eltType x)
{	assert( !empty() );
	node<eltType>*	p = head;
	node<eltType>*	trailp = NULL;
	while ( p != tail && p->data != x )
	{	trailp = p;
		p = p->next;
	}
	if (p != tail)
	{
		if (p == head)
		head = head->next;	// x is first in the CLinkedList
		else
			trailp->next = p->next;	// x is farther down in the CLinkedList
		delete p;

	}

	else
	{
		delete p;
		tail = trailp;
		tail->next = head;
	}
	
	
}

// Remove all nodes in the linked list, starting at l
template <typename eltType> void CLinkedList<eltType>::destroy(node<eltType> *l)
{	
    if (l->next != tail)
    {
        destroy(l->next);
    }
    delete l;
}

// The deep copy. Copy the source list l, one node at a time
template <typename eltType> 
	node<eltType>* CLinkedList<eltType>::copy(node<eltType> *l)
{	node<eltType>* first = NULL;	// ptr to beginning of copied CLinkedList
	node<eltType>* last = NULL;	// ptr to last item insert in the copy
	if (l != NULL)
	{	assert((first=last=new node<eltType>(l->data,NULL)) != NULL);
		for (node<eltType>* source=l->next;source!=NULL;
					source=source->next,last=last->next)
		{	last->next = new node<eltType>(source->data,NULL);
			assert(last->next);
		}
	}
	return first;
}

// Output a linked list, using a list iterator
template <typename eltType> 
	ostream& operator<<(ostream &os,const CLinkedList<eltType> &l)
{	CListItr<eltType>	lt(l);
	for (lt.begin(); lt.more(); lt.next())
		os << lt.value() << " "<<endl;

		os << lt.value() << " "<<endl; 
	return os;
}


/* ****************************************************************
   ************** List Iterator Implementations *******************
   ****************************************************************/

// Construct a list iterator. It consists of:
//	 a reference to a linked list object
//	 a pointer to the actual list, initially pointing to its head
template <typename eltType> 
CListItr<eltType>::CListItr(const CLinkedList<eltType> &l): itr(l),curr(l.head) 
{}

// Set curr to point at itr's head
template <typename eltType> void CListItr<eltType>::begin(void)
{curr = itr.head;}

// Is curr at the end of the list?
template <typename eltType> bool CListItr<eltType>::more(void)
{return curr != itr.tail;}

// Move curr to next node
template <typename eltType> void CListItr<eltType>::next(void)
{//assert( curr != NULL );
 curr = curr->next;
}

// Return data in curr's node. Regardless of assert(), this 
//	function shouldn't be called until making sure more() returns true
template <typename eltType> eltType CListItr<eltType>::value(void)
{//assert( curr != NULL );
 return curr->data;
}

template <typename eltType> eltType CListItr<eltType>::operator*(int x)
{
    return curr->data;
}

template <typename eltType> eltType& CListItr<eltType>::operator*() const
{
    return curr->data;
}

#endif