praia(int *x, int *y, int chama_sprite, int *velocidade, int *mostrar)
{
    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* terseu = load_bitmap("Personagens/terseu.bmp",NULL);
    BITMAP* ariadne = load_bitmap("Personagens/ariadne.bmp",NULL);
    BITMAP* dialogo = load_bitmap("imgs/dialogo.bmp",NULL);
    BITMAP* fase = load_bitmap("Map/praia.bmp",NULL);

    int mapa[20][25] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    ///Vari�veis
    int pon_x;
    int pon_y;
    int tile;
    int h = 0; //define a altura inicial
    int l = 0; //define a largura inicial
    int modo = DRAW_SPRITE_NORMAL;
    int x_vilao = 124, y_vilao = 424;
    int posicao = 9 * 128;
    set_color_blender(0,0,0, makecol(60, 200, 10));


    ///GAME LOOP
    while(!(key[KEY_ESC]))
    {
        ///Imprime as cordenadas que o her�i se encontra
        //textprintf_ex( screen, font, 10, 10, makecol(250,250,250), -1, "Variavel X: %d", *x);
        //textprintf_ex( screen, font, 10, 20, makecol(250,250,250), -1, "Variavel Y: %d", *y);

        draw_sprite (buffer, fase, 0, 0);

        masked_blit(ariadne, buffer, 0, 0, 600, 410, 32, 32);
        masked_blit(terseu, buffer, h, l, *x, *y, 32, 32);

        if (key[KEY_SPACE] && posicao < 13 * 128)
        {
            posicao += 128;
            rest(250);
        }

        masked_blit(dialogo, buffer, 0, posicao, 0, 510, 800, 128);

        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));

        //Persegui��o
        if (pon_x < 404 && pon_y < 475 && pon_y > 365)
        {
            x_vilao = busca_eixo_x(pon_x, x_vilao);
            y_vilao = busca_eixo_y(pon_y, y_vilao);
        }

        //Movimenta��o
        if(key[KEY_UP])
        {
            if (chama_sprite == 0)
            {
                h = 0;
                l = 96;
            }
            else if (chama_sprite == 1)
            {
                h = 32;
                l = 96;
            }
            else
            {
                h = 64;
                l = 96;
                chama_sprite = -1;

            }
            chama_sprite++;
            *y -= *velocidade;
            draw_sprite (buffer, fase, 0, 0);
            masked_blit(terseu, buffer, h, l, *x, *y, 32, 32);
            tile = mapa[*y/32][*x/32];
            colisao_paredes(x, y, pon_x, pon_y, tile);

        }

        if(key[KEY_DOWN])
        {
            if (chama_sprite == 0)
            {
                h = 0;
                l = 0;
            }
            else if (chama_sprite == 1)
            {
                h = 32;
                l = 0;
            }
            else
            {
                h = 64;
                l = 0;
                chama_sprite = -1;

            }
            chama_sprite++;
            *y += *velocidade;
            draw_sprite (buffer, fase, 0, 0);
            masked_blit(terseu, buffer, h, l, *x, *y, 32, 32);
            tile = mapa[*y/32][*x/32];
            colisao_paredes(x, y, pon_x, pon_y, tile);
        }

        if(key[KEY_LEFT])
        {
            if (chama_sprite == 0)
            {
                h = 0;
                l = 32;
            }
            else if (chama_sprite == 1)
            {
                h = 32;
                l = 32;
            }
            else
            {
                h = 64;
                l = 32;
                chama_sprite = -1;

            }
            chama_sprite++;
            *x -= *velocidade;
            draw_sprite (buffer, fase, 0, 0);
            masked_blit(terseu, buffer, h, l, *x, *y, 32, 32);
            tile = mapa[*y/32][*x/32];
            colisao_paredes(x, y, pon_x, pon_y, tile);
        }

        if(key[KEY_RIGHT])
        {
            if (chama_sprite == 0)
            {
                h = 0;
                l = 64;
            }
            else if (chama_sprite == 1)
            {
                h = 32;
                l = 64;
            }
            else
            {
                h = 64;
                l = 64;
                chama_sprite = -1;

            }
            chama_sprite++;
            *x += *velocidade;

            draw_sprite (buffer, fase, 0, 0);
            masked_blit(terseu, buffer, h, l, *x, *y, 32, 32);
            tile = mapa[*y/32][*x/32];
            colisao_paredes(x, y, pon_x, pon_y, tile);
        }
        pon_x = *x;
        pon_y = *y;

        if(*y < 0)
        {
            *y = 601;
            castelo_fora(x, y, chama_sprite, velocidade, mostrar);
            destroy_bitmap(buffer);
            destroy_bitmap(fase);
            destroy_bitmap(terseu);
            return 0;
        }

        else if(*y == 413 && *x >= 502 && *x <= 577)
        {
            *x = 34;
            *y = 32;
            *velocidade = 10;
            tempo();
            mmap_1(x, y, chama_sprite, velocidade);
            destroy_bitmap(buffer);
            destroy_bitmap(fase);
            destroy_bitmap(terseu);
            return 0;
        }

    }

    ///FINALIZA��O
    destroy_bitmap(buffer);
    destroy_bitmap(fase);
    destroy_bitmap(terseu);

    mmenu();

    return 0;
}
END_OF_FUNCTION(mmap_1);

