/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2014 The srsLTE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the srsLTE library.
 *
 * srsLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * A copy of the GNU Lesser General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#include <stdbool.h>

typedef struct {
  int n;
  uint32_t s;
  int len;
  int k;
  bool tail;
  float ebno;
  int errors;
}expected_errors_t;


static expected_errors_t expected_errors[] = {
    {1000, 1, 40, 7, true, 0.0, 5363},
    {1000, 1, 40, 7, true, 2.0, 356},
    {1000, 1, 40, 7, true, 3.0, 48},
    {1000, 1, 40, 7, true, 4.5, 0},

    {100, 1, 1000, 7, true, 0.0, 8753},
    {100, 1, 1000, 7, true, 2.0, 350},
    {100, 1, 1000, 7, true, 3.0, 33},
    {100, 1, 1000, 7, true, 4.5, 0},

    {-1, -1, -1, -1, true, -1.0, -1}
};

int get_expected_errors(int n, uint32_t s, int len, int k, bool tail, float ebno) {
  int i;
  i=0;
  while(expected_errors[i].n != -1) {
    if (expected_errors[i].n == n
      && expected_errors[i].s == s
      && expected_errors[i].len == len
      && expected_errors[i].k == k
      && expected_errors[i].tail == tail
      && expected_errors[i].ebno == ebno) {
      break;
    } else {
      i++;
    }
  }
  return expected_errors[i].errors;
}
