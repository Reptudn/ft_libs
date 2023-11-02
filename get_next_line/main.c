/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/02 12:24:33 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <CUnit/CUnit.h>
#include <fcntl.h>
// #include <unistd.h>
#include "get_next_line.h"

// void test_get_next_line_empty_file(void) {
//     int fd = open("emptyfile.txt", O_RDONLY);
//     CU_ASSERT_EQUAL(get_next_line(fd), -1);
//     close(fd);
// }

// void test_get_next_line_buffer_size_zero(void) {
//     int fd = open("testfile.txt", O_RDONLY);
//     BUFFER_SIZE = 0;
//     CU_ASSERT_EQUAL(get_next_line(fd), -1);
//     close(fd);
// }

// void test_get_next_line_negative_fd(void) {
//     int fd = -1;
//     CU_ASSERT_EQUAL(get_next_line(fd), -1);
// }

// int main() {
//     CU_initialize_registry();

//     CU_pSuite suite1 = CU_add_suite("get_next_line_test_suite", 0, 0);

//     CU_add_test(suite1, "test_get_next_line_valid_file", test_get_next_line_valid_file);
//     CU_add_test(suite1, "test_get_next_line_invalid_file", test_get_next_line_invalid_file);
//     CU_add_test(suite1, "test_get_next_line_empty_file", test_get_next_line_empty_file);
//     CU_add_test(suite1, "test_get_next_line_buffer_size_zero", test_get_next_line_buffer_size_zero);
//     CU_add_test(suite1, "test_get_next_line_negative_fd", test_get_next_line_negative_fd);

//     CU_basic_set_mode(CU_BRM_VERBOSE);
//     CU_basic_run_tests();
//     CU_cleanup_registry();

//     return CU_get_error();
// }

#include <stdio.h>
int main()
{
    int fd = open("texttest.txt", O_RDONLY);
	for (int i = 0; i < 14; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
}