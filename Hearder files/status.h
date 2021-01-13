int view(BITMAP* buffer, int *vida_do_inimigo, int *vida_do_terseu)
{
    char enemy_life[40];
    char my_life[40];

    BITMAP *barra = load_bitmap("imgs/notificacoes.bmp",NULL);
    draw_sprite(buffer, barra, 0, 0);
    destroy_bitmap(barra);

// ############################################################################
        sprintf(my_life,"Terseu Life: 10",vida_do_terseu);
        textout_centre_ex(buffer,font,my_life,70,620,makecol(255,0,0), -1);
// #############################################################################

}
END_OF_FUNCTION(view);
