#include<stdio.h>
#include<time.h>

void transmission(int i,int n,int tf)
{
        while (i <= tf)
        {
                int z = 0,k;
                for (k = i; k < i + n && k <= tf; k++)
                        printf("Sending frame %d\n",k);
                for (k = i; k < i + n && k <= tf; k++)
                {
                        int f = rand() % 4;
                        if (!f)
                        {
                                printf("Acknowledgement for frame %d\n",k);
                                z++;
                        }
                        else
                        {
                                printf("Frame %d not received\n",k);
                                printf("Retransmitting\n");
                                break;
                        }
                }
                printf("\n");
                i=i+z;
        }
}

int main()
{
        int tf,n,i=1;
        srand(time(NULL));
        printf("Enter the total number of frames\n");
        scanf("%d",&tf);
        printf("Enter the window size\n");
        scanf("%d",&n);
        transmission(i,n,tf);
        return 0;
}