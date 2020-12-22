
#include <stdio.h>
#include <stdlib.h>

#define LEN 28
int cmp(const void* b, const void* a){
    return *(int*)a - *(int*)b;
}

int maxProfit(int k, int* prices, int pricesSize){

    int posnum =0;
    int sum = 0;
    int* p = (int*)malloc(pricesSize*sizeof(int));
    int* n = (int*)malloc(pricesSize*sizeof(int)/2);
    int* p0 = (int*)malloc(pricesSize*sizeof(int)/2);
    int count = 0;
    int ncount = 0;
    char flag = 0;
    for (int i = 0; i < pricesSize-1; i++){
        if (count == 0 && flag == 0)
            if (prices[i] >= prices[i+1])
                continue;
            else{
                p[count] = prices[i+1] - prices[i];
                flag = 1;
            }
        else
        if (prices[i] <= prices[i+1]){
            if (flag == 1){
                p[count] += prices[i+1] - prices[i];
            }
            else if (flag == -1){
                p[++count] = prices[i+1] - prices[i];
                flag = 1;
            }
        }
        else if(prices[i] > prices[i+1]){
            if (flag == -1){
                p[count] += prices[i+1] - prices[i];

            }
            else if (flag == 1){
                count += 1;
                p[count] = prices[i+1] - prices[i];
                flag = -1;
            }
        }
    }

    if (p[count] <= 0)
        count -= 1;
    for (int i = 0; i<=count; i++){
        if (p[i] > 0){
            p0[posnum++] = p[i];
            sum += p[i];
        }if (p[i] < 0)
            n[ncount++] = p[i];
    }

    qsort(n,ncount,sizeof(int),cmp);
    qsort(p0,posnum,sizeof(int),cmp);
    if (posnum > k){
        int addnum = posnum -k < ncount?posnum -k:ncount;
        int pi =posnum-1;int ni = 0;
        for (int i =0; i< addnum; i){
            if (p0[pi] > -n[ni]){
                sum += n[ni];
                i++;ni++;
            }else{
                sum -= p0[pi];
                i++;pi--;
            }
        }
    }

    free(p0);
    free(n);
    free(p);
    return sum;
}


int main(){
    int prices[LEN] = {3,2,6,5,0,3,4,5,2,3,1,10, 12,3,3,2,6,5,0,3,4,5,2,3,1,10, 12,3};
    int ret = maxProfit(2, prices, LEN);
    printf("ret : %d\n",ret);
    return 0;
}

