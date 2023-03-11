// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
You have C pieces of strawberry candy.


You are in charge of some kids. L of them love strawberries, and the remaining D of them don't care about strawberries. (The total number of kids is therefore L + D.)


You have decided to distribute as many candies as possible among the kids.
You want to do it according to the following rules:


Each kid must get at least 1 piece of candy.
Each kid must get at most 100,000 pieces of candy.
Each kid that loves strawberries must get the same number of candies.
Each kid that does not care about strawberries must get the same number of candies.
If there are kids of both types (i.e., if both L and D are positive) a kid that loves strawberries must get strictly more candies than a kid that does not care about them.


If your goal cannot be achieved at all (there is no valid way to distribute candies), return -1.
Otherwise, return the smallest possible number of candies left over (i.e., not given to any child).


DEFINITION
Class:DividingCandy
Method:divide
Parameters:long, long, long
Returns:long
Method signature:long divide(long C, long L, long D)


CONSTRAINTS
-C will be between 1 and 10^12, inclusive.
-L will be between 0 and 10^12, inclusive.
-D will be between 0 and 10^12, inclusive.
-L+D will not be zero.


EXAMPLES

0)
80
10
10

Returns: 0


You have 80 strawberry candies. There are 10 kids who love strawberries and 10 kids who don't care about them.


One optimal solution is to give each of the first 10 kids 5 candies and to give each of the other 10 kids 3 candies. This way you have handed out all the candies and you have none left.


1)
27
20
10

Returns: -1

Remember that each kid must get at least one piece of candy.

2)
1234
15
55

Returns: 4

Here it's not possible to hand out all the candies, and it's quite easy to show that you will always have at least 4 candies left over.

3)
1
1
0

Returns: 0

The only child gets the only piece of candy. (This particular child loves strawberries, but that does not really matter here.)

4)
9876543210
0
2

Returns: 9876343210

Remember that each kid can only get up to 100,000 candies. Here the best you can do is to give each kid exactly 100,000 of your candies. You will still have quite many candies left over.

5)
1234567
2323
4747

Returns: 44



6)
200001
1
1

Returns: 2

The best you can do here is to give 100,000 candies to the kid who loves strawberries and 99,999 candies to the kid who doesn't. 

// END CUT HERE
import java.util.*;
public class DividingCandy {
	public long divide(long C, long L, long D) {
		
	}
	public static void main(String[] args) {
		DividingCandy temp = new DividingCandy();
		System.out.println(temp.divide(long C, long L, long D));
	}
}
