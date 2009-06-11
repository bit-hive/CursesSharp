#include <curses.h>

/*
  Name:								window

  Synopsis:
	WINDOW *newwin(int nlines, int ncols, int begy, int begx);
  	WINDOW *derwin(WINDOW* orig, int nlines, int ncols,
		int begy, int begx);
	WINDOW *subwin(WINDOW* orig, int nlines, int ncols,
		int begy, int begx);
	WINDOW *dupwin(WINDOW *win);
	int delwin(WINDOW *win);
	int mvwin(WINDOW *win, int y, int x);
	int mvderwin(WINDOW *win, int pary, int parx);
	int syncok(WINDOW *win, bool bf);
	void wsyncup(WINDOW *win);
	void wcursyncup(WINDOW *win);
	void wsyncdown(WINDOW *win);

  Return Value:
	newwin(), subwin(), derwin() and dupwin() return a pointer
	to the new window, or NULL on failure. delwin(), mvwin(),
	mvderwin() and syncok() return OK or ERR. wsyncup(),
	wcursyncup() and wsyncdown() return nothing.

  Errors:
	It is an error to call resize_window() before calling initscr().
	Also, an error will be generated if we fail to create a newly
	sized replacement window for curscr, or stdscr. This could
	happen when increasing the window size. NOTE: If this happens,
	the previously successfully allocated windows are left alone;
	i.e., the resize is NOT cancelled for those windows.

  Portability				     X/Open    BSD    SYS V
	newwin					Y	Y	Y
	delwin					Y	Y	Y
	mvwin					Y	Y	Y
	subwin					Y	Y	Y
	derwin					Y	-	Y
	mvderwin				Y	-	Y
	dupwin					Y	-      4.0
	wsyncup					Y	-      4.0
	syncok					Y	-      4.0
	wcursyncup				Y	-      4.0
	wsyncdown				Y	-      4.0
	resize_window				-	-	-
	wresize					-	-	-
	PDC_makelines				-	-	-
	PDC_makenew				-	-	-
	PDC_sync				-	-	-
*/

WINDOW *
wrap_newwin(int nlines, int ncols, int begy, int begx)
{
	return newwin(nlines, ncols, begy, begx);
}

WINDOW *
wrap_derwin(WINDOW* orig, int nlines, int ncols, int begy, int begx)
{
	return derwin(orig, nlines, ncols, begy, begx);
}

WINDOW *
wrap_subwin(WINDOW* orig, int nlines, int ncols, int begy, int begx)
{
	return subwin(orig, nlines, ncols, begy, begx);
}

WINDOW *
wrap_dupwin(WINDOW *win)
{
	return dupwin(win);
}

int 
wrap_delwin(WINDOW *win)
{
	return delwin(win);
}

int 
wrap_mvwin(WINDOW *win, int y, int x)
{
	return mvwin(win, y, x);
}

int 
wrap_mvderwin(WINDOW *win, int pary, int parx)
{
	return mvderwin(win, pary, parx);
}

int 
wrap_syncok(WINDOW *win, int bf)
{
	return syncok(win, bf);
}

void 
wrap_wsyncup(WINDOW *win)
{
	wsyncup(win);
}

void 
wrap_wcursyncup(WINDOW *win)
{
	wcursyncup(win);
}

void 
wrap_wsyncdown(WINDOW *win)
{
	wsyncdown(win);
}
