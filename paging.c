#include<stdio.h>
int pagetable[10], n, i;
int pagenumber, offset, pagesize, framenumber, physicaladdress;
int main()
{
    printf("Enter no.of pages:");
    scanf("%d", &n);
    printf("Enter frame no. for each page:\n");
    for(i=0; i<n; i++)
    {
        printf("Page %d -> frame:", i);
        scanf("%d", &pagetable[i]);                                       
    }
    printf("\n Enter page size:");
    scanf("%d", &pagesize);
    printf("Enter page number:");
    scanf("%d", &pagenumber);
    printf("Enter offset:");
    scanf("%d", &offset);
    if(pagenumber >= n || offset >= pagesize)
    {
        printf("Invalid logical address\n");
    }
    else
    {
        framenumber = pagetable[pagenumber];
        physicaladdress = framenumber * pagesize + offset;
        printf("\n Frame number: %d", framenumber);
        printf("\n Physical address: %d\n", physicaladdress);
    }
    return 0;
}