#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mevsim,oda,ucrettipi,tekrar,sec;
    int hafta,misafirsayisi,c,sayac=1,secim, dongu=0;
    int i,j,oran1=0, odalar[36][100]= {0};
    float ucret;
    char yuzde='%';
    do
    {
        printf("\nHangi mevsimde konaklama yapmak istersiniz:\n  Bahar icin\t'B'\n  Yaz icin\t'Y'\n  Sonbahar icin\t'S'\nkodunu basiniz: ");
        scanf("%c",&mevsim);
        switch(mevsim)//mevsim bilgisi
        {
        case 'B'://mevsimlerde  bahar
        case 'b':
            printf("Baharin kacinci haftasinda konaklama yapilacagini giriniz:");
            scanf("%d",& hafta);
            if(hafta<1 || hafta>12)
            {
                do
                {
                    printf("Baharin kacinci haftasinda konaklama yapilacagini giriniz\t");
                    scanf("%d",& hafta);
                    sayac++;
                    if(hafta>=1 && hafta<=12)
                        break;
                    if(sayac==3)
                        return 0;
                }
                while(sayac!=3);
            }
            printf("-ODA TIPLERI-\n  Standart oda icin\t'S'\n  Deluxe oda icin\t'D'\n  Large Deluxe oda icin\t'L'\nkodunu giriniz: ");
            scanf(" %c",&oda);
            if(oda=='S'|| oda=='s')// standart odalar icin
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[hafta-1][i]==0)
                        {
                            if((i+1)%2==1)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar standart odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==0 || odalar[hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[hafta-1][secim-1]==0)
                        {
                            odalar[hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {

                    if (misafirsayisi>4)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[hafta-1][i]==0)
                                {
                                    if((i+1)%2==1)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==0 || odalar[hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[hafta-1][secim-1]==0)
                                {
                                    odalar[hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    misafirsayisi=misafirsayisi-4;
                    if(misafirsayisi<=4)
                        break;
                }
                while(misafirsayisi!=4);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*(c*40-(c*40*0.15));
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[j][i]==1)
                                oran1++;
                        }
                        printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    if(c>3)
                    {
                        ucret=7*(c*40-(40*0.5));
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[j][i]==1)
                                    oran1++;
                            }
                            printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        ucret=7*c*40;
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[j][i]==1)
                                    oran1++;
                            }
                            printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*c*40;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[j][i]==1)
                                oran1++;
                        }
                        printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            if(oda=='D'|| oda=='d')
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[hafta-1][i]==0)
                        {
                            if((i+1)%2==0 && (i+1)%6!=0)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar deluxe odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==1 || secim%6==0 || odalar[hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[hafta-1][secim-1]==0)
                        {
                            odalar[hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>4)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[hafta-1][i]==0)
                                {
                                    if((i+1)%2==0 && (i+1)%6!=0)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==1 && secim%6==0 || odalar[hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[hafta-1][secim-1]==0)
                                {
                                    odalar[hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    misafirsayisi=misafirsayisi-4;
                    if(misafirsayisi<=4)
                        break;
                }
                while(misafirsayisi!=4);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*(c*75-(c*75*0.15));
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[j][i]==1)
                                oran1++;
                        }
                        printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    if(c>3)
                    {
                        ucret=7*(c*75-(75*0.5));
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[j][i]==1)
                                    oran1++;
                            }
                            printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        ucret=7*c*75;
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[j][i]==1)
                                    oran1++;
                            }
                            printf("Baharin %d. haftası doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*c*75;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[j][i]==1)
                                oran1++;
                        }
                        printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            else if(oda=='L'|| oda=='l')
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[hafta-1][i]==0)
                        {
                            if((i+1)%2==0 && (i+1)%6==0)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar large delux odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==1 ||  secim%6!=0 || odalar[hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[hafta-1][secim-1]==0)
                        {
                            odalar[hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>7)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[hafta-1][i]==0)
                                {
                                    if((i+1)%2==0 && (i+1)%6==0)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==1 || secim%6!=0 || odalar[hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[hafta-1][secim-1]==0)
                                {
                                    odalar[hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    dongu++;
                    misafirsayisi=misafirsayisi-7;
                    if(misafirsayisi<=7)
                        break;
                }
                while(misafirsayisi!=7);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*((300*dongu)-(300*dongu)*0.15);
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[j][i]==1)
                                oran1++;
                        }
                        printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    ucret=7*300*dongu;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[j][i]==1)
                                oran1++;
                        }
                        printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*300*dongu;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[j][i]==1)
                                oran1++;
                        }
                        printf("Baharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            else
                printf("uzgunuz oyle bir oda tipi yok!");
            break;

        case 'Y'://mevsimlerde  yaz
        case 'y':
            printf("Yazin kacinci haftasinda konaklama yapilacagini giriniz:");
            scanf("%d",& hafta);
            if(hafta<1 || hafta>12)
            {
                do
                {
                    printf("Yazin kacinci haftasinda konaklama yapilacagini giriniz\t");
                    scanf("%d",& hafta);
                    sayac++;
                    if(hafta>=1 && hafta<=12)
                        break;
                    if(sayac==3)
                        return 0;
                }
                while(sayac!=3);
            }
            printf("-ODA TIPLERI-\n  Standart oda icin\t'S'\n  Deluxe oda icin\t'D'\n  Large Deluxe oda icin\t'L'\nkodunu giriniz: ");
            scanf(" %c",&oda);
            if(oda=='S'|| oda=='s')// standart odalar icin
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[12+hafta-1][i]==0)
                        {
                            if((i+1)%2==1)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar standart odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==0 || odalar[12+hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[12+hafta-1][secim-1]==0)
                        {
                            odalar[12+hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>4)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[12+hafta-1][i]==0)
                                {
                                    if((i+1)%2==1)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==0 || odalar[12+hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[12+hafta-1][secim-1]==0)
                                {
                                    odalar[12+hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    misafirsayisi=misafirsayisi-4;
                    if(misafirsayisi<=4)
                        break;
                }
                while(misafirsayisi!=4);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*(c*60-(c*60*0.15));
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[12+j][i]==1)
                                oran1++;
                        }
                        printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    if(c>3)
                    {
                        ucret=7*(c*60-(60*0.5));
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[12+j][i]==1)
                                    oran1++;
                            }
                            printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        ucret=7*c*60;
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[12+j][i]==1)
                                    oran1++;
                            }
                            printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*c*60;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[12+j][i]==1)
                                oran1++;
                        }
                        printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            if(oda=='D'|| oda=='d')
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[12+hafta-1][i]==0)
                        {
                            if((i+1)%2==0 && (i+1)%6!=0)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar deluxe odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==1 || secim%6==0 || odalar[12+hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[12+hafta-1][secim-1]==0)
                        {
                            odalar[12+hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>4)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[12+hafta-1][i]==0)
                                {
                                    if((i+1)%2==0 && (i+1)%6!=0)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==1 && secim%6==0 || odalar[12+hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[12+hafta-1][secim-1]==0)
                                {
                                    odalar[12+hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    misafirsayisi=misafirsayisi-4;
                    if(misafirsayisi<=4)
                        break;
                }
                while(misafirsayisi!=4);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*(c*90-(c*90*0.15));
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[12+j][i]==1)
                                oran1++;
                        }
                        printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    if(c>3)
                    {
                        ucret=7*(c*90-(90*0.5));
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[12+j][i]==1)
                                    oran1++;
                            }
                            printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        ucret=7*c*90;
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[12+j][i]==1)
                                    oran1++;
                            }
                            printf("Yazin %d. haftası doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*c*90;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[12+j][i]==1)
                                oran1++;
                        }
                        printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            else if(oda=='L'|| oda=='l')
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[12+hafta-1][i]==0)
                        {
                            if((i+1)%2==0 && (i+1)%6==0)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar large delux odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==1 || secim%6!=0 || odalar[12+hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[12+hafta-1][secim-1]==0)
                        {
                            odalar[12+hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>7)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[12+hafta-1][i]==0)
                                {
                                    if((i+1)%2==0 && (i+1)%6==0)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==1 || secim%6!=0 || odalar[12+hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[12+hafta-1][secim-1]==0)
                                {
                                    odalar[12+hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    dongu++;
                    misafirsayisi=misafirsayisi-7;
                    if(misafirsayisi<=7)
                        break;
                }
                while(misafirsayisi!=7);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*((400*dongu)-(400*dongu)*0.15);
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[12+j][i]==1)
                                oran1++;
                        }
                        printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    ucret=7*400*dongu;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[12+j][i]==1)
                                oran1++;
                        }
                        printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*400*dongu;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[12+j][i]==1)
                                oran1++;
                        }
                        printf("Yazin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            else
                printf("uzgunuz oyle bir oda tipi yok!");
            break;


        case 'S'://mevsimlerde  sonbahar
        case 's':
            printf("Sonbaharin kacinci haftasinda konaklama yapilacagini giriniz:");
            scanf("%d",& hafta);
            if(hafta<1 || hafta>12)
            {
                do
                {
                    printf("Sonbaharin kacinci haftasinda konaklama yapilacagini giriniz\t");
                    scanf("%d",& hafta);
                    sayac++;
                    if(hafta>=1 && hafta<=12)
                        break;
                    if(sayac==3)
                        return 0;
                }
                while(sayac!=3);
            }
            printf("-ODA TIPLERI-\n  Standart oda icin\t'S'\n  Deluxe oda icin\t'D'\n  Large Deluxe oda icin\t'L'\nkodunu giriniz: ");
            scanf(" %c",&oda);
            if(oda=='S'|| oda=='s')// standart odalar icin
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[24+hafta-1][i]==0)
                        {
                            if((i+1)%2==1)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar standart odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==0 || odalar[24+hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[24+hafta-1][secim-1]==0)
                        {
                            odalar[24+hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>4)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[24+hafta-1][i]==0)
                                {
                                    if((i+1)%2==1)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==0 || odalar[24+hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[24+hafta-1][secim-1]==0)
                                {
                                    odalar[24+hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    misafirsayisi=misafirsayisi-4;
                    if(misafirsayisi<=4)
                        break;
                }
                while(misafirsayisi!=4);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*(c*25-(c*25*0.15));
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[24+j][i]==1)
                                oran1++;
                        }
                        printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    if(c>3)
                    {
                        ucret=7*(c*25-(25*0.5));
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[24+j][i]==1)
                                    oran1++;
                            }
                            printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        ucret=7*c*25;
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[24+j][i]==1)
                                    oran1++;
                            }
                            printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*c*25;
                    printf("Ucret=%.2f\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[24+j][i]==1)
                                oran1++;
                        }
                        printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            if(oda=='D'|| oda=='d')
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[24+hafta-1][i]==0)
                        {
                            if((i+1)%2==0 && (i+1)%6!=0)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar deluxe odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==1 || secim%6==0 || odalar[24+hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[24+hafta-1][secim-1]==0)
                        {
                            odalar[24+hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>4)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[24+hafta-1][i]==0)
                                {
                                    if((i+1)%2==0 && (i+1)%6!=0)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==1 && secim%6==0 || odalar[24+hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[24+hafta-1][secim-1]==0)
                                {
                                    odalar[24+hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    misafirsayisi=misafirsayisi-4;
                    if(misafirsayisi<=4)
                        break;
                }
                while(misafirsayisi!=4);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*(c*50-(c*50*0.15));
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[24+j][i]==1)
                                oran1++;
                        }
                        printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    if(c>3)
                    {
                        ucret=7*(c*50-(50*0.5));
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[24+j][i]==1)
                                    oran1++;
                            }
                            printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        ucret=7*c*50;
                        printf("Ucret=%.2f$\n",ucret);
                        for(j=0; j<12; j++)
                        {
                            for(i=0; i<100; i++)
                            {
                                if(odalar[24+j][i]==1)
                                    oran1++;
                            }
                            printf("Sonbaharin %d. haftası doluluk orani =%c%d\n",j+1,yuzde,oran1);
                            oran1=0;
                        }
                        printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                        scanf(" %c",&tekrar);
                    }
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*c*50;
                    printf("Ucret=%.2f\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[24+j][i]==1)
                                oran1++;
                        }
                        printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            else if(oda=='L'|| oda=='l')
            {
                do
                {
                    for (i=0; i<100; i++)
                    {
                        if (odalar[24+hafta-1][i]==0)
                        {
                            if((i+1)%2==0 && (i+1)%6==0)
                                printf("%d-- ",i+1);
                        }
                    }
                    printf("nolu odalar large delux odalara dahildir. Birini seciniz: ");
                    scanf("%d",&secim);
                    if(secim%2==1 || secim%6!=0 || odalar[24+hafta-1][secim-1]!=0)
                    {
                        printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                        scanf(" %c",&tekrar);
                    }
                    else
                    {
                        if (odalar[24+hafta-1][secim-1]==0)
                        {
                            odalar[24+hafta-1][secim-1]=1;
                            break ;
                        }
                    }
                    if(tekrar=='h')
                        return 0;
                }
                while(tekrar!='H');
                printf("Lutfen misafir sayisini giriniz: ");
                scanf("%d",&misafirsayisi);
                if(misafirsayisi==0)
                    return 0;
                c=misafirsayisi;
                do
                {
                    if (misafirsayisi>7)
                    {
                        do
                        {
                            for (i=0; i<100; i++)
                            {
                                if (odalar[24+hafta-1][i]==0)
                                {
                                    if((i+1)%2==0 && (i+1)%6==0)
                                        printf("%d-- ",i+1);
                                }
                            }
                            printf("oda kapasitesinden fazla olan kisiler icin yeni bir oda seciniz:");
                            scanf("%d",&secim);
                            if(secim%2==1 || secim%6!=0 || odalar[24+hafta-1][secim-1]!=0)
                            {
                                printf("Olmayan ya da dolu bir oda sectiniz!\nYeniden oda secmek icin-->'E'\nCikmak icin-->'H'\ntiklayiniz");
                                scanf(" %c",&tekrar);
                            }
                            else
                            {
                                if (odalar[24+hafta-1][secim-1]==0)
                                {
                                    odalar[24+hafta-1][secim-1]=1;
                                    break ;
                                }
                            }
                            if(tekrar=='h')
                                return 0;
                        }
                        while(tekrar!='H');
                    }
                    dongu++;
                    misafirsayisi=misafirsayisi-7;
                    if(misafirsayisi<=7)
                        break;
                }
                while(misafirsayisi!=7);
                printf("Rezervasyon ucretinizi nasil odeyeceginizi secin\n");
                printf("  On odemeli islem icin\t\t'O'\n  Havale ile odeme islemi icin\t'H'\n  Standart odeme icin\t\t'S'\nkodunu giriniz: ");
                scanf(" %c",&ucrettipi);
                switch(ucrettipi)//ödeme çeþitleri için
                {
                case 'O'://önödemeli iþlem ücreti
                case 'o':
                    ucret=7*((250*dongu)-(250*dongu)*0.15);
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[24+j][i]==1)
                                oran1++;
                        }
                        printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'H':// havale ile iþlem ücreti
                case 'h':
                    ucret=7*250*dongu;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[24+j][i]==1)
                                oran1++;
                        }
                        printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                case 'S'://standart iþlem ücreti
                case 's':
                    ucret=7*250*dongu;
                    printf("Ucret=%.2f$\n",ucret);
                    for(j=0; j<12; j++)
                    {
                        for(i=0; i<100; i++)
                        {
                            if(odalar[24+j][i]==1)
                                oran1++;
                        }
                        printf("Sonbaharin %d. haftasi doluluk orani =%c%d\n",j+1,yuzde,oran1);
                        oran1=0;
                    }
                    printf("\nYeni bir rezervasyon islemi yapmak ister misiniz?\n Evet->'E' Hayir->'H'");
                    scanf(" %c",&tekrar);
                    break;
                default:
                    printf("Uzgunuz! Oyle bir odeme sekli yoktur.");
                    break;
                }
            }
            else
                printf("uzgunuz oyle bir oda tipi yok!");
            break;
            break;
        default:
            printf("oyle bir mevsim yok!");
            break;

        }
        if(tekrar=='e')
            tekrar='E';
    }
    while(tekrar=='E');
    return 0;
}
