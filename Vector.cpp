#include <iostream>

using namespace std;


template <typename dataType>
class Vector
{
private:
int vSize;
int vCapacity;
dataType * data;

public:

Vector(int initCapacity = 0) : vSize(0) , vCapacity(initCapacity)
{
data = new dataType[vCapacity];
}

~Vector()
{
delete [] data;
}


void reserve (int newCapacity)
{
dataType * oldData = data;
data = new dataType[newCapacity];

for (int i = 0 ; i < vSize ; i++)
{
data[i] = oldData[i]; //copying the data from the old to the new vector
}
vCapacity = newCapacity;
delete [] oldData;
}



void push(dataType x){

if (vSize == vCapacity)
{
reserve(vCapacity *2 + 1);
}
data[vSize++] = x;

}
void del() {vSize--;}
dataType pop() {return data[--vSize];}

void display()
{
cout << "<vector>: " ;
for (int i = 0 ; i < vSize ; i++)
{
cout << data[i] << " ";
}
cout << endl;
}

void vdisplay()
{
cout << "Capacity: " << vCapacity << endl;
cout << "Size: " << vSize << endl;
cout << "<vector>: " ;
for (int i = 0 ; i < vSize ; i++)
{
cout << data[i] << " ";
}
cout << endl;
}

void adisplay()
{
cout << "<vector_addr>: " ;
for (int i = 0 ; i < vSize ; i++)
{
cout << &data[i] << " ";
}
cout << endl;
}

int size(){return vSize;} int capacity(){return vCapacity;} 

bool empty()
{
return (vSize == 0);
}

bool full()
{
return (vSize == vCapacity);
}


void shrink()
{
if (vCapacity > vSize)
{
reserve(vSize);
}
}

void flush()
{
int counter = vSize;
for (int i = 0 ; i < counter ; i ++ )
{
del();
}
shrink();
}


dataType operator [] (int index)
{
if (!(index<0) && !(index >= vSize))
{
return data[index];
}
}

dataType * begin()
{
return data;
}

dataType * last()
{

return data+vSize-1;
}
dataType * end()
{
return data + vSize;
}


};


int main ()
{


Vector<int> v1;


v1.push(7);
v1.push(28);
v1.push(141);

v1.vdisplay();
v1.adisplay();

v1.flush();

v1.push(27);
v1.push(96);
v1.push(163);
v1.push(58);
v1.push(72);

v1.vdisplay();

v1.flush();
v1.vdisplay();
 



return 0;
}