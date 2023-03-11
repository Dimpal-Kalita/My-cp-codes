// BEGIN CUT HERE
// PROBLEM STATEMENT
// You have a bag filled with some number of red, blue and green marbles. You begin picking marbles randomly from the bag. What is the probability that the last marble you select is green?


DEFINITION
Class:MarbleBag
Method:getProbability
Parameters:int, int, int
Returns:double
Method signature:double getProbability(int red, int blue, int green)


CONSTRAINTS
-red will be between 0 and 100, inclusive.
-blue will be between 0 and 100, inclusive.
-green will be between 0 and 100, inclusive.
-There will be at least one marble in the bag.


EXAMPLES

0)
1
1
1

Returns: 0.3333333333333333

The last marble is equally likely to be any of the three, so there's a 1/3 chance it's green.

1)
0
0
100

Returns: 1.0

Since the bag only has green marbles, the last one is guaranteed to be green.

2)
3
4
5

Returns: 0.4166666666666667



// END CUT HERE
import java.util.*;
public class MarbleBag {
	public double getProbability(int red, int blue, int green) {
		
	}
	public static void main(String[] args) {
		MarbleBag temp = new MarbleBag();
		System.out.println(temp.getProbability(int red, int blue, int green));
	}
}
