#include <iostream>

// Class CVector definition
class CVector
{
  private:
    int *m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax,   // Control how many are allocated as maximum
        m_nDelta; // To control the growing

    void Init(int delta); // Init our private variables, etc
    void Resize(); 
  public:
    CVector(int delta = 10); // Constructor
    void Insert(int elem); // Insert a new element
    void Print();
    // More methods go here
};


void CVector::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = (int *)malloc(m_nMax*sizeof(int));
}

CVector::CVector(int delta)
{
    Init(delta);
}

void CVector::Resize()
{
  m_pVect = (int *)realloc(m_pVect, sizeof(int) *
  (m_nMax + m_nDelta));
  // The Max has to be increased by delta
  m_nMax += m_nDelta;
}

void CVector::Insert(int elem)
{
  if( m_nCount == m_nMax ) // Verify the overflow
  Resize(); // Resize the vector before inserting elem
  m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Print()
{
  for(int *i = m_pVect; i < m_pVect + m_nCount; i++){
    std::cout << *i << " ";
  }
}

int main(){
  CVector v;

  for(int i = 0; i < 20; i++){
    v.Insert(i);
  }

  v.Print();
  
  return 0;
}

