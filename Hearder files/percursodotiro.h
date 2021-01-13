void percurso(int *x, int *y, int procura_x, int procura_y, int dist_x, int dist_y)
{
    int y_aux = *y, x_aux = *x;
    if (y_aux < procura_y)
        y_aux += dist_y/10;
    else
        y_aux -= dist_y/10;
    if (x_aux < procura_x)
        x_aux += dist_x/10;
    else
        x_aux -= dist_x/10;

    *x = x_aux;
    *y = y_aux;
}

