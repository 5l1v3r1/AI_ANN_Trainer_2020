// /*
// ** EPITECH PROJECT, 2020
// ** decision.c
// ** File description:
// ** This file contains all the decision that the brain can takes.
// */

// #include "samson.h"

// int get_speed(void)
// {
//     char *response = NULL;
//     int result = SUCCESS;

//     my_error("IN GET SPEED find if get checkpoint\n");
//     my_putstr("GET_CURRENT_SPEED\n");
//     response = get_next_line(0);
//     if (response != NULL || fail(response) == ERROR)
//         result = ERROR;
//     if (hidenp("CP", response) == TRUE) {
//         my_error("CHECKPOINT CLEAREDDDDDDDDDDDDDDDDDDDDDD\n");
//         result = TRUE;
//     }
//     free(response);
//     return (result);
// }

// int brake(void)
// {
//     char *response = NULL;
//     int result = SUCCESS;
//     my_error("BRAKINGG\n");

//     my_putstr("car_forward:0\n");
//     response = get_next_line(0);
//     if (response != NULL || fail(response) == ERROR)
//         result = ERROR;
//     if (hidenp("CP", response) == TRUE) {
//         my_error("CHECKPOINT CLEAREDDDDDDDDDDDDDDDDDDDDDD\n");
//         result = TRUE;
//     }
//     free(response);
//     return (result);
// }

// int run()
// {
//     char *response = NULL;
//     int result = FALSE;

//     my_error("RUN MOTHERFUCKER\n");
//     my_putstr("car_forward:1\n");
//     response = get_next_line(0);
//     if (response != NULL || fail(response) == ERROR)
//         result = ERROR;
//     if (hidenp("CP", response) == TRUE) {
//         my_error("CHECKPOINT CLEAREDDDDDDDDDDDDDDDDDDDDDD\n");
//         result = TRUE;
//     }
//     free(response);
//     return (result);
// }

// int turn_weels(float angle)
// {
//     char *response = NULL;
//     int result = FALSE;
//     char *angle_str = my_float_to_str(angle);

//     my_putstr("wheels_dir:");
//     my_putstr(angle_str);
//     my_putchar('\n');
//     my_error("Turn : ");
//     my_error(angle_str);
//     my_error("\n");
//     response = get_next_line(0);
//     if (response != NULL || fail(response) == ERROR)
//         result = ERROR;
//     if (hidenp("CP", response) == TRUE)
//         result = TRUE;
//     free(response);
//     return (result);
// }

// int get_back(lidar_info_t *lidar)
// {
//     char *response = NULL;
//     int result = FALSE;

//     my_error("GET_BACK A LITTLE BITE\n");
//     my_putstr("car_backwards:1\n");
//     response = get_next_line(0);
//     // if (response != NULL || fail(response) == ERROR) {
//     //     free(response);
//     //     return (ERROR);
//     // }
//     my_error("before while\n");
//     for (int i = 0; lidar->dist_front <= 0.1 && i < 10000; i++) {
//         lidar->lidar_arr_num = get_input(lidar);
//     }
//     if (hidenp("CP", response) == TRUE) {
//         my_error("CHECKPOINT CLEAREDDDDDDDDDDDDDDDDDDDDDD\n");
//         result = TRUE;
//     }
//     free(response);
//     return (SUCCESS);
// #include "n4s.h"
// }