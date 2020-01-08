// Exercise 22 from Chapter 1 of C programming
// File 1ex22.c


//This program 'folds' long input lines into two or more shorter lines
//after the last nonblank character that occurs before the n-th column
// of input.

#include <stdio.h>

#define		MAXCOL		10			/* maximum column of input	*/
#define		TABINC		8			/* tab increment size		*/

char line[MAXCOL];					/* input lines 				*/

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);

/* fold long input lines into two or more shorter lines */

int main()
{
	int c, pos;

	pos = 0;						/* position in the line 	*/
	while ((c = getchar()) != EOF) {
		line[pos] = c; 				/* store current character  */
		if (c == '\t')				/* expand tab character		*/
			pos = exptab(pos);
		else if (c == '\n') {
			prils(pos); 			/* print current input line */
			pos = 0;
		} else if (++pos >= MAXCOL) {
			pos = findblnk(pos);
			prils(pos);
			pos = newpos(pos);
		}
	}
} 

/* prils* print line until pos column 							*/
void prls(int pos)
{
	int i;

	for (i = 0; i < pos; ++i)
		putchar(line[i]);
	if (pos > 0) 					/* any chars printed ? 		*/
		putchar('\n');
}

/* exptab: expand tab into blanks 								*/
int exptab(int pos)
{
	line[pos] = ' '; 				/* tab is at least one blank */
	for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
		line[pos] = ' ';
	if (pos < MAXCOL) 				/* room left in current line */
		return pos;
	else {
		prils(pos);
		return 0; 					/* reset current position    */

	}
}

/* findblnk: find blank's position 								 */
int findblnk(int pos)
{
	while (pos > 0 && line[pos] != ' ')
		--pos;
	if (pos == 0)					/* no blanks in the line ? 	*/
		return MAXCOL;
	else							/* at least one blank 		*/
		return pos+1; 				/* position after the blank */

}

/* newpos: rearrange line with new position 					*/
int newpos(int pos)
{
	int i, j;

	if (pos <= 0 || pos >= MAXCOL)
		return 0; 					/* nothing to rearrange 	*/
	else {
		i = 0;
		for (j = pos; j < MAXCOL; ++j) {
			line[i] = line[j];
			++i;
		}
		return i; 					/* new position in line 	*/
	}
}