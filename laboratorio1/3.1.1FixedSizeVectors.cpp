#include <iostream>

int gVect[100]; // Buffer to save the elements
int gnCount; // Counter to know the number of elements used

void Insert(int elem)
{
  if( gnCount < 100 ) // we can only insert if there is space
    gVect[gnCount++] = elem; // Insert the element at the end
}

int main(){
  gnCount = 0;
  for(int i = 0; i < 101; i++) { // para ver que no inserta el utimo
    Insert(i);
  }

  for(int *i = gVect; i < gVect + 100; i++){
    std::cout << *i << " ";
  }
  return 0;
}