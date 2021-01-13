#include<math.h>

mmap_1(int *x, int *y, int chama_sprite, int *velocidade)
{
    if(*x < 0)
        *x=779;
    else if(*y<0)
        *y=533;

    ///SONS
    SAMPLE* Som_Flecha = load_sample("sons\\flecha.wav");

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *terseu = load_bitmap("Personagens/terseu.bmp",NULL);
    BITMAP *fantasma = load_bitmap("Personagens/fantasma.bmp",NULL);
    BITMAP *fase = load_bitmap("Map/mapa-1.bmp",NULL);
    BITMAP *tiro = load_bitmap("imgs\\FirePower.bmp", NULL);
    BITMAP *game_over = load_bitmap("imgs\\game_over.bmp", NULL);

    int mapa[20][25] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    ///Variáveis
    int pon_x;
    int pon_y;
    int tile;
    int h = 0; //define a altura inicial
    int l = 0; //define a largura inicial
    int h_vilao = 0;
    int l_vilao = 0;
    int procura_posicao_x, procura_posicao_y;
    int base_x, base_y;
    int x_vilao = 124, y_vilao = 424;
    int velocidade_do_tiro_terseu = 10;
    int y_tiro, x_tiro;
    int testa_tiro_terseu = 0;
    int teste_movimento = 0;
    int vida_do_inimigo = 5;
    int vida_do_terseu = 10;
    int aux_tiro = 0;
    int x_tiro_inimigo, y_tiro_inimigo;
    int velocidade_do_tiro_mino = 2;
    int testa_tiro_mino = 0;
    int acertou_terseu = 0;
    int acertou_mino = 0;
    int chama_sprite_vilao=0;
    int dist_x, dist_y;


    set_color_blender(0,0,0, makecol(60, 200, 10));
    *velocidade = 10;


    ///GAME LOOP
    while((!(key[KEY_ESC]))&&vida_do_terseu)
    {
        ///Imprime as cordenadas que o herói se encontra
        //textprintf_ex( screen, font, 10, 10, makecol(250,250,250), -1, "Variavel X: %d", *x);
        //textprintf_ex( screen, font, 10, 20, makecol(250,250,250), -1, "Variavel Y: %d", *y);

        draw_sprite (buffer, fase, 0, 0);
        view(buffer, vida_do_inimigo, vida_do_terseu);
        relogio(buffer);
        masked_blit(terseu, buffer, h, l, *x, *y, 32, 32);

        //Movimentação
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
            tile = mapa[*y/32][*x/32];
            colisao_paredes(x, y, pon_x, pon_y, tile);
        }
        pon_x = *x;
        pon_y = *y;

        // ############## - Tiro do Terseu - ####################
        if(key[KEY_SPACE])
        {
            if(key[KEY_SPACE] != 0)
                play_sample(Som_Flecha, 255, 128, 1000, FALSE);
            x_tiro = *x;
            y_tiro = *y;
            testa_tiro_terseu = 1;
            base_x = *x;
            base_y = *y+15;
            procura_posicao_x = x_vilao;
            procura_posicao_y = y_vilao;
            dist_x=abs(procura_posicao_x-base_x);
            dist_y=abs(procura_posicao_y-base_y);
        }
        if ( testa_tiro_terseu == 1 )
        {
            draw_sprite(buffer, tiro, x_tiro, y_tiro);
            percurso(&x_tiro, &y_tiro, procura_posicao_x, procura_posicao_y, dist_x, dist_y);

            if ( acertou_mino == 1 )
            {
                vida_do_inimigo--;

                testa_tiro_terseu = 0;
                acertou_mino = 0;
            }
        }
// ########## - Testa se atingiu o Inimigo - ##############
        if ( abs(y_tiro - y_vilao)<=5)
        {
            if ( abs(x_tiro - x_vilao)<=5)
                acertou_mino = 1;
        }
        else if(abs(y_tiro - procura_posicao_y)<10 && abs(x_tiro - procura_posicao_x)<10)
        {
            testa_tiro_terseu = 0;
            acertou_mino = 0;
        }

// ########## - Testa vida do Inimigo - ##############

        if(vida_do_inimigo>0)
        {
            masked_blit(fantasma, buffer, h_vilao, l_vilao, x_vilao, y_vilao, 32, 32);

            //Perseguição
            //if (pon_x < 404 && pon_y < 475 && pon_y > 365)
            {
                x_vilao = busca_eixo_x(pon_x, x_vilao);
                y_vilao = busca_eixo_y(pon_y, y_vilao);

                if(x_vilao < *x )
                {
                    if(chama_sprite_vilao==0)
                    {
                        h_vilao = 0;
                        l_vilao = 64;
                    }
                    else if(chama_sprite_vilao==1)
                    {
                        h_vilao = 32;
                        l_vilao = 64;
                    }
                    else
                    {
                        h_vilao = 64;
                        l_vilao = 64;
                        chama_sprite_vilao=-1;
                    }
                    chama_sprite_vilao++;
                }
                else
                {
                    if(chama_sprite_vilao==0)
                    {
                        h_vilao = 0;
                        l_vilao = 32;
                    }
                    else if(chama_sprite_vilao==1)
                    {
                        h_vilao = 32;
                        l_vilao = 32;
                    }
                    else
                    {
                        h_vilao = 64;
                        l_vilao = 32;
                        chama_sprite_vilao=-1;
                    }
                    chama_sprite_vilao++;
                }
                if(y_vilao < *y)
                {
                    if(chama_sprite_vilao==0)
                    {
                        h_vilao = 0;
                        l_vilao = 0;
                    }
                    else if(chama_sprite_vilao==1)
                    {
                        h_vilao = 32;
                        l_vilao = 0;
                    }
                    else
                    {
                        h_vilao = 64;
                        l_vilao = 0;
                        chama_sprite_vilao=-1;
                    }
                    chama_sprite_vilao++;
                }
                else
                {
                    if(chama_sprite_vilao==0)
                    {
                        h_vilao = 0;
                        l_vilao = 96;
                    }
                    else if(chama_sprite_vilao==1)
                    {
                        h_vilao = 32;
                        l_vilao = 96;
                    }
                    else
                    {
                        h_vilao = 64;
                        l_vilao = 96;
                        chama_sprite_vilao=-1;
                    }
                    chama_sprite_vilao++;
                }
            }
        }

// ########## - Testa se atingiu o Terseu - ##############
        if ( abs(*y - y_vilao)<2)
        {
            if ( abs(*x - x_vilao)<2)
                vida_do_terseu--;
        }


// ########################################################
        draw_sprite(screen, buffer, 0, 0);
        clear_to_color(buffer, makecol(255,255,255));




        if(*x > 780)
        {
            mmap_2(x, y, chama_sprite, velocidade);
            destroy_bitmap(buffer);
            destroy_bitmap(fase);
            destroy_bitmap(terseu);
            return 0;
        }

        else if(*y>533)
        {
            mmap_5(x, y, chama_sprite, velocidade);
            destroy_bitmap(buffer);
            destroy_bitmap(fase);
            destroy_bitmap(terseu);
            return 0;
        }
    }
    clear_bitmap(buffer);
    if (  vida_do_terseu <= 0)
    {
        draw_sprite(buffer, game_over, 0, 0);
        readkey();
    }
    draw_sprite(screen, buffer, 0, 0);
    rest(4000);

    ///FINALIZAÇÂO
    destroy_bitmap(buffer);
    destroy_bitmap(fase);
    destroy_bitmap(terseu);

    mmenu();

    return 0;
}
END_OF_FUNCTION(mmap_1);
