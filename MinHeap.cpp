#include <iostream>
#include <climits>

using namespace std;
void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
class Minheap
{
	int *harr;
	int capacity; 
	int heap_size;

public:
	int parent(int i){	return (i - 1) / 2; }
	int left(int i)  {	return 2 * i + 1;   }
	int right(int i) {  return 2 * i + 2;   }
	int getMin()     {	return harr[0]; }
	
	int extractMin();

	void decreaseKey(int i, int new_val);
	void Minheapify(int i);

	void deleteKey(int i);
	void insertKey(int i);

	Minheap(int capacity);
	
};
Minheap::Minheap(int cap) // v ok
{
	heap_size = 0;
	capacity = cap;
	harr = new int[capacity];
}
void Minheap::Minheapify(int i)// v ok 
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if( l < heap_size && harr[l] < harr[i])
		smallest = l;

	if( r < heap_size && harr[r] < harr[smallest])
		smallest = r;

	if( smallest != i)
	{
		Swap(&harr[i], &harr[smallest]);
		Minheapify(smallest);
	}
}
void Minheap::decreaseKey(int i, int new_val)//v ok 
{
	harr[i] = new_val;
	while( i != 0 && harr[parent(i)] > harr[i])
	{
		Swap(&harr[parent(i)], &harr[i]);
		i = parent(i);
	}
}
int Minheap::extractMin() ///  ok 
{
	if( heap_size <= 0)
		return INT_MAX;

	if( heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	Minheapify(0);

	return root;
	
	
}
void Minheap::deleteKey(int i) // ok 
{
	decreaseKey(i, INT_MIN);
	extractMin();
}
void Minheap::insertKey(int k) //v ok
{
	if(heap_size == capacity)
	{
		cout<<"False ! Overflow !\n";
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	
	while( i != 0 && harr[parent(i)] > harr[i] )
	{
		Swap(&harr[parent(i)], &harr[i]);
		i = parent(i);		
	}
}
int main()
{
	Minheap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout<<h.extractMin() <<" , "<<h.getMin()<<" , ";
	h.decreaseKey(2, 1);
	cout<<h.getMin()<<"\n";

	return 0;
}