#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// NameCard struct declaration
typedef struct
{
    int nameCardID;
    char personName[20];
    char companyName[20];
} NameCard;

// function declarations
void listNameCards(NameCard list[], int *currentNumberOfCards);
void addNameCard(NameCard list[], int *currentNumberOfCards);
void removeNameCard(NameCard list[], int *currentNumberOfCards);
void getNameCard(NameCard list[], int *currentNumberOfCards);

// helper functions
void printMenu();
void printNameCard(NameCard *nameCard);
int sortNameCards(NameCard list[], int sizeOfNameCardList);
NameCard obtainNameCardInfo();
char *toUpperCase(char *strToConvert);

int main()
{
    NameCard nameCards[5];
    int numberOfNameCards = 0;
    int userChoice;

    printMenu();
    while (userChoice != 5)
    {
        printf("Enter your choice:");
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            listNameCards(nameCards, &numberOfNameCards);
            break;
        case 2:
            addNameCard(nameCards, &numberOfNameCards);
            sortNameCards(nameCards, numberOfNameCards);
            break;
        case 3:
            removeNameCard(nameCards, &numberOfNameCards);
            sortNameCards(nameCards, numberOfNameCards);
            break;
        case 4:
            getNameCard(nameCards, &numberOfNameCards);
            break;
        default:
            break;
        }
    }
}

// function definitions

void listNameCards(NameCard list[], int *currentNumberOfCards)
{
    if (*currentNumberOfCards == 0)
        printf("The name card holder is empty\n");

    for (int i = 0; i < *currentNumberOfCards; i++)
    {
        printNameCard(&list[i]);
    }
}

void addNameCard(NameCard list[], int *currentNumberOfNameCards)
{
    printf("addNameCard():\n");

    NameCard newNameCard = obtainNameCardInfo();
    list[*currentNumberOfNameCards] = newNameCard;

    printf("The name card has been added successfully\n");

    (*currentNumberOfNameCards)++;
}

void removeNameCard(NameCard list[], int *currentNumberOfNameCards)
{

    printf("removeNameCard():\n");

    if (*currentNumberOfNameCards == 0)
    {
        printf("The name card holder is empty\n");
        return;
    }

    char nameToRemove[20];
    char temp;
    printf("Enter personName:");
    scanf("%c", &temp);
    fgets(nameToRemove, 20, stdin);
    strtok(nameToRemove, "\n");

    for (int i = 0; i < *currentNumberOfNameCards; i++)
    {
        char tempPersonName[20];
        strcpy(tempPersonName, list[i].personName);

        if (strcmp(toUpperCase(tempPersonName), toUpperCase(nameToRemove)) == 0)
        {
            printf("The name card is removed\n");
            printNameCard(&list[i]);

            for (int j = i; j < *currentNumberOfNameCards - 1; j++)
            {
                list[j] = list[j + 1];
            }

            (*currentNumberOfNameCards)--;

            return;
        }
    }

    printf("The target person name is not in the name card holder\n");
}

void getNameCard(NameCard list[], int *currentNumberOfNameCards)
{
    printf("getNameCard():\n");

    if (*currentNumberOfNameCards == 0)
    {
        printf("The name card holder is empty\n");
        return;
    }

    char nameToGet[20];
    char temp;
    printf("Enter personName:");
    scanf("%c", &temp);
    fgets(nameToGet, 20, stdin);
    strtok(nameToGet, "\n");

    for (int i = 0; i < *currentNumberOfNameCards; i++)
    {
        char tempPersonName[20];
        strcpy(tempPersonName, list[i].personName);

        if (strcmp(toUpperCase(tempPersonName), toUpperCase(nameToGet)) == 0)
        {
            printf("The target person name is found\n");
            printNameCard(&list[i]);
            return;
        }
    }

    printf("The target person name is not found\n");
}

void printMenu()
{
    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
    printf("1: listNameCards()\n");
    printf("2: addNameCard()\n");
    printf("3: removeNameCard()\n");
    printf("4: getNameCard()\n");
    printf("5: quit\n");
}

void printNameCard(NameCard *nameCard)
{
    printf("nameCardID: %d\n", nameCard->nameCardID);
    printf("personName: %s\n", nameCard->personName);
    printf("companyName: %s\n", nameCard->companyName);
}

int sortNameCards(NameCard list[], int sizeOfNameCardList)
{
    int i, j;
    NameCard temp;

    for (i = 0; i < sizeOfNameCardList - 1; i++)
    {
        for (j = 0; j < sizeOfNameCardList - i - 1; j++)
        {
            if (list[j].nameCardID > list[j + 1].nameCardID)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    return 0;
}

NameCard obtainNameCardInfo()
{
    NameCard nameCard;
    char temp;

    printf("Enter nameCardID: ");
    scanf("%d", &nameCard.nameCardID);

    printf("Enter personName: ");
    scanf("%c", &temp); // see https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
    fgets(nameCard.personName, 20, stdin);
    strtok(nameCard.personName, "\n");

    printf("Enter companyName: ");
    fgets(nameCard.companyName, 20, stdin);
    strtok(nameCard.companyName, "\n");

    return nameCard;
}

char *toUpperCase(char *strToConvert)
{
    for (int i = 0; strToConvert[i] != '\0'; i++)
    {
        if (strToConvert[i] >= 'a' && strToConvert[i] <= 'z')
        {
            strToConvert[i] = strToConvert[i] - 32;
        }
    }

    return strToConvert;
}