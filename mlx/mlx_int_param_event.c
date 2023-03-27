/*
** mlx_int_data_event.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Wed Oct  6 13:14:52 2004 Olivier Crouzet
*/

#include	"mlx_int.h"

int	mlx_int_data_undef()
{
}

int	mlx_int_data_KeyPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
  win->hooks[KeyPress].hook(XkbKeycodeToKeysym(xvar->display,
					       ev->xkey.keycode, 0, 0),
			    win->hooks[KeyPress].data);
}

int	mlx_int_data_KeyRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
  win->hooks[KeyRelease].hook(XkbKeycodeToKeysym(xvar->display,
						 ev->xkey.keycode, 0, 0),
			      win->hooks[KeyRelease].data);
}

int	mlx_int_data_ButtonPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
  win->hooks[ButtonPress].hook(ev->xbutton.button,ev->xbutton.x,ev->xbutton.y,
			       win->hooks[ButtonPress].data);
}

int	mlx_int_data_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
  win->hooks[ButtonRelease].hook(ev->xbutton.button,
				 ev->xbutton.x, ev->xbutton.y,
				 win->hooks[ButtonRelease].data);
}

int	mlx_int_data_MotionNotify(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
  win->hooks[MotionNotify].hook(ev->xbutton.x,ev->xbutton.y,
				win->hooks[MotionNotify].data);
}

int	mlx_int_data_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
  if (!ev->xexpose.count)
    win->hooks[Expose].hook(win->hooks[Expose].data);
}


int	mlx_int_data_generic(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
  win->hooks[ev->type].hook(win->hooks[ev->type].data);
}

int	(*(mlx_int_data_event[]))() =
{
  mlx_int_data_undef,   /* 0 */
  mlx_int_data_undef,
  mlx_int_data_KeyPress,
  mlx_int_data_KeyRelease,  /* 3 */
  mlx_int_data_ButtonPress,
  mlx_int_data_ButtonRelease,
  mlx_int_data_MotionNotify,  /* 6 */
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_Expose,   /* 12 */
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic,
  mlx_int_data_generic
};
