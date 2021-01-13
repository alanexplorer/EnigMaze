int busca_eixo_x (int x_heroi, int x_vilao)
{
    if (x_vilao > x_heroi)
    {
        x_vilao-=2;
    }
    else if (x_vilao < x_heroi)
    {
        x_vilao+=2;
    }

    return x_vilao;
}
