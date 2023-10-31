#include <stdio.h>

void coinChange(int amount, int coins[], int numCoins) {
    int coinCount[numCoins]; 
    for (int i = 0; i < numCoins; i++) {
        coinCount[i] = 0;
    }

    for (int i = 0; i < numCoins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            coinCount[i]++;
        }
    }


    printf("Coins used:\n");
    for (int i = 0; i < numCoins; i++) {
        if (coinCount[i] > 0) {
            printf("%d cents: %d\n", coins[i], coinCount[i]);
        }
    }
}

int main() {
    int amount = 151;
    int coins[] = {100,50,20, 10, 5, 1};
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    coinChange(amount, coins, numCoins);

    return 0;
}
