/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}
	~L1List() { clean(); };

    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i);// give the reference to the element i-th in the list
    T&      operator[](int i);// give the reference to the element i-th in the list

    bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
    int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

    void    traverse(void (*op)(T&)) {
        // TODO: Your code goes here
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        // TODO: Your code goes here
    }
};

template<class T>
inline T& L1List<T>::at(int i)
{
	// TODO: insert return statement here
	if (i < 0 || i >= _size)
		throw " Index_out_of_bounds! ";
	else
	{
		L1Item<T>* p = _pHead;
		while(i)
		{
			p = p->pNext;
			i--;
		}
		return p;
	}

}

template<class T>
inline T& L1List<T>::operator[](int i)
{
	// TODO: insert return statement here

	if (_size == 0) return NULL;
	int* arr = new int[_size];
	L1Item<T>* p = _pHead;
	int j = 0;
	while (p != NULL)
	{
		arr[j] = p->data;
		j++;
		p = p->pNext;
	}
	return arr[i];
}
	

template<class T>
inline bool L1List<T>::find(T& a, int& idx)
{
	idx = 0;
	L1Item<T> *p = _pHead;
	while (p) {
		if (p->data == a) return true;
		p->pNext;
		idx++;
	}
	return false;
}

template<class T>
inline int L1List<T>::insert(int i, T& a)
{
	if (i) {
		L1Item<T>* pPre = _pHead, * pCur = pPre->pNext;
		while (i > 1 && pCur) {
			pPre = pCur;
			pCur = pCur->pNext;
			i--;
		}
		pPre->pNext = new L1Item<T>(a, pCur);
	}
	else
	{
		_pHead = new L1Item<T>(a, _pHead);
		_size++;
		return 0;
	}
	return -1;
}

template<class T>
inline int L1List<T>::remove(int i)
{
	if (_size == 0) return -1;
	if (i) {
		L1Item<T>* pPre = _pHead, * pCur = pPre->pNext;
		while (i > 1 && pCur) {
			pPre = pCur;
			pCur = pCur->pNext;
			i--;
		}
		if (pCur) {
			pPre->pNext = pCur->pNext;
			delete pCur;
			_size--;
			return 0;
		}
		else return -1;

	}
	

	return 0;
}



/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
    // TODO: Your code goes here
	if (i) {
		L1Item<T>* pPre = _pHead, * pCur = pPre->pNext;
		while (i > 1 && pCur) {
			pPre = pCur;
			pCur = pCur->pNext;
			i--;
		}
		pPre->pNext = new L1Item<T>(a, pCur);
	}
    return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
	_pHead = new L1Item<T>(a, _pHead);
	_size++;
	return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
	L1Item<T> 

    return -1;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here


    return -1;
}

template<class T>
inline L1List<T>::~L1List()
{
}

template<class T>
inline void L1List<T>::clean()
{
	while (_pHead)
	{
		L1List<T>* p = _pHead;
		_pHead = _pHead->pNext;
		delete p;
	}
}
#endif //DSA191_A1_DSALIB_H


