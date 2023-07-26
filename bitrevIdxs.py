# by https://gist.github.com/rosek86 from here: https://gist.github.com/rosek86/d0d709852fddf36193071d7f61987bae

import math
from sympy.combinatorics import Permutation

def bits_for_value(value):
  return int(math.log2(value))

def decompose(N, R):
  logN2 = bits_for_value(N)
  logR2 = []

  while (N >= R):
    logR2.append(bits_for_value(R))
    N = N // R

  if (N > 1):
    logR2.append(bits_for_value(N))

  return (logN2, logR2)

def reverse_bits(x, n, bits_list):
  result = 0
  for bits in bits_list:
    mask = (0xffffffff >> (32 - bits))
    result = (result << bits) | (x & mask)
    x = x >> bits
  return result

def create_transpositions(N, R):
  (logN2, logR2) = decompose(N, R)

  indexes = []
  for n in range(N):
    indexes.append(reverse_bits(n, logN2, logR2))

  # Create transpositions table
  tps = []
  for c in Permutation.from_sequence(indexes).cyclic_form:
    for i in range(len(c) - 1):
      tps.append([c[i] * 8, c[-1] * 8])

  return tps

def transpositions_stringify(N, R, tps):
  MAX_LINE_LEN   = 79
  MAX_FFT_IN_U16 = 8192

  index_type = "uint32_t"  # 'uint16_t' if N <= MAX_FFT_IN_U16 else 'uint32_t'
  tps_elements_count = len(tps) * 2

  out = '#define ARMBITREVINDEXTABLE_{}_TABLE_LENGTH_EXTRA {}\n'.format(N, tps_elements_count)
  out += 'const {} armBitRevIndexTableExtra{}[ARMBITREVINDEXTABLE_{}_TABLE_LENGTH_EXTRA] = {{\n'.format(index_type, N, N)

  line = ''
  for tp in tps:
    entry = '{},{}'.format(tp[0], tp[1])

    # Append to line
    exp_line_len = len(line) + len(entry) + len(', ,')

    if (line == ''):
      line = '   ' + entry
    elif (exp_line_len >= MAX_LINE_LEN):
      out += line + ',\n'
      line = '   ' + entry
    else:
      line += ', ' + entry

  out += line + '\n};'
  return out
