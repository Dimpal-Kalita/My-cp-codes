// BEGIN CUT HERE
// PROBLEM STATEMENT
// This week the ICPC finals are taking place in Dhaka, Bangladesh. We send them our greetings by theming some of the problems in this SRM.

There is a large banner hanging in the entrance hall of a hotel.
Individual letters can be attached to the banner.
Each letter is printed on an A4 sheet of paper.


Currently, there is one word on the banner. This word is given in the String banner. The letters of this word are next to each other, with no spaces between them. There is plenty of room on the banner, both to the left and to the right of these letters.



We want to change the banner to contain exactly the word "DHAKA" and nothing else. There can be spaces between the letters of this word. These spaces can be arbitrarily large (non-integer multiples of a letter size are allowed) but within the word the spaces between adjacent letters must all be the same. 


Each change to the banner requires the use of a ladder, so it's pretty slow. In each change you can either remove a single letter from the banner, or add a new letter anywhere onto the banner. The new letter cannot overlap any other letter that is currently on the banner.


Calculate and return the minimum number of changes needed.


DEFINITION
Class:DhakaBanner
Method:edit
Parameters:String
Returns:int
Method signature:int edit(String banner)


CONSTRAINTS
-banner will contain between 1 and 2,500 characters, inclusive.
-Each character in banner will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"DHAKA"

Returns: 0

We can just reuse the banner as is.

1)
"WELCOMETODHAKABANGLADESH"

Returns: 19

The best solution is to remove the extra letters and keep the "DHAKA".

2)
"DDHHAAKKAA"

Returns: 5

Remove every second letter and keep "D.H.A.K.A.".

3)
"AA"

Returns: 5

You have to remove one of the 'A's and add four new letters. (There is no way to fit a 'K' between the two existing 'A's.)

4)
"ABBA"

Returns: 5


After removing the two 'B's you can place the 'K' halfway between the two 'A's, and then you can add a 'D' and 'H' to the left, keeping the same spacing you have in "AKA": half the width of a letter.


An approximate illustration of the input and final banner:



               +---+---+---+---+
               | A | B | B | A |
               +---+---+---+---+

   +---+ +---+ +---+ +---+ +---+
   | D | | H | | A | | K | | A |
   +---+ +---+ +---+ +---+ +---+


5)
"RIYADH"

Returns: 7

Reuse the "DH" from this old banner.

6)
"TOPCODER"

Returns: 11



// END CUT HERE
import java.util.*;
public class DhakaBanner {
	public int edit(String banner) {
		
	}
	public static void main(String[] args) {
		DhakaBanner temp = new DhakaBanner();
		System.out.println(temp.edit(String banner));
	}
}
