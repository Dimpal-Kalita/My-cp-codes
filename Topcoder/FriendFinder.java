// BEGIN CUT HERE
// PROBLEM STATEMENT
// You and your friend are waiting in a line. A description of the line is given in the String line. The character 'S' represents yourself, the character 'F' represents your friend, and '.' indicates anyone else in the line.

How far apart are you and your friend in this line?

DEFINITION
Class:FriendFinder
Method:distance
Parameters:String
Returns:int
Method signature:int distance(String line)


CONSTRAINTS
-line will have between 2 and 50 characters, inclusive.
-Each character of line will be '.', 'S', or 'F'.
-'S' and 'F' will each appear exactly once in line.


EXAMPLES

0)
"....SF..."

Returns: 1

You and your friend are adjacent in this line, thus you are one position away from each other.

1)
"S........F"

Returns: 9

You and your friend are at completely opposite ends of this line.

2)
"..F...S.."

Returns: 4

You and your friend may appear in either order.

// END CUT HERE
import java.util.*;
public class FriendFinder {
	public int distance(String line) {
		
	}
	public static void main(String[] args) {
		FriendFinder temp = new FriendFinder();
		System.out.println(temp.distance(String line));
	}
}
