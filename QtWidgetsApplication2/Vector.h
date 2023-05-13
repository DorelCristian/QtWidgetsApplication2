#pragma once
#include <iostream>

template<typename ElementType>
class IteratorVectorT;


template<typename ElementType>
class VectorDin
{
public:
	/*
	* constructor default
	*/
	VectorDin();

	/*
	* Constructor de copiere
	*/
	//VectorDin(const Vector& ot);

	/*
	* Eliberam memoria
	*/
	//~VectorsDin();

	/*
	* Operator assignment
	* elibereaza ce era in obiectul curent (this)
	* aloca spatiu pentru elementele din ot
	* copiaza elementele din ot in this
	*
	*/
	//Vector& operator=(const Vector& ot);
	VectorDin& operator=(const VectorDin& ot);

	ElementType& operator[](int poz);

	void push_back(const ElementType& element);
	void pop_back();
	void erase(int poz);
	int size();
	ElementType& get(int poz);

	friend class IteratorVectorT<ElementType>;
	//functii care creaza iteratori
	IteratorVectorT<ElementType> begin();
	IteratorVectorT<ElementType> end();

private:
	ElementType* elements;
	int capacity = 100;
	int lenght = 0;
	void ensureCapacity();
};

template<typename ElementType>
VectorDin<ElementType>::VectorDin()
	:elements{ new ElementType[10] }, capacity{ 10 }, lenght{ 0 } {
}

template<typename ElementType>
ElementType& VectorDin<ElementType>::operator[](int poz)
{
	return elements[poz];
}

template<typename ElementType>
void VectorDin<ElementType>::push_back(const ElementType& element)
{
	if (lenght == capacity)
	{
		capacity *= 2;
		ElementType* new_elements = new ElementType[capacity];
		for (int i = 0; i < lenght; i++)
			new_elements[i] = elements[i];
		delete[] elements;
		elements = new_elements;
	}
	//elements[lenght] = element;
	lenght = lenght + 1;
}

template<typename ElementType>
void VectorDin<ElementType>::erase(int poz)
{
	for (int i = poz; i < lenght - 1; i++)
		elements[i] = elements[i + 1];
	lenght--;
}

template<typename ElementType>
void VectorDin<ElementType>::pop_back()
{
	if (lenght > 0)
		lenght = lenght - 1;
}
template<typename ElementType>
int VectorDin<ElementType>::size()
{
	return lenght;
}
template<typename ElementType>
ElementType& VectorDin<ElementType>::get(int poz)
{
	return elements[poz];
}








template<typename ElementType>
class IteratorVectorT
{
private:
	const VectorDin<ElementType>& v;
	int poz = 0;
public:
	//IteratorVectorT(const Vector<ElementType>& vector) :vector{ vector } {}
	IteratorVectorT(const VectorDin<ElementType>& v) noexcept;
	IteratorVectorT(const VectorDin<ElementType>& v, int poz) noexcept;
	bool valid() const;
	void next();
	ElementType& element() const;
	ElementType& operator*() const;
	IteratorVectorT& operator++();
	bool operator==(const IteratorVectorT& ot) noexcept;
	bool operator!=(const IteratorVectorT& ot) noexcept;
};

template<typename ElementType>
IteratorVectorT<ElementType>::IteratorVectorT(const VectorDin<ElementType>& v) noexcept
	:v{ v }
{
}

template<typename ElementType>
IteratorVectorT<ElementType>::IteratorVectorT(const VectorDin<ElementType>& v, int poz) noexcept
	:v{ v }, poz{ poz }
{
}

template<typename ElementType>
bool IteratorVectorT<ElementType>::valid() const
{
	return poz < v.lenght;
}

template<typename ElementType>
void IteratorVectorT<ElementType>::next()
{
	if (valid())
		poz++;
}

template<typename ElementType>
ElementType& IteratorVectorT<ElementType>::element() const
{
	return v.elements[poz];
}

template<typename ElementType>
ElementType& IteratorVectorT<ElementType>::operator*() const
{
	return element();
}

template<typename ElementType>
IteratorVectorT<ElementType>& IteratorVectorT<ElementType>::operator++()
{
	next();
	return *this;
}

template<typename ElementType>
bool IteratorVectorT<ElementType>::operator==(const IteratorVectorT& ot) noexcept
{
	return poz == ot.poz;
}

template<typename ElementType>
bool IteratorVectorT<ElementType>::operator!=(const IteratorVectorT& ot) noexcept
{
	return !(*this == ot);
}

template<typename ElementType>
IteratorVectorT<ElementType> VectorDin<ElementType>::begin()
{
	return IteratorVectorT<ElementType>(*this);
}

template<typename ElementType>
IteratorVectorT<ElementType> VectorDin<ElementType>::end()
{
	return IteratorVectorT<ElementType>(*this, lenght);
}





void test_vector(); 
