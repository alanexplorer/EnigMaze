int busca_eixo_y (int y_heroi, int y_vilao)
{
    if (y_vilao > y_heroi)
    {
        y_vilao-=2;
    }
    else if (y_vilao < y_heroi)
    {
        y_vilao+=2;
    }

    return y_vilao;
}
