#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//функція яка повертає мінімальне значення масиву
int min_value_of_array(int array[], int size_of_array) {
    int min_value = *array;

    for (int i = 1; i < size_of_array; i++) 
    {
        if (*(array + i) < min_value)
        {
            min_value = *(array + i);
        }
    }

    return min_value;
}


//функція яка повертає максимальне значення масиву
int max_value_of_array(int array[], int size_of_array) {
    int max_value = *array;

    for (int i = 1; i < size_of_array; i++) 
    {
        if (*(array + i) > max_value) 
        {
            max_value = *(array + i);
        }
    }

    return max_value;
}


//функція для пошуку кількості max елементів на їх індексу
void unique_max(int array[], int size_of_array, int max_of_array, int* unique_of_max, int* index_max) 
{

    for (int i = 0; i < size_of_array; i++)
    {

        if (max_of_array == *(array + i))
        {
            (*unique_of_max)++;
            *index_max = i + 1;
        }

    }

}


//функція для пошуку кількості min елементів на їх індексу
void unique_min(int array[], int size_of_array, int min_of_array, int* unique_of_min, int* index_min)
{

    for (int i = 0; i < size_of_array; i++)
    {

        if (min_of_array == *(array + i))
        {
            (*unique_of_min)++;
            *index_min = i + 1;
        }

    }

}


//перевірка рівності введених елементів
int equality_of_array(int* array, int size_of_array) 
{

    for (int i = 0; i < (size_of_array - 1); i++) 
    {

        if (*(array + i) != *(array + 1 + i)) 
        {
            return 0;
        }

    }

    return 1;

}


int main()
{

    while (true) 
    {
        //типізація
        int size_of_array = 0, unique_of_max = 0, unique_of_min = 0, index_max = 0, index_min = 0, difference = 0, equality = 0;
        char stop[5], clean_string = NULL;

        //ввід розміру масиву
        printf("Enter size of array (natural number): ");
        scanf_s("%d", &size_of_array);

        //перевірка чи коректні значення (чи можливо створити масив)
        if (size_of_array > 1)
        {

            //виділення памяті під масив цілих чисел (array - вказіник на перший елемент масиву)
            int* array = (int*)malloc(size_of_array * sizeof(int));

            //перевірка чи коректні значення (чи створений масив)
            if (array == NULL)
            {
                printf("Error, null array\n");
                printf("Please enter a positive integer\n\n");
            }

            //якщо умова виконанна і массив створений
            else
            {

                //ввід масиву
                for (int i = 0; i < size_of_array; i++)
                {
                    printf("enter array element number %d: ", i + 1);
                    scanf_s("%d", array + i);
                }

                //перевірка рівності елементів
                equality = equality_of_array(array, size_of_array);

                //перевірка минулої дії
                if (equality)
                {
                    printf("\n");
                    printf("all number are equal\n");
                }

                else
                {

                    //функції що знаходять найбільше і найменше значення в масиві
                    int max_of_array = max_value_of_array(array, size_of_array);
                    int min_of_array = min_value_of_array(array, size_of_array);

                    //функції що перевіряють скільки max і min елементів і їх індекс
                    unique_max(array, size_of_array, max_of_array, &unique_of_max, &index_max);
                    unique_min(array, size_of_array, min_of_array, &unique_of_min, &index_min);

                    //роздільний рядок
                    printf("\n");

                    //вивід максимального і мінімального значення масиву
                    printf("max of array: %d\nmin of array: %d\n", max_of_array, min_of_array);

                    //перевірка чи дійсно тільки один максимум і мінімум
                    if (unique_of_min == 1 && unique_of_max == 1)
                    {
                        //обрахунки різниці між індексами (кроки)
                        difference = abs(index_max - index_min);

                        //вивід результату
                        printf("index of max number: %d\nindex of min number: %d\n", index_max, index_min);
                        printf("diffrence between indexs of max and min number: %d\n", difference);
                    }

                    //якщо більше одного мінімума чи максимума в масиві
                    else
                    {
                        printf("Error: %d of max number and %d of min number\n", unique_of_max, unique_of_min);
                        printf("Must be one unique max and min naumber in array\n");
                    }

                    // Звільнення виділеної пам'яті
                    free(array);

                }

            }

        }

        //неможливо створити масив
        else
        {
            printf("Such an array cannot exist\n");
            printf("Please enter a positive integer\n");
        }

        //роздільний рядок
        printf("\n");

        //інформація про те як зупинит  програму
        printf("want to stop program?\nenter (S or s) if want stop: ");
        scanf_s("%s", &stop, 3);

        //зупинення роботи програми
        if ((*stop == 's' || *stop == 'S') && *(stop + 1) == '\0')
        {
            break;
        }

        //очищення потоку (якщо користувач вийшов за масив(рядок))
        do {
            clean_string = getchar();
        } while (clean_string != '\n');

        //роздільний рядок
        printf("\n\n");

    }

    return 0;
        
}