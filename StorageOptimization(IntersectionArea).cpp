/*The local library is considering making their bookshelves more efficient by implementing a new flexible shelf system. The new shelves consist of rearrangeable dividers (both vertically and horizontally), with the smallest blocks being a cube of 1 foot by 1 foot by 1 foot.

Given a shelf configuration, calculate the volume of the largest space in the shelf.

n = number of horizontal dividers

m = number of vertical dividers

h = a list of numbers representing the horizontal dividers that are missing

v = a list of numbers representing the vertical dividers that are missing

Example 1:
Input:
n = 6 m = 6 h = [4] v = [2]

Output: 4*/

//https://aonecode.com/oa-storage-optimization//

//JAVA
public long storageOptimization(int h, int v, int[] hc, int[] vc) {
		// track all missing elements
		boolean[] hc_missing = new boolean[h];
		boolean[] vc_missing = new boolean[v];
		
		// mark all elements which are missing in given array
		for(int cut : hc) hc_missing[cut - 1] = true;
		for(int cut : vc) vc_missing[cut - 1] = true;
		
		// calculate horizontal max missing length
		int h_max = 0;
		for(int i = 0, j = 0; i < h; i++) {
			if(!hc_missing[i]) j = 0;
			else {
				j++;
				h_max = Math.max(h_max, j);
			}
		}
		
		// calculate vertical max missing length
		int v_max = 0;
		for(int i = 0, j = 0; i < v; i++) {
			if(!vc_missing[i]) j = 0;
			else {
				j++;
				v_max = Math.max(v_max, j);
			}
		}
		
		// since it could be a large number get the mod 10e7
		return (long) (((h_max + 1 ) * (v_max +1)) % 1000000007);
		
	}

//C++
//Will add shortly
