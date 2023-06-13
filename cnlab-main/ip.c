#include <stdio.h>
#include <string.h>

void separate(char str[], char ipClass)
{
    char network[16], host[16];
    memset(network, 0, sizeof(network));
    memset(host, 0, sizeof(host));

    if (ipClass == 'A')
    {
        strncpy(network, str, 1);
        strncpy(host, str + 1, strlen(str) - 1);
    }
    else if (ipClass == 'B')
    {
        strncpy(network, str, 2);
        strncpy(host, str + 2, strlen(str) - 2);
    }
    else if (ipClass == 'C')
    {
        strncpy(network, str, 3);
        strncpy(host, str + 3, strlen(str) - 3);
    }

    printf("Network ID: %s\n", network);
    printf("Host ID: %s\n", host);
}

char findClass(char str[])
{
    int ip = 0;
    sscanf(str, "%d", &ip);

    if (ip >= 0 && ip <= 127)
        return 'A';
    else if (ip >= 128 && ip <= 191)
        return 'B';
    else if (ip >= 192 && ip <= 223)
        return 'C';
    else if (ip >= 224 && ip <= 239)
        return 'D';
    else if (ip >= 240 && ip <= 255)
        return 'E';
    else
        return 'X'; // Invalid IP address class
}

int main()
{
    char str[16];
    printf("Enter the IP address: ");
    scanf("%s", str);

    char ipClass = findClass(str);
    if (ipClass != 'X')
    {
        printf("Given IP address belongs to Class %c\n", ipClass);
        separate(str, ipClass);
    }
    else
        printf("Invalid IP address!!!!!!\n");

    return 0;
}
