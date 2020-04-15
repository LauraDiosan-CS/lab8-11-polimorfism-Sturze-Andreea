#pragma once
#include <list>
#include <algorithm>
using namespace std;

template <class T>class RepoTemplate{
protected:
	list<T> elem;
public:
	RepoTemplate<T>();
	int addElem(const T&); 
	int delElem(const T&);
	bool findElem(const T&);
	int getSize();
	void updateElem(const T & s, const T nou);
	list<T> getAll();
	T getItemFromPos(int);
	void clear();
	~RepoTemplate();
};



template <class T> RepoTemplate<T>::RepoTemplate()
{
}

template<class T> int RepoTemplate<T>::addElem(const T &e)
{
	list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it == elem.end())
	{
		elem.push_back(e);
		return 0;
	}
	return -1;
}

template<class T> int RepoTemplate<T>::delElem (const T & e)
{
	list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	return -1;
}

template<class T> bool RepoTemplate<T>::findElem(const T &e)
{
	list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end())
		return true;
	return false;
}

template<class T> int RepoTemplate<T>::getSize()
{
	return elem.size();
}

template<class T> void RepoTemplate<T>::updateElem(const T & old, const T newE)
{
	replace(elem.begin(), elem.end(), old, newE);	

}

template<class T> list<T> RepoTemplate<T>::getAll()
{
	return elem;
}

template<class T> T RepoTemplate<T>::getItemFromPos(int i) {
	list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;

	}
	return T();
}

template <class T> RepoTemplate<T>::~RepoTemplate()
{
}

template <class T> void RepoTemplate<T>::clear() {
	elem.clear();
}