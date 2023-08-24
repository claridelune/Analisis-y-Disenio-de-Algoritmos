#include <iostream>

int *gpVect = NULL; // Dynamic buffer to save the elements 
int gnCount = 0; // Counter to know the number of used elements 
int gnMax = 0; // Variable containing the size of the allocated memory

void Resize(){ // no vi que mas abajo habia codigo pero es la misma idea
  gpVect = (int *)realloc(gpVect, (gnMax+5)*sizeof(int));
  gnMax += 5;
}

void Insert(int elem)
{
  if( gnCount == gnMax ) // There is no space at this moment for elem
    Resize(); // Resize the vector before inserting elem
    gpVect[gnCount++] = elem; // Insert the element at the end of the sequence
}

int main(){
  gnMax = 10;
  gpVect = (int *)malloc(gnMax*sizeof(int));
  for(int i = 0; i < 20; i++){
    Insert(i);
  }

  for(int *i = gpVect; i < gpVect + gnCount; i++){
    std::cout << *i << " ";
  }
}