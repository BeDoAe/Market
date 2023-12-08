#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
                                               ////origin project cause I had many versions
                            //There's some issues and not right implement but i tried and searched my best Thx for reading if so
typedef struct Product Product;
typedef struct Category Category;
//Identify struct
typedef struct Product
{
    int Price;
    int quantity;
    char productName[30];
} ;
//in struct of category i'm pointing to products(pointer that have the address of struct products)
typedef struct Category
{
    char categoryName[30];
    Product *products;

} ;
//After many failed attempts i had to declare these 3 variables global cause i need them in every function
//Made categories pointer cause then i'm going to give it dynamic alloctaion so the pointer is to the address of first stored place in the reserved array
//Made size of product global as i made it pointer ....................
Category *categories;
int sizeofCategory;
int *sizeofProducts;

void EnterCategories_Products()
{
    //checks if the size of category empty then enters if not empty then realloc comes in with the same code except adding the old+new size
    if (sizeofCategory==0)
    {


        printf("Enter the number of Categories you want: ");
        scanf("%i", &sizeofCategory);

        categories = malloc(sizeofCategory * sizeof(Category));

        sizeofProducts = malloc(sizeofCategory * sizeof(int));
        //I made the product could be variant in size like the jagged array each one has it's own malloc size of product of specific category
        for (int i = 0; i < sizeofCategory; i++)
        {
            printf("Enter the Name you want for Category %d: ", i + 1);
            scanf("%s", categories[i].categoryName);

            printf("Enter the number of Products you want for Category %d of Name %s: ", i + 1, categories[i].categoryName);

            scanf("%i", &sizeofProducts[i]);
            categories[i].products = malloc(sizeofProducts[i] * sizeof(Product));

            for (int j = 0; j < sizeofProducts[i]; j++)
            {
                printf("Enter details for Category %d of Name : %s  Product %d:\n", i + 1, categories[i].categoryName, j + 1);
                printf("Enter Name: ");
                scanf("%s", categories[i].products[j].productName);
                printf("Enter Price: ");
                scanf("%i", &categories[i].products[j].Price);
                printf("Enter Quantity: ");
                scanf("%i", &categories[i].products[j].quantity);
            }
        }
        printf("Press any key to return to the main menu...");
        getch();
    }
    else
    {
        char additionalCategoryName[30];
        for (int i = 0; i < sizeofCategory; i++)
        {
            printf("Check that the Category you want for The Additional Category  isn't Already Existed :");
            scanf("%s", additionalCategoryName);
            if (strcmp(categories[i].categoryName,additionalCategoryName)!=0)
            {
                int newsizeofCategory;

                printf("Add more Categories , Enter the number for additional Categories : \n");
                scanf("%i", &newsizeofCategory);

                categories = realloc(categories, (newsizeofCategory + sizeofCategory) * sizeof(Category));

                sizeofProducts = realloc(sizeofProducts, (newsizeofCategory + sizeofCategory) * sizeof(int));

                for (int i = sizeofCategory; i < newsizeofCategory + sizeofCategory; i++)
                {

                    printf("Enter the Name you want for Category %d: ", i + 1);
                    scanf("%s", categories[i].categoryName);

                    printf("Enter the number of Products you want for Category %d of Name %s: ", i + 1, categories[i].categoryName);

                    scanf("%i", &sizeofProducts[i]);
                    categories[i].products = malloc(sizeofProducts[i] * sizeof(Product));

                    for (int j = 0; j < sizeofProducts[i]; j++)
                    {
                        printf("Enter details for Category %d of Name : %s  Product %d:\n", i + 1, categories[i].categoryName, j + 1);
                        printf("Enter Name: ");
                        scanf("%s", categories[i].products[j].productName);
                        printf("Enter Price: ");
                        scanf("%i", &categories[i].products[j].Price);
                        printf("Enter Quantity: ");
                        scanf("%i", &categories[i].products[j].quantity);
                    }
                }
                sizeofCategory += newsizeofCategory;

                printf("Press any key to return to the main menu...\n");
                getch();
                break;
            }
            else
            {
                printf("You Already Have a Category with this Name %s \n",categories[i].categoryName);
                printf("Press any key to return to the main menu...\n");
                getch();
                break;
            }
        }
    }
}

//I tried realloc but didn't know the syntax or the view so i had some help until i figured out most of it but not all unfortunate !!!!!!!!!!!!!

//    else
//    {
//        printf("Enter the number of Categories you want: ");
//        scanf("%i", &newsizeofCategory);
////                categories =  realloc(newsizeofCategory + sizeofCategory  * sizeof(Category));
//                        categories = realloc(categories, (newsizeofCategory + sizeofCategory) * sizeof(Category));
//        sizeofProducts = malloc(sizeofCategory * sizeof(int));
//
//        for (int i = 0; i < sizeofCategory; i++)
//        {
//            printf("Enter the Name you want for Category %d: ", i + 1);
//            scanf("%s", categories[i].categoryName);
//
//            printf("Enter the number of Products you want for Category %d of Name %s: ", i + 1, categories[i].categoryName);
//
//            scanf("%i", &sizeofProducts[i]);
//            categories[i].products = malloc(sizeofProducts[i] * sizeof(Product));
//
//            for (int j = 0; j < sizeofProducts[i]; j++)
//            {
//                printf("Enter details for Category %d of Name : %s  Product %d:\n", i + 1, categories[i].categoryName, j + 1);
//                printf("Enter Name: ");
//                scanf("%s", categories[i].products[j].productName);
//                printf("Enter Price: ");
//                scanf("%i", &categories[i].products[j].Price);
//                printf("Enter Quantity: ");
//                scanf("%i", &categories[i].products[j].quantity);
//            }
//        }
//
//
//
//    }
//    printf("Press any key to return to the main menu...");
//    getch();
//
//}
//in display i show each category with it's products and additional info like Receipt the sum of all quantities and prices of category (Silly i know)
void DisplayCategories_Products()
{

    for (int i = 0; i < sizeofCategory; i++)
    {
        int categoryTotal = 0;
        int productTotal = 0;
        for (int j = 0; j < sizeofProducts[i]; j++)
        {
            printf("\n ########################################################################################################### \n");

            printf("Details for Category %d of Name : %s  Product %d:\n", i + 1,categories[i].categoryName, j + 1);
            printf("Name: %s\t", categories[i].products[j].productName);
            printf("Price: %i\t", categories[i].products[j].Price);
            printf("Quantity: %i\n", categories[i].products[j].quantity);
            categoryTotal += categories[i].products[j].Price;
            productTotal += categories[i].products[j].quantity;
        }
//        printf("\n ########################################################################################################### \n");
//        printf("Additional info of The Receipt  for Category %s \n \n ",categories[i].categoryName);
//        printf("Sum of Prices for Category %d  of %s is %i \n \n", i + 1,categories[i].categoryName, categoryTotal);
//        printf("Sum of Quantities for Category %d  of %s is %i \n \n", i + 1,categories[i].categoryName, productTotal);

    }
    printf("\n ########################################################################################################### \n");
    printf("Press any key to return to the main menu...");
    getch();

}
//in this function i search of check for specific product ,, u have to enter the exact same name case I'm searching with string not the index sadly that's not great cause what if i searched for orange not Orange (will update it !!!)
void Check_Products()
{
    char choice[2];

    do
    {
        Category validcatergories;
//    printf("Enter the Category you want to Search : \n");
//    int categoryIndex ;
//    scanf("%i",&categoryIndex);
        printf("Enter the Category Name you want to Search : \n");

        char categoryName[30] ;
        scanf("%s",categoryName);
//    printf("Enter the Product you want to Search : \n");
//    int productIndex ;
//    scanf("%i",&productIndex);
        printf("Enter the Product Name you want to Search : \n");
        char productName[30] ;
        scanf("%s",productName);
        int valid_category=0;
        int valid_product=0;


        //validation
        for (int i=0; i<sizeofCategory; i++)
        {
            //not working cause comparing two strings
            // if (productName==categories[i].products[j].productName)
            if (strcmp(categoryName, categories[i].categoryName) == 0)
            {
                valid_category =1;


                for (int j=0; j<sizeofProducts[i]; j++)
                {
                    // if (productName==categories[i].products[j].productName)


                    if (strcmp(productName, categories[i].products[j].productName) == 0)


                    {
//                    printf("Product Existed \n");
//                    break;
//                }else {
//                        printf("Product Not Existed \n");
//                }

                        valid_product  =1;
                        printf("Selected item Name is : %s \n",categories[i].products[j].productName);
                        printf("Selected item Price is : %d \n",categories[i].products[j].Price);
                        printf("Selected item Qantity is : %d \n",categories[i].products[j].quantity);



                    }




                }
//        else{
//                printf("Category Not Existed \n");
//        }
            }


        }
        if (valid_category==1)
        {
            printf("Category Existed \n");
        }
        else
        {
            printf("Category Not Existed \n");

        }
        if (valid_product==1)
        {
            printf("Product Existed \n");
        }
        else
        {
            printf("Category Not Existed \n");
        }
        printf("Do you Want to Search for something else Enter : Y / N \n");
//        char choice[2]={"Y","N"};
        scanf("%s",choice);
    }
    while (strcmp(choice, "Y") == 0);
    printf("Press any key to return to the main menu...");
    getch();
}
//in sell function it's decreasing the required amount of qantity that the user is asking but not if zero it's removing the product from the category if so
void sellProduct()
{
    int operationDone=0;
    char buyProduct[30];

    printf("Enter the product you want to buy \n");
    scanf("%s",buyProduct);
    int quantity=0;
    printf("Enter How many Quantity you want to buy \n");
    scanf("%i",&quantity);
    int Receipt=0 ;

    for (int i=0; i<sizeofCategory ; i++)
    {
        for (int j=0; j<sizeofProducts[i]; j++)

            if ( (strcmp(categories[i].products[j].productName,buyProduct)==0) && (categories[i].products[j].quantity>0) )

            {
                if (categories[i].products[j].quantity>=quantity)
                {
                    categories[i].products[j].quantity -=quantity;
                    Receipt = categories[i].products[j].Price*quantity;
                    printf("The Receipt of The Sold Product %s  is %i$ \n",categories[i].products[j].productName,Receipt);
                    printf("The remaining Quantity  of Product %s  is %i \n",categories[i].products[j].productName,categories[i].products[j].quantity );


                    operationDone++;

                    if (categories[i].products[j].quantity==0)
                    {
                        for (; j < sizeofProducts[i] - 1; j++)
                        {
                            categories[i].products[j] = categories[i].products[j + 1];
                        }
                        operationDone++;
                        sizeofProducts[i]--;
                    }
                }

            }



    }
    if (operationDone >0)
    {

        printf("The Sell Operation  is Done");
    }
    else
    {
        printf("Sorry The Sell Operation  isn't Done");


    }

    printf("\n ########################################################################################################### \n");
    printf("Press any key to return to the main menu...");
    getch();


}
//Remove category and Remove product all the same  looping around the size of category or size of product then shifting to the left by one index then size--

void removeProduct()
{
    int operationDone=0;

    char removeProduct[30];

//    int id_removeProduct;

    printf("Enter the product you want to remove \n");
    scanf("%s",removeProduct);
//    printf("Enter the ID of the product you want to remove \n");
//    scanf("%i",id_removeProduct);

    for (int i=0; i<sizeofCategory ; i++)
    {
        for (int j=0; j<sizeofProducts[i]; j++)

            if ( strcmp(categories[i].products[j].productName,removeProduct)==0  )

            {


                for (int k = j; k < sizeofProducts[i] - 1; k++)
                {
                    categories[i].products[k] = categories[i].products[k + 1];
                }

                sizeofProducts[i]--;

                operationDone++;

            }



    }
    if (operationDone >0)
    {

        printf("The Remove Product Operation  is Done");
    }
    else
    {
        printf("Sorry The Remove Product  isn't Done");


    }

    printf("\n ########################################################################################################### \n");
    printf("Press any key to return to the main menu...");
    getch();



}
void removeCategory()
{
    int operationDone=0;

    char removeCategory[30];

//    int id_removeProduct;

    printf("Enter the Category you want to remove \n");
    scanf("%s",removeCategory);
//    printf("Enter the ID of the product you want to remove \n");
//    scanf("%i",id_removeProduct);

    for (int i=0; i<sizeofCategory  ; i++)
    {

        if ( strcmp(categories[i].categoryName,removeCategory)==0  )

        {
            for (int k = i; k < sizeofCategory - 1; k++)
            {
                categories[k] = categories[k + 1];
            }
            sizeofCategory--;

            operationDone++;

        }
    }
    if (operationDone >0)
    {

        printf("The Remove Category Operation  is Done");
    }
    else
    {
        printf("Sorry The Remove Category Product  isn't Done");


    }

    printf("\n ########################################################################################################### \n");
    printf("Press any key to return to the main menu...");
    getch();



}
//in this function i got help with the idea and again with realloc cause it's syntax and to understand it with my different project was difficult
void moveProduct()
{
    int operationDone=0;
    int categoryDone=0;

    char moveProduct[30];
    char categoryName[30];
    printf("Enter the Category you want to move to it \n");
    scanf("%s",categoryName);

    printf("Enter the Product you want to move \n");
    scanf("%s",moveProduct);
    int category_index=0;
    int product_index=0;
    int index_ofProductCategroy=0;

//first i take from the user the name of category and save it's index in variable i have

    for (int i=0; i<sizeofCategory ; i++)
    {
        if( strcmp(categories[i].categoryName,categoryName)==0)
        {
            int category_index=i;
            categoryDone++;
        }
    }

    //then do the same with the product the user wants to move
    for (int x=0; x<sizeofCategory ; x++)
    {


        for (int j=0; j<sizeofProducts[x]; j++)
        {



            if ( strcmp(categories[x].products[j].productName,moveProduct)==0  )

            {

                index_ofProductCategroy=x;
                product_index=j;


                // Decrease the size of products and free the memory for the last product


                operationDone++;


            }

        }

    }

//Then decreasing the size of the category that I remove the product from and shift it's items
    for (int k = product_index; k < sizeofProducts[index_ofProductCategroy]-1; k++)
    {
        categories[index_ofProductCategroy].products[k] = categories[index_ofProductCategroy].products[k + 1];
    }

    sizeofProducts[index_ofProductCategroy]--;



//creating a new product so i could move the one i have
    categories[category_index].products = realloc(categories[category_index].products,
                                          (sizeofProducts[category_index] + 1) * sizeof(Product));

//I Tried to access a string after intializition which caused an error ,, I should only copy a new value into the new one which i made with realloc
//
//    categories[category_index].products.productName=categories[index_ofProductCategroy].products[product_index].productName;
//    categories[category_index].products.Price=categories[index_ofProductCategroy].products[product_index].Price;
//    categories[category_index].products.quantity=categories[index_ofProductCategroy].products[product_index].quantity;

// Copy the product details to the new location (sizeofProducts[category_index]) That's the new place index
    strcpy(categories[category_index].products[sizeofProducts[category_index]].productName,
           categories[index_ofProductCategroy].products[product_index].productName);

    categories[category_index].products[sizeofProducts[category_index]].Price =
        categories[index_ofProductCategroy].products[product_index].Price;

    categories[category_index].products[sizeofProducts[category_index]].quantity =
        categories[index_ofProductCategroy].products[product_index].quantity;

    sizeofProducts[category_index]++;


    if (categoryDone>0)
    {
        printf("The  Category Name   is Correct \n");

    }
    else
    {
        printf("The  Category Name   isn't Correct \n");

    }
    if (operationDone >0)
    {

        printf("The Move Category Operation  is Done \n");
    }
    else
    {
        printf("Sorry The Remove Category Product  is not Done \n");


    }

    printf("\n ########################################################################################################### \n");
    printf("Press any key to return to the main menu...");
    getch();

}


COORD coord= {0,0};                  // this is global variable
//center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
int main()
{
    gotoxy(50, 15);

    printf("Welcome To our Shop");
    char arr[7][30] = {"Enter your Categories", "View Products", "Search for Products", "Sell Products", "Move Products","Remove Category","Remove Product"};

    int selectedoption = 0;
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//    int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
//    int centerY = screenHeight / 2 - 2; // Adjusted for the height of the menu

    while (1)
    {
        gotoxy(50, 10);

        char ch;
        int flag = 0;
        ch = getch();

        if (ch == 13) // Enter key
        {
            flag = 1;
            system("cls");

            switch (selectedoption)
            {
            case 0:
                EnterCategories_Products();


                break;
            case 1:
                DisplayCategories_Products();
                break;
            case 2:
                Check_Products();
                break;
            case 3:
//                printf("Function Sell will be added soon");
                sellProduct();
                break ;
            case 4 :
//                printf("Function Move will be added soon");
                moveProduct();

                break ;
            case 5 :
//                printf("Function Remove Category will be added soon");
                removeCategory();
                break ;
            case 6 :
//                printf("Function Remove Product will be added soon");
                removeProduct();
                break ;
            }

        }
        else if (ch == 27) // Esc key
        {
            if (selectedoption == 0)
            {
                // Exit the program if at the first step
                return 0;
            }
            else
            {
                // Move to the previous step
                selectedoption--;
            }
        }
        else if (ch == -32) // Arrow key
        {
            ch = getch();
            switch (ch)
            {
            case 72: // Up arrow
                if(selectedoption==0)
                {
                    selectedoption=6;
                }
                else
                {
                    selectedoption--;
                }
                break;
            case 71 :  //Home
                selectedoption=0;
                break ;
            case 79: //End
                selectedoption=6;
                break;
            case 80:// Down arrow
                if(selectedoption==6)
                {
                    selectedoption=0;
                }
                else
                {
                    selectedoption++;
                }
                break;
            }
        }
        //To color the selected option and print the rest options in different color
        if (flag == 0)
        {
            system("cls");
            for (int i = 0; i < 7; i++)
            {
                gotoxy(50, 10+i*2);

                if (i == selectedoption)
                {

                    SetColor(12);
                    puts(arr[i]);
                }
                else
                {

//                        gotoxy(50, y-2);
                    SetColor(15);
                    puts(arr[i]);
                }
            }
        }
    }

    return 0;
}
