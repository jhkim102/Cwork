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

void displaybook()//1번 책리스트 보이기
{
    int i;
    printf("Title Authors Press Page Price \n");
    printf("----- ------- ----- ---- -----\n");

    for (i = 0; i < 5; i++)
    {
        printf("%s %s %s %d %d \n", list[i].Title, list[i].Author, list[i].Press,
               list[i].Page, list[i].Price);
    }
}
void searchbook(char title[])//2번 책 검색하기
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int res = strcmp(list[i].Title, &title[20]); //원하는 책 제목을 title로 입력받음
        if (res == 0)
        {
            printf("Title Authors Press Page Price borrow \n");
            printf("----- ------- ----- ---- ----- ------\n");
            printf("%s %s %s %d %d %s\n", list[i].Title, list[i].Author, list[i].Press,
                   list[i].Page, list[i].Price, list[i].borrow);
            return;
        }
    }
    printf("입력한 책은 보유하고 있지 않습니다.\n");
}
void output(char book[])//3번 대출(내보내기)하기
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int res = strcmp(list[i].Title, &book[20]); //이번에는 book으로 입력받고 비교함
        if (res == 0)
        {
            if (strcmp(list[i].borrow, "available") == 0)//제목과 같은 상황에서 대출가능하다고 표시되어있는지 확인
            {
                printf("대출 되었습니다,\n");
                printf("Title Authors Press Page Price borrow \n");
                printf("----- ------- ----- ---- ----- ------\n");
                printf("%s %s %s %d %d %s\n", list[i].Title, list[i].Author, list[i].Press,
                       list[i].Page, list[i].Price, list[i].borrow);
                strcpy(list[i].borrow, "borrowing");// strcpy를 통해 문자열 바꾸기
            }
            else if (strcmp(list[i].borrow, "available") != 0)
            {
                printf("대출 중이라 대출 할 수 없습니다.\n");
            }
            else
                printf("입력한 책은 보유하고 있지 않습니다.\n");
        }
    }
}
void input(char book[])// 반납(받아오기)하기
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int res = strcmp(list[i].Title, &book[20]);
        if (res == 0)
        {
            if (strcmp(list[i].borrow, "borrowing") == 0)
            {
                printf("책이 반납되었습니다.\n");
                printf("Title Authors Press Page Price borrow \n");
                printf("----- ------- ----- ---- ----- ------\n");
                printf("%s %s %s %d %d %s\n", list[i].Title, list[i].Author, list[i].Press,
                       list[i].Page, list[i].Price, list[i].borrow);
                strcpy(list[i].borrow, "available");
            }
            else if (strcmp(list[i].borrow, "available") != 0)
            {
                printf("대출 되지 않은 책입니다.\n");
            }
            else
                printf("입력한 책은 보유하고 있지 않습니다.\n");
        }
    }
}

int main(void)
{
    int opt;
    while (1)
    {
        printf("\n1.[도서목록] 2.[검색] 3.[대출] 4.[반납] 5.[종료]\n");
        printf("원하는 작업의 번호를 입력하세요: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            displaybook();
            printf("\n");
            break;
        case 2:
        {
            char title[20];
            printf("검색할 도서를 선택하세요.: ");
            scanf("%s", &title[20]);
            searchbook(title);
            printf("\n");
            break;
        }
        case 3:
        {
            char book[20];
            printf("대출할 도서를 선택하세요: ");
            scanf("%s", &book[20]);
            output(book);
            printf("\n");
            break;
        }
        case 4:
        {
            char book[20];
            printf("반납할 도서를 선택하세요: ");
            scanf("%s", &book[20]);
            input(book);
            printf("\n");
            break;
        }
        case 5:
        {
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
        default:
            printf("다시 선택하세요. \n");
        }
    }
    return 0;
}
