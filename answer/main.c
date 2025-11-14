#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void taskFirst(void *pvParameter)
{
    int count = 0;
    while (count < 3) {
        printf("hello task1: count %d\n", count);
        count++;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void taskSecond(void *pvParameter)
{
    int count = 0;
    while (count < 3) {
        printf("hello task2: count %d\n", count);
        count++;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void taskThird(void *pvParameter)
{
    int count = 0;
    while (count < 3) {
        printf("hello task3: count %d\n", count);
        count++;
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    xTaskCreate(taskFirst,  "t1", 2048, NULL, 3, NULL);
    xTaskCreate(taskSecond, "t2", 2048, NULL, 2, NULL);
    xTaskCreate(taskThird,  "t3", 2048, NULL, 1, NULL);
}
