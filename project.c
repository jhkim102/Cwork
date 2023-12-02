#include <stdio.h>
#include <string.h>

struct books
{
    char Title[20];
    char Author[20];
    char Press[20];
    int Page;
    int Price;
    char borrow[20];
};
struct books list[5] = {
    {"Truth", "John", "Century", 300, 20000, "available"},
    {"Love", "Paul", "Goods", 200, 15000, "available"},
    {"Joy", "James", "Cookie", 250, 18000, "available"},
    {"Thanks", "Mark", "Saejong", 240, 21000, "available"},
    {"God", "Johnson", "Jungjo", 450, 35000, "available"}};

void displaybook()
{
    int i;
    printf("Title Authors Press Page Price \n");
    printf("----- ------- ----- ---- -----\n");

    for (i = 0; i < 5; i++)
    {
        printf("%s %s %s %d %d \n", list[i].Title, list[i].Author, list[i].Press, list[i].Page, list[i].Price);
    }
}
void searchbook(char title[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int res = strcmp(list[i].Title, &title[20]);
        if (res == 0)
        {
            printf("Title Authors Press Page Price borrow \n");
            printf("----- ------- ----- ---- ----- ------\n");
            printf("%s %s %s %d %d %s\n", list[i].Title, list[i].Author, list[i].Press, list[i].Page, list[i].Price, list[i].borrow);
            return;
        }
    }
    printf("입력한 책은 보유하고 있지 않습니다.\n");
}
int main(void)
{
    int opt;
    while (1)
    {
        printf("1.[도서목록] 2.[검색] 3.[대출] 4.[반납] 5.[종료]\n");
        printf("원하는 작업의 번호를 입력하세요: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            displaybook();
            break;
        case 2:
        {
            char title[20];
            printf("검색할 도서를 선택하세요.: ");
            scanf("%s", &title[20]);
            searchbook(title);
            break;
        }
        case 3:
        {
            char rent[20];
            printf("대출할 도서를 선택하세요: ");
        }
        case 5:
        {
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
        default:
            printf("다시 선택하세요 \n");
        }
    }
    return 0;
}