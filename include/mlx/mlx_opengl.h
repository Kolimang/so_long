/*
**
** mlx_opengl.h 
**
** public include, use it after mlx.h
** designed only for minilibx_macos
**
*/

void    *mlx_new_opengl_window(void *mlx, int size_x, int size_y, char *title);

/* create an opengl window. put_image & pixel_put & string_put do not work there. */

int	mlx_opengl_swap_buffers(void *windw);

/* the created window is double buffered. Use this funct to swap buffers */
/* this funct will call glFlush(). Don't call it. */

int	mlx_opengl_window_set_context(void *windw);

/* in case multiple opengl windows are present, change opengl active context */
