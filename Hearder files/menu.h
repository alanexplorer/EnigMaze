mmenu()
{
    ///SONS
    MIDI* musica = load_midi("sons/title.mid");


    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *cursor = load_bitmap("imgs/cursor.bmp",NULL);
    BITMAP *fase = load_bitmap("Map/menu.bmp",NULL);

    ///Variáveis
    int x_cursor = 280, y_cursor = 255;
    int tile;
    int h = 0; //define a altura inicial
    int l = 0; //define a largura inicial
    int modo = DRAW_SPRITE_NORMAL;
    set_color_blender(0,0,0, makecol(60, 200, 10));
    int cont = 0;
    int m = 1;
    int chama_sprite=0;
    int x = 382, y = 421, velocidade = 3; ///POSIÇÃO INICIAL DO HEROI E VELOCIDADE

    play_midi(musica, TRUE);
        set_volume(255,255);

    ///GAME LOOP
    while(1)
    {

        draw_sprite (buffer, fase, 0, 0);
        masked_blit(cursor, buffer, h, l, x_cursor, y_cursor, 32, 32);
        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));

        readkey();
        if(key[KEY_ENTER] && cont==0)
        {
            castelo_fora(&x, &y, 0, &velocidade, &m);
            break;
        }

        else if(key[KEY_ENTER] && cont==1)
        {
            ccreditos(1);
            break;
        }
        else if(key[KEY_ENTER] && cont==2)
        {
            break;
        }

        //Movimentação
        if(key[KEY_UP])
        {
            if(cont == 0)
            {
                y_cursor = 475;
                cont = 2;

            }
            else if(cont == 1)
            {
                y_cursor = 255;
                cont = 0;

            }
            else
            {
                y_cursor = 365;
                cont = 1;

            }
            draw_sprite (buffer, fase, 0, 0);
            masked_blit(cursor, buffer, h, l, x_cursor, y_cursor, 32, 32);


        }

        if(key[KEY_DOWN])
        {
            if(cont == 0)
            {
                y_cursor = 365;
                cont = 1;

            }
            else if(cont == 1)
            {
                y_cursor = 475;
                cont = 2;
            }
            else
            {
                y_cursor = 255;
                cont = 0;

            }
            draw_sprite (buffer, fase, 0, 0);
            masked_blit(cursor, buffer, h, l, x_cursor, y_cursor, 32, 32);
        }
    }

    ///FINALIZAÇÂO
    destroy_bitmap(buffer);
    destroy_bitmap(fase);
    destroy_bitmap(cursor);
    destroy_midi(musica);

    return 0;
}
END_OF_FUNCTION(mmenu);
