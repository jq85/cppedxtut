/**

  $ g++ -g -o encapsulation .\encapsulation.cpp .\Rectangle2.cpp

Often considered the first pillar of object-oriented programming,
encapsulation can be used to describe the accessibility of the members belonging to a class.
C++ provides access modifiers and properties to help implement encapsulation in your classes.
While some consider this "accessibility configuration" to be the only aspect of encapsulation,
others also define encapsulation as the act of "including all data and behavior" required of the class,
"within the class definition".

We use encapsulation to prevent changing the member variables directly.
This is considered a poor practice because it presents the opportunity for potentially incorrect values to be assigned to these member variables.
This can result in unexpected behavior or more serious problems with your executing code.
It also helps with debugging of your code.

IMPLEMENTING BUSINESS LOGIC:
Remember.
If you're writing a banking system you had to say remember after you reduce anybody's balance also charge them a service charge,
and with encapsulation you can say I'm not going to let you get directly to balance,
I'll let you call "withdraw" function
and "withdraw" will charge the service charge;
Now whoever is working with the bank account doesn't have to remember to make that call.

Like for the Rectangle class with the resize function, which has made it impossible to change the width without the height.
*/
