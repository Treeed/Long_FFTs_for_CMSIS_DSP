import numpy as np

def bit_reversers(power):
    length = (2**power)//4
    return [int(f'{val:0{power-1}b}'[::-1], 2) for val in range(1, length+1)]

def twiddle_coefs_real(length):
    return np.exp(np.pi / 2 * 1j - 2 * np.pi * 1j * np.arange(0, length // 2) / length)

def twiddle_coefs_complex(length):
    return np.exp(2 * np.pi * 1j * np.arange(0, length) / length)