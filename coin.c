#include<stdio.h>

#include<string.h>

int possiblewayschangeorder(int changemakingcoinorder[], int dcoinssize, int n);

int main()

{

    int denominationcoins[] = {1, 3, 5};

    int dcoinssize = sizeof(denominationcoins) / sizeof(denominationcoins[0]);

    int n = 9;
    printf("Number of possible ways: \n");

    printf("%d", possiblewayschangeorder(denominationcoins, dcoinssize, n));

    return 0;

}

int possiblewayschangeorder(int changemakingcoinorder[], int dcoinssize, int n)

{

    int coin, making;

    int changemaking[n + 1][dcoinssize];

    for (int i = 0; i < dcoinssize; i++)

        changemaking[0][i] = 1;

    for (int i = 1; i < n + 1; i++)

    {

        for (int j = 0; j < dcoinssize; j++)

        {

            coin = (i - changemakingcoinorder[j] >= 0) ? changemaking[i - changemakingcoinorder[j]][j] : 0;

            making = (j >= 1) ? changemaking[i][j - 1] : 0;

            changemaking[i][j] = coin + making;

        }

    }

    return changemaking[n][dcoinssize - 1];

}