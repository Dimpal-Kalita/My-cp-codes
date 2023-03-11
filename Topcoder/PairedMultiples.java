// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a set of distinct positive integer values in the int[] values, and another value, int multiple.



A set of numbers is called nice if each element x of the set has the following property: in the set we can find a different element y such that the sum of x and y is divisible by multiple.

For example, if multiple = 10, the set {1, 9, 19, 29} is nice: for each element x we can find another element y such that x+y is a multiple of 10. However, the set {23, 25, 27} is not nice - note that we cannot pair the 25 with itself.



Find the largest nice subset of values. Return the sum of its elements.

DEFINITION
Class:PairedMultiples
Method:selectedTotal
Parameters:int[], int
Returns:int
Method signature:int selectedTotal(int[] values, int multiple)


NOTES
-It can be shown that the largest nice subset of values is always unique.


CONSTRAINTS
-multiple will be between 2 and 100, inclusive.
-values will contain between 2 and 50 elements, inclusive.
-Each element of values will be between 1 and 100, inclusive.
-Each element of values will be unique.


EXAMPLES

0)
{ 1, 2, 3, 4, 5 }
3

Returns: 12


The entire set {1, 2, 3, 4, 5} is not nice because the value 3 cannot be added to any of the other values to have a sum that is divisible by 3.


We can easily verify that the subset {1, 2, 4, 5} is a nice set.
This is the largest nice subset of values.
The sum of its elements is 1 + 2 + 4 + 5 = 12.


1)
{ 1, 2, 3, 4 }
2

Returns: 10

The entire set is nice.

2)
{ 1, 2, 3, 6, 10 }
10

Returns: 0

There's no way to make a pair adding up to something divisible by 10, so in this case the only nice subset of the given values is the empty set. The sum of its elements is zero.

3)
{1, 9, 19, 29}
10

Returns: 58

The example from the problem statement. This entire set is nice.

4)
{15, 25, 47}
10

Returns: 40

The largest nice subset of this set is {15, 25}.

// END CUT HERE
import java.util.*;
public class PairedMultiples {
	public int selectedTotal(int[] values, int multiple) {
		
	}
	public static void main(String[] args) {
		PairedMultiples temp = new PairedMultiples();
		System.out.println(temp.selectedTotal(int[] values, int multiple));
	}
}
