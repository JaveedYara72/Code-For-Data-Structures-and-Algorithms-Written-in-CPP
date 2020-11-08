//<----------------------------------------------------------------->
// Given a String Replace all the occurences of the string "pi" with 3.14
// xpighpijklsmpi - x3.14gh3.14jklsm3.14
// Also, Remember that we have to shift characters as well
// Traverse the Entire Input Array, and array [p,i,x,c,d].
// Once you find p at i, shift all the elements of i+2 to to i+4.
// Obviously "i" would be at i+1. So keep traversing and shift elments by 2 spaces front

void replacePi(char a[], int i) {
	//base case
	if (a[i] == '\0' or a[i + 1] == '\0') { // Last Place in the array
		return;
	}

	// Look for Pi at the current Location
	if (a[i] == 'p' and a[i + 1] == 'i') {
		//shifting followed by replacement with 3.14
		int j = i + 2;

		//take j to the end of the array
		while (a[j] != '\0') {
			j++;
		}
		// DO the Shifting from  right to left
		while (j >= i + 2) {
			a[j + 2] = a[j]; // We are putting the elmenets of efg into two places after giving it space
			j-- ;
		}

		a[i] = '3';
		a[i + 1] = '.';
		a[i + 2] = '1';
		a[i + 3] = '4';
		replacePi(a, i + 4); // Calling it after 4 elements, Obviousllt because of new shifting of elements


		//Why should you take j to the end of the array?
		//suppose there is an array [a,b,c,p,i,e,f,g].
		// So shift efg to 2 more places, leave 4 place for the replacement of 3.14 -> [a,b,c,3,.,1,4,e,f,g]
		// This is why we take j to the end and give the alphabets new positions

	} else {
		//Go to the Next Posititon
		replacePi(a, i + 1);
	}
}

//<----------------------------------------------------------------->