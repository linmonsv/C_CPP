#include <iostream>
#include <vector>
#include <iterator>

#include <list>

using namespace std;

template< class it >
void
function( it i1, it i2 )
{
   iterator_traits<it>::iterator_category cat;
   cout << typeid( cat ).name( ) << endl;
   while ( i1 != i2 )
   {
      iterator_traits<it>::value_type x;
      x = *i1;
      cout << x << " ";
      i1++;
   };
   cout << endl;
};

template <typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
  typename std::iterator_traits<IteratorType>::value_type temp;
  temp = *it;
  cout << temp << endl;
}

int main()
{
	std::vector<int> v(5, 5);
  iteratorTraitsTest(cbegin(v));

  vector<char> vc( 10,'a' );
  list<int> li( 10 );
  function( vc.begin( ), vc.end( ) );
  function( li.begin( ), li.end( ) );

	return 0;
}
