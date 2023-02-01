class Solution {
public:
	int findLUSlength(string a, string b) {

		if (a == b) return -1;

		return max(a.size(), b.size());
	}
};

/*
* 
uncommon subsequence means that it is not common sub string between given two strings
ex)ab, bcd

subsequence of ab
a, b, ab

subsequence of bcd
b, c, d, bc, bd, cd, bcd

compare two subsequence
a		b->uncommon subsequence 1 (a or b)
b		c->uncommon subsequence 1 (b or c)
ab		d->uncommon subsequence 2 (ab)
bc->uncommon subsequence 2 (bc)
bd->uncommon subsequence 2 (bd)
cd->uncommon subsequence 2 (bd)
bcd->uncommon subsequence 3 (bcd)

the largest uncommon subsequence is 3.

*/